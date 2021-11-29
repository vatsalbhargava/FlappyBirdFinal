#include "view.hxx"
#include <string>

using Sprite_set = ge211::Sprite_set;

// colors for sprites
static ge211::Color const bird_color {255, 255, 255};
static ge211::Color const pipe_color {61, 166, 43};

View::View(Model const& model)
        : model_(model),
        //sprite initilization
        bird_sprite(model.bird.radius, bird_color),
        pipe_sprite({50, 500}, pipe_color),
        score_sprite(std::to_string(model.score), {"sans.ttf",25}),
        game_over_sprite("Game Over", {"sans.ttf", 30}),
        over_inst_sprite("Press spacebar or click the mouse to start over",
                         {"sans.ttf",20}),
        welcome_sprite("Flappy Bird", {"sans.ttf", 30}),
        instructions_sprite("Press spacebar or click the mouse to start",
                            {"sans.ttf", 20})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    set.add_sprite(score_sprite, {385, 100}, 3);
    set.add_sprite(bird_sprite, model_.bird.bird_top_left(), 1);
    // draw UI
    show_instructions(set);
    // draw elements
    draw_pipes(set);
}

// helpers


void
View::show_instructions(Sprite_set& sprites) {
    if (model_.bird_alive() == "start") {
        sprites.add_sprite(welcome_sprite, {250,200}, 2);
        sprites.add_sprite(instructions_sprite, {100,400}, 2);
    } else if (model_.bird_alive() == "dead") {
        sprites.add_sprite(game_over_sprite, {100,200}, 2);
        sprites.add_sprite(over_inst_sprite, {385,400}, 2);
    }
}

void
View::draw_pipes(Sprite_set& sprites) {
    for (Block pipe : model_.pipes) {
        if (pipe.y == 0) {
            sprites.add_sprite(pipe_sprite, {pipe.x, pipe.height-500}, 1);
        } else {
            sprites.add_sprite(pipe_sprite, {pipe.x, pipe.y}, 2);
        }
    }
}