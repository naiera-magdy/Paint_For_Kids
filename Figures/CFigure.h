#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	FigureType FigType;
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	bool cut;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

	void setID(int);
	void setType(FigureType);
	FigureType getType() const;

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	void toggleSelection();

	void SetCut(bool);
	bool IsCut() const;

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	color getFillColor();
	color getDrawColor();

	bool isFilled();
	void setFilled(bool filled);
	virtual bool doesItContain(int, int) = 0;
	virtual string getInfo() = 0;

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	//virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
};

void SetFigType(CFigure *& FP, FigureType T);	//Takes a CFigure* and creates a dummy object of a passed FigureType

#endif