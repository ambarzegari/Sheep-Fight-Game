#ifndef RIGHTPLAYER_HPP
#define RIGHTPLAYER_HPP

#include "General.hpp"
#include "ًRightSheeps.hpp"

class RightPlayer
{
private:
    vector<RightBozi*> Bozi;
    vector<RightShangool*> Shangool;
    vector<RightMangool*> Mangool;
    int health;
public:
    RightPlayer();
    void AddSheep(int row);
    void move();
    void render(RenderWindow& window);
};

double randomValue();

#endif