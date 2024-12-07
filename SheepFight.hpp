#ifndef SHEEPFIGHT_HPP
#define SHEEPFIGHT_HPP

#include <SFML/Graphics.hpp>
#include "General.hpp"

using namespace std;
using namespace sf;

enum State
{
    START,
    IN_GAME,
    GAMEOVER,
    EXIT,
};

class SheepFight
{
private:
    Texture start_texture;
    Sprite start_sprite;
public:
    State state;
    SheepFight(int width, int height);
    void run();
    RenderWindow window;
};








#endif