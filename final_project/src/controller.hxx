#pragma once

#include "model.hxx"
#include "view.hxx"

#include <ge211.hxx>

//EVERY CLICK SETS duration_of_jump to 0

class Controller : public ge211::Abstract_game
{
public:
    Controller();

protected:
    void draw(ge211::Sprite_set& set) override;

private:
    Model model_;
    View view_;
};
