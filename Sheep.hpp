#ifndef SHEEP_HPP
#define SHEEP_HPP

#include "General.hpp"

class Sheep
{
private:
    SheepConfigs sheep_config;
    Texture sheep_texture;
    Sprite sheep_sprite;
public:
    Sheep(string name, int i);
};






#endif