//
// Created by Bruno on 10/08/2018.
//

#include <string>
#include "TestClass.h"

std::string TestClass::getHelloString(std::string input) {
    std::string hello = "Hello " + input;
    return hello;
}
