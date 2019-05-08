//
// Created by Rocinantie on 2019/4/23.
//

#pragma once

#include <string>
#include "Huffman.h"

using namespace std;

class Compress
{
public:
    Compress();

    int calSize(Huffman h);

    void print(Huffman h, string path);

    void initCompress(string path);

    int fileSize();

    ~Compress();
};
