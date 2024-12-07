#ifndef SHEEPFIGHT_HPP
#define SHEEPFIGHT_HPP

#include "General.hpp"

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
    void handleEvent();
    void update();
    void gameover();
    void render();
    RenderWindow window;
};

#endif