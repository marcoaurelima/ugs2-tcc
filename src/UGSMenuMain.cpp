#include "UGSMenuMain.h"

UGSMenuMain::UGSMenuMain()
{
    bgpb = UGSFunctions::create_SFsprite("GUI/menus/mainMenu/mainPB.png");

    mLeftButtons.push_back(UGSLeftButtonsMenuMain(43, 377       , "NOVO JOGO"));
    mLeftButtons.push_back(UGSLeftButtonsMenuMain(43, 377+(51*1), "CRIAR SERVER"));
    mLeftButtons.push_back(UGSLeftButtonsMenuMain(43, 377+(51*2), "ENCONTRAR SERVER"));
    mLeftButtons.push_back(UGSLeftButtonsMenuMain(43, 377+(51*3), "CONFIGURAÇÕES"));
    mLeftButtons.push_back(UGSLeftButtonsMenuMain(43, 377+(51*4), "SOBRE"));

    //ctor
}

UGSMenuMain::~UGSMenuMain()
{

    //dtor
}


void UGSMenuMain::draw(sf::RenderWindow& window){

    window.draw(bgpb);

    /// compara todos os botoes e deixa apenas 1 botao selecionado por vez;
    /// quando clicar fora o botão nao irá desSelecionar
    for(unsigned i=0;i<mLeftButtons.size();i++){
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            if(UGSFunctions::mouseColision(mLeftButtons[i].getSprite(), window)){
                mLeftButtons[i].setSelected(true);
                for(unsigned j=0;j<mLeftButtons.size();j++){
                    if(j!=i){
                        mLeftButtons[j].setSelected(false);
                    }
                }
            }
        }

        mLeftButtons[i].draw(window);
    }

    if(mLeftButtons[0].isSelected()){
        mNovoJogo.draw(window);
    }

}
