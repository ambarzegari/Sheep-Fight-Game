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
    Font font;
    Text health;
    int right_health;
    vector<string> sheep_queue;
public:
    RightPlayer();
    void AddSheep(int row);
    void move();
    void render(RenderWindow& window);
};

double randomValue();
void ThreeNextSheep(vector<string> queue, RenderWindow& window);

#endif