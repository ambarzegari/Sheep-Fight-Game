#ifndef SHEEPFIGHT_HPP
#define SHEEPFIGHT_HPP

#include "General.hpp"
#include "RightPlayer.hpp"
#include "LeftPlayer.hpp"

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
    RightPlayer right_player;
    LeftPlayer left_player;
    Texture start_texture;
    Sprite start_sprite;
    Music start_music;
    Font font;
    Text start_text;
    Texture background_texture;
    Sprite background_sprite;
    Music game_music;
    Texture right_flsh_texture;
    Sprite right_flash_sprite;
    Texture left_flsh_texture;
    Sprite left_flash_sprite;
    int row_num_right;
    int row_num_left;

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

Vector2f flashPositionRight(int i);
Vector2f flashPositionLeft(int i);

#endif