#ifndef RIGHTSHEEP_HPP
#define RIGHTSHEEP_HPP

#include "General.hpp"


class RightBozi
{
private:
    Texture right_bozi_texture;
    Sprite right_bozi_sprite;
    SheepConfigs right_bozi_config;
    Vector2f right_bozi_position;

public:
    RightBozi(int row);
    void setPosition(Vector2f);
    void move();
    void render(RenderWindow& window);
};

Vector2f InitialPosition(int i);

#endif
