#include <iostream>
#include "Symulation.h"

int main(int argc, char *argv[]) {
    Symulation s(argv[1], argv[2]);
	int turns = atoi(argv[3]);
    s.turn(turns);
    //s.check();
    return 0;
}
