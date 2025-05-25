#include "Enemy.h"
#include <vector>

void Enemy::initShape()
{
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setRadius(10.0f);
}

Enemy::Enemy(std::vector<sf::Vector2f> pathOfEnemy, float moveSpeed)
{
	this->movementSpeed = moveSpeed;
	this->pathOfEnemy = pathOfEnemy;
	this->shape.setPosition(pathOfEnemy[0]);
	this->startPos = pathOfEnemy[0];
	this->endPos = pathOfEnemy.back();

	this->initShape();
}

Enemy::~Enemy()
{
}

sf::CircleShape Enemy::getShape() {
	return this->shape;
}

sf::Vector2f Enemy::getStartPos() {
	return this->startPos;
}

void Enemy::move(float deltaTime)
{
	if (this->pathOfEnemy.size() == 1)
	{
		// kui seisab paigal
		return;
	}

	sf::Vector2f currentPos = this->shape.getPosition();
	sf::Vector2f targetPos = pathOfEnemy[currentTargetIndex];
	sf::Vector2f direction = targetPos - currentPos;

	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// normaliseerimine diagonaalliikumise jaoks
	if (distance != 0.f)
		direction /= distance;

	// liigub j�rgmise punktini vektoris
	this->shape.move(direction * this->movementSpeed * deltaTime);

	// kui punktil l�hedal ,siis kas tagasi (vektor size = 2) v�i l�puni.
	if (distance < 2.f)
	{
		if (pathOfEnemy.size() == 2)
		{
			// kui kaks, siis edasi tagasi liikumine
			currentTargetIndex = (currentTargetIndex == 0) ? 1 : 0;
		}
		else
		{
			// veel ei ole j�utud vektori l�ppu liikumisega
			if (this->movingForward)
			{
				currentTargetIndex++;
				if (currentTargetIndex >= pathOfEnemy.size() - 1)
				{
					this->movingForward = false;
				}
			}
			// j�uti vektori l�ppu liikumisega, aeg tagasi minna
			else
			{
				currentTargetIndex--;
				// kui j�utakse algusesse tagasi, siis j�lle �iget pidi
				if (currentTargetIndex == 0)
				{
					this->movingForward = true;
				}
			}
		}
	}
}

void Enemy::update(const sf::RenderTarget* target, float deltaTime)
{
	this->move(deltaTime);
	// this->updateWindowBoundsCollision(target);
}

void Enemy::render(sf::RenderTarget& target)
{
	target.draw(this->shape);
}

void Enemy::reset()
{
	this->shape.setPosition(this->startPos);
	this->currentTargetIndex = 1;
	this->movingForward = true;
}
