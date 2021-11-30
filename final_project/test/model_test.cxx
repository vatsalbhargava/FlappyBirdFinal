#include "model.hxx"
#include <catch.hxx>

TEST_CASE("Bird Builds")
{
    Model m;
    CHECK(m.bird.live == "start");
    CHECK(m.bird.center.y == 300);

}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate at least six of the functional
// requirements.
//
TEST_CASE("1.Jump Works?")
{
    Model m;
    CHECK(m.bird.live == "start");
    m.bird.live = "live";
    m.pipes.clear();
    m.jump();
    double dt = .1;
    m.on_frame(dt);
    CHECK(m.bird.center.y == 260);
    CHECK(m.bird.center.x == 400);
}

TEST_CASE("2. Gravity Works?")
{
    Model m;
    CHECK(m.bird.live == "start");
    m.bird.live = "live";
    m.pipes.clear();
    double dt = .1;
    m.on_frame(dt);
    CHECK(m.bird.center.y == 330);
    CHECK(m.bird.center.x == 400);
    CHECK(m.bird.velocity.height == 300);
}

TEST_CASE("3.Hit Pipes, Top, and Bottom")
{
    //Check if it has hit a pipe by seeing if the bird dies
    Model m;
    CHECK(m.bird.live == "start");
    m.bird.live = "live";
    double dt = 1;
    m.bird.center.y = 501;
    m.bird.velocity.height = 0;
    Block test_pipe = {310,300,500,500};
    m.pipes.push_back(test_pipe);
    m.bird.velocity.width = 12;
    m.on_frame(dt);
    CHECK(m.bird.live == "dead");
//-----------------------------------------//

    //See if it hits the bottom and top by killing the bird
    Model m1;
    m1.bird.live = "live";
    m1.bird.velocity.height = 1000;
    m1.on_frame(dt);
    CHECK(m1.bird.live == "dead");

    Model m2;
    m2.bird.live = "live";
    m2.bird.velocity.height = -1000;
    m2.on_frame(dt);
    CHECK(m2.bird.live == "dead");

}

TEST_CASE("4. Score Resetting when Game Restarts")
{
    Model m;
    CHECK(m.bird.live == "start");
    m.bird.live = "live";
    m.score = 10;
    CHECK(m.score == 10);
    m.bird.live = "dead";
    // restart game then score should be 0
    m.start_game();
    CHECK(m.score == 0);

}

TEST_CASE("5. Point Gaining")
{
    Model m;
    CHECK(m.bird.live == "start");
    m.bird.live = "live";
    // move to center
    m.bird.center = {400, 300};
    // kill velocity
    m.bird.velocity = {0,0};

    // check if score increases when goes through first pipe
    int old_score1 = m.score;
    m.pipes.clear();
    Block new_pipe1 = {326, 0, 50, 100};
    Block new_pipe2 = {326, 500, 50, 100};
    m.pipes.push_back(new_pipe1);
    m.pipes.push_back(new_pipe2);
    m.on_frame(10);
    CHECK(m.score == old_score1 + 1);

    // check hitting power up increases score +1
    Block test_power = {40, 40, 400, 300};
    int old_score2 = m.score;
    m.powerups.push_back(test_power);
    m.on_frame(1);
    CHECK(m.score == old_score2 + 1);
}

TEST_CASE("6. Game Speeds Up")
{
    Model m;
    m.bird.live = "live";
    m.pipes.clear();
    CHECK(m.level == 0);
    CHECK(m.score == 0);
    Block new_pipe1 = {326, 0, 50, 100};
    Block new_pipe2 = {326, 500, 50, 100};
    Block new_pipe3 = {346, 0, 50, 100};
    Block new_pipe4 = {346, 500, 50, 100};
    Block new_pipe5 = {366, 0, 50, 100};
    Block new_pipe6 = {366, 500, 50, 100};
    Block new_pipe7 = {386, 0, 50, 100};
    Block new_pipe8 = {386, 500, 50, 100};
    Block new_pipe9 = {406, 0, 50, 100};
    Block new_pipe10 = {406, 500, 50, 100};
    m.pipes.push_back(new_pipe1);
    m.pipes.push_back(new_pipe2);
    m.pipes.push_back(new_pipe3);
    m.pipes.push_back(new_pipe4);
    m.pipes.push_back(new_pipe5);
    m.pipes.push_back(new_pipe6);
    m.pipes.push_back(new_pipe7);
    m.pipes.push_back(new_pipe8);
    m.pipes.push_back(new_pipe9);
    m.pipes.push_back(new_pipe10);
    m.bird.velocity.height = 0;
    m.bird.velocity.width = 100;
    double dt = 10;
    for (size_t i = 0; i < 100; i++){
        m.on_frame(dt);
    }
    CHECK(m.score == 5);
    CHECK(m.level == 1);


}