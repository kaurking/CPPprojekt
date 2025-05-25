#pragma once

#include <SFML/Graphics.hpp>

// kontrollib sd::CircleShape obeketide kokkup�rget
inline bool checkCircleCircleCollision(const sf::CircleShape& a, const sf::CircleShape& b)
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

// kontrollib sf::CircleShape ja sf::RectangleShape objektide kokkupõrget.
inline bool checkCircleRectangleCollision(const sf::CircleShape& a, const sf::RectangleShape b)
{
    sf::Vector2f posA = a.getPosition();
    float radiusA = a.getRadius();
    sf::Vector2f centreA = { posA.x + radiusA, posA.y + radiusA };

    sf::Vector2f posB = b.getPosition();
    sf::Vector2f sizeB = b.getSize();

    float closestX = std::clamp(centreA.x, posB.x, posB.x + sizeB.x);
    float closestY = std::clamp(centreA.y, posB.y, posB.y + sizeB.y);

    float dx = centreA.x - closestX;
    float dy = centreA.y - closestY;
    float distSquared = dx * dx + dy * dy;
    return distSquared < radiusA * radiusA;
}

// Kontrollib kahe sf::RectangleShape objekti kokkupõrget
inline bool checkRectangleRectangleCollision(const sf::RectangleShape& a, const sf::RectangleShape& b)
{
    sf::Vector2f posA = a.getPosition();
    sf::Vector2f sizeA = a.getSize();

    sf::Vector2f posB = b.getPosition();
    sf::Vector2f sizeB = b.getSize();

    bool overlapX = posA.x < posB.x + sizeB.x && posA.x + sizeA.x > posB.x;
    bool overlapY = posA.y < posB.y + sizeB.y && posA.y + sizeA.y > posB.y;

    return overlapX && overlapY;
}


