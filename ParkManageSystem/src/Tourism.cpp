//
// Created by Rocinantie on 2019/4/30.
//

#include "Tourism.h"
#include <iostream>
#include "Graph.h"

Graph graph;

void Tourism::createGraph() {
    graph.init();
    graph.initialize();
    graph.print();
}

void Tourism::getSpotInfo() {
    int choice;
    int num = graph.getVexNumber();
    std::cout << "������ĿΪ��" << num << std::endl;
    for (int i = 0; i < num; i++) {
        std::cout << i << "-" << graph.getVex(i).name << std::endl;
    }
    std::cout << "������Ҫ��ѯ�ľ���\n";
    std::cin >> choice;
    std::cout << graph.getVex(choice).name << "\n"
              << graph.getVex(choice).description << "\n";
    std::cout << "---- �ܱ߾��� ----\n";
    graph.findEdge(choice);
}

void Tourism::travelPath() {
    int choice;
    int num = graph.getVexNumber();
    pathList myList = new Path;
    pathList phead = myList;
    std::cout << "������ĿΪ��" << num << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << i << "-" << graph.getVex(i).name << std::endl;
    }
    std::cout << "��������ʼ����\n";
    std::cin >> choice;
    graph.DFSTraverse(choice, myList);
    std::cout << "����·��Ϊ\n";
    int i = 1;
    myList = phead;
    while (myList->pNext) {
        Vex myVex = graph.getVex(myList->vexs[0]);
        std::cout << "-·��" << i++ << ": " << myVex.name;
        for (int j = 1; j < num; ++j) {
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

void Tourism::findShortPath() {
    int num = graph.getVexNumber();
    for (int i = 0; i < num; i++) {
        std::cout << i << "-" << graph.getVex(i).name << std::endl;
    }
    int vexStart, vexEnd;
    std::cout << "�����������";
    std::cin >> vexStart;
    std::cout << "�������յ���";
    std::cin >> vexEnd;
    if (vexStart < 0 || vexStart > num || vexEnd < 0 || vexEnd > num) {
        std::cout << "��Ŵ���\n";
    }
    Edge mypath[20];
    int Num = graph.findShortestPath(vexStart, vexEnd, mypath);
    Vex vexes = graph.getVex(mypath[0].vex1);
    int Length = 0;
    std::cout << "���·��Ϊ��\n";
    std::cout << vexes.name << "->";
    for (int i = 0; i < Num; ++i) {
        vexes = graph.getVex(mypath[i].vex2);
        std::cout << vexes.name;
        if (i < Num - 1) std::cout << "->";
        Length += mypath[i].weight;
    }
    std::cout << "\n��̾���Ϊ" << Length << "\n";
}

void Tourism::pathDesign() {
    Edge mypath[20];
    graph.findMinTree(mypath);
    int allLength = 0;
    int vexNum = graph.getVexNumber();
    std::cout << "�����¸���֮���������\n";
    for (int i = 0; i < vexNum - 1; ++i) {
        Vex Vex1 = graph.getVex(mypath[i].vex1);
        Vex Vex2 = graph.getVex(mypath[i].vex2);
        std::cout << Vex1.name << " - " << Vex2.name << " " << mypath[i].weight
                  << "m\n";
        allLength += mypath[i].weight;
    }
    std::cout << "������µ��ܳ���Ϊ" << allLength << "m\n";
}