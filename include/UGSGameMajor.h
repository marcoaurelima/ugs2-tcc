#ifndef UGSGAMEMAJOR_H
#define UGSGAMEMAJOR_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <sstream>
#include <math.h>
#include "UGSfunctions.h"
#include "UGSMat.h"
#include "UGSTile.h"

struct sequenceTilesInfo{
    float musicTime;
    int   type;
    float duration;
};


class UGSGameMajor : public UGSFunctions
{
    public:
        UGSGameMajor();
        UGSGameMajor(int posX, int posY, int speed, int folderCode,
                     std::string musicPath, std::vector<int>& backgroudCodes, std::string tileSequencePath,
                     std::string userName, std::string instrumentName);
        virtual ~UGSGameMajor();

        void  draw(sf::RenderWindow& window);
        int   getScore();
        int   getMultiplicator();
        int   getConsecutiveNotesNow();
        int   getConsecutiveNotesRecord();
        int   getRock();
        int   getTotalMusicNotes();
        float getMusicTimeTotal();
        float getMusicTimeCurrent();

        void stopAudio();

        void setTransform(sf::Transform transform);
    protected:

    private:
        sf::Transform mTransform;
        sf::Sprite    mUserBar;
        sf::Sprite    mBody;
        sf::Sprite    mHeart;
        sf::Sprite    mStar;
        sf::Sprite    mShadow;
        sf::Sprite    mPB;

        TilesResources mTilesRes;
        std::vector<sf::Sprite> mShineHit;
        std::vector<sf::Sprite> mHole;
        std::vector<UGSTile>    mTile;
        std::vector<bool>       mSequenceBoolTiles; /// este vector terá o tamanho da quantidade de notas. se acretar, true na msm posicao relativa ao tile
                                                    /// se nao, coloca-se false. depois o jogo vai pegar esse vector e calcular as notas consecutivas.

        std::vector<sequenceTilesInfo> mSequenceTilesInfo;

        UGSMat mMat;

        sf::Music  mMusic; /// audio do intrumento principal que será jogado
        sf::Music  mIntro; /// audio da introdução do jogo//
        sf::Music  mMusicBackground[4]; /// background instrument /// tentei usar o std::vector mas nao aceitou o .pushback() //
        sf::Music  mMusicBackgroundOgg; /// background background.ogg //

        sf::Sound          mSoundError[5];
        sf::RectangleShape mLife;
        sf::RectangleShape mSpecial;
        sf::RectangleShape mSquare;
        sf::Text           mUserName;
        sf::Text           mInstrumentName;
        sf::Event          mEvent;
        sf::SoundBuffer    mSoundBuffer;
        sf::Clock          mClock;

        int  mScore;
        int  mSpeed;
        int  mTilesDownCount; /// Contador de quantos Tiles foram produzidos e desceram
        int  mMultiplicator;
        bool mControl; /// Responsavel pelo controle do pressionamento dos botoes do teclado
        int  mTotalMusicNotes; /// Total de todas as notas presentes no jogo / musica
        int  mConsecutiveNotesRecord; /// Total de notas consecutivas maximas conseguidos pelo jogador
        int  mConsecutiveNotesNow; /// Contador em tempo real das notas consecutivas
        int  mRock;               /// armazena valor do ROCK, pra que o ponteiro do UGSRock possa mostrar// varia de 0 - 100
        int  mShineHitAlpha[5];        /// Transparencioa do shineHit que o faz ficar piscando
        char mKeyboardConfig[6];       /// define quais os botoes do teclado serão usados no jogo
        int  mPosX;
        int  mPosY;

        void gameButtonsControl();
        void setMusicVolumeHighORLow(bool high_low);
        void startShineHit(int shineColor, bool isError);
};

#endif // UGSGAMEMAJOR_H






















