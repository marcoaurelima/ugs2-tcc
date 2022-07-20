#ifndef UGSMENUMAINDETAILS_H
#define UGSMENUMAINDETAILS_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <sstream>
#include <iostream>
#include "UGSfunctions.h"

class UGSMenuMainDetails : public UGSFunctions
{
    public:
        UGSMenuMainDetails();
        virtual ~UGSMenuMainDetails();
        void draw(sf::RenderWindow& window);
        void setNewDetails(DetailsInfo* details);
    protected:

    private:
        int posX;
        int posY;
        sf::Sprite mSpriteDetails;
        sf::Text   mBandName;
        sf::Text   mMusicName;
        sf::Text   mDuration;

        std::vector<sf::Sprite> mInstruments;
        std::vector<sf::Sprite> mInstrumentsToShow;
        std::vector<sf::Sprite> mDificultyTiles;
        std::vector<sf::Text>   mInstrumentsName;

};

#endif // UGSMENUMAINDETAILS_H
