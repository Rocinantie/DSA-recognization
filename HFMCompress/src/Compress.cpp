//
// Created by Rocinantie on 2019/4/23.
//

#include "../include/Compress.h"
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char str2Byte(string p)
{
    int t = 0;
    for (int i = 0; i < 8; i++)
        if (p[i] == '1')
            t = t + pow(2, 7 - i);
    char c = (char)t;
    return c;
}

void keySort(nodeData a[], int l, int r)
{
    if (l >= r)
        return;
    nodeData t = a[l];
    int i = l, j = r;
    while (i < j)
    {
        while ((a[j].key >= t.key))
            j--;
        a[i] = a[j];
        while ((a[i].key <= t.key))
            i++;
        a[j] = a[i];
    }
    a[i] = t;
    keySort(a, l, i - 1);
    keySort(a, i + 1, r);
}

Compress::Compress() {}

int Compress::calSize(Huffman h)
{
    int num = h.getNum();
    nodeData *data = h.getData();
    int size = 0;
    for (int i = 0; i < num; i++)
        size += data[i].value * data[i].code.length();
    size = (size % 8) ? size / 8 + 1 : size / 8;
    return size;
}

void Compress::print(Huffman h, string path)
{
    int size = calSize(h);
    int num = h.getNum();
    nodeData *data = h.getData();
    ofstream out(path + ".huf");
    // int s = 0;
    // cout << "BYTE\tCODE" << endl;
    for (int i = 0; i < num; i++)
    {
        // cout << "0x" << hex << data[i].key << "\t" << data[i].code << endl;
    }
    // cout << "---------------------" << endl;
    int initialSize = fileSize();
    cout << "Size after compression:" << size << " bytes." << endl;
    cout << "Compress ratio:" << double(size * 1.0 / initialSize) * 100 << " %" << endl;
    keySort(data, 0, num - 1);
    char *p = (char *)path.data();
    FILE *in = fopen(p, "rb");
    int ch;
    char cr = ' ';
    if (in == nullptr)
    {
        perror("打开文件出错");
    }
    do
    {
        ch = getc(in);
        string s = data[ch].code;
        while (s.length() >= 8)
        {
            cr = str2Byte(s);
            out << cr;
            s = s.substr(8);
        }
        if (s.length() > 0)
        {
            int t = 0;
            for (int i = 0; i < s.length(); i++)
                if (s[i] == '1')
                    t = t + pow(2, s.length() - 1 - i);
            cr = (char)t;
            out << cr;
        }
    } while (ch != EOF);

    // while ((ch = getc(in)) != EOF)
    // {
    //     string s = data[ch].code;
    //     while (s.length() >= 8)
    //     {
    //         cr = str2Byte(s);
    //         out << cr;
    //         s = s.substr(8);
    //     }
    //     if (s.length() > 0)
    //     {
    //         int t = 0;
    //         for (int i = 0; i < s.length(); i++)
    //             if (s[i] == '1')
    //                 t = t + pow(2, s.length() - 1 - i);
    //         cr = (char)t;
    //         out << cr;
    //     }
    // }
    fclose(in);
}

void Compress::initCompress(string path)
{
    Huffman h(path);
    print(h, path);
}

int Compress::fileSize()
{
    FILE *pFile;
    long size = 0;

    pFile = fopen("Pic.bmp", "rb");
    if (pFile == nullptr)
        perror("Error opening file");
    else
    {
        fseek(pFile, 0, SEEK_END);
        size = ftell(pFile);
        fclose(pFile);
        printf("Size before compression:%ld bytes.\n", size);
    }
    return size;
}

Compress::~Compress() {}
