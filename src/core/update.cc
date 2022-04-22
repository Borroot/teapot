#include <tuple>
#include "core/update.hh"
#include "core/window.hh"

static void check(Window &window)
{
    sf::Event event;
    while (window.poll(event))
        switch (event.type)
        {
        case sf::Event::KeyPressed:
            // for one time events
            if (event.key.code == sf::Keyboard::Escape)
                window.set_mouse(false);
            break;

        case sf::Event::LostFocus:
            window.set_mouse(false);
            break;
        case sf::Event::GainedFocus:
            window.set_mouse(true);
            break;

        case sf::Event::Closed:
            window.close();
            break;

        default: break;
        }
}

static void move(Window &window, World &world, double dt)
{
    if (!window.mouse) return;

    Vec3 move(0, 0, 0);

    Vec3 forward(world.camera.forward().x, 0, world.camera.forward().z);
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

    world.camera.pos += move * dt;
}

static void turn(Window &window, World &world, double dt)
{
    if (!window.mouse) return;

    sf::Vector2i pos = sf::Mouse::getPosition(window.window);
    pos.x -= window.w / 2;
    pos.y -= window.h / 2;

    if (pos.y != 0)
        world.camera.update_pitch(pos.y * dt);
    if (pos.x != 0)
        world.camera.update_yaw(pos.x * dt);

    sf::Mouse::setPosition(sf::Vector2i(window.w / 2, window.h / 2), window.window);
}

void update(Window &window, World &world, double dt)
{
    check(window);
    move(window, world, dt);
    turn(window, world, dt);
}