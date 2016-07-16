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

using namespace std;

struct IO_stat{
    size_t TotalFilesCreate;
    size_t TotalFilesDelete;
    size_t TotalBlockRead;
    size_t TotalBlockWrite;

    IO_stat();

    string to_string() const;
};

class FileManager{
private:
    queue<File*> Pointer;
public:
    ReadFirstFile(Buffer* buffer);
};

#endif //EXTERNALSORTING_FILEMANAGER_H
