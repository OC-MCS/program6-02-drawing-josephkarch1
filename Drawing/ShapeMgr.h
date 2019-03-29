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
	
vector <DrawingShape*> shapeHolder; // this is the vector that holds all the DrawingShapes

//================================================================================
// addShape: recieves Vector2f, ShapeEnum, and Color. Then it adds a DrawingShape to 
// the vector via the push_back function
// parameters: Vector2f, ShapeEnum and Color
// return type: void
//================================================================================

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

//= ==============================================================================
// outputFile: recieves fstream from the main() and writes data to the binary file 
// parameters: fstream
// return type: void
//================================================================================
	void outputFile(fstream &outputFile1)
	{
		for (int x = 0; x < shapeHolder.size(); x++)
		{
			outputFile1.write(reinterpret_cast<char*>(&shapeHolder[x]->getShapeData()), sizeof(shapeHolder[x]->getShapeData()));
		}
		
	}

//= ==============================================================================
// inputFile: recieves fstream from the main() and reads data from the binary file 
// into the shape-holding vector
// parameters: fstream
// return type: void
//================================================================================
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


