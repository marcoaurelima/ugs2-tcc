#ifndef UGSSCREENGAME_H
#define UGSSCREENGAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include <iostream>
#include <iomanip>
#include "UGSNotasConsecutivas.h"
#include "UGSRock.h"
#include "UGSMusicPlayer.h"
#include "UGSScoreMinor.h"
#include "UGSScoreMajor.h"
#include "UGSGameMajor.h"
#include "UGSMat.h"
#include "UGSfunctions.h"

#include "NeuroEvolutiveEngine.h"


class UGSScreenGame : public UGSFunctions
{
    public:
        UGSScreenGame();
        UGSScreenGame(Game1playerInfo* gameInfo);
        virtual ~UGSScreenGame();
        void draw(sf::RenderWindow& window);
        bool getPermissionToShow();
    protected:

    private:
        sf::Sprite      mBackButton;
        sf::Sprite      mBGpb;
        sf::Sprite      mBackground;
        UGSGameMajor*   mGameMajor;
        UGSMusicPlayer* mMusicPlayer;
        UGSScoreMajor*  mScoreMajor;
        UGSRock*        mRock;
        UGSNotasConsecutivas* mNotasConsec;
        sf::View mView;

        sf::Sprite mTCC_BandBG;
        sf::Sprite mTCC_BangLogo;

        bool mPermissionToShow;

        std::vector<sf::Text> ia_logs;

        NeuroEvolutiveEngine engine;
};

#endif // UGSSCREENGAME_H
