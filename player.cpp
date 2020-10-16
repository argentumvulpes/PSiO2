#include "player.h"

Player::Player(const sf::Vector2f &position, const sf::Texture &texture) {
    this->position = position;
    setPosition(position.x,position.y);
    setTexture(texture);
}

void Player::move_x(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -0.4;
        move(velocity.x, 0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = 0.4;
        move(velocity.x, 0);
    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        velocity.y = -0.4;
//        move(0, velocity.y);
//    }
//    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//        velocity.y = 0.2;
//        move(0, velocity.y);
//    }
    if(sf::Event::KeyReleased){
        velocity.y = 0.2;
        move(0, velocity.y);
    }
}

void Player::collision(sf::Sprite &s){

    sf::Vector2f playerPosition = getPosition();
    sf::Vector2f platformPosition = s.getPosition();

    float playerWidth = getGlobalBounds().width;
    float playerHeight = getGlobalBounds().height;
    float platformWidth = s.getGlobalBounds().width;
    float platformHeight = s.getGlobalBounds().height;

    if (((playerPosition.x + playerWidth) > platformPosition.x && playerPosition.x < (platformPosition.x+platformWidth)) &&
       ((playerPosition.y + playerHeight) < (platformPosition.y+platformHeight) && (playerPosition.y+playerHeight) > (platformPosition.y))){

        velocity.y = -200;
        move(0,velocity.y);
    }
}


//void Player::gravity(sf::Clock &clock){

//    dt = clock.restart().asSeconds();

//    velocity.y = dt * 200;
//    move(0,velocity.y);
//}

void Player::setAcceleration(float acceleration_x, float acceleration_y) {
    acceleration_x_ = acceleration_x;
    acceleration_y_ = acceleration_y;
}




