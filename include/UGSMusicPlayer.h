#ifndef UGSMUSICPLAYER_H
#define UGSMUSICPLAYER_H
#include "UGSfunctions.h"

class UGSMusicPlayer : UGSFunctions
{
    public:
        UGSMusicPlayer(int posX, int posY);
        virtual ~UGSMusicPlayer();

        void draw(sf::RenderWindow& window);
        void setRange(float timeTotal, float timePartial);
    protected:

    private:
        float              mTotalSize;
        sf::Text           mIcon;
        sf::RectangleShape mShape;

        std::vector<sf::Sprite> mSprite;
};

#endif // UGSMUSICPLAYER_H
