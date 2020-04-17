#include <iostream>
#include <cstdlib>

#include "Circunferencia.h"

using namespace std;

/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {

    if (argc >= 3) {
        Circunferencia uno(argv[1]);
        Circunferencia dos(argv[2]);
        
        if (uno.seIntersecta(dos)) {
            std::cout << std::endl << "Los circulos se intersectan" << std::endl;
        } else {
            std::cout << std::endl << "Los NO circulos se intersectan" << std::endl;
        }
    } else {
        return 99;
    }
    
    return 0;
}

