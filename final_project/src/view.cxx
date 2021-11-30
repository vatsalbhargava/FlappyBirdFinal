#include "view.hxx"
#include <string>

using Sprite_set = ge211::Sprite_set;

// colors for sprites
static ge211::Color const bird_color {34, 34, 34};
static ge211::Color const pipe_color {61, 166, 43};
static ge211::Color const powerup_color { 250, 245, 74};

View::View(Model const& model)
        : model_(model),
        //sprite initilization
        flappy_sprite("homemade_flappy.png"),
          background_sprite("background.png"),
          pipe_image("pipe.png"),
          coin_sprite("coin.png"),
        bird_sprite(model.bird.radius, bird_color),
        pipe_sprite({50, 500}, pipe_color),
        powerup_sprite(20, powerup_color),
        score_sprite(std::to_string(model.score), {"sans.ttf",25}),
        game_over_sprite("Game Over", {"sans.ttf", 40}),
        over_inst_sprite("Press the spacebar or mouse to start over",
                         {"sans.ttf",20}),
          quit_sprite("Or Press 'Q' to Quit", {"sans.ttf",20}),
          welcome_sprite("Flappy Bird", {"sans.ttf", 40}),
        instructions_sprite("Press the spacebar or mouse to start and to jump",
                            {"sans.ttf", 20})
{ }

void
View::draw(ge211::Sprite_set& set)
{
    show_score(set);
    set.add_sprite(flappy_sprite, model_.bird.bird_top_left(),1);
    set.add_sprite(bird_sprite, model_.bird.bird_top_left(),.5);
    set.add_sprite(background_sprite, {0,-150}, -1);
    // draw UI
    show_instructions(set);
    // draw elements
    draw_pipes(set);
    show_powerup(set);
}

// helpers
void
View::show_instructions(Sprite_set& sprites) {
    if (model_.bird_alive() == "start") {
        sprites.add_sprite(welcome_sprite, {300,200}, 2);
        sprites.add_sprite(instructions_sprite, {200,350}, 2);
    } else if (model_.bird_alive() == "dead") {
        sprites.add_sprite(game_over_sprite, {310,200}, 2);
        sprites.add_sprite(over_inst_sprite, {225,325}, 2);
        sprites.add_sprite(quit_sprite, {325, 375}, 2);
    }
}

void
View::draw_pipes(Sprite_set& sprites) {
    for (Block pipe : model_.pipes) {
        if (pipe.y == 0) {
            sprites.add_sprite(pipe_image, {pipe.x, pipe.height-500}, 0);
        } else {
            sprites.add_sprite(pipe_image, {pipe.x, pipe.y}, 0);
        }
    }
}

void
View::show_score(Sprite_set& sprites) {
    score_sprite = ge211::Text_sprite (std::to_string(model_.score),
                                       {"sans.ttf",30});
    sprites.add_sprite(score_sprite, {388, 100}, 3);
}

void
View::show_powerup(Sprite_set& sprites) {
    for (Block item : model_.powerups) {
        sprites.add_sprite(coin_sprite, item.top_left(), 0);
    }
}