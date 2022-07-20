#ifndef UGSFUNCTIONS_H
#define UGSFUNCTIONS_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

struct DetailsInfo{
    int folderNumber;
    std::string artist; std::string music; std::string duration;
    int code1; std::string instrumentLabel1;
    int code2; std::string instrumentLabel2;
    int code3; std::string instrumentLabel3;
    int code4; std::string instrumentLabel4;
    std::string dificulty;
};

struct Game1playerInfo{
    std::string playerName;
    std::string instrumentName;
    std::string bandName;
    std::string misicName;
    int folderCode;
    int dificultyCode;
    int instrumentCode;
    int speed;
    std::vector<int> backgrounCodes;
};


class UGSFunctions{
    public:
    sf::Sprite& create_SFsprite(std::string imagePath);
    sf::Music&  create_SFmusic(std::string musicPath);
    sf::Text&   create_SFtext(std::string fontPath, int size, sf::Color color, std::string text);
    bool key_pressed(int key);
    bool sprite_colision(sf::Sprite sprite1,         sf::Sprite sprite2);
    bool mouseColision  (sf::RectangleShape& sprite, sf::RenderWindow& window);
    bool mouseColision  (sf::Sprite&         sprite, sf::RenderWindow& window);
};


#endif // UGSFUNCTIONS_H
