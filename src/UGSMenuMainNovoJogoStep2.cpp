#include "UGSMenuMainNovoJogoStep2.h"

UGSMenuMainNovoJogoStep2::UGSMenuMainNovoJogoStep2(DetailsInfo* details)
{
    mGameInitControl = true;
    mGameInit        = false;
    mMenuDificultyInit = false;

    mDetails = details;

    mDificultyChoose = create_SFsprite("GUI/menus/mainMenu/dificultyChoose.png");
    mRectChoose[0].setSize(sf::Vector2f(210, 125));
    mRectChoose[0].setPosition(353, 422);
    mRectChoose[0].setFillColor(sf::Color(0,0,255,50));
    mRectChoose[0].setOutlineColor(sf::Color::Blue);
    mRectChoose[0].setOutlineThickness(1);

    mRectChoose[1].setSize(sf::Vector2f(210, 125));
    mRectChoose[1].setPosition(353+(217*1), 422);
    mRectChoose[1].setFillColor(sf::Color(0,0,255,50));
    mRectChoose[1].setOutlineColor(sf::Color::Blue);
    mRectChoose[1].setOutlineThickness(1);

    mRectChoose[2].setSize(sf::Vector2f(210, 125));
    mRectChoose[2].setPosition(353+(217*2), 422);
    mRectChoose[2].setFillColor(sf::Color(0,0,255,50));
    mRectChoose[2].setOutlineColor(sf::Color::Blue);
    mRectChoose[2].setOutlineThickness(1);

    mInfo = create_SFsprite("GUI/menus/mainMenu/info.png");
    mInfo.setPosition(57, 615);

    std::stringstream ss;
    ss << "songs/" << details->folderNumber << "/picture/poster.png";
    //mBackground = create_SFsprite("GUI/menus/mainMenu/bg1.png");
    mBackground = create_SFsprite(ss.str());
    ss.str("");

    ss << "songs/" << details->folderNumber << "/picture/logo.png";
    mBandLogo = create_SFsprite(ss.str());
    mBandLogo.setPosition(58,353);
    ss.str("");

    ss << "GUI/instruments/medium/" << details->code1 << ".png";
    mInstruments.push_back(create_SFsprite(ss.str()));
    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 11, sf::Color::White, details->instrumentLabel1));
    ss.str("");
    ss << "GUI/instruments/medium/" << details->code2 << ".png";
    mInstruments.push_back(create_SFsprite(ss.str()));
    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 11, sf::Color::White, details->instrumentLabel2));
    ss.str("");
    ss << "GUI/instruments/medium/" << details->code3 << ".png";
    mInstruments.push_back(create_SFsprite(ss.str()));
    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 11, sf::Color::White, details->instrumentLabel3));
    ss.str("");
    ss << "GUI/instruments/medium/" << details->code4 << ".png";
    mInstruments.push_back(create_SFsprite(ss.str()));
    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 11, sf::Color::White, details->instrumentLabel4));
    ss.str("");

    /// colocando transparencia nos instrumentos de valor 15
    if(details->code1 == 15){mInstruments[0].setColor(sf::Color::Transparent);}
    if(details->code2 == 15){mInstruments[1].setColor(sf::Color::Transparent);}
    if(details->code3 == 15){mInstruments[2].setColor(sf::Color::Transparent);}
    if(details->code4 == 15){mInstruments[3].setColor(sf::Color::Transparent);}

    for(unsigned i = 0;i<mInstrumentsName.size();i++){
        mInstrumentsName[i].setFillColor(mInstruments[i].getColor());
    }

    /// estou fazendo dessa maneira pq no padrao do info, obrigatoriamente seré lido 4 instrumentos//
    /// quando nao existir instrumentos, ele sera um sprite transparente


    mInstruments[0].setPosition(790    , 606);
    mInstruments[1].setPosition(790+130, 606);
    mInstruments[2].setPosition(790+260, 606);
    mInstruments[3].setPosition(790+390, 606);

    mInstrumentsSelection.push_back(create_SFsprite("GUI/menus/mainMenu/selectionInstrument.png"));
    mInstrumentsSelection.push_back(create_SFsprite("GUI/menus/mainMenu/selectionInstrument.png"));
    mInstrumentsSelection.push_back(create_SFsprite("GUI/menus/mainMenu/selectionInstrument.png"));
    mInstrumentsSelection.push_back(create_SFsprite("GUI/menus/mainMenu/selectionInstrument.png"));
    mInstrumentsSelection[0].setPosition(781    , 597);
    mInstrumentsSelection[1].setPosition(781+130, 597);
    mInstrumentsSelection[2].setPosition(781+260, 597);
    mInstrumentsSelection[3].setPosition(781+390, 597);

    mInstrumentsName[0].setOrigin(mInstrumentsName[0].getLocalBounds().width/2, 0);
    mInstrumentsName[0].setPosition(846    , 720);
    mInstrumentsName[1].setOrigin(mInstrumentsName[1].getLocalBounds().width/2, 0);
    mInstrumentsName[1].setPosition(846+130, 720);
    mInstrumentsName[2].setOrigin(mInstrumentsName[2].getLocalBounds().width/2, 0);
    mInstrumentsName[2].setPosition(846+260, 720);
    mInstrumentsName[3].setOrigin(mInstrumentsName[3].getLocalBounds().width/2, 0);
    mInstrumentsName[3].setPosition(846+390, 720);


    mBandName = create_SFtext("fonts/seguibl.ttf", 25, sf::Color::White, details->artist);
    mBandName.setPosition(80,618);
    mMusicName= create_SFtext("fonts/seguibl.ttf", 25, sf::Color::White, details->music);
    mMusicName.setPosition(80,667);

    mBlackBackground.setSize(sf::Vector2f(2000, 2000));
    mBlackBackground.setFillColor(sf::Color(0,0,0,210));

    mClock.restart();







    //ctor
}

