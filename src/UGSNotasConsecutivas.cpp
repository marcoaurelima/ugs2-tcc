#include "UGSNotasConsecutivas.h"

#include "functions.h"

UGSNotasConsecutivas::UGSNotasConsecutivas(int posX, int posY) : posX(posX), posY(posY)
{

    this->text.push_back(create_SFtext("fonts/BigDots.ttf", 20, sf::Color(255,204,0), "1235"));
    this->text.push_back(create_SFtext("fonts/BigDots.ttf", 20, sf::Color(255,204,0), "6789"));
    this->text.push_back(create_SFtext("fonts/BigDots.ttf", 20, sf::Color(255,204,0), "5621"));
    this->text.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 10, sf::Color::White, "GUITARRA"));
    this->text.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 10, sf::Color::White, "BAIXO"));
    this->text.push_back(create_SFtext("fonts/WaukeganLdoBlack-Eael.ttf", 10, sf::Color::White, "BATERIA"));

    this->text[0].setPosition(posX+170, posY+49);
    this->text[1].setPosition(posX+170, posY+75);
    this->text[2].setPosition(posX+170, posY+100);
    this->text[3].setPosition(posX+10, posY+55);
    this->text[4].setPosition(posX+10, posY+80);
    this->text[5].setPosition(posX+10, posY+105);

    this->sprite.push_back(create_SFsprite("GUI/widgets/notas_consecutivas/nCons01.png"));
    this->sprite.push_back(create_SFsprite("GUI/widgets/notas_consecutivas/nCons02.png"));
    this->sprite.push_back(create_SFsprite("GUI/widgets/notas_consecutivas/nCons02.png"));
    this->sprite.push_back(create_SFsprite("GUI/widgets/notas_consecutivas/nCons02.png"));/*
    this->sprite.push_back(create_SFsprite("GUI/widgets/notas_consecutivas/nConsIconGuitar.png"));
    this->sprite.push_back(create_SFsprite("GUI/widgets/notas_consecutivas/nConsIconDrum.png"));
    this->sprite.push_back(create_SFsprite("GUI/widgets/notas_consecutivas/nConsIconBass.png"));*/

    this->sprite[0].setPosition(posX   , posY   );
    this->sprite[1].setPosition(posX+69, posY+50);
    this->sprite[2].setPosition(posX+69, posY+75);
    this->sprite[3].setPosition(posX+69, posY+101);
/*
    this->sprite[4].setPosition(posX+13, posY+47);
    this->sprite[5].setPosition(posX+16, posY+75);
    this->sprite[6].setPosition(posX+13, posY+100);
*/
}


UGSNotasConsecutivas::~UGSNotasConsecutivas()
{
    //dtor
}


void UGSNotasConsecutivas::setRange(int points0, int points1, int points2){

   this->points[0] = points0;
   this->points[1] = points1;
   this->points[2] = points2;

   std::stringstream ss;

   ss << points0;
   this->text[0].setString(ss.str());
   ss.str("");

    ss << points1;
   this->text[1].setString(ss.str());
   ss.str("");

   ss << points2;
   this->text[2].setString(ss.str());
   ss.str("");

   int total = points0 + points1 + points2;

   this->range[0] = (100 * (float)points0) / (float)total / 100;
   this->range[1] = (100 * (float)points1) / (float)total / 100;
   this->range[2] = (100 * (float)points2) / (float)total / 100;

   this->sprite[1].setScale(this->range[0], 1);
   this->sprite[2].setScale(this->range[1], 1);
   this->sprite[3].setScale(this->range[2], 1);

}


float  UGSNotasConsecutivas::getRange(int indice){
    return  this->range[indice];
}

int  UGSNotasConsecutivas::getPoints(int indice){
    return  this->points[indice];
}

void UGSNotasConsecutivas::setPosition(int posX, int posY){

    this->sprite[0].setPosition(posX   , posY   );
    this->sprite[1].setPosition(posX+69, posY+50);
    this->sprite[2].setPosition(posX+69, posY+75);
    this->sprite[3].setPosition(posX+69, posY+101);

    this->sprite[4].setPosition(posX+13, posY+47);
    this->sprite[5].setPosition(posX+16, posY+75);
    this->sprite[6].setPosition(posX+13, posY+100);

    this->text[0].setPosition(posX+170, posY+49);
    this->text[1].setPosition(posX+170, posY+75);
    this->text[2].setPosition(posX+170, posY+100);
}

void UGSNotasConsecutivas::move(float x, float y){

    this->sprite[0].move(x, y);

    int posX = this->sprite[0].getPosition().x;
    int posY = this->sprite[0].getPosition().y;

    this->sprite[1].setPosition(posX+69, posY+50);
    this->sprite[2].setPosition(posX+69, posY+75);
    this->sprite[3].setPosition(posX+69, posY+101);

    this->sprite[4].setPosition(posX+13, posY+47);
    this->sprite[5].setPosition(posX+16, posY+75);
    this->sprite[6].setPosition(posX+13, posY+100);

    this->text[0].setPosition(posX+170, posY+49);
    this->text[1].setPosition(posX+170, posY+75);
    this->text[2].setPosition(posX+170, posY+100);
}

sf::Vector2f UGSNotasConsecutivas::getPosition(){
    return this->sprite[0].getPosition();
}


void UGSNotasConsecutivas::draw(sf::RenderWindow& window){

    window.draw(sprite[0]);
    window.draw(sprite[1]);
    window.draw(sprite[2]);
    window.draw(sprite[3]);/*
    window.draw(sprite[4]);
    window.draw(sprite[5]);
    window.draw(sprite[6]);*/

    window.draw(text[0]);
    window.draw(text[1]);
    window.draw(text[2]);
    window.draw(text[3]);
    window.draw(text[4]);
    window.draw(text[5]);

}









