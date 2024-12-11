#include "LeftPlayer.hpp"

LeftPlayer::LeftPlayer()
{
    right_health = INITTAL_HEALTH;
    Bozi = {};
    Shangool = {};
    Mangool = {};
    font.loadFromFile(FONTS_FOLDER + "Cute Dino.ttf");
    health.setString("HEALTH : " + to_string(right_health));
    health.setFont(font);
    health.setCharacterSize(25);
    health.setFillColor(sf::Color::Black);
    health.setStyle(sf::Text::Bold);
    health.setPosition(730, 655);
    for (int i = 0; i < 3; i++)
    {
        double random_ = randomValuel();
        if (random_ <= SHEEP_CONFIGS[0].displayProb)
        {
            sheep_queue.push_back("Bozi");
        }
        else if (random_ <= SHEEP_CONFIGS[0].displayProb + SHEEP_CONFIGS[1].displayProb)
        {
            sheep_queue.push_back("Shangool");
        }
        else
        {
            sheep_queue.push_back("Mangool");
        }
    }
}
void LeftPlayer::AddSheep(int row)
{
    double random_ = randomValuel();
    if (random_ <= SHEEP_CONFIGS[0].displayProb)
    {
        sheep_queue.push_back("Bozi");
    }
    else if (random_ <= SHEEP_CONFIGS[0].displayProb + SHEEP_CONFIGS[1].displayProb)
    {
        sheep_queue.push_back("Shangool");
    }
    else
    {
        sheep_queue.push_back("Mangool");
    }

    string sheep_name = sheep_queue[0];

    sheep_queue.erase(sheep_queue.begin());

    if (sheep_name == "Bozi")
    {
        LeftBozi *bozi = new LeftBozi(row);
        Bozi.push_back(bozi);
    }
    else if (sheep_name == "Shangool")
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
        if (bozi_->getPosition().x >= 880)
        {
            right_health = right_health - bozi_->left_bozi_config.damage;
            Bozi.erase(remove(Bozi.begin(), Bozi.end(), bozi_), Bozi.end());
            delete bozi_;
        }
    }
    for (auto shangool_ : Shangool)
    {
        shangool_->move();
        if (shangool_->getPosition().x >= 880)
        {
            right_health = right_health - shangool_->left_shangool_config.damage;
            Shangool.erase(remove(Shangool.begin(), Shangool.end(), shangool_), Shangool.end());
            delete shangool_;
        }
    }
    for (auto mangool_ : Mangool)
    {
        mangool_->move();
        if (mangool_->getPosition().x >= 880)
        {
            right_health = right_health - mangool_->left_mangool_config.damage;
            Mangool.erase(remove(Mangool.begin(), Mangool.end(), mangool_), Mangool.end());
            delete mangool_;
        }
    }
    health.setString("HEALTH : " + to_string(right_health));
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
    window.draw(health);
    ThreeNextSheepl(sheep_queue, window);
}

void ThreeNextSheepl(vector<string> queue, RenderWindow &window)
{
    Texture texture;
    Sprite sprite;

    if (queue[0] == "Bozi")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_goat.png");
        sprite.setTexture(texture);
        sprite.setPosition(150, 30);
        sprite.setScale(0.7,0.7);
        window.draw(sprite);
    }
    else if (queue[0] == "Shangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_pig.png");
        sprite.setTexture(texture);
        sprite.setPosition(150, 30);
        sprite.setScale(1,1);
        window.draw(sprite);
    }
    else if (queue[0] == "Mangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_sheep.png");
        sprite.setTexture(texture);
        sprite.setPosition(150, 30);
        sprite.setScale(0.7,0.7);
        window.draw(sprite);
    }

    if (queue[1] == "Bozi")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_goat.png");
        sprite.setTexture(texture);
        sprite.setPosition(250, 30);
        sprite.setScale(0.7,0.7);
        window.draw(sprite);
    }
    else if (queue[1] == "Shangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_pig.png");
        sprite.setTexture(texture);
        sprite.setPosition(250, 30);
        sprite.setScale(1,1);
        window.draw(sprite);
    }
    else if (queue[1] == "Mangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_sheep.png");
        sprite.setTexture(texture);
        sprite.setPosition(250, 30);
        sprite.setScale(0.7,0.7);
        window.draw(sprite);
    }

    if (queue[2] == "Bozi")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_goat.png");
        sprite.setTexture(texture);
        sprite.setPosition(350, 30);
        sprite.setScale(0.7,0.7);
        window.draw(sprite);
    }
    else if (queue[2] == "Shangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_pig.png");
        sprite.setTexture(texture);
        sprite.setPosition(350, 30);
        sprite.setScale(1,1);
        window.draw(sprite);
    }
    else if (queue[2] == "Mangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "white_sheep.png");
        sprite.setTexture(texture);
        sprite.setPosition(350, 30);
        sprite.setScale(0.7,0.7);
        window.draw(sprite);
    }
}

double randomValuel()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}
