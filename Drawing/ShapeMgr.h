#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	
public:
	vector <DrawingShape*> shapeHolder;

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		if (whichShape == CIRCLE)
		{
			circle* newCircle;

			newCircle = new circle(pos, color, whichShape);
			shapeHolder.push_back(newCircle);
		}

		if (whichShape == SQUARE)
		{
			square* newSquare;
			newSquare = new square(pos, color, whichShape);
			shapeHolder.push_back(newSquare);
		}


		
	}
	void outputFile(fstream &outputFile1)
	{
		for (int x = 0; x < shapeHolder.size(); x++)
		{
			outputFile1.write(reinterpret_cast<char*>(&shapeHolder[x]->getShapeData()), sizeof(shapeHolder[x]->getShapeData()));
		}
		
	}

	void inputFile(fstream &inputFile1)
	{
		int tempColor = 0;
		Color tempColor1;
		Vector2f tempVector2f;
		ShapeEnum tempShape = CIRCLE;

		while (inputFile1.read(reinterpret_cast<char*>(&tempColor), sizeof(tempColor)))
		{
			inputFile1.read(reinterpret_cast<char*>(&tempVector2f), sizeof(tempVector2f));
			inputFile1.read(reinterpret_cast<char*>(&tempShape), sizeof(tempShape));

			Color aColor(tempColor);
			tempColor1 = aColor;
			addShape(tempVector2f, tempShape, tempColor1);

		}
	}
};


