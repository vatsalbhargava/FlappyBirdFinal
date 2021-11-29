#pragma once

#include "model.hxx"
#include "view.hxx"
#include "bird.hxx"
#include <ge211.hxx>

//EVERY CLICK SETS duration_of_jump to 0

class Controller : public ge211::Abstract_game
{
public:
    Controller(Model& model);

protected:
    void draw(ge211::Sprite_set& set) override;
    void on_key(ge211::Key) override;
    void on_mouse_down(ge211::Mouse_button) override;
    void on_frame(double dt) override;


private:
    Model model_;
    View view_;
    Bird bird;
};
