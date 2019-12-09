#include <iostream>
#include "../TextureManager/TextureManager.h"

int main() {
    TextureManager::load("apple.png");
    sf::RectangleShape apple;
    apple.setTexture(TextureManager::get_texture("apple.png"));
    sf::Vector2f size = static_cast<sf::Vector2f>(apple.getTexture()->getSize());
    apple.setSize(size);
    sf::RenderWindow window(sf::VideoMode(size.x, size.y), "This is an apple");
    window.setFramerateLimit(1);
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.draw(apple);
        window.display();
    }
}
