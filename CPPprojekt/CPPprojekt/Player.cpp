#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 200.f;
}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setRadius(10.0f);
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

sf::CircleShape& Player::getShape()
{
	return this->shape;
}

void Player::setPositionOfPlayer(float x, float y)
{
	this->shape.setPosition(x, y);
}

void Player::move(float deltaTime)
{
	sf::Vector2f direction(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		direction.x -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		direction.x += 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		direction.y -= 1.f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		direction.y += 1.f;

	if (direction.x != 0.f || direction.y != 0.f)
	{
		float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
		direction /= length;
	}
	
	// sprintimise jaoks
	bool isSprinting = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift);
	float speed = this->movementSpeed * (isSprinting ? 1.5f : 1.f);

	// nt 60 fpsi puhul : direction(0, 1) * 200.f * 0,0167f = 3.33 pixels/frame = 200 pixels/s
	this->shape.move(direction * speed * deltaTime);
	// kuna .move teeb liigutust iga frame, siis kui fps on suurem, siis liigub objekt ikka sama kiirelt,
	// kuna deltaTime on madalam 120 fps = 0,0083f.

}


void Player::updateWindowBoundsCollision(const sf::RenderTarget* target)
{	
	// Left
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	// Right
	else if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(std::round(target->getSize().x - this->shape.getGlobalBounds().width), this->shape.getGlobalBounds().top);
	// Up
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(std::round(this->shape.getGlobalBounds().left), 0.f);
	// Down
	else if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(std::round(this->shape.getGlobalBounds().left), target->getSize().y - this->shape.getGlobalBounds().height);
}

void Player::update(const sf::RenderTarget* target, float deltaTime)
{
	this->move(deltaTime);
	this->updateWindowBoundsCollision(target);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
