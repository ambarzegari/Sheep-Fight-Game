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
        break;
    default:
        break;
    }
    window.display();
}