#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include "UGSfunctions.h"
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <windows.h>

sf::Sprite& UGSFunctions::create_SFsprite(std::string imagePath){
    sf::Texture* texture = new sf::Texture;
    texture->loadFromFile(imagePath);

    sf::Sprite* sprite = new sf::Sprite(*texture);
    return *sprite;
}

sf::Text& UGSFunctions::create_SFtext(std::string fontPath, int size, sf::Color color, std::string text){
    sf::Font* font = new sf::Font;
    font->loadFromFile(fontPath);

    sf::Text* t = new sf::Text;
    t->setFont(*font);
    t->setCharacterSize(size);
    t->setFillColor(color);
    t->setString(text);
    return *t;

}


bool UGSFunctions::key_pressed(int key){
    //return (GetAsyncKeyState(key) < 0);

    switch (key) {
        case 'A':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            break;
        case 'B':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::B);
            break;
        case 'C':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::C);
            break;
        case 'D':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::D);
            break;
        case 'E':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::E);
            break;
        case 'F':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::F);
            break;
        case 'G':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::G);
            break;
        case 'H':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::H);
            break;
        case 'I':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::I);
            break;
        case 'J':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::J);
            break;
        case 'K':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::K);
            break;
        case 'L':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::L);
            break;
        case 'M':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::M);
            break;
        case 'N':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::N);
            break;
        case 'O':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::O);
            break;
        case 'P':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::P);
            break;
        case 'Q':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
            break;
        case 'R':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::R);
            break;
        case 'S':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::S);
            break;
        case 'T':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::T);
            break;
        case 'U':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::U);
            break;
        case 'V':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::V);
            break;
        case 'W':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::W);
            break;
        case 'X':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::X);
            break;
        case 'Y':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Y);
            break;
        case 'Z':
            return sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
            break;
    }

    return false;
}



bool UGSFunctions::sprite_colision(sf::Sprite sprite1, sf::Sprite sprite2){
    return sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds());
}

bool UGSFunctions::mouseColision(sf::RectangleShape& sprite, sf::RenderWindow& window){
    sf::Vector2i mouse_pos      = sf::Mouse::getPosition(window);
    sf::Vector2f translated_pos = window.mapPixelToCoords(mouse_pos);
    if(sprite.getGlobalBounds().contains(translated_pos)){
        return true;
    } else {
        return false;
    }
}

bool UGSFunctions::mouseColision(sf::Sprite& sprite, sf::RenderWindow& window){
    sf::Vector2i mouse_pos      = sf::Mouse::getPosition(window);
    sf::Vector2f translated_pos = window.mapPixelToCoords(mouse_pos);
    if(sprite.getGlobalBounds().contains(translated_pos)){
        return true;
    } else {
        return false;
    }
}

sf::Music& UGSFunctions::create_SFmusic(std::string musicPath){
    sf::Music* music = new sf::Music;
    music->openFromFile(musicPath);

    return *music;
}

#endif // FUNCTIONS_H_INCLUDED
