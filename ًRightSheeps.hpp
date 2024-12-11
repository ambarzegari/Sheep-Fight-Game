#ifndef RIGHTSHEEPS_HPP
#define RIGHTSHEEPS_HPP

#include "General.hpp"

class RightBozi
{
private:
    Texture right_bozi_texture;
    Sprite right_bozi_sprite;
    int row;
    Vector2f right_bozi_position;

public:
    RightBozi(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow &window);
    Vector2f getPosition();
    SheepConfigs right_bozi_config;
};

class RightShangool
{
private:
    Texture right_shangool_texture;
    Sprite right_shangool_sprite;
    Vector2f right_shangool_position;
    int row;

public:
    RightShangool(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow &window);
    Vector2f getPosition();
    SheepConfigs right_shangool_config;
};

class RightMangool
{
private:
    Texture right_mangool_texture;
    Sprite right_mangool_sprite;
    Vector2f right_mangool_position;
    int row;

public:
    RightMangool(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow &window);
    Vector2f getPosition();
    SheepConfigs right_mangool_config;
};

Vector2f InitialPosition(int i);

#endif
