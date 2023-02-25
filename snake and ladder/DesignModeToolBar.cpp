#include "DesignModeToolBar.h"

#include "Input.h"
#include "Output.h"
#include"Grid.h"

DesignModeToolBar::DesignModeToolBar(ApplicationManager *pApp) : Action(pApp)
{
}
void DesignModeToolBar::ReadActionParameters(){

}
void DesignModeToolBar::Execute(){
 pManager->GetGrid()->GetOutput()->CreateDesignModeToolBar();
}

DesignModeToolBar::~DesignModeToolBar()
{
}
