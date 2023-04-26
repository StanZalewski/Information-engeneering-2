#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <random>

using namespace std;


class CustomRectangleShape : public sf::RectangleShape {

public:
    CustomRectangleShape(const sf::Vector2f &size, const sf::Vector2f &position)
        : sf::RectangleShape(size){
        setPosition(position);
    }

    int x_velocity(){
        return x_velocity_;
    }
    int y_velocity(){
        return y_velocity_;
    }
    int rotation(){
        return rotation_;
    }

    void setSpeed(int vel_x, int vel_y, int rot){
        x_velocity_=vel_x;
        y_velocity_=vel_y;
        rotation_=rot;
    }


    void setBounds(int left, int right, int top, int bottom){
        left_=left;
        right_=right;
        top_=top;
        bottom_=bottom;

    }

    void setIndex(bool index){
        current_in_use = index;
        std::cout<<index<<std::endl;
    }

    int getIndex(){
        return current_in_use;
    }

    void moveInDirection(const sf::Time &elapsed, const sf::Keyboard::Key &key){

        sf::Vector2f position=getPosition();
        if (getFillColor()==sf::Color::Red && key==sf::Keyboard::A){
            position.x -= x_velocity_*elapsed.asSeconds();
            position.y = position.y;
            setPosition(position);
        }
        if (getFillColor()==sf::Color::Red && key==sf::Keyboard::D){
            position.x += x_velocity_*elapsed.asSeconds();
            position.y = position.y;
            setPosition(position);
        }
        if (getFillColor()==sf::Color::Red && key==sf::Keyboard::W){
            position.x =position.x;
            position.y -= y_velocity_*elapsed.asSeconds();
            setPosition(position);
        }
        if (getFillColor()==sf::Color::Red && key==sf::Keyboard::S){
            position.x = position.x;
            position.y += y_velocity_*elapsed.asSeconds();
            setPosition(position);
        }
    }

private:
    int x_velocity_;
    int y_velocity_;
    int rotation_;

    int left_,right_,top_,bottom_;

    bool current_in_use;



};

int main() {
    sf::Clock clock;

    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 800), "My window");

    // for loop to create 15 rectangles in random spots
    sf::Vector2f size(120.0, 60.0);
    std::vector<CustomRectangleShape> rectangles;
    for (int i = 0; i < 15; i++) {
        sf::Vector2f size(120.0, 60.0);
        sf::Vector2f position(std::rand() % (window.getSize().x - 120), std::rand() % (window.getSize().y - 60));
        rectangles.emplace_back(CustomRectangleShape(size, position));
    }
    for (auto &rec : rectangles) {
        rec.setFillColor(sf::Color::Green);
        rec.setBounds(0, window.getSize().x, 0, window.getSize().y);
        rec.setSpeed(500, 500, 500);
    }

    // run the program as long as the window is open
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                // check if mouse click is inside the rectangle
                for (int i = 0; i < 15; i++) {
                    if (rectangles[i].getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))) {
                        for (auto &r : rectangles) {
                            r.setFillColor(sf::Color::Green);
                        }
                        // change the rectangle color to red
                        rectangles[i].setFillColor(sf::Color::Red);
                        rectangles[i].setIndex(i);
                        break;
                    }
                }
            }
        }

        // move the rectangles in the selected direction
        for (auto &rec : rectangles) {
            if (rec.getIndex()==true){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
                    rec.moveInDirection(clock.restart(), sf::Keyboard::Key::A);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
                    rec.moveInDirection(clock.restart(), sf::Keyboard::Key::D);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
                    rec.moveInDirection(clock.restart(), sf::Keyboard::Key::W);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
                    rec.moveInDirection(clock.restart(), sf::Keyboard::Key::S);
                }
            }
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for (auto &rec : rectangles) {
            window.draw(rec);
        }

        // end the current frame
        window.display();
    }

    return 0;
}


