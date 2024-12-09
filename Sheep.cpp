#include "Sheep.hpp"

Sheep::Sheep(string name, int i)
{
    sheep_config = SHEEP_CONFIGS[i];
    sheep_texture.loadFromFile(IMAGE_FOLDER + name + ".png");
    sheep_sprite.setTexture(sheep_texture);
}