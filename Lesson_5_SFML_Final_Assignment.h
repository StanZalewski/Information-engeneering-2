#ifndef LESSON_5_SFML_FINAL_ASSIGNMENT_H
#define LESSON_5_SFML_FINAL_ASSIGNMENT_H
#include <iostream>

//Function that inputs all objects to a single vector
void create_shapes(sf::RenderWindow& window, std::vector<std::unique_ptr<sf::Drawable>>& shapes_vec, std::vector<sf::Texture>& textures_);
// Function that inputs all teaxtures into one vector
void input_texture(std::vector<sf::Texture>& textures_);

#endif // LESSON_5_SFML_FINAL_ASSIGNMENT_H
