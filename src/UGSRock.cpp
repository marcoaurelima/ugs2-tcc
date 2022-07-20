#include "UGSRock.h"

UGSRock::UGSRock(int posX, int posY)
{
    this->mSprite.push_back(create_SFsprite("GUI/widgets/rock/rockPB.png"));
    this->mSprite.push_back(create_SFsprite("GUI/widgets/rock/rock01.png"));
    this->mSprite.push_back(create_SFsprite("GUI/widgets/rock/rock02.png"));
    this->mSprite.push_back(create_SFsprite("GUI/widgets/rock/rock03.png"));
    this->mSprite.push_back(create_SFsprite("GUI/widgets/rock/rock04.png"));
    this->mSprite.push_back(create_SFsprite("GUI/widgets/rock/rock05.png"));

    this->mSprite[0].setPosition(posX   , posY   );
    this->mSprite[1].setPosition(posX   , posY   );
    this->mSprite[2].setPosition(posX+11, posY+11);
    this->mSprite[3].setPosition(posX+11, posY+11);

    this->mSprite[4].setOrigin  (this->mSprite[4].getLocalBounds().width/2, this->mSprite[4].getLocalBounds().height);
    this->mSprite[4].setPosition(posX+79, posY+105);

    this->mSprite[5].setPosition(posX+172, posY+85);
    this->mSprite[2].setColor   (sf::Color(255,180,0));

    this->mText.push_back(create_SFtext("fonts/BigDots.ttf",      18, sf::Color::Blue,   "SCORE"));
    this->mText.push_back(create_SFtext("fonts/BigDots.ttf",      18, sf::Color::Blue,   "X 1"));
    this->mText.push_back(create_SFtext("fonts/DigitalDism.otf",  49, sf::Color::Yellow, "8888888888"));
    this->mText.push_back(create_SFtext("fonts/DigitalDism.otf",  49, sf::Color::Yellow, "0"));
    this->mText.push_back(create_SFtext("fonts/premier-2019.otf", 17, sf::Color::Yellow, "GUNS N' ROSES"));
    this->mText.push_back(create_SFtext("fonts/premier-2019.otf", 17, sf::Color::Yellow, "SWEET CHILD O MINE"));

    this->mText[0].setFillColor(sf::Color::Red);
    this->mText[1].setFillColor(sf::Color::Yellow);
    this->mText[2].setFillColor(sf::Color(71,0,0));
    this->mText[3].setFillColor(sf::Color::Red);
    this->mText[4].setFillColor(sf::Color::Blue);
    this->mText[5].setFillColor(sf::Color::White);

    this->mText[0].setPosition(posX+167, posY+17);
    this->mText[1].setPosition(posX+192, posY+37);
    this->mText[2].setPosition(posX+234, posY+7);
    this->mText[3].setPosition(posX+234, posY+7);
    this->mText[4].setPosition(posX+226, posY+87);
    this->mText[5].setPosition(posX+226, posY+107);

    this->blink         = 125;
    this->isBlinking    = false;
    this->score         = 0;
    this->multiplicator = 1;
    mRockStatus         = 100;
}

UGSRock::~UGSRock()
{
    //dtor
}


void UGSRock::setPosition(float posX, float posY){

    this->mSprite[0].setPosition(posX   , posY   );
    this->mSprite[1].setPosition(posX   , posY   );
    this->mSprite[2].setPosition(posX+11, posY+11);
    this->mSprite[3].setPosition(posX+11, posY+11);

    this->mSprite[4].setOrigin(this->mSprite[4].getLocalBounds().width/2, this->mSprite[4].getLocalBounds().height);
    this->mSprite[4].setPosition(posX+79,  posY+105);
    this->mSprite[5].setPosition(posX+172, posY+85);

    this->mText[0].setFillColor(sf::Color::Red);
    this->mText[1].setFillColor(sf::Color::Yellow);
    this->mText[2].setFillColor(sf::Color(71,0,0));
    this->mText[3].setFillColor(sf::Color::Red);
    this->mText[4].setFillColor(sf::Color::Blue);
    this->mText[5].setFillColor(sf::Color::White);

    this->mText[0].setPosition(posX+167, posY+17);
    this->mText[1].setPosition(posX+192, posY+37);
    this->mText[2].setPosition(posX+234, posY+7);
    this->mText[3].setPosition(posX+234, posY+7);
    this->mText[4].setPosition(posX+226, posY+87);
    this->mText[5].setPosition(posX+226, posY+107);
}


