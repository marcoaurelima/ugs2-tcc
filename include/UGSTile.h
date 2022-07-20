#ifndef UGSTILE_H
#define UGSTILE_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UGSfunctions.h"

enum UGSColor{
        GREEN,
        RED,
        YELLOW,
        BLUE,
        ORANGE
};


/// Esta struct vai conter a referencia aos recursos pra montagem dos tiles. O jogo ainda ta travando muito
/// e eu acho que seja por causa do excesso de texturas. vou usar a referencia ao mesmo recurso pra todos
/// os tiles e ver se fica mais rápido.
struct TilesResources{
    sf::Sprite tileRes;      /// Peça que irá descer
    sf::Sprite shineHeadRes; /// Rastro da nota, quando ha duração maior dela
    sf::Sprite shineBodyRes; /// Parte de cima do rastro; Cabeça
    sf::Music* soundErrorRes;
};


class UGSTile : public UGSFunctions
{
    public:
        UGSTile();
        UGSTile(int posX, int posY, int type, float duration, float speed, float musicTime, TilesResources tilesRes);
        virtual ~UGSTile();

        void  draw(sf::RenderWindow& window, sf::Transform transform, int& errorControlRock, sf::Music& music);
        void  wast();
        void  hit();
        void  eraseTrace();
        void  setTransparent(); /// Faz o tile ficar 100% transparente
        bool  isFinalized();    /// Diz se o tile foi finalizado e o rastro totalmente gasto;
        void  goDown();      /// informa ao tile que ele já pode descer depois que foi gerado.
        void  move(float x, float y);
        float getDuration();
        int   getType();
        float getMusicTime();
        bool  getPlayerError();

        sf::Sprite&  getSprite();
        sf::Vector2f getPosition();

    protected:

    private:
        sf::Sprite      mTile;      /// Peça que irá descer
        sf::Sprite      mShineHead; /// Rastro da nota, quando ha duração maior dela
        sf::Sprite      mShineBody; /// Parte de cima do rastro; Cabeça
        sf::SoundBuffer mSoundBuffer;
        //sf::Sound mSoundError;
        sf::Music* mSoundError;
        float mDuration;        /// Duraçao do rastro
        float mSpeed;           /// Velocidade da esteira
        float mMusicTime;       /// tempo da música em que começa a descer
        bool  mPlayerError;     /// Diz se o jogador já errou
        bool  mTileFinalized;   /// Diz se o tile foi finalizado e o rastro totalmente gasto;
        bool  mCanGoDown;       /// O tile so vai descer se essa variavel estiver true
        float mScaleY;
        int   mType;            /// Inteiro que representa a cor do tile

};

#endif // UGSTILE_H
