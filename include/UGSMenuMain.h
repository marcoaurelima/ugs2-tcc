#ifndef UGSMENUMAIN_H
#define UGSMENUMAIN_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "UGSfunctions.h"
#include "UGSLeftButtonsMenuMain.h"
#include "UGSMenuMainNovoJogo.h"

class UGSMenuMain : public UGSFunctions
{
    public:
        UGSMenuMain();
        virtual ~UGSMenuMain();
        void draw(sf::RenderWindow& window);
    protected:

    private:
        sf::Sprite bgpb;
        std::vector<UGSLeftButtonsMenuMain> mLeftButtons;
        UGSMenuMainNovoJogo mNovoJogo;

};

#endif // UGSMENUMAIN_H
