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
    std::cout << "请输入要查询的景点\n";
    std::cin >> choice;
    std::cout << graph.getVex(choice).name << "\n"
              << graph.getVex(choice).description << "\n";
    std::cout<<"---- 周边景点 ----\n";
    graph.findEdge(choice);
}