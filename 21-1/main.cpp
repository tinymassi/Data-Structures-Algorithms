// ************************************************************** //
// Main function that is used to demonstrate the functionality of //
// the Stack class                                                //
// massimoginella12@gmail.com                                     //
// ************************************************************** //

#include <iostream>
#include <fstream>
#include "stack.h"


int main() {
    Stack mystack;

    std::string line;

    while (std::getline(std::cin, line)) {
        mystack.push(line);
    }

    while (mystack.is_empty() == false) {
        std::cout << mystack.pop() << std::endl;
    }

    return 0;
}
