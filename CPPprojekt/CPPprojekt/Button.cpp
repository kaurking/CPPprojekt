#include "Button.h"

Button::Button(const std::string& label, sf::Vector2f pos, sf::Font& font) {
	text.setFont(font);
	text.setString(label);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::White);
	text.setPosition(pos);
}

void Button::render(sf::RenderTarget& target) {
	target.draw(text);
}

bool Button::isHovered(const sf::Vector2f& mousePos) const {
	return text.getGlobalBounds().contains(mousePos);
}

bool Button::isClicked(const sf::Vector2f& mousePos) const {
	return isHovered(mousePos); 
}

void Button::setColor(const sf::Color& color) {
	text.setFillColor(color);
}

