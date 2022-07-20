#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <iostream>
#include <SFML/Graphics.hpp>

namespace ugs{

sf::Sprite& create_SFsprite(std::string imagePath){
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile(imagePath);

    sf::Sprite* sprite = new sf::Sprite(*texture);

    return *sprite;
}

sf::Text& create_SFtext(std::string fontPath, int size, sf::Color color, std::string text){
    sf::Font* font = new sf::Font;
    font->loadFromFile(fontPath);

    sf::Text* t = new sf::Text;
    t->setFont(*font);
    t->setCharacterSize(size);
    t->setFillColor(color);
    t->setString(text);
    return *t;

}






}





#endif // FUNCTIONS_H_INCLUDED
