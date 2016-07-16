//
// Created by Tom Wang on 16/7/16.
//

#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include "CreateRandomFile.h"

using namespace std;

int main(int argc, char* argv) {
    if (argc < 2) {
        CreateRandomNumber();
    } else {
        SortFile();
    }
}