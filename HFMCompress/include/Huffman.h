//
// Created by Rocinantie on 2019/4/23.
//

#include<string>

using namespace std;
struct nodeData {
    int key, value;
    string code;
};

struct HuffNode {
    HuffNode *parent;
    HuffNode *left;
    HuffNode *right;
    nodeData data;

    HuffNode() {
        data.key = -1;
        data.value = -1;
        parent = this;
        left = this;
        right = this;
    }

    HuffNode(int w) {
        data.key = -1;
        data.value = w;
        parent = this;
        left = this;
        right = this;
    }

    HuffNode(int i, int w) {
        data.key = i;
        data.value = w;
        parent = this;
        left = this;
        right = this;
    }
};

class Huffman {
private:
    nodeData data[256];
    HuffNode *node[256];
    int num, nodeSize;
public:
    nodeData *getData();

    int getNum();

    Huffman(string path);

    HuffNode *makeHuffTree();

    void makeHuffCode(HuffNode *p, string s);

    HuffNode *select(int i);

    ~Huffman();
};

