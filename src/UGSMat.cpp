#include "UGSMat.h"

UGSMat::UGSMat(){

}

UGSMat::UGSMat(int posX, int posY, int speed, int transparency) : mPosX(posX), mPosY(3), mSpeed(speed)
{
    /// O posY terá esse valor sempre (3) por motivo de sincronia.
    /// Ele não precisa de mudança em relaççao ao Y pq ele ocupa a tela toda verticalmente;
    /// Vou manter o posY no construtor pra manter no padrao das classes do jogo .
    posY = 3;

    mStickBombs.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajor05.png"));
    mStickBombs.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajor05.png"));
    mStickBombs.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajor05.png"));

    mStickBombs[0].setColor(sf::Color(255,255,255, transparency));
    mStickBombs[1].setColor(sf::Color(255,255,255, transparency));
    mStickBombs[2].setColor(sf::Color(255,255,255, transparency));

    mStickBombs[0].setPosition(posX+70, posY-mStickBombs[0].getLocalBounds().height);
    mStickBombs[1].setPosition(posX+70, posY);
    mStickBombs[2].setPosition(posX+70, posY+mStickBombs[1].getLocalBounds().height);


    //ctor
}

UGSMat::~UGSMat()
{
    //dtor
}

void UGSMat::draw(sf::RenderWindow& window, sf::Transform transform){

    window.draw(mStickBombs[0], transform);
    window.draw(mStickBombs[1], transform);
    window.draw(mStickBombs[2], transform);

    if(mStickBombs[0].getPosition().y > 0){
        mStickBombs[0].setPosition(mPosX+70, mPosY-mStickBombs[0].getLocalBounds().height);
        mStickBombs[1].setPosition(mPosX+70, mPosY);
        mStickBombs[2].setPosition(mPosX+70, mPosY+mStickBombs[1].getLocalBounds().height);
    }

    for(int i=0;i<3;i++){
        mStickBombs[i].move(0, mSpeed);
    }
}

void UGSMat::setSpeed(int speed){
    mSpeed = speed;
}

int UGSMat::getSpeed(){
    return mSpeed;
}











