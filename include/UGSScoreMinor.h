#ifndef UGSSCOREMINOR_H
#define UGSSCOREMINOR_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include "UGSfunctions.h"

class UGSScoreMinor : public UGSFunctions
{
    public:
        UGSScoreMinor(int posX, int posY);
        virtual ~UGSScoreMinor();

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

#endif // UGSSCOREMINOR_H
