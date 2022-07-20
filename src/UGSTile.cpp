#include "UGSTile.h"

#define UGS_SPEED_4  0.066
#define UGS_SPEED_5  0.0815
#define UGS_SPEED_6  0.1
#define UGS_SPEED_7  0.115
#define UGS_SPEED_8  0.13
#define UGS_SPEED_9  0.15
#define UGS_SPEED_10 0.17
#define UGS_SPEED_11 0.18




UGSTile::UGSTile()
{
    //ctor
}

UGSTile::UGSTile(int posX, int posY, int type, float duration, float speed, float musicTime, TilesResources tilesRes) : mDuration(duration), mSpeed(speed), mMusicTime(musicTime), mPlayerError(false)
{
    /// Defini provisoriamente que a duração será em SEGUNDOS ///
    /// O Speed deve estar no intervalo entre 4 - 11 ///

    mTile      = tilesRes.tileRes;
    mShineHead = tilesRes.shineHeadRes;
    mShineBody = tilesRes.shineBodyRes;



    mCanGoDown     = false;
    mTileFinalized = false;
    mType          = type;

    if(type == 0){
        mTile.setPosition   (posX+87, posY-50);
        mTile.setColor      (sf::Color::Green);
        mShineHead.setColor (sf::Color::Green);
        mShineBody.setColor (sf::Color::Green);
    } else if(type == 1){
        mTile.setPosition   (posX+155, posY-50);
        mTile.setColor      (sf::Color::Red);
        mShineHead.setColor (sf::Color::Red);
        mShineBody.setColor (sf::Color::Red);
    } else if(type == 2){
        mTile.setPosition   (posX+223, posY-50);
        mTile.setColor      (sf::Color::Yellow);
        mShineHead.setColor (sf::Color::Yellow);
        mShineBody.setColor (sf::Color::Yellow);
    } else if(type == 3){
        mTile.setPosition   (posX+290, posY-50);
        mTile.setColor      (sf::Color::Blue);
        mShineHead.setColor (sf::Color::Blue);
        mShineBody.setColor (sf::Color::Blue);
    } else if(type == 4){
        mTile.setPosition   (posX+358, posY-50);
        mTile.setColor      (sf::Color(255,112,0));
        mShineHead.setColor (sf::Color(255,112,0));
        mShineBody.setColor (sf::Color(255,112,0));
    }


    mTile.setOrigin       (0, mTile.getGlobalBounds().height/2);
    mShineBody.setOrigin  (0, mShineBody.getGlobalBounds().height);
    mShineBody.setPosition(mTile.getPosition().x-22, mTile.getPosition().y);

    if(mDuration > 0){
        mShineBody.setScale(1, duration * mSpeed);
    } else {
        /// Proporcao do tile se for com duraçao 0;
        mShineBody.setScale(1, 0.2);
        mShineBody.setColor(sf::Color::Transparent);
        mShineHead.setScale(1, 0.2);
        mShineHead.setColor(sf::Color::Transparent);

    }
    mShineHead.setOrigin  (0, mShineHead.getGlobalBounds().height);
    mShineHead.setPosition(mTile.getPosition().x-22, mShineBody.getPosition().y - mShineBody.getGlobalBounds().height);

    mScaleY = mShineBody.getScale().y;


    /// Resolvi declarar um sf::Music para o som de erro ao inves de sf::Sound
    /// Mas para funcionar, precisei instanciar um ponteiro, pois da forma
    /// convencional dava erro de alocação ou algo do tipo.
    /// Acho que isso se deve a alocação dinamica de tiles que eu estou fazendo em UGSGameMajor.
    /// Curiosamente deu bug quando tentei destruir o ponteiro no destrutor. Então deixei o ponteiro solto.
    mSoundError = tilesRes.soundErrorRes;
    mSoundError->openFromFile("media/error.ogg");
    mSoundError->setVolume(15);

    //ctor
}


UGSTile::~UGSTile()
{

    //dtor
}


