#include <SFML/Window.hpp>

#include <Box2D\Box2D.h>
using namespace sf;
using namespace std;


const int gameWidth = 1000;
const int gameHeight = 800;

b2World* world;

void init() {
    const b2Vec2 gravity(0.0f, -10.0f);

    // Construct a world, which holds and simulates the physics bodies.
    world = new b2World(gravity);
    //ToDO
}

int main()
{
    return 0;
}