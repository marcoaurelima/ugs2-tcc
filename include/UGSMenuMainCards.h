#ifndef UGSMENUMAINCARDS_H
#define UGSMENUMAINCARDS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
//#include <windows.h>
#include <stdlib.h>
#include <cmath>
#include "UGSfunctions.h"

class UGSMenuMainCards : public UGSFunctions
{
    public:
        UGSMenuMainCards();
        UGSMenuMainCards(int posX, int posY, int folderNumber);
        void draw(sf::RenderWindow& window);
        DetailsInfo* getDetails();
        bool isMouseOver();
        bool isMouseClicked();
        bool isMusicPlaying();
        void stopMusic();
        void setPosition(int x, int y);
        void move(float x, float y);
        virtual ~UGSMenuMainCards();

    protected:

    private:
        int mPosX;
        int mPosY;
        sf::Sprite  mCardBG;
        sf::Sprite  mPhoto;
        sf::Sprite  mSelectionCardBlink;
        sf::Text    mArtist;
        sf::Text    mSong;
        sf::Music   mSampleMusic; /// Trecho da musica que sera tocada qdo o mouse ficar sobre o card
        float       mVolume;
        bool        mMouseOver;
        bool        mMouseClicked;
        DetailsInfo mDetail;
};

#endif // UGSMENUMAINCARDS_H
