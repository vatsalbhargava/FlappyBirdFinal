#include "model.hxx"

#include <stdlib.h>

Model::Model()
        :bird(Bird()),
        time_passed(0),
        level(0),
        pipes(),
        score(0),
        powerups(),
        dist_traveled(0),
        pu_score(0),
        duration_of_jump(0.0)

{ }

//Move onto member functions!!!

//How do we know when we should play??
void
Model::start_game()
{
    std::vector<Block> pipes_temp;
    std::vector<Block> pu_temp;

    for (size_t i = 0; i < 1000; i++){
        Block curr;
        Block curr2;
        curr.x = 650 + (350*i);
        curr2.x = 650 + (350*i);
        curr.y = 0;
        int randval;
        randval = rand() % 200 + 300;
        curr2.y = randval;
        curr.width = 50;
        curr2.width = 50;
        curr.height = randval - 200;
        curr2.height = 600 - randval;
        pipes_temp.push_back(curr);
        pipes_temp.push_back(curr2);
        int randpu = rand() % 6;

        if (randpu < 2){
            Block powerup;
            powerup.width = 40;
            powerup.height = 40;
            powerup.x = 655 + (350*i);
            powerup.y = randval - 100;
            pu_temp.push_back(powerup);
        }
    }


    pipes = pipes_temp;
    powerups = pu_temp;
    time_passed = 0;
    score = 0;
    dist_traveled = 0;
    pu_score = 0;
    bird.live = "live";
}

// helper for making pipes

//Useful for restarting the game
void
Model::bird_to(int y)
{
    bird.center.y = y;

}

std::string
Model::bird_alive() const{
    return bird.live;
}

void
Model::jump() {
    bird.velocity.height = -400;
    bird.jumping = true;
    duration_of_jump = 0.0;
}


void
Model::on_frame(double dt)
{
    //Only do shit if the bird is live

    if (bird.live == "live"){
        dist_traveled += 1;
        time_passed += 1;
        if (bird.jumping) {
            duration_of_jump += 1;
            if (duration_of_jump > 10) {
                bird.velocity.height = bird.gravity;
                duration_of_jump = 0.0;
                bird.jumping = false;
            }
        }

        Bird temp_bird = bird.next(dt);

        //Check if it hits the top,bottom, or any bricks
        if (temp_bird.hits_top()){
            bird.live = "dead";
        }

        if (temp_bird.hit_pipe(pipes)){
            bird.live = "dead";
        }

        if (temp_bird.hits_bottom()){
            bird.live = "dead";
        }

        if (temp_bird.hit_powerup(powerups)) {
            pu_score += 1;
        }

        level = (score - pu_score)/5;
        int tempsc = 0;
        for (size_t i = 0; i < pipes.size(); i++){
            pipes[i].x -= (5 + level);

            if(pipes[i].x < 325){
                tempsc += 1;
            }
        }
        score = tempsc/2 + pu_score;

        if (bird.live == "live"){
            bird = bird.next(dt);
        }
        for (size_t i = 0; i < powerups.size(); i++) {
            powerups[i].x -= (5 + level);
        }

    }
}