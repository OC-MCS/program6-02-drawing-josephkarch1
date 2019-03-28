#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

void die(string msg);

class SettingsUI
{
private:
	CircleShape blueBtn;
	CircleShape redBtn;
	CircleShape greenBtn;
	RectangleShape squareBtn;
	CircleShape circleBtn;
	SettingsMgr *settingsMGR;

public:
	// all the buttons and borders are here



	SettingsUI(SettingsMgr *mgr)
	{
		settingsMGR = mgr;
		// define blue button
		Vector2f pos1(80, 100);
		blueBtn.setPosition(pos1);
		blueBtn.setRadius(10);
		blueBtn.setOutlineThickness(2);
		blueBtn.setOutlineColor(Color::Blue);
		blueBtn.setFillColor(Color::Transparent);

		// define red button
		Vector2f pos2(80, 200);
		redBtn.setPosition(pos2);
		redBtn.setRadius(10);
		redBtn.setOutlineThickness(2);
		redBtn.setOutlineColor(Color::Red);
		redBtn.setFillColor(Color::Transparent);

		// draw green button
		Vector2f pos3(80, 300);
		greenBtn.setPosition(pos3);
		greenBtn.setRadius(10);
		greenBtn.setOutlineThickness(2);
		greenBtn.setOutlineColor(Color::Green);
		greenBtn.setFillColor(Color::Transparent);

		// define square shape selection button
		Vector2f sqPos1(80, 425);
		squareBtn.setPosition(sqPos1);
		squareBtn.setOutlineColor(Color::White);
		squareBtn.setOutlineThickness(2);
		squareBtn.setSize(Vector2f(15, 15));
		squareBtn.setFillColor(Color::Transparent);

		// define circle shape selection button
		Vector2f pos4(80, 525);
		circleBtn.setPosition(pos4);
		circleBtn.setRadius(10);
		circleBtn.setOutlineThickness(2);
		circleBtn.setOutlineColor(Color::White);
		circleBtn.setFillColor(Color::Transparent);
	}


	void handleMouseUp(Vector2f mouse)
	{
		if (blueBtn.getGlobalBounds().contains(mouse))
		{
			blueBtn.setFillColor(Color::Blue);
			settingsMGR->setCurColor(Color::Blue);

			redBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}

		if (redBtn.getGlobalBounds().contains(mouse))
		{
			redBtn.setFillColor(Color::Red);
			settingsMGR->setCurColor(Color::Red);

			blueBtn.setFillColor(Color::Transparent);
			greenBtn.setFillColor(Color::Transparent);
		}

		if (greenBtn.getGlobalBounds().contains(mouse))
		{
			greenBtn.setFillColor(Color::Green);
			settingsMGR->setCurColor(Color::Green);

			redBtn.setFillColor(Color::Transparent);
			blueBtn.setFillColor(Color::Transparent);
		}

		if (squareBtn.getGlobalBounds().contains(mouse))
		{
			squareBtn.setFillColor(Color::White);
			settingsMGR->setCurShape(SQUARE);

			circleBtn.setFillColor(Color::Transparent);
		}

		if (circleBtn.getGlobalBounds().contains(mouse))
		{
			circleBtn.setFillColor(Color::White);
			settingsMGR->setCurShape(CIRCLE);

			squareBtn.setFillColor(Color::Transparent);
		}
	}

	void draw(RenderWindow& win)
	{
		if (settingsMGR->getCurColor() == Color::Blue)
		{
			blueBtn.setFillColor(Color::Blue);
		}

		if (settingsMGR->getCurColor() == Color::Red)
		{
			redBtn.setFillColor(Color::Red);
		}

		if (settingsMGR->getCurColor() == Color::Green)
		{
			greenBtn.setFillColor(Color::Green);
		}

		if (settingsMGR->getCurShape() == SQUARE)
		{
			squareBtn.setFillColor(Color::White);
		}

		if (settingsMGR->getCurShape() == CIRCLE)
		{
			circleBtn.setFillColor(Color::White);
		}


		// first have to load font
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");

		// draw selected color menu title
		Text title1("Selected Color", font, 25);
		title1.setPosition(30, 25);
		win.draw(title1);

		// define buttons
		win.draw(redBtn);
		win.draw(blueBtn);
		win.draw(greenBtn);

		// draw selected shape menu title
		Text title2("Selected Shape", font, 25);
		title2.setPosition(30, 350);
		win.draw(title2);

		// draw square shape selection button
		win.draw(squareBtn);

		// draw circle shape selection button 
		win.draw(circleBtn);

		
	}

};

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}