#ifndef UGSMENUMAINNOVOJOGOSTEP2_H
#define UGSMENUMAINNOVOJOGOSTEP2_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "UGSScreenGame.h"
#include "UGSfunctions.h"

class UGSMenuMainNovoJogoStep2 : UGSFunctions
{
    public:
        UGSMenuMainNovoJogoStep2();
        UGSMenuMainNovoJogoStep2(DetailsInfo* details);
        virtual ~UGSMenuMainNovoJogoStep2();
        void draw(sf::RenderWindow& window);

    protected:

    private:
        DetailsInfo* mDetails;
        bool mGameInit; /// Se for true, ignora este menu no draw() e começa um novo jogo//
        bool mGameInitControl;
        bool mMenuDificultyInit;
        Game1playerInfo mGameInfo;
        UGSScreenGame*    game1Player;

        int mInstrumentCodeChoose;
        std::string mInstrumentNameChoose;

        sf::Sprite mBackground;
        sf::Sprite mInfo;
        sf::Sprite mBandLogo;
        sf::Sprite mInstrumentMajor;
        sf::Sprite mDificultyChoose;
        sf::RectangleShape mRectChoose[3];
        sf::RectangleShape mBlackBackground;
        sf::Text mBandName;
        sf::Text mMusicName;
        sf::Clock mClock;
        std::vector<sf::Sprite> mInstruments;
        std::vector<sf::Sprite> mInstrumentsSelection;
        std::vector<sf::Text> mInstrumentsName;

};

#endif // UGSMENUMAINNOVOJOGOSTEP2_H
