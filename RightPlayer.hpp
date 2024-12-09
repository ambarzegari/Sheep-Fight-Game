#ifndef RIGHTPLAYER_HPP
#define RIGHTPLAYER_HPP

#include "General.hpp"
#include "ًRightSheeps.hpp"

class RightPlayer
{
private:
    vector<RightBozi*> Bozi;
    int health;
public:
    RightPlayer();
    void AddBozi(int row);
    void move();
    void render(RenderWindow& window);
};

#endif