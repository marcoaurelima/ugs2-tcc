#ifndef UGSMENUMAINNOVOJOGO_H
#define UGSMENUMAINNOVOJOGO_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <cstring>
#include "UGSfunctions.h"
#include "UGSMenuMainDetails.h"
#include "UGSMenuMainCards.h"
#include "UGSMenuMainNovoJogoStep2.h"

class UGSMenuMainNovoJogo : public UGSFunctions
{
    public:
        UGSMenuMainNovoJogo();
        virtual ~UGSMenuMainNovoJogo();
        void draw(sf::RenderWindow& window);

    protected:

    private:
        bool wasChose; /// Se for falso indica que nao foi ecolhido nenhum card de musica// se for true, ele apaga todos os cards e detalhes
        bool wasChooseControl; /// controle pra apenas 1 clique;
        sf::Sprite         mTitle;
        DetailsInfo        mDetails;
        UGSMenuMainDetails mMenuDetails;

        UGSMenuMainNovoJogoStep2* mMenuStep2;

        std::vector<UGSMenuMainCards*> mMenuCards;

        std::vector<bool> mMouseOverControl;
};

#endif // UGSMENUMAINNOVOJOGO_H
