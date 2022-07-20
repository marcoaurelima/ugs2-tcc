#ifndef UGSLEFTBUTTONSMENUMAIN_H
#define UGSLEFTBUTTONSMENUMAIN_H

#include <SFML/Graphics.hpp>
#include "UGSfunctions.h"

class UGSLeftButtonsMenuMain : public UGSFunctions
{
    public:
        UGSLeftButtonsMenuMain();
        UGSLeftButtonsMenuMain(int posX, int posY, std::string label);
        virtual ~UGSLeftButtonsMenuMain();
        void draw(sf::RenderWindow& window);
        bool isSelected();
        void setSelected(bool selected);
        sf::RectangleShape& getSprite();
    protected:

    private:
        sf::RectangleShape mRectangle;
        sf::Text mText;
        bool mSelected;
};

#endif // UGSLEFTBUTTONSMENUMAIN_H
