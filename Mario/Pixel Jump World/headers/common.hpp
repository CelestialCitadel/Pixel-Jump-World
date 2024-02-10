#pragma once
#include <iostream>

// blocks
static constexpr unsigned char CELL_SIZE = 16;
static constexpr unsigned char FONT_HEIGHT = 16;

static constexpr unsigned char TEXTURE_BIT = 16;

static constexpr unsigned char SCREEN_RESIZE_FACTOR = 2;

static constexpr unsigned short SCREEN_WIDTH = 800;
static constexpr unsigned short SCREEN_HEIGHT = 480;

static constexpr float GRAVITY = 0.25f;
static constexpr float MARIO_SPEED = 4;

static constexpr unsigned short FRAME_DURATION = 16667;

enum Cell
{
    Empty,
    Wall,
    Floor
};

typedef std::vector <std::array<Cell, SCREEN_HEIGHT / CELL_SIZE>> Map;