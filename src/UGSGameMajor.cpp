#include "UGSGameMajor.h"

UGSGameMajor::UGSGameMajor(){}

UGSGameMajor::UGSGameMajor(int posX, int posY, int speed, int folderCode, std::string musicPath, std::vector<int>& backgroudCodes,
                            std::string tileSequencePath, std::string userName, std::string instrumentName) : mSpeed(speed)
{

    mPosX             = posX;
    mPosY             = posY;
    mScore            = 0;
    mRock             = 0;
    mMultiplicator    = 1;
    mControl          = false;
    mShineHitAlpha[0] = 255;
    mShineHitAlpha[1] = 255;
    mShineHitAlpha[2] = 255;
    mShineHitAlpha[3] = 255;
    mShineHitAlpha[4] = 255;

    mUserBar = create_SFsprite("GUI/widgets/gameMajor/gameMajor01.png");
    mBody    = create_SFsprite("GUI/widgets/gameMajor/gameMajor02.png");
    mHeart   = create_SFsprite("GUI/widgets/gameMajor/gameMajor03.png");
    mStar    = create_SFsprite("GUI/widgets/gameMajor/gameMajor04.png");
    mShadow  = create_SFsprite("GUI/widgets/gameMajor/gameMajor06.png");

    mPB      = create_SFsprite("GUI/widgets/gameMajor/gameMajorPB.png");



    mHole.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorTileHole.png"));
    mHole.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorTileHole.png"));
    mHole.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorTileHole.png"));
    mHole.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorTileHole.png"));
    mHole.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorTileHole.png"));
    mHole[0].setPosition(posX+85,  posY+510);
    mHole[1].setPosition(posX+152, posY+510);
    mHole[2].setPosition(posX+220, posY+510);
    mHole[3].setPosition(posX+287, posY+510);
    mHole[4].setPosition(posX+356, posY+510);

    mShineHit.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorShine3.png"));
    mShineHit.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorShine3.png"));
    mShineHit.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorShine3.png"));
    mShineHit.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorShine3.png"));
    mShineHit.push_back(create_SFsprite("GUI/widgets/gameMajor/gameMajorShine3.png"));
    mShineHit[0].setPosition(mHole[0].getPosition().x-79, mHole[0].getPosition().y-75);
    mShineHit[0].setColor(sf::Color::Green);
    mShineHit[1].setPosition(mHole[1].getPosition().x-79, mHole[1].getPosition().y-75);
    mShineHit[1].setColor(sf::Color::Red);
    mShineHit[2].setPosition(mHole[2].getPosition().x-79, mHole[2].getPosition().y-75);
    mShineHit[2].setColor(sf::Color::Yellow);
    mShineHit[3].setPosition(mHole[3].getPosition().x-79, mHole[3].getPosition().y-75);
    mShineHit[3].setColor(sf::Color::Blue);
    mShineHit[4].setPosition(mHole[4].getPosition().x-79, mHole[4].getPosition().y-75);
    mShineHit[4].setColor(sf::Color(255,112,0));



    mUserBar.setPosition (posX,     posY);
    mBody.setPosition    (posX+35,  posY+36);
    mHeart.setPosition   (posX+46,  posY+622);
    mStar.setPosition    (posX+442, posY+619);
    mShadow.setPosition  (posX+69,  posY+37);
    mShadow.setColor     (sf::Color(255,255,255,175));

    mMat = UGSMat(posX, posY, mSpeed, 10);

    mLife.setFillColor (sf::Color::Green);
    mLife.setSize      (sf::Vector2f(14, 400));
    mLife.setOrigin    (0, mLife.getLocalBounds().height);
    mLife.setPosition  (posX+47, posY+600);

    mSpecial.setFillColor(sf::Color::Blue);
    mSpecial.setSize(sf::Vector2f(14, 250));
    mSpecial.setOrigin(0, mSpecial.getLocalBounds().height);
    mSpecial.setPosition(posX+443, posY+600);

    mSquare.setFillColor(sf::Color::Black);
    mSquare.setSize(sf::Vector2f(420, 36));
    mSquare.setPosition(posX+42, posY+616);

    mUserName       = create_SFtext("fonts/Square721BTBold.ttf", 16, sf::Color(180,180,180), userName);
    mInstrumentName = create_SFtext("fonts/Square721BTBold.ttf", 16, sf::Color::Green, instrumentName);

    mUserName.setOrigin  (sf::Vector2f(mUserName.getLocalBounds().width, 0));
    mUserName.setPosition(posX+420, posY+32);

    mInstrumentName.setOrigin  (sf::Vector2f(mInstrumentName.getLocalBounds().width/2, 0));
    mInstrumentName.setPosition(posX+242, posY+623);

    mIntro.openFromFile("media/intro.ogg");
    mIntro.play();

    /// int speed, std::string musicPath, std::vector<int>& backgroudCodes,
    /// std::string tileSequencePath, std::string userName, std::string instrumentName

    std::stringstream ss;
    ss << "songs/" << folderCode << "/audio/background.ogg";
    mMusicBackgroundOgg.openFromFile(ss.str());

    for(unsigned i=0;i<backgroudCodes.size();i++){
        ss.str("");
        ss << "songs/" << folderCode << "/audio/" << backgroudCodes[i] << ".ogg";
        mMusicBackground[i].openFromFile(ss.str());
    }


    mMusic.openFromFile(musicPath);
    mMusic.setVolume(100);


    mSoundBuffer.loadFromFile("media/error.ogg");
    mSoundError[0].setBuffer(mSoundBuffer);
    mSoundError[0].setVolume(15);
    mSoundError[1].setBuffer(mSoundBuffer);
    mSoundError[1].setVolume(15);
    mSoundError[2].setBuffer(mSoundBuffer);
    mSoundError[2].setVolume(15);
    mSoundError[3].setBuffer(mSoundBuffer);
    mSoundError[3].setVolume(15);
    mSoundError[4].setBuffer(mSoundBuffer);
    mSoundError[4].setVolume(15);

    mTotalMusicNotes        = 0;
    mConsecutiveNotesRecord = 0;
    mConsecutiveNotesNow    = 0;

    mClock.restart();
    mTilesDownCount = 0;

    FILE* file = fopen(tileSequencePath.c_str(), "r");

    sequenceTilesInfo sequence;
    while((fscanf(file, "%f %d %f", &sequence.musicTime, &sequence.type, &sequence.duration)) != EOF){
        mSequenceTilesInfo.push_back(sequence);
        mTotalMusicNotes++;
    }
    fclose(file);

    file = fopen("gameConfig/keyboard.txt", "r");
    fscanf(file, "%c %c %c %c %c %c", &mKeyboardConfig[0], &mKeyboardConfig[1], &mKeyboardConfig[2],
                                      &mKeyboardConfig[3], &mKeyboardConfig[4], &mKeyboardConfig[5]);
    //
    fclose(file);


    mTilesRes.tileRes       = create_SFsprite("GUI/widgets/gameMajor/gameMajorTileWhite.png");
    mTilesRes.shineHeadRes  = create_SFsprite("GUI/widgets/gameMajor/gameMajorShine1.png");
    mTilesRes.shineBodyRes  = create_SFsprite("GUI/widgets/gameMajor/gameMajorShine2.png");
    mTilesRes.soundErrorRes = new sf::Music;

    //ctor
}

