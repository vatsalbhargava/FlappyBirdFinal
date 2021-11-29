#include "controller.hxx"

Controller::Controller(Model& model)
        :model_(model),
         view_(model_),
         bird(model.bird)
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_mouse_down(ge211::Mouse_button)
{
    if (model_.bird_alive() == "live"){
        bird.center.y += 80;
    }else {
        model_.bird_to(300);
        model_.start_game();
    }

}

void
Controller::on_key(ge211::Key key){
    if (key == ge211::Key::code('q')){
        quit();
    }

    if (key == ge211::Key::code(' ')){
        if (model_.bird_alive() == "live"){
            bird.center.y += 80;
        }else {
            model_.bird_to(300);
            model_.start_game();
        }
    }
}

void
Controller::on_frame(double dt){
    model_.on_frame(dt);
}