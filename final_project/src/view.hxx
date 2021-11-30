#pragma once

#include "model.hxx"

class View
{
public:
    explicit View(Model const& model);

    void draw(ge211::Sprite_set& set);

private:
    Model const& model_;
    // image sprites
    ge211::Image_sprite const flappy_sprite;
    ge211::Image_sprite const background_sprite;
    ge211::Image_sprite const pipe_image;
    ge211::Image_sprite const coin_sprite;
    // sprites for game
    ge211::Circle_sprite const bird_sprite;
    ge211::Rectangle_sprite const pipe_sprite;
    ge211::Circle_sprite const powerup_sprite;

    // score sprite
    ge211::Text_sprite score_sprite;

    // end game sprites
    ge211::Text_sprite const game_over_sprite;
    ge211::Text_sprite const over_inst_sprite;
    ge211::Text_sprite const quit_sprite;
    // start screen sprites
    ge211::Text_sprite const welcome_sprite;
    ge211::Text_sprite const instructions_sprite;

    // helpers
    void show_instructions(ge211::Sprite_set& sprites);
    void draw_pipes(ge211::Sprite_set& sprites);
    void show_score(ge211::Sprite_set& sprites);
    void show_powerup(ge211::Sprite_set& sprites);
};
