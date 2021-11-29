#include "model.hxx"

#include <stdlib.h>

Model::Model()
        :bird(Bird()),
        score(0),
        duration_of_jump(0.0),
        pipes(),
        time_passed(0),
        powerups()

{ }

//Move onto member functions!!!

//How do we know when we should play??
void
Model::start_game()
{
    std::vector<Block> pipes_temp;
    // Block one;
    // one.x = 600;
    // one.y = 0;
    // one.width = 100;
    // one.height = 200;
    // Block two;
    // two.x = 600;
    // two.y = 200;
    // two.width = 100;
    // two.height = 200;
    // pipes_temp.push_back(one);
    // pipes_temp.push_back(two);
    for (size_t i = 0; i < 1000; i++){
        Block curr;
        Block curr2;
        curr.x = 600 + (350*i);
        curr2.x = 600 + (350*i);
        curr.y = 0;
        int randval;
        randval = rand() % 200 + 300;
        curr2.y = randval;
        curr.width = 100;
        curr2.width = 100;
        curr.height = randval - 200;
        curr2.height = 600 - randval;
        pipes_temp.push_back(curr);
        pipes_temp.push_back(curr2);
    }
    pipes = pipes_temp;

    bird.live = "live";
}

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

        if (bird.jumping) {
            duration_of_jump += 1;
            if (duration_of_jump > 15) {
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

        for (size_t i = 0; i < 1000; i++){
            pipes[i].x -= 5;
        }

        bird = bird.next(dt);
    }
}