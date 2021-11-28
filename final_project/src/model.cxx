#include "model.hxx"

Model::Model()
        :bird(Bird()),
        score(0),
        duration_of_jump(0.0)

{
    Block curr;
    curr.x = 600;
    curr.y = 400;
    curr.width = 100;
    curr.height = 200;
    Block curr1;
    curr1.x = 600;
    curr1.y = 200;
    curr1.width = 100;
    curr1.height = 200;
    pipes.push_back(curr);
    pipes.push_back(curr1);
}

//Move onto member functions!!!




