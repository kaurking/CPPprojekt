#include "LevelSelectScreen.h"

#include <string>
#include <array>

void LevelSelectScreen::initVariables()
{
	if (!this->font.loadFromFile("../Fonts/RobotoBlackItalic-LmMD.ttf"))
		throw("FAILED TO OPEN FONT");
}

int LevelSelectScreen::wasButtonClicked(sf::Vector2i* mousePos)
{
	sf::Vector2f mousePosF((float)mousePos->x, (float)mousePos->y);
	for (int i = 0; i < std::size(buttons); ++i)
	{
		if (buttons[i].getGlobalBounds().contains(mousePosF))
			return i + 1;
	}
	return 0;
}

void LevelSelectScreen::initButtons(const sf::RenderTarget* target)
{
	float vahe = target->getSize().x / 12.f;
	float x = target->getSize().x / 4.f;
	float y = target->getSize().y / 2.f;
	std::string labels[] = {"Level 1", "Level 2", "Level 3"};

	for (int i = 0; i < std::size(labels); ++i)
	{
		sf::Text button;
		button.setFont(this->font);
		button.setString(labels[i]);
		button.setCharacterSize(24);
		button.setFillColor(sf::Color::White);
		button.setPosition(x + i * (button.getGlobalBounds().width + vahe), y);
		buttons.push_back(button);
	}
}

LevelSelectScreen::LevelSelectScreen()
{
	this->initVariables();
}

void LevelSelectScreen::update(const sf::RenderTarget* target)
{

}

void LevelSelectScreen::render(sf::RenderTarget* target)
{
	for (auto el : this->buttons)
		target->draw(el);
}
