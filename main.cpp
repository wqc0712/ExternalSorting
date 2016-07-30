//
// Created by Tom Wang on 16/7/16.
//

#include <iostream>
#include <cstring>
#include <set>
#include <map>
#include "CreateRandomFile.h"
#include "Buffer.h"
#include "FileManager.h"

using namespace std;

int main(int argc, char** argv) {
    Buffer buffer;
    FileManager file("TestFile");
    for (int i = 0;i < M;i++) {
        int T = rand()%100000;
        buffer.WriteBuffer(&T,1);
    }

}