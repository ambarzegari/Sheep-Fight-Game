#include <SFML/Graphics.hpp>
#include <vector>

const int ROWS = 50; // تعداد ردیف‌ها
const int COLS = 50; // تعداد ستون‌ها
const int CELL_SIZE = 50; // اندازه هر خانه (پیکسل)

std::vector<std::vector<bool>> createWalkableGrid() {
    std::vector<std::vector<bool>> grid(ROWS, std::vector<bool>(COLS, true)); // پیش‌فرض همه قابل‌حرکت‌اند
    
    // مشخص کردن مناطق غیرقابل‌حرکت
    grid[2][2] = false; // یک مثال: خانه (2, 2) غیرقابل‌حرکت است
    grid[4][5] = false;

    return grid;
}

bool isWalkable(int x, int y, const std::vector<std::vector<bool>>& grid) {
    int row = y / CELL_SIZE;
    int col = x / CELL_SIZE;

    if (row >= 0 && row < ROWS && col >= 0 && col < COLS) {
        return grid[row][col];
    }
    return false; // اگر بیرون از محدوده بود
}

int main() {
    sf::RenderWindow window(sf::VideoMode(COLS * CELL_SIZE, ROWS * CELL_SIZE), "Sheep Fight");
    std::vector<std::vector<bool>> walkableGrid = createWalkableGrid();

    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
    cell.setOutlineColor(sf::Color::Black);
    cell.setOutlineThickness(1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        // رسم شبکه
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                cell.setPosition(col * CELL_SIZE, row * CELL_SIZE);
                if (walkableGrid[row][col]) {
                    cell.setFillColor(sf::Color::Green); // مناطق قابل‌حرکت
                } else {
                    cell.setFillColor(sf::Color::Red); // مناطق غیرقابل‌حرکت
                }
                window.draw(cell);
            }
        }

        window.display();
    }

    return 0;
}
