#include "UGSScoreMinor.h"

UGSScoreMinor::UGSScoreMinor(int posX, int posY)
{
    mSprite = create_SFsprite("GUI/widgets/score/scoreMinor.png");

    mText.push_back(create_SFtext("fonts/DigitalDism.otf", 30, sf::Color(0, 0, 220), "888888888"));
    mText.push_back(create_SFtext("fonts/DigitalDism.otf", 30, sf::Color::White,     "10"       ));

    mSprite.setPosition(posX, posY);

    mText[0].setLetterSpacing (2);
    mText[0].setPosition      (posX+100, posY-2);
    mText[1].setLetterSpacing (2);
    mText[1].setPosition      (posX+100, posY-2);

    mScore = 0;
    //ctor
}

UGSScoreMinor::~UGSScoreMinor()
{
    //dtor
}

void UGSScoreMinor::draw(sf::RenderWindow& window){
    window.draw(mSprite);
    window.draw(mText[0]);
    window.draw(mText[1]);

}

void UGSScoreMinor::setScore(int score){
    mScore = score;
    std::stringstream ss;
    ss << mScore;
    mText[1].setString(ss.str());

}

void UGSScoreMinor::addValue(int value){
    mScore += value;
    setScore(mScore);
}

int UGSScoreMinor::getScore(){
    return mScore;
}








