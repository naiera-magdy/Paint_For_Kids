#include "ByShapeAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
//constructor
ByShapeAction::ByShapeAction(ApplicationManager * pApp) :Action(pApp)
{
	Correct = 0;
	Wrong = 0;
	FIG_TYPE = EMPTY_TYPE;
	Terminate = 0;

	// Auto-saving:
	SaveAction* Save = new SaveAction(pManager);
	Save->QuickSave();
}
//functions of ByShapeAction are very close to ByColorAction 
//function ReadActionParameters gets user actions and analyze them
void ByShapeAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Point P;
	if (pIn->GetUserAction(P) == COL_SHP)
	{
		Terminate = 1;
		return;
	}
	CFigure* Clicked = pManager->GetFigure(P.x, P.y);
	if (!Clicked)
		return;
	if (Clicked->getType() == FIG_TYPE)
	{
		Correct++;
		pManager->DeleteFigure(Clicked);
		PlaySound(TEXT("Sounds/CorrectAnswer.wav"), NULL, SND_FILENAME);
		pManager->UpdateInterface();
	}
	else
	{
		Wrong++;
		PlaySound(TEXT("Sounds/WrongAnswer.wav"), NULL, SND_FILENAME);

	}
}
//function Play tells the user which color he should pick and analyzes his action
bool ByShapeAction::Play()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	FIG_TYPE = pManager->RandomFigure();
	pOut->PrintMessage("Pick " + Display(FIG_TYPE) + ", Click to start!");
	pIn->GetUserAction();
	pOut->PrintMessage("Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	while (pManager->HasFigure(FIG_TYPE))
	{
		ReadActionParameters();
		if (Terminate)
			return false;
		pOut->PrintMessage("Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	}
	return true;
}
//function Reset resets the game
void ByShapeAction::Reset()
{
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Game Restarted!");
	pManager->ClearFigures();
	LoadAction* Load = new LoadAction(pManager);
	Load->QuickLoad();
}
//function Execute redraws playtoolbar, calls Play until the game ends
void ByShapeAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreatePlayToolBar();
	pOut->playOnToolbar("images\\MenuItems\\col_shp_selected.jpg", ITM_COL_SHP);
	while (!pManager->Empty())
		if (!Play())
		{
			Reset();
			return;
		}
	pOut->PrintMessage("Game Over! Final Score ==> Correct: " + to_string(Correct) + "    Wrong: " + to_string(Wrong));
	PlaySound(TEXT("Sounds/GameFinished.wav"), NULL, SND_FILENAME);

	// Auto-Loading:
	LoadAction* Load = new LoadAction(pManager);
	Load->QuickLoad();
}