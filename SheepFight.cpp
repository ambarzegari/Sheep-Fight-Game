#include "SheepFight.hpp"

SheepFight::SheepFight(int width, int height)
{
    window.create(VideoMode(width, height), "Sheep Fight");
    state = START;
    start_texture.loadFromFile(IMAGE_FOLDER + "start.png");
    start_sprite.setTexture(start_texture);
    Vector2u textureSize = start_texture.getSize();
    Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    start_sprite.setScale(scaleX, scaleY);
}
void SheepFight::run()
{
    while (window.isOpen() && state != EXIT)
    {
        window.clear();
        switch (state)
        {
        case START:
            window.draw(start_sprite);
            break;

        default:
            break;
        }
        window.display();
    }
}