#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 2.f;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setRadius(5.0f);
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->shape.move(this->movementSpeed, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::update()
{
	this->updateInput();
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
