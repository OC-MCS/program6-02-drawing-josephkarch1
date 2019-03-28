#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

// finish this code; add functions, data as needed

class SettingsMgr
{
private:
	Color startingColor1;
	ShapeEnum startingShape1;
	
public:
	SettingsMgr()
	{
		startingColor1 = Color::Black;
		startingShape1 = CIRCLE;
	}

	SettingsMgr(Color startingColor, ShapeEnum startingShape )
	{
		startingColor1 = startingColor;
		startingShape1 = startingShape;
	}

	Color getCurColor()
	{
		return startingColor1;  
	}


	ShapeEnum getCurShape()
	{
		return startingShape1;
	}


	void setCurColor(Color startingColor)
	{
		startingColor1 = startingColor;
	}


	void setCurShape(ShapeEnum startingShape)
	{
		startingShape1 = startingShape;
	}

	void loadData(fstream &inputFile1)
	{
		int temp = 0;
		inputFile1.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		Color aColor(temp);
		startingColor1 = aColor;
		inputFile1.read(reinterpret_cast<char*>(&startingShape1), sizeof(startingShape1));
		
	}

	void saveData(fstream &outputFile1)
	{
		int tempColor2 = 0;
		tempColor2 = startingColor1.toInteger();
		outputFile1.write(reinterpret_cast<char*>(&tempColor2), sizeof(tempColor2));
		outputFile1.write(reinterpret_cast<char*>(&startingShape1), sizeof(startingShape1));
	}
};