UGSGameMajor::~UGSGameMajor()
{
    //dtor
}

int UGSGameMajor::getScore(){
    return mScore;
}

void UGSGameMajor::stopAudio(){
    mMusic.stop();
    mIntro.stop();
    mMusicBackground[0].stop();
    mMusicBackground[1].stop();
    mMusicBackground[2].stop();
    mMusicBackground[3].stop();
    mMusicBackgroundOgg.stop();
}

void UGSGameMajor::startShineHit(int shineColor, bool isError){

    int r = mShineHit[shineColor].getColor().r;
    int g = mShineHit[shineColor].getColor().g;
    int b = mShineHit[shineColor].getColor().b;


    if(!isError){
        if(mShineHitAlpha[shineColor]<150){mShineHitAlpha[shineColor]=255;}
           mShineHitAlpha[shineColor] = mShineHitAlpha[shineColor] - 10;
           mShineHit[shineColor].setColor(sf::Color(r, g, b, mShineHitAlpha[shineColor]));
    } else {
        mShineHitAlpha[shineColor]=0;
        mShineHit[shineColor].setColor(sf::Color(r, g, b, mShineHitAlpha[shineColor]));
    }


}

void UGSGameMajor::gameButtonsControl(){

    /// Essa variavel vai cotrolar se foi apertado algum tile ou nao.
    /// se foi apertado e acertado em cima do tile, ele vai ser true e nao vai ter som de erro.
    /// se nao, ele sera falso e emitirá o som de erro;
    bool tileHitted[5] = {false,false,false,false,false};

    /// Essa variavel controla o pressionamento de botao para não ficar
    /// continuo, ele so aceita um toque por vez.
    /// OBS. ISSO SÓ SE APLICA AO SOM DE ERRO. FOI CRIADO EXCLUSIVAMENTE PRO SOM DE ERRO.
    static bool pressControl[5] = {true,true,true,true,true};


    if(key_pressed(mKeyboardConfig[0]) ){

        mHole[0].setColor(sf::Color(0,255,0,255));

        for(unsigned i=0;i<mTile.size();i++){
            if(mTile[i].getPosition().y > 490 && mTile[i].getPosition().y < 580
                && mTile[i].getType() == UGSColor::GREEN ){

                /// Enquanto o som de erro não parar, ficara bloqueado o hit do tile.
                /// Isso evitara que o jogador fique pressionado o tempo todo ganhando ponto.
                if(mSoundError[0].getStatus() != sf::SoundSource::Playing){
                    mTile[i].hit();

                    if(!mTile[i].isFinalized()){
                        mScore = mScore + mMultiplicator;
                        startShineHit(UGSColor::GREEN, false);
                        setMusicVolumeHighORLow(true);
                    }
                }

                tileHitted[0] = true;
                break;
            }
        }

        if(!tileHitted[0] && pressControl[0]){
            mSoundError[0].play();
            pressControl[0] = !pressControl[0];
            setMusicVolumeHighORLow(false);
            mRock--;
        }

    } else {
        mHole[0].setColor(sf::Color(255,255,255,110));
        pressControl[0] = true;
        startShineHit(UGSColor::GREEN, true);
    }



    if(key_pressed(mKeyboardConfig[1])){
        mHole[1].setColor(sf::Color(255,0,0,255));

        for(unsigned i=0;i<mTile.size();i++){
            if(mTile[i].getPosition().y > 490 && mTile[i].getPosition().y < 580
                && mTile[i].getType() == UGSColor::RED ){

                if(mSoundError[1].getStatus() != sf::SoundSource::Playing){
                    mTile[i].hit();

                    if(!mTile[i].isFinalized()){
                        mScore = mScore + mMultiplicator;
                        startShineHit(UGSColor::RED, false);
                        setMusicVolumeHighORLow(true);
                    }
                }

                tileHitted[1] = true;
                break;
            }
        }

        if(!tileHitted[1] && pressControl[1]){
            mSoundError[1].play();
            pressControl[1] = !pressControl[1];
            setMusicVolumeHighORLow(false);
            mRock--;
        }

    } else {
        mHole[1].setColor(sf::Color(255,255,255,110));
        pressControl[1] = true;
        startShineHit(UGSColor::RED, true);
    }

    if(key_pressed(mKeyboardConfig[2]) || key_pressed(mKeyboardConfig[3])){
        mHole[2].setColor(sf::Color(255,255,0,255));

        for(unsigned i=0;i<mTile.size();i++){
            if(mTile[i].getPosition().y > 490 && mTile[i].getPosition().y < 580
                && mTile[i].getType() == UGSColor::YELLOW ){

                if(mSoundError[2].getStatus() != sf::SoundSource::Playing){
                    mTile[i].hit();

                    if(!mTile[i].isFinalized()){
                        mScore = mScore + mMultiplicator;
                        startShineHit(UGSColor::YELLOW, false);
                        setMusicVolumeHighORLow(true);
                    }
                }

                tileHitted[2] = true;
                break;
            }
        }

        if(!tileHitted[2] && pressControl[2]){
            mSoundError[2].play();
            pressControl[2] = !pressControl[2];
            setMusicVolumeHighORLow(false);
            mRock--;
        }

    } else {
        mHole[2].setColor(sf::Color(255,255,255,110));
        pressControl[2] = true;
        startShineHit(UGSColor::YELLOW, true);
    }

    if(key_pressed(mKeyboardConfig[4])){
        mHole[3].setColor(sf::Color(0,0,255,255));

        for(unsigned i=0;i<mTile.size();i++){
            if(mTile[i].getPosition().y > 490 && mTile[i].getPosition().y < 580
                && mTile[i].getType() == UGSColor::BLUE ){

                if(mSoundError[3].getStatus() != sf::SoundSource::Playing){
                    mTile[i].hit();

                    if(!mTile[i].isFinalized()){
                        mScore = mScore + mMultiplicator;
                        startShineHit(UGSColor::BLUE, false);
                        setMusicVolumeHighORLow(true);
                    }
                }

                tileHitted[3] = true;
                break;
            }
        }

        if(!tileHitted[3] && pressControl[3]){
            mSoundError[3].play();
            pressControl[3] = !pressControl[3];
            setMusicVolumeHighORLow(false);
            mRock--;
        }

    } else {
        mHole[3].setColor(sf::Color(255,255,255,110));
        pressControl[3] = true;
        startShineHit(UGSColor::BLUE, true);
    }

    if(key_pressed(mKeyboardConfig[5])){
        mHole[4].setColor(sf::Color(255,112,0));

        for(unsigned i=0;i<mTile.size();i++){
            if(mTile[i].getPosition().y > 490 && mTile[i].getPosition().y < 580
                && mTile[i].getType() == UGSColor::ORANGE ){

                if(mSoundError[4].getStatus() != sf::SoundSource::Playing){
                    mTile[i].hit();

                    if(!mTile[i].isFinalized()){
                        mScore = mScore + mMultiplicator;
                        startShineHit(UGSColor::ORANGE, false);
                        setMusicVolumeHighORLow(true);
                    }
                }

                tileHitted[4] = true;
                break;
            }
        }

        if(!tileHitted[4] && pressControl[4]){
            mSoundError[4].play();
            pressControl[4] = !pressControl[4];
            setMusicVolumeHighORLow(false);
            mRock--;
        }

    } else {
        mHole[4].setColor(sf::Color(255,255,255,110));
        pressControl[4] = true;
        startShineHit(UGSColor::ORANGE, true);
    }




}

