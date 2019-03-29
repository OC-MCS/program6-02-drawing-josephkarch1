#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "ShapeMgr.h"

// finish this code; add functions, data as needed

class DrawingUI
{
private:
	RectangleShape outerBorder;		// drawingShape which provides the borders for the entire program UI
	RectangleShape leftBorder;		// drawingShape which divides the left and right areas of the UI into settings and drawing canvas
public:

	DrawingUI(Vector2f p)
	{

	}

//================================================================================
// draw: this draws the drawing canvas, the shapes on the canvas, and the borders around it
// parameters: renderWindow, ShapeMgr*
// return type: void
//================================================================================
	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		// Draw outter border
		Vector2f sqPos2(10, 10);
		outerBorder.setPosition(sqPos2);
		outerBorder.setOutlineColor(Color::White);
		outerBorder.setOutlineThickness(3);
		outerBorder.setSize(Vector2f(780, 580));
		outerBorder.setFillColor(Color::Transparent);
		win.draw(outerBorder);

		// Draw left border for settings menu
		Vector2f sqPos3(10, 10);
		leftBorder.setPosition(sqPos3);
		leftBorder.setOutlineColor(Color::White);
		leftBorder.setOutlineThickness(3);
		leftBorder.setSize(Vector2f(250, 580));
		leftBorder.setFillColor(Color::Transparent);
		win.draw(leftBorder);

		for (int x = 0; x < mgr->shapeHolder.size(); x++)
		{
			mgr->shapeHolder[x]->draw(win);
		}
	}
	
//================================================================================
// isMouseInCanvas: this function checks to see if the mouse is inside the drawing canvas
// parameters: Vector2f
// return type: bool
//================================================================================
	bool isMouseInCanvas(Vector2f mousePos)
	{
		if (mousePos.x >= 260 && mousePos.x <= 750 && mousePos.y >= 11 && mousePos.y <= 550)
		{
			return true;
		}
		else
		{
			return false; 
		}
		
	}

};

