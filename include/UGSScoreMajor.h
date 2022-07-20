#ifndef UGSSCOREMAJOR_H
#define UGSSCOREMAJOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include "UGSfunctions.h"

class UGSScoreMajor : public UGSFunctions
{
    public:
        UGSScoreMajor(int posX, int posY);
        virtual ~UGSScoreMajor();

        void draw(sf::RenderWindow& window);
        void setScore(int score);
        void addValue(int value);

        int getScore();
    protected:

    private:
        sf::Sprite mSprite;
        std::vector<sf::Text> mText;
        int mScore;
};

#endif // UGSSCOREMAJOR_H
