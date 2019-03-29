#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct shapeData
{
	int colorNumber;	// this holds the color of the shape as an int value
	Vector2f position;	// this holds the x and y coords of the shape
	ShapeEnum shape3;	// this holds the shape type
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	Vector2f location;		// this holds the x and y coords of the shape
	Color color1;			// this holds the color of the shape
	ShapeEnum shape1;		// this holds the shape type
	shapeData shapeData1;	// this is a struct which holds a copy of the data for writing to the binary file

public:
	DrawingShape(Vector2f location1, Color color2, ShapeEnum shape2)
	{
		location = location1;
		color1 = color2;
		shape1 = shape2;

		shapeData1.colorNumber = color2.toInteger();
		shapeData1.position = location1;
		shapeData1.shape3 = shape2;
	}
	
	virtual void draw(RenderWindow &window) = 0;

//================================================================================
// getShapeData: returns the struct which holds the shape data so it can be exported to a binary file
// parameters: N/A
// return type: shapeData
//================================================================================
	shapeData getShapeData()
	{
		return shapeData1;
	}
};

// add Circle, Square classes below. These are derived from DrawingShape

class circle : public DrawingShape
{
public:
	CircleShape newCircle;  // instance of a new circle that is created when the user draws a circle

	circle(Vector2f location1, Color color2, ShapeEnum shape2) : DrawingShape(location1, color2, shape2)
	{
		newCircle.setPosition(location1);
		newCircle.setRadius(20.0);
		newCircle.setOutlineThickness(3);
		newCircle.setOutlineColor(color2);
		newCircle.setFillColor(color2);
	}

//================================================================================
// draw: this draws the circle
// parameters: renderWindow, 
// return type: void
//================================================================================
	void draw(RenderWindow &window)
	{
		window.draw(newCircle);
	}
};

class square : public DrawingShape
{
public:
	RectangleShape newSquare;	// instance of a new square that is created when the user draws a square

	square(Vector2f location1, Color color2, ShapeEnum shape2) : DrawingShape(location1, color2, shape2)
	{
		newSquare.setPosition(location1);
		newSquare.setOutlineColor(color2);
		newSquare.setOutlineThickness(3);
		newSquare.setSize(Vector2f(30, 30));
		newSquare.setFillColor(color2);
	}
//================================================================================
// draw: this draws the square
// parameters: renderWindow, 
// return type: void
//================================================================================
	void draw(RenderWindow &window)
	{
		window.draw(newSquare);
	}
};

