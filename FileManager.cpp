//
// Created by Tom Wang on 16/7/16.
//

#include "FileManager.h"

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

size_t FileManager::ReadFirstFile(Buffer *buffer, size_t *Size) {
    FILE* file = Pointer.front();
    int temp[B+20];
    statistic.TotalBlockRead++;
    if (fread(&temp,1,Size,file) != size)
        return -1;
    fflush(file);
    buffer->WriteBuffer(&temp,Size);
    return 0;
}

size_t FileManager::SeekFirstFile(size_t Position) {

}