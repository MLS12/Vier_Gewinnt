#include <iostream>
#include "matchfield_controller.h"

int main() {
	matchfield_controller match;

	if (!match.game()) {
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}