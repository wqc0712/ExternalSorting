//
// Created by Tom Wang on 16/7/16.
//

#include "Buffer.h"
#include <algorithm>



bool compare (int a, int b) {
    return a<b;
}

int Buffer::SortBlock() {
    std::sort(buffer,buffer+size,compare);
    return size;
}

int Buffer::WriteBuffer(int *WriteData, int Wsize) {
    std::copy(WriteData,WriteData+Wsize,buffer+size);
    size = size+Wsize;
    return size;
}