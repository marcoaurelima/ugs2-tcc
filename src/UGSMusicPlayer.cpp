#include "UGSMusicPlayer.h"

UGSMusicPlayer::UGSMusicPlayer(int posX, int posY)
{
    posY = posY - 14; /// Desconto pela imprecisao na localização Y da fonte;

    mIcon = create_SFtext("fonts/MUSICELE.TTF", 76, sf::Color::White, "f");
    mIcon.setPosition(posX, posY);

    mSprite.push_back(create_SFsprite("GUI/widgets/rock/bg.png"));
    mSprite.push_back(create_SFsprite("GUI/widgets/music_player/musicPlayer01.png"));
    mSprite.push_back(create_SFsprite("GUI/widgets/music_player/musicPlayer02.png"));

    mSprite[1].setPosition(posX, posY+82);

    mSprite[2].setOrigin  (mSprite[2].getLocalBounds().width/2, mSprite[2].getLocalBounds().height);
    mSprite[2].setPosition(posX + (mSprite[1].getLocalBounds().width/2), posY+420);

    mShape.setFillColor (sf::Color::Red);
    mShape.setSize      (sf::Vector2f(50, 320));
    mShape.setOrigin    (mShape.getLocalBounds().width/2, mShape.getLocalBounds().height);
    mShape.setPosition  (posX + (mSprite[1].getLocalBounds().width/2), posY+407);



    this->mTotalSize = mSprite[1].getLocalBounds().height + mSprite[2].getLocalBounds().height;
    //ctor
}

UGSMusicPlayer::~UGSMusicPlayer()
{
    //dtor
}


void UGSMusicPlayer::setRange(float timeTotal, float timePartial){
    if(timePartial < 0.5) {timePartial = 0;} /// Resolve o Bug do triangulo que reaparece com tam enorme. Esse bug ocorre pq quandoa musica termina timepartial fica com o mesmo valor de timefinal

    static float triangleStartPoint; /// Quando a barra quadrada terminar, ele vai guardar quanto ainda falta pra acabar. dai ele calcula a escala do triangulo.
    if(mShape.getSize().y > 0){
        mShape.setSize  (sf::Vector2f(mShape.getSize().x, ((mTotalSize / timeTotal) * timePartial) - (2.5 * mSprite[2].getLocalBounds().height)));
        mShape.setOrigin(mShape.getLocalBounds().width/2, mShape.getLocalBounds().height);

        triangleStartPoint = timePartial;

    } else if(mSprite[2].getScale().x > 0){
        mShape.setSize(sf::Vector2f(mShape.getSize().x, 0));
        mSprite[2].setScale( ((timePartial*100) / triangleStartPoint)/100,
                             ((timePartial*100) / triangleStartPoint)/100 );
    } else {
        mSprite[2].setScale(0,0);
    }

}
void UGSMusicPlayer::draw(sf::RenderWindow& window){

    window.draw(mIcon);
    window.draw(mSprite[1]);
    window.draw(mSprite[2]);

    window.draw(mShape);

}
