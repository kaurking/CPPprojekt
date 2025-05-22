#pragma once

#include <SFML/Graphics.hpp>

class Button 
{
private:
	sf::Text text;
public:

	Button(const std::string& label, sf::Vector2f pos, sf::Font& font);
	void render(sf::RenderTarget& target);
	bool isHovered(const sf::Vector2f& mousePos) const;
	bool isClicked(const sf::Vector2f& mousePos) const;
	void setColor(const sf::Color& color);


};
