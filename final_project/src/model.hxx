#pragma once


#include "bird.hxx"
#include <vector>

class Model
{

public:
    //Constructor, should not take in any arguments because the size of the
    // window is not changing. The bird will always start in the middle of
    // the screen and the first set of blocks will be pre-made and then
    // random after that. Add one each time after they move off the screen
    explicit Model();


    ///MEMBER FUNCTIONS

    // Start the game or restart and have the bird begin to move
    // Set the score to 0
    void start_game();

    std::string bird_alive() const;
    // When the game is started the bird is moved to the original position
    void bird_to(int y);

    // If ball is dead do nothing.
    // Using the BIRD::NEXT(), which gives you the bird at the next dt.
    // Check if it has hit something:

    // Could have hit the top
    // Could have hit the bottom
    // Could have hit a pipe

    //If the ball is still live then actually update the jaunt
    void on_frame(double dt);


    void jump();
    ///MEMBER VARIABLES:

    Bird bird;

    int time_passed;

    int level;

    std::vector<Block> pipes;

    int score;

    std::vector<Block> powerups;

    int dist_traveled;
private:

    float duration_of_jump;
};
