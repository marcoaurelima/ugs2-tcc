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


int main()
{

    sf::RenderWindow window(sf::VideoMode(1368, 768), "UGS2 - Ultimate Guitar Show", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setPosition(sf::Vector2i(0, 0));

    for(int i = 0; i < 40; i++){ puts("\n\n\n"); }

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

        window.display();
    }

    return 0;
}

