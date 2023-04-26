#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

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

    void animate(const sf::Time &elapsed){
        sf::Vector2f position = getPosition();
        position.x += x_velocity_*elapsed.asSeconds();
        position.y += y_velocity_*elapsed.asSeconds();
        setPosition(position);

        float rotation =getRotation();
        rotation+= rotation_ * elapsed.asSeconds();
        setRotation(rotation);

        bounce();


    }

    void setBounds(int left, int right, int top, int bottom){
        left_=left;
        right_=right;
        top_=top;
        bottom_=bottom;

    }

private:
    int x_velocity_;
    int y_velocity_;
    int rotation_;

    int left_,right_,top_,bottom_;


    void bounce(){
        sf::Vector2f position= getPosition();
        if (position.x<=left_){
            x_velocity_=abs(x_velocity_);
        }
        if (position.x>=right_){
            x_velocity_=-abs(x_velocity_);
        }
        if (position.y<=top_){
            y_velocity_=abs(y_velocity_);
        }
        if (position.y>=bottom_){
            y_velocity_=-abs(y_velocity_);
        }
    }


};

int main() {
    // create the window
    sf::RenderWindow window(sf::VideoMode(1000, 800), "My window");

    // create some shapes
    sf::CircleShape circle(100.0);
    circle.setPosition(100.0, 300.0);
    circle.setFillColor(sf::Color(100, 250, 50));


    sf::Vector2f size(120.0, 60.0);
    sf::Vector2f position(120.0, 60.0);
    CustomRectangleShape rectangle(size, position);
    rectangle.setFillColor(sf::Color(100, 50, 250));
    rectangle.setSpeed(100, 150, 10);
    rectangle.setBounds(0, window.getSize().x, 0, window.getSize().y);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.0, 0.0));
    triangle.setPoint(1, sf::Vector2f(0.0, 100.0));
    triangle.setPoint(2, sf::Vector2f(140.0, 40.0));
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setOutlineThickness(5);
    triangle.setPosition(600.0, 100.0);

    sf::Clock clock;




    // run the program as long as the window is open
    while (window.isOpen()) {




        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            std::cout << "Holding up button" << std::endl;
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Middle))
        {
            std::cout << "Holding middle mouse button" << std::endl;
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        sf::Time elapsed = clock.restart();

        rectangle.animate(elapsed);


        // draw everything here...
        window.draw(circle);
        window.draw(rectangle);
        window.draw(triangle);


        // end the current frame
        window.display();
    }

    return 0;
}