sf::Vector2f UGSRock::getPosition(){
    return mSprite[0].getPosition();
}


void UGSRock::move(float x, float y){
    this->mSprite[0].move(x, y);
    float posX = this->mSprite[0].getPosition().x;
    float posY = this->mSprite[0].getPosition().y;

    this->mSprite[1].setPosition(posX   , posY   );
    this->mSprite[2].setPosition(posX+11, posY+11);
    this->mSprite[3].setPosition(posX+11, posY+11);

    this->mSprite[4].setOrigin(this->mSprite[4].getLocalBounds().width/2, this->mSprite[4].getLocalBounds().height);
    this->mSprite[4].setPosition(posX+79,  posY+105);
    this->mSprite[5].setPosition(posX+172, posY+85);

    this->mText[0].setFillColor(sf::Color::Red);
    this->mText[1].setFillColor(sf::Color::Yellow);
    this->mText[2].setFillColor(sf::Color(71,0,0));
    this->mText[3].setFillColor(sf::Color::Red);
    this->mText[4].setFillColor(sf::Color::Blue);
    this->mText[5].setFillColor(sf::Color::White);

    this->mText[0].setPosition(posX+167, posY+17);
    this->mText[1].setPosition(posX+192, posY+37);
    this->mText[2].setPosition(posX+234, posY+7);
    this->mText[3].setPosition(posX+234, posY+7);
    this->mText[4].setPosition(posX+226, posY+87);
    this->mText[5].setPosition(posX+226, posY+107);
}

void UGSRock::draw(sf::RenderWindow& window){

    window.draw(this->mSprite[1]);
    window.draw(this->mSprite[2]);
    window.draw(this->mSprite[4]);
    window.draw(this->mSprite[5]);

    for(unsigned i=0;i<mText.size();i++){
        window.draw(this->mText[i]);
    }

    if(this->isBlinking){
        static bool control = true;
        if(blink > 250){
            control = false;
        } else if(blink < 150){
            control = true;
        }

        if(control){
            blink += 6;
        } else {
            blink -= 6;
        }

        this->mSprite[2].setColor(sf::Color(this->mSprite[2].getColor().r,
                                            this->mSprite[2].getColor().g,
                                            this->mSprite[2].getColor().b, this->blink));

    } else if(!this->isBlinking && this->mSprite[2].getColor().a != 255){
        this->blink = 255;
        this->mSprite[2].setColor(sf::Color(this->mSprite[2].getColor().r,
                                            this->mSprite[2].getColor().g,
                                            this->mSprite[2].getColor().b, 255));

    }

}



void UGSRock::setRockStatus(float rockStatus){
    if(rockStatus< 0  ){ rockStatus= 0;  }
    if(rockStatus> 100){ rockStatus= 100;}
    mRockStatus = rockStatus;

    int r=0, g=0, b=0;

    if(rockStatus < 50){
        r = 255;
        g = 2.5 * ((rockStatus*2));
        b = 0;
    } else if(rockStatus == 50){
        r = 255;
        g = 255;
        b = 0;
    } else if(rockStatus > 50){
        r = 255 - ((2.5 * (rockStatus-50)) * 2);
        g = 255;
        b = 0;
    }

    //std::stringstream ss;
    //ss << "r: " << r << "     g: " << g << "      b: " << b;
    //mText[5].setString(ss.str());

    this->mSprite[2].setColor(sf::Color(r, g, b, blink));
    this->mSprite[3].setColor(sf::Color((float)((r/100)*90), (float)((g/100)*90), 0, blink));

    if(this->mSprite[2].getColor().g <45){
        this->isBlinking = true;
    } else {
        this->isBlinking = false;
    }

    this->mSprite[4].setRotation(((140 * rockStatus)/100)-70);
}


void UGSRock::setScore(int score){
    this->score = score;
    std::stringstream ss;
    ss << this->score;
    this->mText[3].setString(ss.str());
}
void UGSRock::setMultiplicator(int multiplicator){
    this->multiplicator = multiplicator;
    std::stringstream ss;
    ss << "X " << multiplicator;
    this->mText[1].setString(ss.str());
}
void UGSRock::setBandName(std::string bandName){
    this->mText[4].setString(bandName);
}
void UGSRock::setMusicName(std::string musicName){
    this->mText[5].setString(musicName);
}

void UGSRock::setBandLogo(std::string logoPath){
    this->mSprite[5] = create_SFsprite(logoPath);
}

















