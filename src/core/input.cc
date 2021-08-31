#include <tuple>
#include "core/input.hh"
#include "core/window.hh"

static void check(Window &window)
{
    sf::Event event;
    while (window.poll(event))
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            // for one time actions
            break;
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
}

static void move(Window &window, World &world, double dt)
{
    Vec3 move(0, 0, 0);

    Vec3 forward(world.camera.forward.x, 0, world.camera.forward.z);
    Vec3 right = forward ^ Vec3(0, 1, 0);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        move += forward;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        move -= forward;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        move += right;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        move -= right;

    move.normalize();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        move += Vec3(0, 1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        move += Vec3(0, -1, 0);

    world.camera.pos += move * 2 * dt;
}

static void turn(Window &window, World &world, double dt)
{
    sf::Vector2i pos = sf::Mouse::getPosition(window.window);
    pos.x -= window.w / 2;
    pos.y -= window.h / 2;

    if (pos.x != 0 || pos.y != 0)
    {
        Mat4 pitch = Mat4::rotx(pos.y * dt);
        Mat4 yaw = Mat4::roty(pos.x * dt);

        // TODO put a limit on the total pitch

        world.camera.forward = pitch * yaw * world.camera.forward;
        sf::Mouse::setPosition(sf::Vector2i(window.w / 2, window.h / 2), window.window);
    }
}

void update(Window &window, World &world, double dt)
{
    check(window);
    move(window, world, dt);
    turn(window, world, dt);
}