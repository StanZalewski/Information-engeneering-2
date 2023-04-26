//PREVIOUS EXERCISE
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

void create_shapes(std::vector<std::unique_ptr<sf::Drawable>> &shapes_vec) {
    // create some shapes
    std::unique_ptr<sf::CircleShape> circle = std::make_unique<sf::CircleShape>(100.0);
    circle->setPosition(100.0, 300.0);
    circle->setFillColor(sf::Color(100, 250, 50));
    shapes_vec.emplace_back(std::move(circle));

    std::unique_ptr<sf::ConvexShape> triangle = std::make_unique<sf::ConvexShape>(3);
    triangle->setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle->setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle->setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle->setOutlineColor(sf::Color::Red);
    triangle->setOutlineThickness(5);
    triangle->setPosition(600.0, 100.0);
    shapes_vec.emplace_back(std::move(triangle));

    std::unique_ptr<sf::RectangleShape> rectangle = std::make_unique<sf::RectangleShape>(sf::Vector2f(120.0, 60.0));
    rectangle->setPosition(500.0, 400.0);
    rectangle->setFillColor(sf::Color(100, 50, 250));
    shapes_vec.emplace_back(std::move(rectangle));


}




int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    // creating vector to stre different shapes
    std::vector<std::unique_ptr<sf::Drawable>> shapes;

    create_shapes(shapes);






    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }



        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for(auto &s : shapes) {
            window.draw(*s);
        }

        // end the current frame
        window.display();
    }

    return 0;
}
