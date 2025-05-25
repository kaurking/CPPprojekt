#include "movableBox.h"

movableBox::movableBox(sf::Vector2f position, sf::Vector2f size)
{
	this->shape.setPosition(position);

}

bool movableBox::tryMove(std::string direction)
{
	return false;
}

void movableBox::update()
{
	sf::Vector2f 
}

void movableBox::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}
