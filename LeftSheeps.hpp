#ifndef LEFTSHEEPS_HPP
#define LEFTSHEEPS_HPP

#include "General.hpp"

class LeftBozi
{
private:
    Texture left_bozi_texture;
    Sprite left_bozi_sprite;
    Vector2f left_bozi_position;
    int row;

public:
    LeftBozi(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow &window);
    Vector2f getPosition();
    SheepConfigs left_bozi_config;
};

class LeftShangool
{
private:
    Texture left_shangool_texture;
    Sprite left_shangool_sprite;
    Vector2f left_shangool_position;
    int row;

public:
    LeftShangool(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow &window);
    Vector2f getPosition();
    SheepConfigs left_shangool_config;
};

class LeftMangool
{
private:
    Texture left_mangool_texture;
    Sprite left_mangool_sprite;
    Vector2f left_mangool_position;
    int row;

public:
    LeftMangool(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow &window);
    Vector2f getPosition();
    SheepConfigs left_mangool_config;
};

Vector2f InitialPositionl(int i);

#endif
