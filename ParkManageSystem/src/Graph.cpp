//
// Created by Rocinantie on 2019/4/30.
//

#include "../include/Graph.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int number;

void Graph::init() {
    FILE *pFile;
    int c;
    pFile = fopen("Edge.txt", "r");
    if (pFile == nullptr) {
        perror("打开文件出错");
    }
    do {
        c = getc(pFile);
        if (c > 1600000) {
            break;
        }
        if (c == '\n') number++;
    } while (c != EOF);
    fclose(pFile);
}

Edge pEdge[10];
bool aVisited[20];

void Graph::initialize() {
    ifstream inputVex("Vex.txt");
    ifstream inputEdge("Edge.txt");
    inputVex >> vexNum;

    for (int i = 0; i < vexNum; i++) {
        inputVex >> vexs[i].num >> vexs[i].name >> vexs[i].description;
    }
    for (int i = 0; i < number; i++) {
        inputEdge >> pEdge[i].vex1 >> pEdge[i].vex2 >> pEdge[i].weight;
        ajdMatrix[pEdge[i].vex1][pEdge[i].vex2] = pEdge[i].weight;
        ajdMatrix[pEdge[i].vex2][pEdge[i].vex1] = pEdge[i].weight;
    }
}

void Graph::print() {
    cout << "景点数目：" << vexNum << endl;
    cout << "---- 景点信息 ----\n";
    for (int i = 0; i < vexNum; i++) {
        cout << i << "-" << vexs[i].name << endl;
    }
    cout << "---- 边 ----\n";
    for (int i = 0; i < number; i++) {
        cout << "<v" << pEdge[i].vex1 << ",v" << pEdge[i].vex2 << ">"
             << " " << pEdge[i].weight << endl;
    }
}
Vex Graph::getVex(int v) { return vexs[v]; }

int Graph::findEdge(int v) {
    int k = 0;
    for (int i = 0; i < vexNum; i++) {
        if (ajdMatrix[v][i] != 0) {
            cout << vexs[v].name << " --> " << vexs[i].name << " "
                 << ajdMatrix[v][i] << "m " << vexs[i].description << endl;
            k++;
        }
    }
    return k;
}

int Graph::getVexNumber() { return this->vexNum; }
void Graph::DFS(int nVex, bool bVisited[], int &index, pathList &pList) {
    aVisited[nVex] = true;
    pList->vexs[index++] = nVex;
    int all = 0;
    for (int i = 0; i < vexNum; ++i) {
        if (aVisited[i]) all++;
    }
    if (all == vexNum) {
        pList->pNext = new Path;
        for (int i = 0; i < vexNum; ++i) {
            pList->pNext->vexs[i] = pList->vexs[i];
        }
        pList = pList->pNext;
        pList->pNext = nullptr;
    } else {
        for (int i = 0; i < vexNum; ++i) {
            if (ajdMatrix[nVex][i] != 0 && !bVisited[i]) {
                DFS(i, aVisited, index, pList);
                bVisited[i] = false;
                index--;
            }
        }
    }
}

void Graph::DFSTraverse(int nVex, pathList &pList) {
    int index = 0;
    aVisited[10] = {false};
    DFS(nVex, aVisited, index, pList);
}

int Graph::findShortestPath(int vexStart, int vexEnd, Edge path[]) {
    int shortestPath[20][20];
    int shortestDistance[20];
    bool aVisited[20];
    int v;

    for (v = 0; v < vexNum; ++v) {
        aVisited[v] = false;
        if (ajdMatrix[vexStart][v]) {
            shortestDistance[v] = ajdMatrix[vexStart][v];
        } else {
            shortestDistance[v] = 0x7fffffff;
        }
        shortestPath[v][0] = vexStart;
        for (int w = 1; w < vexNum; ++w) {
            shortestPath[v][w] = -1;
        }
    }
    aVisited[vexStart] = true;
    for (int i = 1; i < vexNum; ++i) {
        int min = 0x7fffffff;
        bool add = false;
        for (int w = 0; w < vexNum; ++w) {
            if (!aVisited[w]) {
                if (shortestDistance[w] < min) {
                    v = w;
                    min = shortestDistance[w];
                    add = true;
                }
            }
        }
        if (!add) {
            break;
        }
        aVisited[v] = true;
        shortestPath[v][i] = v;
        for (int w = 0; w < vexNum; ++w) {
            if (!aVisited[w] && (min + ajdMatrix[v][w] < shortestDistance[w]) &&
                ajdMatrix[v][w] != 0) {
                shortestDistance[w] = min + ajdMatrix[v][w];
                for (int i = 0; i < vexNum; ++i) {
                    shortestPath[w][i] = shortestPath[v][i];
                }
            }
        }
    }
    int Index = 0;
    int Vex1 = vexStart;
    for (int i = 1; i < vexNum; ++i) {
        if (shortestPath[vexEnd][i] != -1) {
            path[Index].vex1 = Vex1;
            path[Index].vex2 = shortestPath[vexEnd][i];
            path[Index].weight = ajdMatrix[path[Index].vex1][path[Index].vex2];
            Vex1 = shortestPath[vexEnd][i];
            Index++;
        }
    }
    return Index;
}

void Graph::findMinTree(Edge path[]) {
    bool aVisited[20];
    for (int i = 0; i < vexNum; ++i) {
        aVisited[i] = false;
    }
    aVisited[0] = true;
    int Vex1, Vex2;
    for (int k = 0; k < vexNum - 1; ++k) {
        int min = 0x7fffffff;
        for (int i = 0; i < vexNum; ++i) {
            if (aVisited[i]) {
                for (int j = 0; j < vexNum; ++j) {
                    if (!aVisited[j]) {
                        if ((ajdMatrix[i][j] < min) && (ajdMatrix[i][j] != 0)) {
                            Vex1 = i;
                            Vex2 = j;
                            min = ajdMatrix[i][j];
                        }
                    }
                }
            }
        }
        path[k].vex1 = Vex1;
        path[k].vex2 = Vex2;
        path[k].weight = ajdMatrix[Vex1][Vex2];
        aVisited[Vex1] = true;
        aVisited[Vex2] = true;
    }
}