//
// Created by Rocinantie on 2019/4/30.
//

#include "Graph.h"
#include "Tourism.h"
#include <iostream>

Graph graph;

void Tourism::createGraph()
{
    graph.init();
    graph.initialize();
    graph.print();
}

void Tourism::getSpotInfo()
{
    int choice;
    for (int i = 0; i < 7; i++)
    {
        std::cout << i << "-" << graph.getVex(i).name << std::endl;
    }
    std::cout << "-������Ҫ��ѯ�ľ���\n";
    std::cin >> choice;
    std::cout << graph.getVex(choice).name << "\n"
              << graph.getVex(choice).description << "\n";
    std::cout << "---- �ܱ߾��� ----\n";
    graph.findEdge(choice);
}

void Tourism::travelPath()
{
    int choice;
    int num = graph.getVexNumber();
    pathList myList = new Path;
    pathList phead = myList;
    std::cout << "������ĿΪ��" << num << std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << i << "-" << graph.getVex(i).name << std::endl;
    }
    std::cout << "-��������ʼ����\n";
    std::cin >> choice;
    graph.DFSTraverse(choice, myList);
    std::cout << "-����·��Ϊ\n";
    int i = 1;
    myList = phead;
    while (myList->pNext)
    {
        Vex myVex = graph.getVex(myList->vexs[0]);
        std::cout << "-·��" << i++ << ": " << myVex.name;
        for (int j = 1; j < num; ++j)
        {
            myVex = graph.getVex(myList->vexs[j]);
            std::cout << " -> " << myVex.name;
        }
        std::cout << "\n";

        Path *temp = myList;
        myList = myList->pNext;
        delete temp;
    }
    delete myList;
    myList = nullptr;
    phead = nullptr;
}