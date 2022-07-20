#ifndef UGSMAT_H
#define UGSMAT_H

#include <SFML/Graphics.hpp>
#include "UGSfunctions.h"


class UGSMat : public UGSFunctions
{
    public:
        UGSMat();
        UGSMat(int posX, int posY, int speed, int transparency);
        virtual ~UGSMat();

        void draw(sf::RenderWindow& window, sf::Transform transform);
        void setSpeed(int speed);
        int  getSpeed();
    protected:

    private:
        std::vector<sf::Sprite> mStickBombs;
        int mPosX, mPosY, mSpeed;
};

#endif // UGSMAT_H
