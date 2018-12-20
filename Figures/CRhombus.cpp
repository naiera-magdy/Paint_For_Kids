#include "CRhombus.h"

CRhombus::CRhombus(Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Center = P;
	FigType = RHOMBUS;
}

Point CRhombus::getCenter() 
{
	return Center;
}

void CRhombus::Draw(Output* pOut) const
{
	//Call Output::DrawRhombus to draw a rhombus on the screen	
	pOut->DrawRhombus(Center, FigGfxInfo, Selected);
}

bool CRhombus::doesItContain(int x, int y)
{
	int X = x - Center.x;
	int Y = y - Center.y;

	if (X >= -151 && X <= 151 && Y >= -81 && Y <= 81)
	{

		if (X >= 0 && X <= 151 && Y >= 0 && Y <= 81)
		{ 
			//1st quad
			if (15 * Y + 8 * X <= 1250)
				return true;
		}
		else if (X <= 0 && X >= -151 && Y >= 0 && Y <= 81)
		{ 
			//2nd quad
			if (15 * Y - 8 * X <= 1250)
				return true;
		}
		else if (X <= 0 && X >= -151 && Y <= 0 && Y >= -81)
		{ 
			//3rd quad
			if (15 * Y + 8 * X >= -1250)
				return true;
		}
		else if (X >= 0 && X <= 151 && Y <= 0 && Y >= -81) 
		{ 
			//4th quad
			if (15 * Y - 8 * X >= -1250)
				return true;
		}
	}

	return false;
}

void CRhombus::Save(ofstream &OutFile)
{
	string Info = StoreType(FigType) + " " + to_string(ID) + " " + Center.Data() + " " + FigGfxInfo.Data();
	OutFile << endl << Info;
}

void CRhombus::Load(ifstream &InFile)
{
	Point P;
	GfxInfo RhomGfxInfo;
	InFile >> ID;
	P.Read(InFile);
	RhomGfxInfo.Read(InFile);
	*this = CRhombus(P, RhomGfxInfo);
}

void CRhombus::PrintInfo(Output * pOut)
{
	string s;
	s = "ID: " + to_string(ID) + "    Center Point: (" + to_string(Center.x) + ", " + to_string(Center.y) + ")";
	pOut->PrintMessage(s);
}