void UGSGameMajor::setMusicVolumeHighORLow(bool high_low){
    if(high_low){
        mMusic.setVolume(100);
    } else {
        mMusic.setVolume(10);
    }
}

void UGSGameMajor::draw(sf::RenderWindow& window){
   /// aqqui será detectado a diferenca de pontuação frame a frame para o calculo do ROCK.
   /// se a diferença for pra mais, ele incrementa, se for pra menos, ele decrementa;
   static int rockControl = 0;
   if(mConsecutiveNotesNow > rockControl) { mRock++; } else if
     (mConsecutiveNotesNow < rockControl) { mRock--; }

    if(mRock > 20){ mRock=20; } else
    if(mRock < 0 ){ mRock=0; }

    //std::stringstream ss4;
    //ss4 << mRock;
    //mInstrumentName.setString(ss4.str());

    rockControl = mConsecutiveNotesNow;

    /// aqui será calculado as notas consecutivas e tudo relacionado com o vector de bool que guarda essas informaçãoes (mSequenceBoolTiles)
    /// NOTAS CONSECUTIVAS AGORA
    mConsecutiveNotesNow = 0;
    for(unsigned i=0;i<mSequenceBoolTiles.size();i++){
        if(mSequenceBoolTiles[i] == true){
            mConsecutiveNotesNow++;
        } else {
            mConsecutiveNotesNow = 0;
            mMultiplicator = 1;
        }
    }
//mMusic
    if(mConsecutiveNotesNow > mConsecutiveNotesRecord){
        mConsecutiveNotesRecord = mConsecutiveNotesNow;
    }

    /// DEFINICAO DO MULTIPLICADOR: DE QUANTAS NOTAS CONSECUTIVAS PRECISO PRA AUMENTYAR +1 (POR ENQUANTO SERÁ 10 COM LIMITE DE 5X)
    mMultiplicator = (mConsecutiveNotesNow / 10) + 1;
    if(mMultiplicator <= 0){ mMultiplicator = 1;}
    if(mMultiplicator >  5){ mMultiplicator = 5;}

    window.draw (mBody,   mTransform);
    mMat.draw   (window,  mTransform);
    window.draw (mShadow, mTransform);


    /// Geração dos Tiles em tempo real.
    /// Pra ser gerado, compara-se o tempo do clock com o tempo do tile e
    /// depois vejo o contador, que nao deve ter o tamanho superior ao size() do vector que
    /// guarda as informações dos tiles. Se isso acontecesse, ele geraria mais peça e seriam aleatorias;
    if(mClock.getElapsedTime().asSeconds() > mSequenceTilesInfo[mTilesDownCount].musicTime
       && (unsigned)mTilesDownCount < mSequenceTilesInfo.size()){
        int type        = mSequenceTilesInfo[mTilesDownCount].type;
        float duration  = mSequenceTilesInfo[mTilesDownCount].duration;
        float musicTime = mSequenceTilesInfo[mTilesDownCount].musicTime;
        mTile.push_back(UGSTile(mPosX, mPosY, type, duration, mSpeed, musicTime, mTilesRes));
        mTilesDownCount++;

    }

    //std::stringstream ss;
    //ss << "downCount: " << mTilesDownCount << "   mTile " << mTile.size();
    //mUserName.setString(ss.str());

    /// Os tiles comecam a descer antes de tocar a música usando o tempo desse sf::Clock
    /// A musica só comeca depois de alguns instantes (floatPlayControlSync)
    static float floatPlayControlSync = 0;
    if(mSpeed ==  6){floatPlayControlSync = 1.62;} else
    if(mSpeed ==  7){floatPlayControlSync = 1.40;} else
    if(mSpeed ==  8){floatPlayControlSync = 1.20;} else
    if(mSpeed ==  9){floatPlayControlSync = 1.00;} else
    if(mSpeed == 10){floatPlayControlSync = 0.92;} else
    if(mSpeed == 11){floatPlayControlSync = 0.62;}

    static bool boolPlayControl = true;
    if(mClock.getElapsedTime().asSeconds() > floatPlayControlSync && boolPlayControl){
        mMusic.play();
        mMusicBackgroundOgg.play();
        mMusicBackground[0].play();
        mMusicBackground[1].play();
        mMusicBackground[2].play();

        boolPlayControl = !boolPlayControl;
    }

    for(unsigned i=0;i<mTile.size();i++){
        if(mClock.getElapsedTime().asSeconds() > mTile[i].getMusicTime()){
            mTile[i].goDown();
        }
    }



    for(unsigned i=0;i<mTile.size();i++){
        /// Destruição de tiles em tempo real.
        if(mTile[i].getPosition().y > 800){
            bool tileState = mTile[i].isFinalized();
            mSequenceBoolTiles.push_back(tileState); /// Antes dos tiles serem destruidos, vai ser guardado o estado dele para conbstagem de notas consecutivas
            mTile.erase(mTile.begin()+i);
        }

        mTile[i].draw(window, mTransform, mRock, mMusic);
    }


    window.draw(mUserBar, mTransform);

    window.draw(mHole[0], mTransform);
    window.draw(mHole[1], mTransform);
    window.draw(mHole[2], mTransform);
    window.draw(mHole[3], mTransform);
    window.draw(mHole[4], mTransform);

    gameButtonsControl();

    window.draw(mSquare, mTransform);
    window.draw(mHeart,  mTransform);
    window.draw(mStar,   mTransform);

    window.draw(mLife,    mTransform);
    window.draw(mSpecial, mTransform);

    window.draw(mUserName,       mTransform);
    window.draw(mInstrumentName, mTransform);


    window.draw(mShineHit[4], mTransform);
    window.draw(mShineHit[3], mTransform);
    window.draw(mShineHit[2], mTransform);
    window.draw(mShineHit[1], mTransform);
    window.draw(mShineHit[0], mTransform);

}
//mMusic
int UGSGameMajor::getConsecutiveNotesNow(){
    return mConsecutiveNotesNow;
}
int UGSGameMajor::getConsecutiveNotesRecord(){
    return mConsecutiveNotesRecord;
}
int UGSGameMajor::getTotalMusicNotes(){
    return mTotalMusicNotes;
}

void UGSGameMajor::setTransform(sf::Transform transform){
    mTransform = transform;
}

float UGSGameMajor::getMusicTimeTotal(){
    return mMusic.getDuration().asSeconds();
}

float UGSGameMajor::getMusicTimeCurrent(){
    return mMusic.getPlayingOffset().asSeconds();
}

int UGSGameMajor::getMultiplicator(){
    return mMultiplicator;
}

int UGSGameMajor::getRock(){
    return mRock;
}










