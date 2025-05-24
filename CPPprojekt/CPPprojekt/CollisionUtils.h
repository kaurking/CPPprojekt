#pragma once

#include <SFML/Graphics.hpp>

// kontrollib sd::CircleShape obeketide kokkupõrget
inline bool checkCircleCollision(const sf::CircleShape& a, const sf::CircleShape& b)
{
    sf::Vector2f posA = a.getPosition();
    sf::Vector2f posB = b.getPosition();

    float radiusA = a.getRadius();
    float radiusB = b.getRadius();

    sf::Vector2f centerA = { posA.x + radiusA, posA.y + radiusA };
    sf::Vector2f centerB = { posB.x + radiusB, posB.y + radiusB };

    float dx = centerA.x - centerB.x;
    float dy = centerA.y - centerB.y;
    float distSquared = dx * dx + dy * dy;
    float radiusSum = radiusA + radiusB;

    return distSquared < radiusSum * radiusSum;
}


