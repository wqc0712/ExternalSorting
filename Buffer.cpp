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
    if (Wsize+size > M) return -1;
    std::copy(WriteData,WriteData+Wsize,buffer+size);
    size = size+Wsize;
    return size;
}

int Buffer::ReadBuffer(int *ReadData, int Wsize, int StartPoint) {
    if (size-StartPoint > Wsize) {
        std::copy(buffer + StartPoint, buffer + StartPoint + Wsize, ReadData);
        return Wsize;
    } else {
        std::copy(buffer+StartPoint,buffer+(size-StartPoint),ReadData);
        return size-StartPoint;
    }
}

bool Buffer::IsFull() {
    if (size > M) return true;
    else return false;
}

int Buffer::ReadElement(int Point) {
    return buffer[Point];
}