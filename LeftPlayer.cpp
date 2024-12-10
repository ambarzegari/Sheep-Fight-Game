#include "LeftPlayer.hpp"

LeftPlayer::LeftPlayer()
{
    health = INITTAL_HEALTH;
    Bozi = {};
    Shangool = {};
    Mangool = {};
}
void LeftPlayer::AddSheep(int row)
{
    double random_ = randomValue();
    if (random_ <= SHEEP_CONFIGS[0].displayProb)
    {
        LeftBozi *bozi = new LeftBozi(row);
        Bozi.push_back(bozi);
    }
    else if (random_ <= SHEEP_CONFIGS[0].displayProb + SHEEP_CONFIGS[1].displayProb)
    {
        LeftShangool *shangool = new LeftShangool(row);
        Shangool.push_back(shangool);
    }
    else
    {
        LeftMangool *mangool = new LeftMangool(row);
        Mangool.push_back(mangool);
    }
}
void LeftPlayer::move()
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
void LeftPlayer::render(RenderWindow &window)
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
