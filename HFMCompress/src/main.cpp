//
// Created by Rocinantie on 2019/4/23.
//

#include <iostream>
#include <fstream>
#include "../include/Compress.h"

using namespace std;

int main() {
    cout << "------ Huffman Picture Compress(Pic.bmp) ------\n";
    string filename;
    cout << "Please enter the picture path:";
    cin >> filename;
    Compress c;
    c.initCompress(filename);
    return 0;
}


