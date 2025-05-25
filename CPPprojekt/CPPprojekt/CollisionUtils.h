#pragma once

#include <SFML/Graphics.hpp>

// kontrollib sd::CircleShape obeketide kokkup�rget
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

// kontrollib sf::CircleShape ja sf::RectangleShape objektide kokkupõrget.
inline bool checkRectangleCollision(const sf::CircleShape& circ, const sf::RectangleShape rect)
{
    sf::Vector2f circPos = circ.getPosition();
    float circRad = circ.getRadius();
    sf::Vector2f circCenter = { circPos.x + circRad, circPos.y + circRad };

    sf::Vector2f rectPos = rect.getPosition();
    sf::Vector2f rectSize = rect.getSize();

    float closestX = std::clamp(circCenter.x, rectPos.x, rectPos.x + rectSize.x);
    float closestY = std::clamp(circCenter.y, rectPos.y, rectPos.y + rectSize.y);

    float dx = circCenter.x - closestX;
    float dy = circCenter.y - closestY;
    float distSquared = dx * dx + dy * dy;
    return distSquared < circRad * circRad;
}


