#include "point.h"

Point::Point(const sf::Vector2f &position, const sf::Texture &texture){
    this->position = position;
    setPosition(position.x, position.y);
    setTexture(texture);
}
