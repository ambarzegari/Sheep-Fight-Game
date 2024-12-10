#include "ًRightSheeps.hpp"

RightBozi::RightBozi(int row)
{
    right_bozi_config = SHEEP_CONFIGS[0];
    right_bozi_texture.loadFromFile(IMAGE_FOLDER + "black_goat.png");
    right_bozi_sprite.setTexture(right_bozi_texture);
    right_bozi_position = InitialPosition(row);
    right_bozi_sprite.setPosition(right_bozi_position);
}
void RightBozi::setPosition(Vector2f pos)
{
    right_bozi_position = pos;
    right_bozi_sprite.setPosition(pos);
}
void RightBozi::move()
{
    right_bozi_position.x -= SPEED;
    right_bozi_sprite.setPosition(right_bozi_position);
}
void RightBozi::render(RenderWindow &window)
{
    window.draw(right_bozi_sprite);
}

RightShangool::RightShangool(int row)
{
    right_shangool_config = SHEEP_CONFIGS[1];
    right_shangool_texture.loadFromFile(IMAGE_FOLDER + "black_pig.png");
    right_shangool_sprite.setTexture(right_shangool_texture);
    right_shangool_position = InitialPosition(row);
    right_shangool_sprite.setPosition(right_shangool_position);
    right_shangool_sprite.setScale(1.6, 1.6);
}
void RightShangool::setPosition(Vector2f pos)
{
    right_shangool_position = pos;
    right_shangool_sprite.setPosition(pos);
}
void RightShangool::move()
{
    right_shangool_position.x -= SPEED;
    right_shangool_sprite.setPosition(right_shangool_position);
}
void RightShangool::render(RenderWindow &window){
    window.draw(right_shangool_sprite);
}

RightMangool::RightMangool(int row)
{
    right_mangool_config = SHEEP_CONFIGS[2];
    right_mangool_texture.loadFromFile(IMAGE_FOLDER + "black_sheep.png");
    right_mangool_sprite.setTexture(right_mangool_texture);
    right_mangool_position = InitialPosition(row);
    right_mangool_sprite.setPosition(right_mangool_position);
    right_mangool_sprite.setScale(1, 1);
}
void RightMangool::setPosition(Vector2f pos)
{
    right_mangool_position = pos;
    right_mangool_sprite.setPosition(pos);
}
void RightMangool::move()
{
    right_mangool_position.x -= SPEED;
    right_mangool_sprite.setPosition(right_mangool_position);
}
void RightMangool::render(RenderWindow &window){
    window.draw(right_mangool_sprite);
}

Vector2f InitialPosition(int i)
{
    if (i == 1)
    {
        return Vector2f(850, 102);
    }
    else if (i == 2)
    {
        return Vector2f(850, 252);
    }
    else if (i == 3)
    {
        return Vector2f(850, 399);
    }
    else if (i == 4)
    {
        return Vector2f(850, 546);
    }
    return Vector2f(-1000, -1000);
}