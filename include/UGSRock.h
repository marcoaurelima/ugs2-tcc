#ifndef UGSROCK_H
#define UGSROCK_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <vector>
#include "UGSfunctions.h"

class UGSRock : public UGSFunctions
{
    public:
        UGSRock(int posX, int posY);
        virtual ~UGSRock();

        void setPosition     (float posX, float posY);
        void setMultiplicator(int multiplicator);
        void setBandName     (std::string bandName);
        void setMusicName    (std::string musicName);
        void setRockStatus   (float rockStatus);
        void setBandLogo     (std::string logoPath);
        void setScore        (int score);

        sf::Vector2f getPosition();
        void move(float x, float y);

        void draw(sf::RenderWindow& window);
    protected:

    private:
        std::vector<sf::Text>   mText;
        std::vector<sf::Sprite> mSprite;
        int  blink;
        bool isBlinking;
        int  score;
        int  multiplicator;
        int  mRockStatus;
};

#endif // UGSROCK_H
