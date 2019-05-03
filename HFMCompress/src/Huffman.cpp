//
// Created by Rocinantie on 2019/4/23.
//

#include "../include/Huffman.h"
#include<string>
#include<iostream>
#include <fstream>
#include <bitset>

using namespace std;

bool isSon(HuffNode *p) {
    return (p->left == p) && (p->right == p);
}

void valueSort(nodeData a[], int l, int r) {
    if (l >= r) return;
    nodeData t = a[l];
    int i = l, j = r;
    while (i < j) {
        while ((a[j].value >= t.value) && (i < j)) j--;
        a[i] = a[j];
        while ((a[i].value <= t.value) && (i < j)) i++;
        a[j] = a[i];
    }
    a[i] = t;
    valueSort(a, l, i - 1);
    valueSort(a, i + 1, r);
}

HuffNode *Huffman::makeHuffTree() {
    nodeSize = num;
    HuffNode *p, *q, *r = new HuffNode(-2);
    for (int i = 0; i < num; i++) {
        node[i]->data = data[i];
        node[i]->left = node[i];
        node[i]->right = node[i];
        node[i]->parent = node[i];
    }
    while (nodeSize > 1) {
        p = select(0);
        q = select(1);
        int nw = p->data.value + q->data.value;
        r = new HuffNode(nw);
        r->left = p;
        r->right = q;
        p->parent = r;
        q->parent = r;
        for (int i = 0; i < nodeSize - 2; i++)
            node[i] = node[i + 2];
        int i = 0;
        for (i = 0; i < nodeSize - 2; i++)
            if (nw <= node[i]->data.value) break;
        for (int j = nodeSize - 2; j > i; j--)
            node[j] = node[j - 1];
        node[i] = r;
        nodeSize--;
    }
    return r;
}

void Huffman::makeHuffCode(HuffNode *p, string s) {
    if (isSon(p))
        for (int i = 0; i < num; i++)
            if (p->data.key == data[i].key) {
                data[i].code = s;
                break;
            }
    if (!isSon(p)) {
        makeHuffCode(p->left, s + "0");
        makeHuffCode(p->right, s + "1");
    }
}



HuffNode *Huffman::select(int i) {
    return node[i];
}

Huffman::Huffman(string path) {
    char *p = (char *) path.data();
    FILE *in = fopen(p, "rb");
    for (int i = 0; i < 256; i++) {
        data[i].key = i;
        data[i].value = 0;
        data[i].code = "";
    }
    int k = -1;
    int ch;
    while ((ch = getc(in)) != EOF) {
        bool f = false;
        for (int j = 0; j <= k; j++)
            if (data[j].key == ch) {
                data[j].value++;
                f = true;
                break;
            }
        if (f == false) {
            k++;
            data[k].key = ch;
            data[k].value++;
        }
    }
    fclose(in);
    num = k + 1;
    valueSort(data, 0, num - 1);
    for (int i = 0; i < 256; i++)
        node[i] = new HuffNode();
    makeHuffCode(makeHuffTree(), "");
}

int Huffman::getNum() {
    return num;
}

nodeData *Huffman::getData() {
    return data;
}

Huffman::~Huffman() {}
