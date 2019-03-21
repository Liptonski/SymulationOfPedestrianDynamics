#include <iostream>
#include "Symulation.h"

int main(int argc, char *argv[]) {
    Symulation s("proba2.txt", "wartosci.txt");
    s.turn(20);
    s.check();
    return 0;
}