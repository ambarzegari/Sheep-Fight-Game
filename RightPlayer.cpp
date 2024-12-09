# include "RightPlayer.hpp"

RightPlayer::RightPlayer()
{
    health = 300;
    Bozi = {};
}
void RightPlayer::AddBozi(int row)
{
    RightBozi* bozi = new RightBozi(row);
    Bozi.push_back(bozi);
}
void RightPlayer::move(){
    for(auto bozi_ : Bozi){
        bozi_->move();
    }
}
void RightPlayer::render(RenderWindow& window){
    for(auto bozi_ : Bozi){
        bozi_->render(window);
    }
}
    