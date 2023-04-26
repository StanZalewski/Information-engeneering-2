#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));

    sf::RectangleShape rectangle(sf::Vector2f(120.0, 60.0));
    rectangle.setPosition(500.0, 400.0);
    rectangle.setFillColor(sf::Color(100, 50, 250));

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::Clock clock;

    int rectangle_velocity_x=50;
    int rectangle_velocity_y=100;
    int rectangle_angular_velocity=10;



    // run the program as long as the window is open
    while (window.isOpen()) {




        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsed = clock.restart();
        float timeDelta = elapsed.asSeconds();;

        float distance_x = rectangle_velocity_x * timeDelta;
        float distance_y = rectangle_velocity_y * timeDelta;
        float rotation_trinagle=rectangle_angular_velocity * timeDelta;

        rectangle.move(distance_x, distance_y);
        rectangle.rotate(rotation_trinagle);

        sf::FloatRect rectangle_bounds = rectangle.getGlobalBounds();

        if (rectangle_bounds.top >= 500) {
            rectangle.setPosition(rectangle.getPosition().x, 500 - rectangle_bounds.height);
            rectangle_velocity_y *= -1;
        }
        if (rectangle_bounds.left >= 800) {
            rectangle.setPosition(800 - rectangle_bounds.width, rectangle.getPosition().y);
            rectangle_velocity_x *= -1;
        }
        if (rectangle_bounds.top <= 0) {
            rectangle.setPosition(rectangle.getPosition().x, 0);
            rectangle_velocity_y *= -1;
        }
        if (rectangle_bounds.left <= 0) {
            rectangle.setPosition(0, rectangle.getPosition().y);
            rectangle_velocity_x *= -1;
        }


        // clear the window with black color
        window.clear(sf::Color::Black);
        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);

        // end the current frame
        window.display();
    }

    return 0;
}
