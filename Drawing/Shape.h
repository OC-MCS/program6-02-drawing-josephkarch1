#pragma once
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed
struct shapeData
{
	int colorNumber;
	Vector2f position;
	ShapeEnum shape3;
};

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	Vector2f location;
	Color color1;
	ShapeEnum shape1;
	shapeData shapeData1;

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

	shapeData getShapeData()
	{
		return shapeData1;
	}
};

// add Circle, Square classes below. These are derived from DrawingShape

class circle : public DrawingShape
{
public:
	CircleShape newCircle;

	circle(Vector2f location1, Color color2, ShapeEnum shape2) : DrawingShape(location1, color2, shape2)
	{
		newCircle.setPosition(location1);
		newCircle.setRadius(20.0);
		newCircle.setOutlineThickness(3);
		newCircle.setOutlineColor(color2);
		newCircle.setFillColor(color2);
	}

	void draw(RenderWindow &window)
	{
		window.draw(newCircle);
	}
};

class square : public DrawingShape
{
public:
	RectangleShape newSquare;

	square(Vector2f location1, Color color2, ShapeEnum shape2) : DrawingShape(location1, color2, shape2)
	{
		newSquare.setPosition(location1);
		newSquare.setOutlineColor(color2);
		newSquare.setOutlineThickness(3);
		newSquare.setSize(Vector2f(30, 30));
		newSquare.setFillColor(color2);
	}

	void draw(RenderWindow &window)
	{
		window.draw(newSquare);
	}
};

