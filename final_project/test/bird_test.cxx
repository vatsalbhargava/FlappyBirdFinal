#include "bird.hxx"
#include <catch.hxx>

TEST_CASE("Bird Hitting Tings Test")
{
    Bird bird;
    CHECK(bird.center.x == 400);
    CHECK_FALSE(bird.hits_top());
    CHECK_FALSE(bird.hits_bottom());
    std::vector<Block> pipes;
    pipes.push_back({600,300,100,100});
    bird.velocity.width = 199;
    double dt = 1;
    bird = bird.next(dt);
    CHECK(bird.hit_pipe(pipes));
    bird = bird.next(dt);
    bird.center.y = 10;
    CHECK(bird.hits_top());

}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate at least six of the functional
// requirements.
//
