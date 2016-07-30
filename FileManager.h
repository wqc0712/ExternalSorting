//
// Created by Tom Wang on 16/7/16.
//

#ifndef EXTERNALSORTING_FILEMANAGER_H
#define EXTERNALSORTING_FILEMANAGER_H

#include <cstdio>
#include <queue>
#include <string>
#include <map>
#include <set>
#include "Buffer.h"
using namespace std;

struct IO_stat{
    size_t TotalFilesCreate;
    size_t TotalFilesDelete;
    size_t TotalBlockRead;
    size_t TotalBlockWrite;
    size_t TotalSeek;
    IO_stat();
    string to_string() const;
};

class FileManager{
private:
    FILE* Pointer;
    size_t FileSize;
    size_t PointerPosition;
    string FileName;
    bool CreateFile();
    bool CloseFile();
    bool DestroyFile();
    bool Writable;
public:
    FileManager();
    FileManager(string Name);
    ~FileManager();
    size_t ReadFromFile(Buffer* buffer, size_t* Size);
    size_t WriteToFile(Buffer* buffer,size_t Size);
    size_t SeekFile(size_t Position);
    bool FinishWrite();
};

IO_stat statistic;

#endif //EXTERNALSORTING_FILEMANAGER_H
