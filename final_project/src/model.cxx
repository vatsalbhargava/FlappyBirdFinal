#include "model.hxx"

#include <stdlib.h>

Model::Model()
        :bird(Bird()),
        score(0),
        duration_of_jump(0.0)

{
    //Create an array with 200 pipes that are evenly spaced apartvia the x
    // There is however a random size gap between the size of the pillars

    for (size_t i = 0; i < 100; i++){
        Block curr;
        Block curr2;
        curr.x = 600 + (350*i);
        curr2.x = 600 + (350*i);
        curr.y = 0;
        int randval;
        randval = rand() % 400 + 100;
        curr2.y = randval;
        curr.width = 100;
        curr2.width = 100;
        curr.height = randval - 200;
        curr2.height = randval;
        pipes.push_back(curr);
        pipes.push_back(curr2);
    }


}

//Move onto member functions!!!

//How do we know when we should play??
void
Model::start_game()
{
    bird.live = true;
}

//Useful for restarting the game
void
Model::bird_to(int y)
{
    bird.center.y = y;

}

void
Model::on_frame(double dt)
{
    //Only do shit if the bird is live
    if (bird.live){
        Bird temp_bird = bird.next();

        //Check if it hits the top,bottom, or any bricks
        if (temp_bird.hits_top()){
            bird.live = false;
        }

        if (temp_bird.hit_pipe(pipes)){
            bird.live = false;
        }

        if (temp_bird.hits_bottom()){
            bird.live = false;
        }

        bird = bird.next(dt);
    }
}