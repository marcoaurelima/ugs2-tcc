#include "UGSScoreMajor.h"


UGSScoreMajor::UGSScoreMajor(int posX, int posY)
{
    mSprite = create_SFsprite("GUI/widgets/score/scoreMajor.png");

    mText.push_back(create_SFtext("fonts/DigitalDism.otf", 36, sf::Color(0, 0, 220), "888888888"));
    mText.push_back(create_SFtext("fonts/DigitalDism.otf", 36, sf::Color::White,     "10"       ));

    mSprite.setPosition(posX, posY);

    mText[0].setLetterSpacing (2);
    mText[0].setPosition      (posX+170, posY-2);
    mText[1].setLetterSpacing (2);
    mText[1].setPosition      (posX+170, posY-2);

    mScore = 0;
    //ctor
}

UGSScoreMajor::~UGSScoreMajor()
{
    //dtor
}

void UGSScoreMajor::draw(sf::RenderWindow& window){
    window.draw(mSprite);
    window.draw(mText[0]);
    window.draw(mText[1]);

}

void UGSScoreMajor::setScore(int score){
    mScore = score;
    std::stringstream ss;
    ss << mScore;
    mText[1].setString(ss.str());

}

void UGSScoreMajor::addValue(int value){
    mScore += value;
    setScore(mScore);
}

int UGSScoreMajor::getScore(){
    return mScore;
}






