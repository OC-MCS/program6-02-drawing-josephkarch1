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
	Color startingColor1;			// variable to hold the setting on the UI that determines the drawing color
	ShapeEnum startingShape1;		// variable to hold the setting on the UI that determines the drawing shape
	
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
//================================================================================
// getCurColor: returns the variable that has been saved as the UI setting for the drawing color
// parameters: N/A
// return type: Color
//================================================================================
	Color getCurColor()
	{
		return startingColor1;  
	}

//================================================================================
// getCurShape: returns the variable that has been saved as the UI setting for the drawing shape
// parameters: N/A
// return type: ShapeEnum
//================================================================================
	ShapeEnum getCurShape()
	{
		return startingShape1;
	}

//================================================================================
// setCurColor: sets the startingColor1 variable that stores the color button selection for the settings UI
// parameters: Color
// return type: void
//================================================================================
	void setCurColor(Color startingColor)
	{
		startingColor1 = startingColor;
	}

//================================================================================
// setCurShape: sets the startingShape1 variable that stores the shape button selection for the settings UI
// parameters: Color
// return type: void
//================================================================================
	void setCurShape(ShapeEnum startingShape)
	{
		startingShape1 = startingShape;
	}

//================================================================================
// loadData: receives an fstream and reads the variable values 
// from the binary file and puts the values into startingShape1 and startingColor1
// parameters: fstream
// return type: void
//================================================================================
	void loadData(fstream &inputFile1)
	{
		int temp = 0;
		inputFile1.read(reinterpret_cast<char*>(&temp), sizeof(temp));
		Color aColor(temp);
		startingColor1 = aColor;
		inputFile1.read(reinterpret_cast<char*>(&startingShape1), sizeof(startingShape1));
		
	}
//================================================================================
// saveData: receives an fstream and writes the UI settings menu's variable values 
// in the binary file 
// parameters: fstream
// return type: void
//================================================================================
	void saveData(fstream &outputFile1)
	{
		int tempColor2 = 0;
		tempColor2 = startingColor1.toInteger();
		outputFile1.write(reinterpret_cast<char*>(&tempColor2), sizeof(tempColor2));
		outputFile1.write(reinterpret_cast<char*>(&startingShape1), sizeof(startingShape1));
	}
};
