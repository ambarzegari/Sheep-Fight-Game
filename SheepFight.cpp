#include "SheepFight.hpp"

SheepFight::SheepFight(int width, int height)
{
    window.create(VideoMode(width, height), "Sheep Fight");
    state = START;
    start_texture.loadFromFile(IMAGE_FOLDER + "start.png");
    start_sprite.setTexture(start_texture);
    Vector2u textureSize = start_texture.getSize();
    Vector2u windowSize = window.getSize();

    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    start_sprite.setScale(scaleX, scaleY);

    start_music.openFromFile(MUSICS_FOLDER + "start.ogg");
    start_music.play();
    start_music.setLoop(true);

    font.loadFromFile(FONTS_FOLDER + "Cute Dino.ttf");
    start_text.setFont(font);
    start_text.setString("Press Enter to start the game.");
    start_text.setCharacterSize(40);
    start_text.setFillColor(sf::Color::Black);
    start_text.setStyle(sf::Text::Bold);
    start_text.setPosition(240, 600);

    background_texture.loadFromFile(IMAGE_FOLDER + "background.png");
    background_sprite.setTexture(background_texture);

    Vector2u textureSize2 = background_texture.getSize();
    Vector2u windowSize2 = window.getSize();

    float scaleX2 = static_cast<float>(windowSize2.x) / textureSize2.x;
    float scaleY2 = static_cast<float>(windowSize2.y) / textureSize2.y;

    background_sprite.setScale(scaleX2, scaleY2);

    game_music.openFromFile(MUSICS_FOLDER + "game.ogg");

    right_flsh_texture.loadFromFile(IMAGE_FOLDER + "right_flash.png");
    right_flash_sprite.setTexture(right_flsh_texture);
    right_flash_sprite.setScale(0.1, 0.1);
    row_num_right = 0;

    left_flsh_texture.loadFromFile(IMAGE_FOLDER + "left_flash.png");
    left_flash_sprite.setTexture(left_flsh_texture);
    left_flash_sprite.setScale(0.1, 0.1);
    row_num_left = 0;
};

void SheepFight::run()
{
    while (window.isOpen() && state != EXIT)
    {
        handleEvent();
        update();
        gameover();
        render();
    }
}

void SheepFight::handleEvent()
{
    Event event;
    switch (state)
    {
    case START:
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.key.code == Keyboard::Enter)
            {
                state = IN_GAME;
                start_music.pause();
                game_music.play();
                game_music.setLoop(true);
            }
        }
        break;

    case IN_GAME:
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::W)
                {
                    row_num_left--;
                    if (row_num_left < 1)
                    {
                        row_num_left = 4;
                    }
                }
                else if (event.key.code == Keyboard::S)
                {
                    row_num_left++;
                    if (row_num_left > 4)
                    {
                        row_num_left = 1;
                    }
                }
                else if (event.key.code == Keyboard::Up)
                {
                    row_num_right--;
                    if (row_num_right < 1)
                    {
                        row_num_right = 4;
                    }
                }
                else if (event.key.code == Keyboard::Down)
                {
                    row_num_right++;
                    if (row_num_right > 4)
                    {
                        row_num_right = 1;
                    }
                }
                else if (event.key.code == Keyboard::Enter)
                {
                    if (row_num_right != 0)
                        right_player.AddSheep(row_num_right);
                    row_num_right = 0;
                }
                else if (event.key.code == Keyboard::Space)
                {
                    if (row_num_left != 0)
                        left_player.AddSheep(row_num_left);
                    row_num_left = 0;
                }
            }
        }
        break;

    default:
        break;
    }
}

void SheepFight::update()
{
    switch (state)
    {
    case START:
        break;

    case IN_GAME:
        right_flash_sprite.setPosition(flashPositionRight(row_num_right));
        left_flash_sprite.setPosition(flashPositionLeft(row_num_left));
        right_player.move();
        left_player.move();
        break;

    default:
        break;
    }
}

void SheepFight::gameover()
{
    switch (state)
    {
    case START:
        break;
    case IN_GAME:
        break;
    default:
        break;
    }
}

void SheepFight::render()
{
    window.clear();
    switch (state)
    {
    case START:
        window.draw(start_sprite);
        window.draw(start_text);
        break;

    case IN_GAME:
        window.draw(background_sprite);
        window.draw(right_flash_sprite);
        window.draw(left_flash_sprite);
        right_player.render(window);
        left_player.render(window);
        break;
    default:
        break;
    }
    window.display();
}

Vector2f flashPositionRight(int i)
{
    if (i == 1)
    {
        return Vector2f(850, 125);
    }
    else if (i == 2)
    {
        return Vector2f(850, 272);
    }
    else if (i == 3)
    {
        return Vector2f(850, 419);
    }
    else if (i == 4)
    {
        return Vector2f(850, 566);
    }
    return Vector2f(-1000, -1000);
}

Vector2f flashPositionLeft(int i)
{
    if (i == 1)
    {
        return Vector2f(160, 125);
    }
    else if (i == 2)
    {
        return Vector2f(160, 272);
    }
    else if (i == 3)
    {
        return Vector2f(160, 419);
    }
    else if (i == 4)
    {
        return Vector2f(160, 566);
    }
    return Vector2f(-1000, -1000);
}