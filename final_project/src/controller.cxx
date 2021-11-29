#include "controller.hxx"

Controller::Controller(Model& model)
        :model_(model),
         view_(model_)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_mouse_down(ge211::Mouse_button)
{
    if (model_.bird_alive()){

    }else {
        model_.start_game();
    }

}

