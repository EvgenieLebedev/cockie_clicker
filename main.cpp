#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main() {
    // Создание окна
    sf::RenderWindow window(sf::VideoMode(800, 600), "Cookie Clicker");

    // Загрузка текстуры печеньки
    sf::Texture cookieTexture;
    if (!cookieTexture.loadFromFile("cookie.png")) {
        std::cout << "Ошибка загрузки изображения печеньки!" << std::endl;
        return -1;
    }

    // Спрайт для печеньки
    sf::Sprite cookieSprite;
    cookieSprite.setTexture(cookieTexture);
    cookieSprite.setPosition(300, 200); // Позиция печеньки

    // Шрифт для отображения счёта
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "Ошибка загрузки шрифта!" << std::endl;
        return -1;
    }

    // Текст для отображения счёта
    sf::Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(30);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(10, 10);

    int score = 0;  // Начальный счёт
    scoreText.setString("Score: " + std::to_string(score));

    // Основной цикл игры
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Проверка клика мышью
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Получение позиции клика
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Проверка, попал ли клик на печеньку
                    if (cookieSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        score += 1;;  // Увеличение счёта
                        scoreText.setString("Score: " + std::to_string(score));  // Обновление текста
                    }
                }
            }
        }

        // Очистка экрана
        window.clear();

        // Отрисовка печеньки и текста счёта
        window.draw(cookieSprite);
        window.draw(scoreText);

        // Отображение нового кадра
        window.display();
    }

    return 0;
}
