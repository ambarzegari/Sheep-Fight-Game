#ifndef GENERAL_HPP
#define GENERAL_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <random>

using namespace std;
using namespace sf;

const int WIDTH = 1080;
const int HEIGHT = 720;

const string IMAGE_FOLDER = "files/images/";
const string MUSICS_FOLDER = "files/musics/";
const string FONTS_FOLDER = "files/fonts/";

struct SheepConfigs
{
    string name;
    int damage;
    int strength;
    float displayProb;
};

const vector<SheepConfigs> SHEEP_CONFIGS =
    {{
        {"Bozi", 50, 50, 0.5},
        {"Mangool", 30, 150, 0.3},
        {"Shangool", 30, 250, 0.2},
    }};

const int INITTAL_HEALTH = 400;
const double SPEED = 0.03;

#endif