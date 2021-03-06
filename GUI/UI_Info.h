#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here


	ITM_GAME,
	ITM_RECTANGLE,		//Rectangle item in menu
	ITM_TRIANGLE,
	ITM_ELLIPSE,
	ITM_RHOMBUS,
	ITM_LINE,
	ITM_BORDER_SIZE,
	ITM_FILL_COLOR,
	ITM_DRAW_COLOR,
	ITM_UNDO,
	ITM_REDO,
	ITM_SOUND,
	ITM_EXIT,		//Exit item

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};

enum DrawMenuAction {

	ITM_LOAD,
	ITM_SAVE,
	ITM_SAVE_TYPE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DELETE,
	ITM_CLEAR,
	ITM_SELECT,
	ITM_SEND_TO_BACK,
	ITM_BRING_TO_FRONT,
	ITM_RESIZE,


	DRAW_ACTION_COUNT, //no. of menu action items

};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_DRAW,
	ITM_COL_CLR,
	ITM_COL_SHP,

	//TODO: Add more items names here

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    //Window width and height
		wx, wy,				//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth,		//Width of each item in toolbar menu
		MenuActionWidth;	//Width of each action item (copy , delete ...) in toolbar menu


	Color DrawColor;		//Drawing color
	Color FillColor;		//Filling color
	Color HighlightColor;	//Highlighting color
	Color MessageColor;		//Messages color
	Color BackgroundColor;	//Background color
	Color StatusBarColor;	//Status bar color
	int BorderSize;			//width of the pen that draws shapes

	/// Add more members if needed

}UI;	//create a global object UI

#endif