void UGSTile::draw(sf::RenderWindow& window, sf::Transform transform, int& errorControlRock, sf::Music& music){
    ///  ( int& errorControlRock ) serve apenas para decrementar o ROCK quando fizer o som de erro

    ///Á partir de 570px o rastro apaga
    if(mTile.getPosition().y > 570 && !mPlayerError){
        if(!mTileFinalized){ /// So irá fazer som de erro quando o tile estiver finalizado, com o rastro totalmente gasto
            mSoundError->play();
            errorControlRock--;
            music.setVolume(10);
        }
        eraseTrace();
        mPlayerError = !mPlayerError;
    }

    if(mCanGoDown){
        mTile.move(0, mSpeed);
    }


    mShineBody.setPosition(mTile.getPosition().x-22, mTile.getPosition().y);
    mShineHead.setPosition(mTile.getPosition().x-22, mShineBody.getPosition().y - mShineBody.getGlobalBounds().height);

    window.draw(mShineBody, transform);
    window.draw(mShineHead, transform);
    window.draw(mTile,      transform);

}


void UGSTile::wast(){
    ///Desgaste do rastro da nota
    ///Como o numero de velocidades jogaveis é limitado (no momento 8 opçoes),
    ///resolvi buscar constantes de calculo de proporção do rastro da nota ao
    ///inves de uma formula que servisse a todos os inteiros colocados como speed nos parametros


    if(mSpeed ==  4){ mScaleY -= UGS_SPEED_4;  } else
    if(mSpeed ==  5){ mScaleY -= UGS_SPEED_5;  } else
    if(mSpeed ==  6){ mScaleY -= UGS_SPEED_6;  } else
    if(mSpeed ==  7){ mScaleY -= UGS_SPEED_7;  } else
    if(mSpeed ==  8){ mScaleY -= UGS_SPEED_8;  } else
    if(mSpeed ==  9){ mScaleY -= UGS_SPEED_9;  } else
    if(mSpeed == 10){ mScaleY -= UGS_SPEED_10; } else
    if(mSpeed == 11){ mScaleY -= UGS_SPEED_11; }

    mTile.setColor(sf::Color(mTile.getColor().r, mTile.getColor().g, mTile.getColor().b, 0));

    mShineBody.setScale   (1, mScaleY);
    mShineBody.setPosition(mTile.getPosition().x-22, mTile.getPosition().y);
    mShineHead.setPosition(mTile.getPosition().x-22, mShineBody.getPosition().y - mShineBody.getGlobalBounds().height);

    mTile.move(0, (-1) * mSpeed);
}

bool UGSTile::isFinalized(){
    return mTileFinalized;
}


void UGSTile::hit(){
    /// Comportamento de quando se acerta o tile
    wast();

    if(mShineBody.getScale().y < 0 && !mTileFinalized){
        mShineBody.setColor(sf::Color(mShineBody.getColor().r, mShineBody.getColor().g, mShineBody.getColor().b, 0));
        mShineHead.setColor(sf::Color::Transparent);
        mTileFinalized = true;
    }

}

float UGSTile::getDuration(){
    return mDuration;
}

void UGSTile::setTransparent(){
    mTile.setColor     (sf::Color(0,0,0,0));
    mShineHead.setColor(sf::Color(0,0,0,0));
    mShineBody.setColor(sf::Color(0,0,0,0));
}

void UGSTile::eraseTrace(){
    mShineBody.setColor(sf::Color::Transparent);
    mShineHead.setScale(1,0);
}

void UGSTile::move(float x, float y){
    mTile.move(x, y);
}

sf::Sprite& UGSTile::getSprite(){
    return mTile;

}

sf::Vector2f UGSTile::getPosition(){
    return mTile.getPosition();
}

int UGSTile::getType(){
    return mType;

}

bool UGSTile::getPlayerError(){
    return mPlayerError;

}

void UGSTile::goDown(){
    mCanGoDown = true;
}

float UGSTile::getMusicTime(){
    return mMusicTime;
}






