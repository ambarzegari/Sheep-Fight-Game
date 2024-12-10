#ifndef LEFTSHEEPS_HPP
#define LEFTSHEEPS_HPP

#include "General.hpp"


class LeftBozi
{
private:
    Texture left_bozi_texture;
    Sprite left_bozi_sprite;
    SheepConfigs left_bozi_config;
    Vector2f left_bozi_position;

public:
    LeftBozi(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow& window);
};

class LeftShangool
{
private:
    Texture left_shangool_texture;
    Sprite left_shangool_sprite;
    SheepConfigs left_shangool_config;
    Vector2f left_shangool_position;

public:
    LeftShangool(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow& window);
};

class LeftMangool
{
private:
    Texture left_mangool_texture;
    Sprite left_mangool_sprite;
    SheepConfigs left_mangool_config;
    Vector2f left_mangool_position;

public:
    LeftMangool(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow& window);
};

Vector2f InitialPosition(int i);

#endif
