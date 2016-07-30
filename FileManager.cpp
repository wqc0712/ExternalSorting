//
// Created by Tom Wang on 16/7/16.
//

#include "FileManager.h"
#include <iostream>
#include <sstream>

IO_stat::IO_stat() {
    memset(this,0,sizeof(IO_stat));
}

string IO_stat::to_string() const {
    ostringstream ans;
    ans << "dist statistic" << endl;
    ans << "total file create: " << TotalFilesCreate << endl;
    ans << "total file delete: " << TotalFilesDelete << endl;
    ans << "total block read: " << TotalBlockRead << endl;
    ans << "total block write: " << TotalBlockWrite << endl;
    ans << "total seek: " << TotalSeek << endl;
    return ans.str();
}

size_t FileManager::ReadFromFile(Buffer *buffer, size_t *Size) {
    FILE* file = Pointer;
    int temp[B+20];
    statistic.TotalBlockRead++;
    if (fread(&temp,1,(size_t)Size,file) != *Size)
        return -1;
    fflush(file);
    buffer->WriteBuffer(temp,(int)*Size);
    return 0;
}

size_t FileManager::SeekFile(size_t Position) {

}

size_t FileManager::WriteToFile(Buffer* buffer,size_t size) {
    int temp[B+20];
    statistic.TotalBlockWrite++;
    int StartPoint=0;

    //buffer->ReadBuffer()
}

bool FileManager::CreateFile() {
    if (Pointer != NULL) {
        if (!DestroyFile()) return false;
        Pointer = NULL;
    }
    statistic.TotalFilesCreate++;
    if (FileName == "") FileName = statistic.TotalFilesCreate;
    Pointer = fopen(FileName.c_str(),"wb");
    Writable = true;
    FileSize = 0;
    PointerPosition = 0;
    return true;
}

bool FileManager::DestroyFile() {
    if (Pointer == NULL)
        return true;
    CloseFile();
    if (remove(FileName.c_str())!=0) return false;
    FileName = "";
    FileSize = 0;
    PointerPosition = 0;
    Writable = false;
    Pointer=NULL;
    return true;
}

bool FileManager::CloseFile() {
    fclose(Pointer);
}

FileManager::FileManager() {
    FileName = "";
    CreateFile();
}

FileManager::FileManager(string Name) {
    FileName = "Name";
    CreateFile();
}