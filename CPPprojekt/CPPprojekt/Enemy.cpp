#include "Enemy.h"
#include <vector>

void Enemy::initVariables()
{
	this->movementSpeed = 200.f;
	
}

void Enemy::initShape()
{
	this->shape.setFillColor(sf::Color::Red);
	this->shape.setRadius(10.0f);
}

Enemy::Enemy(std::vector<sf::Vector2f> pathOfEnemy)
{
	this->pathOfEnemy = pathOfEnemy;
	this->shape.setPosition(pathOfEnemy[0]);
	this->startPos = pathOfEnemy[0];
	this->endPos = pathOfEnemy.back();

	this->initVariables();
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

	// liigub järgmise punktini vektoris
	this->shape.move(direction * this->movementSpeed * deltaTime);

	// kui punktil lähedal ,siis kas tagasi (vektor size = 2) või lõpuni.
	if (distance < 2.f)
	{
		if (pathOfEnemy.size() == 2)
		{
			// kui kaks, siis edasi tagasi liikumine
			currentTargetIndex = (currentTargetIndex == 0) ? 1 : 0;
		}
		else
		{
			// veel ei ole jõutud vektori lõppu liikumisega
			if (this->movingForward)
			{
				currentTargetIndex++;
				if (currentTargetIndex >= pathOfEnemy.size() - 1)
				{
					this->movingForward = false;
				}
			}
			// jõuti vektori lõppu liikumisega, aeg tagasi minna
			else
			{
				currentTargetIndex--;
				// kui jõutakse algusesse tagasi, siis jälle õiget pidi
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
