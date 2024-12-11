#include "RightPlayer.hpp"

RightPlayer::RightPlayer()
{
    left_health = INITTAL_HEALTH;
    Bozi = {};
    Shangool = {};
    Mangool = {};
    font.loadFromFile(FONTS_FOLDER + "Cute Dino.ttf");
    health.setString("HEALTH : " + to_string(left_health));
    health.setFont(font);
    health.setCharacterSize(25);
    health.setFillColor(sf::Color::Black);
    health.setStyle(sf::Text::Bold);
    health.setPosition(150, 655);
    for (int i = 0; i < 3; i++)
    {
        double random_ = randomValue();
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
void RightPlayer::AddSheep(int row)
{
    double random_ = randomValue();
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
        RightBozi *bozi = new RightBozi(row);
        Bozi.push_back(bozi);
    }
    else if (sheep_name == "Shangool")
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
        if (bozi_->getPosition().x <= 100)
        {
            left_health = left_health - bozi_->right_bozi_config.damage;
            Bozi.erase(remove(Bozi.begin(), Bozi.end(), bozi_), Bozi.end());
            delete bozi_;
        }
    }
    for (auto shangool_ : Shangool)
    {
        shangool_->move();
        if (shangool_->getPosition().x <= 100)
        {
            left_health = left_health - shangool_->right_shangool_config.damage;
            Shangool.erase(remove(Shangool.begin(), Shangool.end(), shangool_), Shangool.end());
            delete shangool_;
        }
    }
    for (auto mangool_ : Mangool)
    {
        mangool_->move();
        if (mangool_->getPosition().x <= 100)
        {
            left_health = left_health - mangool_->right_mangool_config.damage;
            Mangool.erase(remove(Mangool.begin(), Mangool.end(), mangool_), Mangool.end());
            delete mangool_;
        }
    }
    health.setString("HEALTH : " + to_string(left_health));
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
    window.draw(health);
    ThreeNextSheep(sheep_queue, window);
}

void ThreeNextSheep(vector<string> queue, RenderWindow &window)
{
    Texture texture;
    Sprite sprite;

    if (queue[0] == "Bozi")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_goat.png");
        sprite.setTexture(texture);
        sprite.setPosition(850, 30);
        sprite.setScale(0.7, 0.7);
        window.draw(sprite);
    }
    else if (queue[0] == "Shangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_pig.png");
        sprite.setTexture(texture);
        sprite.setPosition(850, 30);
        sprite.setScale(1, 1);
        window.draw(sprite);
    }
    else if (queue[0] == "Mangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_sheep.png");
        sprite.setTexture(texture);
        sprite.setPosition(850, 30);
        sprite.setScale(0.7, 0.7);
        window.draw(sprite);
    }

    if (queue[1] == "Bozi")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_goat.png");
        sprite.setTexture(texture);
        sprite.setPosition(750, 30);
        sprite.setScale(0.7, 0.7);
        window.draw(sprite);
    }
    else if (queue[1] == "Shangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_pig.png");
        sprite.setTexture(texture);
        sprite.setPosition(750, 30);
        sprite.setScale(1, 1);
        window.draw(sprite);
    }
    else if (queue[1] == "Mangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_sheep.png");
        sprite.setTexture(texture);
        sprite.setPosition(750, 30);
        sprite.setScale(0.7, 0.7);
        window.draw(sprite);
    }

    if (queue[2] == "Bozi")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_goat.png");
        sprite.setTexture(texture);
        sprite.setPosition(650, 30);
        sprite.setScale(0.7, 0.7);
        window.draw(sprite);
    }
    else if (queue[2] == "Shangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_pig.png");
        sprite.setTexture(texture);
        sprite.setPosition(650, 30);
        sprite.setScale(1, 1);
        window.draw(sprite);
    }
    else if (queue[2] == "Mangool")
    {
        texture.loadFromFile(IMAGE_FOLDER + "black_sheep.png");
        sprite.setTexture(texture);
        sprite.setPosition(650, 30);
        sprite.setScale(0.7, 0.7);
        window.draw(sprite);
    }
}

double randomValue()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    return dis(gen);
}
