
#include "bird.hxx"

// setting value of gravity
float bird_gravity = 250;

Bird::Bird()
        : radius(10),
          center(Posn {400,300}),
          velocity({0, bird_gravity}),
          live("start"),
          jumping(false),
          gravity(bird_gravity)

{ }

ge211::Posn<int>
Bird::bird_top_left() const
{
    // TODO: replace this with your code:
    int x_coordinate = center.x - radius;
    int y_coordinate = center.y - radius;

    return {x_coordinate,y_coordinate};
}

bool
Bird::hits_bottom() const
{
    // TODO: replace this with your code:
    return (center.y + radius > 600) ;
}

// The Bird hits the top when the y coordinate of its top is less than
// 0. (Note that the parameter isn't used.)
bool
Bird::hits_top() const
{
    // TODO: replace this with your code:
    return (center.y - radius < 0);
}


// Recall that `this` is a `const Bird*`, and you can create a copy of a Bird
// with the copy constructor. So to get a new `Bird` to return, you can write
//
//     Bird result(*this);
//
Bird
Bird::next(double dt) const
{
    Bird result(*this);

    // TODO: your code here
    // if (!jumping){
    //     result.center.y -= 1;
    //     return result;
    // }else{
    //     result.center.y += 50;
    //     return result;
    // }

    float dist_y = velocity.height * dt;
    result.center.y += dist_y;
    return result;

}

// As with the edge collision functions, we want to use the Bird's
// bounding box. That is, the box whose top is center.y - radius, whose
// left is center.x - radius, whose bottom is center.y + radius, and
// whose right is center.x + radius.
//
// That way, we are checking for the intersection of two rectangles.
//
// One way to think of that is that the rectangles *don't* intersect if
// either of these is true:
//
//  - The right side of one rectangle is to the left of the left side of
//  the other.
//
//  - The bottom of one rectangle is above the top of the other
//
// Otherwise, they do.
//
bool
Bird::hits_block(Block const& block) const
{
    // x = left side
    //y is the top
    // TODO: replace this with your code:
    // ccheck left right
    if (center.x + radius < block.x){
        return false;
    }
    if (block.x + block.width < center.x - radius){
        return false;
    }
    // check up down
    if (center.y + radius < block.y){
        return false;
    }
    if (block.y + block.height <  center.y - radius){
        return false;
    }
    return true;

    // bird dims
    /*float ball_right = center.x + radius;
    float ball_left = center.x - radius;
    float ball_top = center.y - radius;
    float ball_bottom = center.y + radius;
    // block dims
    float block_right = block.x + block.width;
    float block_left = block.x;
    float block_top = block.y;
    float block_bottom = block.y + block.height;

    if ((ball_right < block_left) || (block_right < ball_left)) {
        return false;
    } else if ((ball_bottom < block_top) || (block_bottom < ball_top)) {
        return false;
    } else {
        return true;
    }*/
}

// Once you've written `Bird::hits_block`, finding an element of `bricks`
// that collides with this Bird isn't hard (use a for-each loop), but
// how to /remove it once you find it? The more obvious solution may be
// to shift all the elements after it to the left, but that's awkward,
// and there's a cleaner way when the order of the elements of the
// vector doesn't matter:
//
//  1. Replace the hit brick with a copy of the last brick (`bricks.last()`)
//     by assignment. If you want to edit a brick in `bricks`, make sure each
//     brick given by the for-each loop is a reference to the existing brick,
//     not a copy.
//
//  2. Now the brick you didn't want is gone, but you have an extra in the back
//     that duplicates the one you just got rid of, so remove the last brick
//     using pop_back().
//
//  3. Don't keep iterating after a pop_back() or you will go out of
//     bounds, because the loop condition won't adjust to the diminished
//     vector.
//
bool
Bird::hit_pipe(std::vector<Block>& bricks) const
{
    // TODO: replace this with your code:
    for (Block& curr: bricks){
        if (hits_block(curr)){
            // curr = bricks.back();
            // bricks.pop_back();
            return true;
        }
    }
    return false;
}

bool
Bird::hit_powerup(std::vector<Block>& powerups) const
{
    for (Block& curr: powerups) {
        if (hits_block(curr)) {
            powerups.pop_back();
            return true;
        }
    }
    return false;
}
