#include "UGSLeftButtonsMenuMain.h"

UGSLeftButtonsMenuMain::UGSLeftButtonsMenuMain()
{
    //ctor
}


UGSLeftButtonsMenuMain::UGSLeftButtonsMenuMain(int posX, int posY, std::string label){

    mRectangle.setPosition        (posX, posY);
    mRectangle.setSize            (sf::Vector2f(260,51));
    mRectangle.setFillColor       (sf::Color(0,0,0,0));
    mRectangle.setOutlineColor    (sf::Color(0,0,0,0));
    mRectangle.setOutlineThickness(1);

    mText = UGSFunctions::create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 15, sf::Color::White, label);
    mText.setPosition(posX+35, posY+15);

    mSelected = false;

    //ctor
}

UGSLeftButtonsMenuMain::~UGSLeftButtonsMenuMain()
{
    //dtor
}

void UGSLeftButtonsMenuMain::draw(sf::RenderWindow& window){
    if(UGSFunctions::mouseColision(mRectangle, window)){
        mRectangle.setFillColor   (sf::Color(255,255,255,20));
        mRectangle.setOutlineColor(sf::Color(255,255,255,150));
    } else {
        mRectangle.setFillColor   (sf::Color(0,0,0,0));
        mRectangle.setOutlineColor(sf::Color(0,0,0,0));
    }

    if(mSelected){
        mRectangle.setFillColor   (sf::Color(0,0,255,50));
        mRectangle.setOutlineColor(sf::Color(0,0,255,150));
    }

    window.draw(mRectangle);
    window.draw(mText);
}

bool UGSLeftButtonsMenuMain::isSelected(){
    return mSelected;
}

void UGSLeftButtonsMenuMain::setSelected(bool selected){
    mSelected = selected;
}

sf::RectangleShape& UGSLeftButtonsMenuMain::getSprite(){
    return mRectangle;
}


