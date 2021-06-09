#include <iostream>
#include "matchfield_controller.h"

int main() {
	matchfield_controller match;		// Erzeugen eines Objektes vom Controller

	if (!match.game()) {				// Aufruf der game-Methode des Objektes, in der alle weiteren Funktionalitäten aufgerufen werden
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}