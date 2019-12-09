#include <iostream>
#include "../TextureManager/TextureManager.h"

int main() {
    sf::Texture appletexture;
    appletexture.loadFromFile("apple.png");
    sf::RectangleShape apple;
    apple.setTexture(&appletexture);
    sf::Vector2f size = static_cast<sf::Vector2f>(appletexture.getSize());
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
