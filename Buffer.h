//
// Created by Tom Wang on 16/7/16.
//

#ifndef EXTERNALSORTING_BUFFER_H
#define EXTERNALSORTING_BUFFER_H
#include "ConstDefine.h"

class Buffer{
private:
    int buffer[M+20];
    int size;
public:
    int SortBlock();
    int WriteBuffer(int* WriteData,int size);
    bool IsFull();
    Buffer();
    ~Buffer();
};

#endif //EXTERNALSORTING_BUFFER_H