UGSMenuMainNovoJogoStep2::UGSMenuMainNovoJogoStep2()
{
    //ctor
}

UGSMenuMainNovoJogoStep2::~UGSMenuMainNovoJogoStep2()
{
    //dtor
}

void UGSMenuMainNovoJogoStep2::draw(sf::RenderWindow& window){

    if(mGameInit){
        //static UGSScreenGame* game1Player2 = new UGSScreenGame(&mGameInfo);
        if(mGameInitControl){
            std::cout << mGameInfo.bandName << "\n";
            std::cout << mGameInfo.dificultyCode << "\n";
            std::cout << mGameInfo.folderCode << "\n";
            std::cout << mGameInfo.instrumentCode << "\n";
            std::cout << mGameInfo.misicName << "\n";
            std::cout << mGameInfo.playerName << "\n";
            std::cout << mGameInfo.speed << "\n\n";

            game1Player = new UGSScreenGame(&mGameInfo);
            mGameInitControl = false;
        }
        game1Player->draw(window);

        if(!game1Player->getPermissionToShow()){
            mGameInitControl = true;
            mGameInit        = false;
            mMenuDificultyInit = false;

            game1Player = new UGSScreenGame(&mGameInfo);
        }

        return;
    }

    window.draw(mBackground);
    window.draw(mInfo);
    window.draw(mBandName);
    window.draw(mMusicName);

    //printf(">> %d\n", abs(sin(mClock.getElapsedTime().asMilliseconds())) );

    for(unsigned i=0;i<mInstruments.size();i++){
        window.draw(mInstruments[i]);
        window.draw(mInstrumentsName[i]);
    }

    static float frameCount = 0;
    frameCount += 0.1;
    for(unsigned i=0;i<mInstrumentsSelection.size();i++){
        if(mouseColision(mInstrumentsSelection[i], window)){
            if(!(mInstruments[i].getColor().a < 255) && !mMenuDificultyInit){ // So irá aparecer se mInstrument não for transparente
                mInstrumentsSelection[i].setColor(sf::Color(255,255,255, abs(sin(frameCount)*255)));
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    if(i==0){ mInstrumentCodeChoose = mDetails->code1; } else
                    if(i==1){ mInstrumentCodeChoose = mDetails->code2; } else
                    if(i==2){ mInstrumentCodeChoose = mDetails->code3; } else
                    if(i==3){ mInstrumentCodeChoose = mDetails->code4; }

                    mInstrumentNameChoose = mInstrumentsName[i].getString();
                    mMenuDificultyInit = true;
                }
            }
        } else {
             mInstrumentsSelection[i].setColor(sf::Color(255,255,255,0));
        }
        window.draw(mInstrumentsSelection[i]);
    }


    for(int i=0;i<3;i++){
        if(mouseColision(mRectChoose[i], window)){
            mRectChoose[i].setFillColor(sf::Color(0,0,255,50));
            mRectChoose[i].setOutlineColor(sf::Color::Blue);
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                mGameInit = true;
                mGameInfo.bandName       = mDetails->artist;
                mGameInfo.dificultyCode  = i;
                mGameInfo.folderCode     = mDetails->folderNumber;
                mGameInfo.instrumentCode = mInstrumentCodeChoose;
                mGameInfo.instrumentName = mInstrumentNameChoose;
                mGameInfo.misicName      = mDetails->music;
                mGameInfo.playerName     = "PLAYER";

                /*   */if(mInstrumentCodeChoose == mDetails->code1){ /// to fazendo assim pq nao implemntei os 4 codigos em 1 vetor: preferi 4 variaveis// burrice kkk
                    mGameInfo.backgrounCodes.push_back(mDetails->code2);
                    mGameInfo.backgrounCodes.push_back(mDetails->code3);
                    mGameInfo.backgrounCodes.push_back(mDetails->code4);
                } else if(mInstrumentCodeChoose == mDetails->code2){ /// to fazendo assim pq nao implemntei os 4 codigos em 1 vetor: preferi 4 variaveis// burrice kkk
                    mGameInfo.backgrounCodes.push_back(mDetails->code1);
                    mGameInfo.backgrounCodes.push_back(mDetails->code3);
                    mGameInfo.backgrounCodes.push_back(mDetails->code4);
                } else if(mInstrumentCodeChoose == mDetails->code3){ /// to fazendo assim pq nao implemntei os 4 codigos em 1 vetor: preferi 4 variaveis// burrice kkk
                    mGameInfo.backgrounCodes.push_back(mDetails->code1);
                    mGameInfo.backgrounCodes.push_back(mDetails->code2);
                    mGameInfo.backgrounCodes.push_back(mDetails->code4);
                } else if(mInstrumentCodeChoose == mDetails->code4){ /// to fazendo assim pq nao implemntei os 4 codigos em 1 vetor: preferi 4 variaveis// burrice kkk
                    mGameInfo.backgrounCodes.push_back(mDetails->code1);
                    mGameInfo.backgrounCodes.push_back(mDetails->code2);
                    mGameInfo.backgrounCodes.push_back(mDetails->code3);
                }


                int speed[3];
                std::stringstream ss;
                ss << "songs/" << mDetails->folderNumber << "/sequence/speeds.txt";
                FILE* file = fopen(ss.str().c_str(), "r");
                fscanf(file, "%d %d %d", &speed[0], &speed[1], &speed[2]);
                mGameInfo.speed = speed[i];
                fclose(file);

            }
        } else {
            mRectChoose[i].setFillColor(sf::Color::Transparent);
            mRectChoose[i].setOutlineColor(sf::Color::Transparent);
        }
    }

    window.draw(mBandLogo);

    if(mMenuDificultyInit){
        window.draw(mBlackBackground);
        window.draw(mDificultyChoose);
        window.draw(mRectChoose[0]);
        window.draw(mRectChoose[1]);
        window.draw(mRectChoose[2]);
    }


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        mMenuDificultyInit = false;
    }

}
