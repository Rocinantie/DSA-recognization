//
// Created by Rocinantie on 2019/4/30.
//

#include "../include/Graph.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int number;

void Graph::init()
{
    FILE *pFile;
    int c;
    pFile = fopen("Edge.txt", "r");
    if (pFile == nullptr)
    {
        perror("打开文件出错");
    }
    do
    {
        c = getc(pFile);
        if (c > 1600000)
        {
            break;
        }
        if (c == '\n')
            number++;
    } while (c != EOF);
    fclose(pFile);
}

Edge pEdge[10];
bool aVisited[20];

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

void Graph::print()
{
    cout << "-景点数目：" << vexNum << endl;
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

int Graph::getVexNumber()
{
    return this->vexNum;
}
void Graph::DFS(int nVex, bool bVisited[], int &index, pathList &pList)
{
    aVisited[nVex] = true;
    pList->vexs[index++] = nVex;
    int all = 0;
    for (int i = 0; i < vexNum; ++i)
    {
        if (aVisited[i])
            all++;
    }
    if (all == vexNum)
    {
        pList->pNext = new Path;
        for (int i = 0; i < vexNum; ++i)
        {
            pList->pNext->vexs[i] = pList->vexs[i];
        }
        pList = pList->pNext;
        pList->pNext = nullptr;
    }
    else
    {

        for (int i = 0; i < vexNum; ++i)
        {
            if (ajdMatrix[nVex][i] != 0 && !bVisited[i])
            {
                DFS(i, aVisited, index, pList);
                bVisited[i] = false;
                index--;
            }
        }
    }
}

void Graph::DFSTraverse(int nVex, pathList &pList)
{
    int index = 0;
    aVisited[10] = {false};
    DFS(nVex, aVisited, index, pList);
}