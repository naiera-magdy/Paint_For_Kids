#ifndef ELPS_H
#define ELPS_H

#include "CFigure.h"
#include "..\GUI\Output.h"


class CEllipse : public CFigure
{
private:
	Point Center;
public:
	CEllipse(Point, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	Point getCenter();
	bool doesItContain(int x, int y);
	string getInfo();
	virtual void Save(ofstream &OutFile);
	virtual void Load(ifstream &Infile);
};

#endif
