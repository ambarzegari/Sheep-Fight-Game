#include "RightPlayer.hpp"

RightPlayer::RightPlayer()
{
    health = INITTAL_HEALTH;
    Bozi = {};
    Shangool = {};
    Mangool = {};
}
void RightPlayer::AddSheep(int row)
{
    double random_ = randomValue();
    if (random_ <= SHEEP_CONFIGS[0].displayProb)
    {
        RightBozi *bozi = new RightBozi(row);
        Bozi.push_back(bozi);
    }
    else if (random_ <= SHEEP_CONFIGS[0].displayProb + SHEEP_CONFIGS[1].displayProb)
    {
        RightShangool *shangool = new RightShangool(row);
        Shangool.push_back(shangool);
    }
    else
    {
        RightMangool *mangool = new RightMangool(row);
        Mangool.push_back(mangool);
    }
}
void RightPlayer::move()
{
    for (auto bozi_ : Bozi)
    {
        bozi_->move();
    }
    for (auto shangool_ : Shangool)
    {
        shangool_->move();
    }
    for (auto mangool_ : Mangool)
    {
        mangool_->move();
    }
}
void RightPlayer::render(RenderWindow &window)
{
    for (auto bozi_ : Bozi)
    {
        bozi_->render(window);
    }
    for (auto shangool_ : Shangool)
    {
        shangool_->render(window);
    }
    for (auto mangool_ : Mangool)
    {
        mangool_->render(window);
    }
}

double randomValue()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}
