#ifndef UGSNOTASCONSECUTIVAS_H
#define UGSNOTASCONSECUTIVAS_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>
#include "UGSfunctions.h"

class UGSNotasConsecutivas : UGSFunctions
{
    public:
        UGSNotasConsecutivas(int posX, int posY);
        virtual ~UGSNotasConsecutivas();
        void   setRange (int points0, int points1, int points2);
        float  getRange (int indice);
        int    getPoints(int indice);

        void setPosition(int posX, int posY);
        void move       (float x,  float y);
        void draw       (sf::RenderWindow& window);

        sf::Vector2f getPosition();
    private:
        int posX, posY;
        float range [3];
        int   points[3];
        std::vector<sf::Text>   text;
        std::vector<sf::Sprite> sprite;
};

#endif // UGSNOTASCONSECUTIVAS_H
