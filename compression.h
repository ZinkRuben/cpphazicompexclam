//
// Created by Zear on 6/2/2023.
//

#ifndef FILE_COMP___COMPRESSION_H
#define FILE_COMP___COMPRESSION_H
#include "read_from_file.h"
class os {
};


using namespace std;
class compression {
public:
    void compress(string read_from, string write_to, map<string, string>);
    void decompress(string read_from, string write_to);
};


#endif //FILE_COMP___COMPRESSION_H
