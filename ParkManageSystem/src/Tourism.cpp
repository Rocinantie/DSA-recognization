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
    std::cout << "-请输入要查询的景点\n";
    std::cin >> choice;
    std::cout << graph.getVex(choice).name << "\n"
              << graph.getVex(choice).description << "\n";
    std::cout << "---- 周边景点 ----\n";
    graph.findEdge(choice);
}

void Tourism::travelPath()
{
    int choice;
    int num = graph.getVexNumber();
    pathList myList = new Path;
    pathList phead = myList;
    std::cout << "景点数目为：" << num << std::endl;
    for (int i = 0; i < 7; i++)
    {
        std::cout << i << "-" << graph.getVex(i).name << std::endl;
    }
    std::cout << "-请输入起始景点\n";
    std::cin >> choice;
    graph.DFSTraverse(choice, myList);
    std::cout << "-导航路线为\n";
    int i = 1;
    myList = phead;
    while (myList->pNext)
    {
        Vex myVex = graph.getVex(myList->vexs[0]);
        std::cout << "-路线" << i++ << ": " << myVex.name;
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