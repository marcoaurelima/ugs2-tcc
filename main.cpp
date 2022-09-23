///**** OBSERVA��ES IMPORTANTES ****///
/*

 ** Algumas implementa��es de sprites, principalmente os que dizem respeito a instrumentos
      podem ter uma implementa��o aparentemente n�o eficiente. Mas isso n�o � verdade.
      a forma como foi implementado visa possibilitar o carregamento de sprites com texturas iguais,
      para que seja possivel instrumentos repetidos (ex.: Guitarra 1, Guitarra 2, etc).

*/


//#include <windows.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UGSNotasConsecutivas.h"
#include "UGSRock.h"
#include "UGSMusicPlayer.h"
#include "UGSScoreMinor.h"
#include "UGSScoreMajor.h"
#include "UGSGameMajor.h"
#include "UGSMat.h"
#include "UGSfunctions.h"
#include "UGSScreenGame.h"
#include "UGSMenuMain.h"
#include "UGSMenuMainNovoJogo.h"
#include "UGSMenuMainNovoJogoStep2.h"


void screenMain(sf::RenderWindow& window){ /// menu principal

    sf::Texture textureClose;
    textureClose.loadFromFile("GUI/widgets/close.png");
    sf::Sprite spriteClose;
    spriteClose.setTexture(textureClose);
    spriteClose.setPosition(1310, 10);

    UGSFunctions functions;

    UGSMenuMain menuMain;

    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        menuMain.draw(window);

        if(functions.mouseColision(spriteClose, window)){
            spriteClose.setColor(sf::Color(255,255,255,255));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
            }
        } else {
            spriteClose.setColor(sf::Color(255,255,255,120));
        }
        window.draw(spriteClose);
        window.display();
    }

//    return 0;
}

int main()
{

    //openIntro();
    //return 0;

    sf::RenderWindow window(sf::VideoMode(1368, 768), "UGS2 - Ultimate Guitar Show", sf::Style::Default);
    //window.setPosition(sf::Vector2i(0,0));
    window.setVerticalSyncEnabled(true);

    sf::Texture textureClose;
    textureClose.loadFromFile("GUI/widgets/close.png");
    sf::Sprite spriteClose;
    spriteClose.setTexture(textureClose);
    spriteClose.setPosition(1310, 10);

    UGSFunctions functions;

    UGSMenuMain menuMain;

    Game1playerInfo info;
    info.backgrounCodes = std::vector<int>{2,3};
    info.bandName = "G-Off";
    info.dificultyCode = 1;
    info.folderCode = 1;
    info.instrumentCode = 1;
    info.misicName = "Quando eu acordar";
    info.playerName = "Marco";
    info.speed = 6;
    //info.speed = 1;
    UGSScreenGame gameTst(&info);


    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();
        }
        window.clear();
        gameTst.draw(window);

        if(functions.mouseColision(spriteClose, window)){
            spriteClose.setColor(sf::Color(255,255,255,255));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
            }
        } else {
            spriteClose.setColor(sf::Color(255,255,255,120));
        }
        window.draw(spriteClose);

        //window.draw(circleShape);
        window.display();
    }

    /*
    sf::Event event;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        menuMain.draw(window);

        if(functions.mouseColision(spriteClose, window)){
            spriteClose.setColor(sf::Color(255,255,255,255));
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                window.close();
            }
        } else {
            spriteClose.setColor(sf::Color(255,255,255,120));
        }
        window.draw(spriteClose);
        window.display();
    }*/

    return 0;
}



void openIntro(){
    /*
    sf::RenderWindow window(sf::VideoMode(1366, 708), "UGS2 - Ultimate Guitar Show", sf::Style::None);
    window.setPosition(sf::Vector2i(0,0));
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    HWND hWnd = window.getSystemHandle();
    SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
    SetLayeredWindowAttributes(hWnd, 0, 0, LWA_COLORKEY);

    sf::Texture textureIntro1;
    textureIntro1.loadFromFile("GUI/intro/intro1.png");
    sf::Texture textureIntro2;
    textureIntro2.loadFromFile("GUI/intro/intro2.png");

    sf::Sprite spriteIntro1;
    spriteIntro1.setTexture(textureIntro1);
    spriteIntro1.setPosition(500, 200);
    spriteIntro1.setRotation(-70);
    spriteIntro1.setScale(0,0);

    sf::Sprite spriteIntro2;
    spriteIntro2.setTexture(textureIntro2);
    spriteIntro2.setPosition(563,750);

    sf::Event event;
    int framecont = 0;
    float rotationCont = -70;
    float scaleCont = 0;
    while (window.isOpen()){
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(rotationCont < 0){ rotationCont += 7  ;}
        if(scaleCont    < 1){ scaleCont    += 0.1;}


        spriteIntro1.setRotation(rotationCont);
        spriteIntro1.setScale   (scaleCont, scaleCont);

        if(spriteIntro2.getPosition().y > 390){
            spriteIntro2.move(0,-15);
        } else {
            if(framecont++ > 80){ window.close(); }
        }

        window.clear();
        window.draw(spriteIntro1);
        window.draw(spriteIntro2);
        window.display();
    }

    return;
    */

}

