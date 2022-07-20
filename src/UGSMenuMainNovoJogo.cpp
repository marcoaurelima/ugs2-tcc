#include "UGSMenuMainNovoJogo.h"

UGSMenuMainNovoJogo::UGSMenuMainNovoJogo()
{
    wasChose = false;
    wasChooseControl = true;
    mTitle = UGSFunctions::create_SFsprite("GUI/menus/mainMenu/title.png");
    mTitle.setPosition(394,83);

    /// Parte do código que procura as pastas das musicas// comeca de 1 e quando chega no numero de uma pasta que
    /// nao existe ele retorna null e sai do loop infinito
    int index = 0;
    int three = 0; /// conta de 3 em 3 // representa cada linha de cards
    for(;;){
        index++;
        std::stringstream ss;
        ss << "songs/" << index << "/info/about.txt";
        FILE* file = fopen(ss.str().c_str(), "r");
        if(file == NULL){break;}
        mMenuCards.push_back       (new UGSMenuMainCards(492+(three*210), 296+(((index-1)/3)*243), index));
        mMouseOverControl.push_back(true);

        three++;
        if(three == 3){three = 0;}

        fclose(file);

    }

    mDetails.folderNumber = 0;
    mDetails.code1 = 15;
    mDetails.code2 = 15;
    mDetails.code3 = 15;
    mDetails.code4 = 15;
    mDetails.instrumentLabel1 = "--";
    mDetails.instrumentLabel2 = "--";
    mDetails.instrumentLabel3 = "--";
    mDetails.instrumentLabel4 = "--";
    mDetails.artist = "--";
    mDetails.music = "--";
    mDetails.duration = "--";
    mDetails.dificulty = "000";

    mMenuDetails.setNewDetails(&mDetails);
    //ctor
}

UGSMenuMainNovoJogo::~UGSMenuMainNovoJogo()
{

    //delete mMenuDetails;

    //dtor
}

void UGSMenuMainNovoJogo::draw(sf::RenderWindow& window){

    /// primeiro o jogo seta o detail padrao//depois verificase o mouse esta sobre pra alterar//se nao tiver continua o padrao
    mMenuDetails.setNewDetails(&mDetails);
    int indexChoose = 0;
    for(unsigned i=0;i<mMenuCards.size();i++){
        if(mMenuCards[i]->isMouseOver()){
            mMenuDetails.setNewDetails(mMenuCards[i]->getDetails());
            indexChoose = i;
        }
        if(mMenuCards[i]->isMouseClicked()){
            mMenuCards[i]->stopMusic();
            wasChose = true;
        }
    }

    /// esta parte garante que haverá apenas 1 alocação de UGSMenuMainNovoJogoStep2 e que será desenhado somente ele
    if(wasChose){
        if(wasChooseControl){
            mMenuStep2 = new UGSMenuMainNovoJogoStep2(mMenuCards[indexChoose]->getDetails());
            wasChooseControl = false;
        }
        mMenuStep2->draw(window);
        return;
    }


    mMenuDetails.draw(window);
    for(unsigned i=0;i<mMenuCards.size();i++){
        mMenuCards[i]->draw(window);
    }

    window.draw(mTitle);



    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::MouseWheelMoved){
            for(unsigned i=0;i<mMenuCards.size();i++){
                mMenuCards[i]->move(0, event.mouseWheel.delta);
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            window.close();
        }
    }


}
