#include "PlayModeToolBar.h"

#include "Input.h"
#include "Output.h"
#include"Grid.h"

PlayModeToolBar::PlayModeToolBar(ApplicationManager *pApp) : Action(pApp)
{

}
void PlayModeToolBar::ReadActionParameters(){

}
void PlayModeToolBar::Execute(){
	pManager->GetGrid()->GetOutput()->CreatePlayModeToolBar();
}

PlayModeToolBar::~PlayModeToolBar()
{
}
