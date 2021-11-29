#include "view.hxx"
#include <string>

using Sprite_set = ge211::Sprite_set;

// colors for sprites
static ge211::Color const bird_color {255, 255, 255};
static ge211::Color const pipe_color {61, 166, 43};

View::View(Model const& model)
        : model_(model),
        //sprite initilization
        bird_sprite(5, bird_color),
        pipe_sprite({50, 300}, pipe_color),
        game_over_sprite("Game Over", {"sans.ttf", 30}),
        over_inst_sprite("Press spacebar or click the mouse to start over",
                         {"sans.ttf",20})
        welcome_sprite("Flappy Bird", {"sans.ttf", 30}),
        instructions_sprite("Press spacebar or click the mouse to start",{"sans.ttf", 30})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    // This needs to do something!
    show_score(set);
}

// helpers

void
View::show_score(Sprite_set& sprites) {
    int score = model_.score;
    ge211::Text_sprite score_sprite(std::to_string(score),
                                          {"sans.ttf",25});
    sprites.add_sprite(score_sprite, {385, 285}, 3);
}
