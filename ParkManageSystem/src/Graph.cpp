//
// Created by Rocinantie on 2019/4/30.
//

#include "../include/Graph.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int number;

// 初始化边的数目
void Graph::init()
{
    FILE *pFile;
    int c;
    pFile = fopen("Edge.txt", "r");
    while ((c = fgetc(pFile)) != EOF)
    {
        if (c == '\n')
            number++;
    }
}

// 为边分配内存空间
// Edge *pEdge = new Edge[number];
Edge pEdge[10];

// 初始化景点信息
void Graph::initialize()
{
    ifstream inputVex("Vex.txt");
    ifstream inputEdge("Edge.txt");
    inputVex >> vexNum;

    for (int i = 0; i < vexNum; i++)
    {
        inputVex >> vexs[i].num >> vexs[i].name >> vexs[i].description;
    }
    for (int i = 0; i < number; i++)
    {
        inputEdge >> pEdge[i].vex1 >> pEdge[i].vex2 >> pEdge[i].weight;
        ajdMatrix[pEdge[i].vex1][pEdge[i].vex2] = pEdge[i].weight;
        ajdMatrix[pEdge[i].vex2][pEdge[i].vex1] = pEdge[i].weight;
    }
}

// 打印景点信息
void Graph::print()
{
    cout << "景点数目：" << vexNum << endl;
    cout << "---- 景点信息 ----\n";
    for (int i = 0; i < vexNum; i++)
    {
        cout << i << "-" << vexs[i].name << endl;
    }
    cout << "---- 边 ----\n";
    for (int i = 0; i < number; i++)
    {
        cout << "<v" << pEdge[i].vex1 << ",v" << pEdge[i].vex2 << ">"
             << " " << pEdge[i].weight << endl;
    }
}
// 返回景点信息
Vex Graph::getVex(int v)
{
    return vexs[v];
}

int Graph::findEdge(int v)
{
    int k = 0;
    for (int i = 0; i < vexNum; i++)
    {
        if (ajdMatrix[v][i] != 0)
        {
            cout << vexs[v].name << " --> " << vexs[i].name << " " << ajdMatrix[v][i] << "m " << vexs[i].description << endl;
            k++;
        }
    }
    return k;
}