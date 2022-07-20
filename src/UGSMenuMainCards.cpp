#include "UGSMenuMainCards.h"

UGSMenuMainCards::UGSMenuMainCards()
{
    //ctor
}

UGSMenuMainCards::UGSMenuMainCards(int posX, int posY, int folderNumber) : mPosX(posX), mPosY(posY){

    mMouseOver    = false;
    mMouseClicked = false;

    mCardBG = UGSFunctions::create_SFsprite("GUI/menus/mainMenu/card.png");
    mCardBG.setOrigin  (mCardBG.getLocalBounds().width/2, mCardBG.getLocalBounds().height/2);
    mCardBG.setPosition(mPosX, mPosY);

    mSelectionCardBlink = UGSFunctions::create_SFsprite("GUI/menus/mainMenu/selectionCard.png");
    mSelectionCardBlink.setOrigin  (mSelectionCardBlink.getLocalBounds().width/2, mSelectionCardBlink.getLocalBounds().height/2);
    mSelectionCardBlink.setPosition(mCardBG.getPosition());
    mSelectionCardBlink.move(-7,-4); /// ajuste fino da posicao

    std::stringstream ss;
    ss << "songs/" << folderNumber << "/picture/card.png";
    mPhoto = UGSFunctions::create_SFsprite(ss.str());
    mPhoto.setOrigin  (mPhoto.getLocalBounds().width/2, mPhoto.getLocalBounds().height/2);
    mPhoto.setPosition(mPosX-5, mPosY-18);

    char artist[100];
    char music[100];
    char duration[100];
    int  code1;
    int  code2;
    int  code3;
    int  code4;
    char label1[100];
    char label2[100];
    char label3[100];
    char label4[100];
    char dificulty[10];


    ss.str("");
    ss << "songs/" << folderNumber << "/info/about.txt";
    FILE* file2 = fopen(ss.str().c_str(), "r");
    fscanf(file2, " %[^\n]s", artist);
    fscanf(file2, " %[^\n]s", music);
    fscanf(file2, " %[^\n]s", duration);
    fscanf(file2, " %[^\n]s", dificulty);
    fclose(file2);

    ss.str("");
    ss << "songs/" << folderNumber << "/info/instrument1.txt";
    file2 = fopen(ss.str().c_str(), "r");
    fscanf(file2, " %d", &code1);
    fscanf(file2, " %[^\n]s", label1);
    fclose(file2);

    ss.str("");
    ss << "songs/" << folderNumber << "/info/instrument2.txt";
    file2 = fopen(ss.str().c_str(), "r");
    fscanf(file2, " %d", &code2);
    fscanf(file2, " %[^\n]s", label2);
    fclose(file2);

    ss.str("");
    ss << "songs/" << folderNumber << "/info/instrument3.txt";
    file2 = fopen(ss.str().c_str(), "r");
    fscanf(file2, " %d", &code3);
    fscanf(file2, " %[^\n]s", label3);
    fclose(file2);

    ss.str("");
    ss << "songs/" << folderNumber << "/info/instrument4.txt";
    file2 = fopen(ss.str().c_str(), "r");
    fscanf(file2, " %d", &code4);
    fscanf(file2, " %[^\n]s", label4);
    fclose(file2);


    mDetail.folderNumber     = folderNumber;
    mDetail.artist           = artist;
    mDetail.music            = music;
    mDetail.duration         = duration;
    mDetail.code1            = code1;
    mDetail.code2            = code2;
    mDetail.code3            = code3;
    mDetail.code4            = code4;
    mDetail.instrumentLabel1 = label1;
    mDetail.instrumentLabel2 = label2;
    mDetail.instrumentLabel3 = label3;
    mDetail.instrumentLabel4 = label4;
    mDetail.dificulty        = dificulty;

    mArtist = UGSFunctions::create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 13, sf::Color(26,26,26), mDetail.artist);
    mArtist.setOrigin  (mArtist.getLocalBounds().width/2, mArtist.getLocalBounds().height/2);
    mArtist.setPosition(mPosX-5,mPosY+62);

    mSong   = UGSFunctions::create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 13, sf::Color::Blue, mDetail.music);
    mSong.setOrigin  (mSong.getLocalBounds().width/2, mSong.getLocalBounds().height/2);
    mSong.setPosition(mPosX-5,mPosY+77);

    ss.str("");
    ss << "songs/" << folderNumber << "/song.ogg";
    mSampleMusic.openFromFile(ss.str());
    mVolume = 0;
    mSampleMusic.setVolume(mVolume);
}


UGSMenuMainCards::~UGSMenuMainCards()
{
    //dtor
}

void UGSMenuMainCards::draw(sf::RenderWindow& window){
    std::stringstream ss;
    static float frameCount = 0;
    frameCount -= 0.03;
    if(UGSFunctions::mouseColision(mCardBG, window)){
        mCardBG.setScale    (1.07,1.07);
        mPhoto.setScale     (1.07,1.07);
        mArtist.setScale    (1.07,1.07);
        mArtist.setPosition (mPosX-5,mPosY+72);
        mSong.setScale      (1.07,1.07);
        mSong.setPosition   (mPosX-5,mPosY+87);
        mMouseOver = true;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){ mMouseClicked = true; }

    } else {
        mCardBG.setScale    (1,1);
        mPhoto.setScale     (1,1);
        mArtist.setScale    (1,1);
        mArtist.setPosition (mPosX-5,mPosY+62);
        mSong.setScale      (1,1);
        mSong.setPosition   (mPosX-5,mPosY+77);
        mMouseOver    = false;
        mMouseClicked = false;
    }

    if(mMouseOver){

        mSelectionCardBlink.setColor(sf::Color(255,255,255, abs(sin(frameCount)*255)));

        if(mVolume < 100){mVolume += (0.5*1.5);}
        mSampleMusic.setVolume(mVolume);
        if(mSampleMusic.getStatus() != sf::SoundSource::Playing){
            mSampleMusic.play();
        }
    } else {
        mSelectionCardBlink.setColor(sf::Color(255,255,255, 0));
        if(mVolume > 1){mVolume -= (0.5*1.5);}
        mSampleMusic.setVolume(mVolume);
        if(mVolume < 1){
            mSampleMusic.stop();
        }
    }

    window.draw(mCardBG);
    window.draw(mPhoto);
    window.draw(mArtist);
    window.draw(mSong);

    window.draw(mSelectionCardBlink);

}

DetailsInfo* UGSMenuMainCards::getDetails(){
    return &mDetail;
}

bool UGSMenuMainCards::isMouseOver(){
    return mMouseOver;
}
bool UGSMenuMainCards::isMouseClicked(){
    return mMouseClicked;
}
void UGSMenuMainCards::setPosition(int x, int y){

    mCardBG.setPosition(x,   y);
    mPhoto.setPosition (x-5, y-18);
    mArtist.setPosition(x-5, y+67);
    mSong.setPosition  (x-5, y+82);
}

bool UGSMenuMainCards::isMusicPlaying(){
    return (mSampleMusic.getStatus() == sf::SoundSource::Playing);
}

void UGSMenuMainCards::stopMusic(){
    mSampleMusic.stop();
}

void UGSMenuMainCards::move(float x, float y){

    mCardBG.move(x,y*40);
    mPosX = mCardBG.getPosition().x;
    mPosY = mCardBG.getPosition().y;

    mPhoto.setPosition (mPosX-5, mPosY-18);
    mArtist.setPosition(mPosX-5, mPosY+62);
    mSong.setPosition  (mPosX-5, mPosY+77);

}

