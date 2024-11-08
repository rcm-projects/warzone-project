// ------------------------------------------
// Written by Ruairi Connor-Mondor (40248427)
// Fall 2024
// ------------------------------------------


#include <iostream>
#include "GameEngine.h"


void testGameStates() {
	GameEngine engine;
	engine.Run();
}


//---------------------------------------------------------
//             Game startup phase
//---------------------------------------------------------

void testStartupPhase(){
    GameEngine engine;
    engine.startupPhase();

}


int main() {
	//testGameStates();
	testStartupPhase();
}
