#include "UGSMenuMainDetails.h"

/// OBS.: a cada mudança que for ser efetuada, deve-se criar uma nova instancia dessa classe!!!! /////////

UGSMenuMainDetails::UGSMenuMainDetails()
{
    posX = 1079;
    posY = 144;

    mSpriteDetails = UGSFunctions::create_SFsprite("GUI/menus/mainMenu/details.png");
    mSpriteDetails.setPosition(posX, posY);

    mBandName  = UGSFunctions::create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 14, sf::Color(255,255,255,100), "GUNS N' ROSES");
    mBandName.setPosition (posX+21, posY+81);
    mMusicName = UGSFunctions::create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 14, sf::Color(255,255,255,100), "PATIENCE");
    mMusicName.setPosition(posX+21, posY+147);
    mDuration  = UGSFunctions::create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 14, sf::Color(255,255,255,100), "3:25");
    mDuration.setPosition (posX+21, posY+216);

    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/0.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/1.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/2.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/3.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/4.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/5.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/6.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/7.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/8.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/9.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/10.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/11.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/12.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/13.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/14.png"));
    mInstruments.push_back(UGSFunctions::create_SFsprite("GUI/instruments/small/0.png"));
    mInstruments[15].setColor(sf::Color::Transparent);
    /// este sprite mInstruments[15] representará provisoriamente um instrumento inexistente//sera transparente
    for(unsigned i=0;i<mInstruments.size();i++){
        mInstruments[i].setPosition(0, -100); /// posição deixará fora de vista usando posicao fora da tela
    }


    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 10, sf::Color(255,255,255,170), "teste1"));
    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 10, sf::Color(255,255,255,170), "teste2"));
    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 10, sf::Color(255,255,255,170), "teste3"));
    mInstrumentsName.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 10, sf::Color(255,255,255,170), "teste4"));


    /// vai receber stringas vazias para os nomes
    mInstrumentsName[0].setString("");
    mInstrumentsName[1].setString("");
    mInstrumentsName[2].setString("");
    mInstrumentsName[3].setString("");


    mDificultyTiles.push_back(UGSFunctions::create_SFsprite("GUI/menus/mainMenu/dificultyTile.png"));
    mDificultyTiles.push_back(UGSFunctions::create_SFsprite("GUI/menus/mainMenu/dificultyTile.png"));
    mDificultyTiles.push_back(UGSFunctions::create_SFsprite("GUI/menus/mainMenu/dificultyTile.png"));

    mDificultyTiles[0].setPosition (posX+18,  posY+546);
    mDificultyTiles[0].setColor    (sf::Color::Green);
    mDificultyTiles[1].setPosition (posX+86,  posY+546);
    mDificultyTiles[1].setColor    (sf::Color::Yellow);
    mDificultyTiles[2].setPosition (posX+154, posY+546);
    mDificultyTiles[2].setColor    (sf::Color::Red);

    //ctor
}

UGSMenuMainDetails::~UGSMenuMainDetails()
{
    //dtor
}

void UGSMenuMainDetails::draw(sf::RenderWindow& window){
    window.draw(mSpriteDetails);
    window.draw(mBandName);
    window.draw(mMusicName);
    window.draw(mDuration);

    for(unsigned i=0;i<mInstrumentsName.size();i++){
        window.draw(mInstrumentsName[i]);
    }

    for(unsigned i=0;i<mInstrumentsToShow.size();i++){
        window.draw(mInstrumentsToShow[i]);
    }

    window.draw(mDificultyTiles[0]);
    window.draw(mDificultyTiles[1]);
    window.draw(mDificultyTiles[2]);


}


 void UGSMenuMainDetails::setNewDetails(DetailsInfo* details){
    mBandName.setString (details->artist);
    mMusicName.setString(details->music);
    mDuration.setString (details->duration);

    mInstrumentsToShow.clear();
    mInstrumentsToShow.push_back(mInstruments[details->code1]);
    mInstrumentsToShow.push_back(mInstruments[details->code2]);
    mInstrumentsToShow.push_back(mInstruments[details->code3]);
    mInstrumentsToShow.push_back(mInstruments[details->code4]);

    mInstrumentsToShow[0].setPosition(posX+21,  posY+300);
    mInstrumentsToShow[1].setPosition(posX+123, posY+300);
    mInstrumentsToShow[2].setPosition(posX+21,  posY+421);
    mInstrumentsToShow[3].setPosition(posX+123, posY+421);


    mInstrumentsName[0].setString   (details->instrumentLabel1);
    mInstrumentsName[0].setOrigin   (mInstrumentsName[0].getGlobalBounds().width/2, 0);
    mInstrumentsName[0].setPosition (posX+66, posY+392);

    mInstrumentsName[1].setString   (details->instrumentLabel2);
    mInstrumentsName[1].setOrigin   (mInstrumentsName[1].getGlobalBounds().width/2, 0);
    mInstrumentsName[1].setPosition (posX+170, posY+392);

    mInstrumentsName[2].setString   (details->instrumentLabel3);
    mInstrumentsName[2].setOrigin   (mInstrumentsName[2].getGlobalBounds().width/2, 0);
    mInstrumentsName[2].setPosition (posX+66, posY+511);

    mInstrumentsName[3].setString   (details->instrumentLabel4);
    mInstrumentsName[3].setOrigin   (mInstrumentsName[3].getGlobalBounds().width/2, 0);
    mInstrumentsName[3].setPosition (posX+170, posY+511);


    if(details->dificulty[0] == '1'){mDificultyTiles[0].setColor(sf::Color(0,255,0,255));}
    else {mDificultyTiles[0].setColor(sf::Color(0,255,0,40));}

    if(details->dificulty[1] == '1'){mDificultyTiles[1].setColor(sf::Color(255,255,0,255));}
    else {mDificultyTiles[1].setColor(sf::Color(255,255,0,40));}

    if(details->dificulty[2] == '1'){mDificultyTiles[2].setColor(sf::Color(255,0,0,255));}
    else {mDificultyTiles[2].setColor(sf::Color(255,0,0,40));}


 }
