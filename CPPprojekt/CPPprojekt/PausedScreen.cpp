#include "PausedScreen.h"

#include <string>
#include <array>

void PausedScreen::initVariables()
{
	if (!this->font.loadFromFile("Fonts/RobotoBlackItalic-LmMD.ttf"))
		throw("FAILED TO OPEN FONT");
}

PausedScreen::PausedScreen()
{
	this->initVariables();
}

int PausedScreen::wasButtonClicked(sf::Vector2i* mousePos)
{
	sf::Vector2f mousePosF((float)mousePos->x, (float)mousePos->y);
	for (int i = 0; i < std::size(buttons); ++i)
	{
		if (buttons[i].isClicked(mousePosF))
			return i + 1;
	}
	return 0;
}

void PausedScreen::initButtons(const sf::RenderTarget* target)
{
	float vahe = target->getSize().x / 12.f;
	float x = target->getSize().x / 4.f;
	float y = target->getSize().y / 2.f;
	std::string labels[] = { "Continue", "To levels", "Reset"};

	for (int i = 0; i < std::size(labels); ++i)
	{
		sf::Vector2f position(
			x + i * (100.f + vahe), // 100.f nuppude vahe
			y
		);

		Button button(labels[i], position, this->font);
		buttons.push_back(button);
	}
}

void PausedScreen::update(const sf::RenderTarget* target)
{

}

void PausedScreen::render(sf::RenderTarget& target)
{
	for (auto el : this->buttons)
		el.render(target);
}