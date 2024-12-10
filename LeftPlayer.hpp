#ifndef LEFTPLAYER_HPP
#define LEFTPLAYER_HPP

#include "General.hpp"
#include "LeftSheeps.hpp"

class LeftPlayer
{
private:
    vector<LeftBozi*> Bozi;
    vector<LeftShangool*> Shangool;
    vector<LeftMangool*> Mangool;
    Font font;
    Text health;
    int left_health;
public:
    LeftPlayer();
    void AddSheep(int row);
    void move();
    void render(RenderWindow& window);
};

double randomValuel();

#endif