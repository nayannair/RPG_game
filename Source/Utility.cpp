#include "Utility.h"

/* Normalize a vector */
sf::Vector2f vectorNormalize(sf::Vector2f& vector)
{
    float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / magnitude;
    normalizedVector.y = vector.y / magnitude;
    return normalizedVector;
}