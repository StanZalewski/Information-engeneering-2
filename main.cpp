#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Lesson_5_SFML_Final_Assignment.h"

////TO CONTROL THE GUY IN THE MAZE USE W,S,A,D CONTROLS //////


void create_shapes(sf::RenderWindow& window, std::vector<std::unique_ptr<sf::Drawable>>& shapes_vec, std::vector<sf::Texture>& textures_) {
    // create some shapes
    ////BACKGROUND---->>>>

    sf::Sprite background;
    background.setTexture(textures_[0]);
    background.setScale(0.5, 0.5);
    background.setTextureRect(sf::IntRect(0, 0, 2 * window.getSize().x, 2 * window.getSize().x));

    ////GUY------>>>

    sf::Sprite guy;
    guy.setTexture(textures_[1]);
    guy.setTextureRect(sf::IntRect(10, 0, 25, 70));
    ////WALLS----->>>>

    sf::Sprite wall_1;
    wall_1.setTexture(textures_[2]);
    wall_1.setScale(0.3, 0.3);
    wall_1.setTextureRect(sf::IntRect(0, 0, 70, 600));
    wall_1.setPosition(200, 300);

    sf::Sprite wall_2;
    wall_2.setTexture(textures_[2]);
    wall_2.setScale(0.3, 0.3);
    wall_2.setTextureRect(sf::IntRect(0, 0, 70, 400));
    wall_2.setPosition(400, 80);

    sf::Sprite wall_3;
    wall_3.setTexture(textures_[2]);
    wall_3.setScale(0.3, 0.3);
    wall_3.setTextureRect(sf::IntRect(0, 0, 400, 70));
    wall_3.setPosition(200, 300);

    sf::Sprite wall_4;
    wall_4.setTexture(textures_[2]);
    wall_4.setScale(0.3, 0.3);
    wall_4.setTextureRect(sf::IntRect(0, 0, 800, 70));
    wall_4.setPosition(500, 380);

    shapes_vec.push_back(std::make_unique<sf::Sprite>(background));
    shapes_vec.push_back(std::make_unique<sf::Sprite>(guy));
    shapes_vec.push_back(std::make_unique<sf::Sprite>(wall_1));
    shapes_vec.push_back(std::make_unique<sf::Sprite>(wall_2));
    shapes_vec.push_back(std::make_unique<sf::Sprite>(wall_3));
    shapes_vec.push_back(std::make_unique<sf::Sprite>(wall_4));
}

void input_texture(std::vector<sf::Texture>& textures_) {
    sf::Texture texture_background;
    if (!texture_background.loadFromFile("C:/grass.png")) {}
    texture_background.setRepeated(true);
    textures_.push_back(texture_background);

    sf::Texture texture_guy;
    if (!texture_guy.loadFromFile("C:/guy.png")) {
        std::cerr << "Could not load texture" << std::endl;
    }
    textures_.push_back(texture_guy);

    sf::Texture texture_wall;
    if (!texture_wall.loadFromFile("C:/wall.png")) {}
    texture_wall.setRepeated(true);
    textures_.push_back(texture_wall);
}



int main() {
    sf::Clock clock;
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // creating vector to store different shapes and textures
    std::vector<std::unique_ptr<sf::Drawable>> shapes;
    std::vector<sf::Texture> textures;

    input_texture(textures);
    create_shapes(window, shapes, textures);


    // run the program as long as the window is open
    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        auto guy = dynamic_cast<sf::Sprite*>(shapes[1].get());
        auto wall_1 = dynamic_cast<sf::Sprite*>(shapes[2].get());
        auto wall_2 = dynamic_cast<sf::Sprite*>(shapes[3].get());
        auto wall_3 = dynamic_cast<sf::Sprite*>(shapes[4].get());
        auto wall_4 = dynamic_cast<sf::Sprite*>(shapes[5].get());
        sf::Vector2f position = guy->getPosition();
        int x_velocity_=150;
        int y_velocity_=150;




        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
            if (wall_1->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_2->getGlobalBounds().intersects(guy->getGlobalBounds())||
                wall_3->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_4->getGlobalBounds().intersects(guy->getGlobalBounds())){
                position.x+=1;
                guy->setPosition(position);

            }
            else{
                if (position.x>0){
                    position.x -= x_velocity_*elapsed.asSeconds();
                    position.y = position.y;
                    guy->setPosition(position);
                }
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
            if (wall_1->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_2->getGlobalBounds().intersects(guy->getGlobalBounds())||
                wall_3->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_4->getGlobalBounds().intersects(guy->getGlobalBounds())){
                position.x-=1;
                guy->setPosition(position);
            }
            else{
                if (position.x+26<window.getSize().x){
                    position.x += x_velocity_*elapsed.asSeconds();
                    position.y = position.y;
                    guy->setPosition(position);
                }
            }


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            if (wall_1->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_2->getGlobalBounds().intersects(guy->getGlobalBounds())||
                wall_3->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_4->getGlobalBounds().intersects(guy->getGlobalBounds())){
                position.y+=1;
                guy->setPosition(position);
            }
            else{
                if (position.y>0){
                    position.x =position.x;
                    position.y -= y_velocity_*elapsed.asSeconds();
                    guy->setPosition(position);
                }
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            if (wall_1->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_2->getGlobalBounds().intersects(guy->getGlobalBounds())||
                wall_3->getGlobalBounds().intersects(guy->getGlobalBounds())||wall_4->getGlobalBounds().intersects(guy->getGlobalBounds())){
                position.y-=1;
                guy->setPosition(position);
            }
            else{
                if (position.y+70<window.getSize().y){
                    position.x = position.x;
                    position.y += y_velocity_*elapsed.asSeconds();
                    guy->setPosition(position);
                }
            }

        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        for (auto& s : shapes) {
            window.draw(*s);
        }
        // end the current frame
        window.display();
    }

    return 0;
}

    //
