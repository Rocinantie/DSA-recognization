//
// Created by Rocinantie on 2019/4/30.
//

#include "../include/Graph.h"
#include "../include/Tourism.h"
#include <iostream>

using namespace std;

int main()
{
    int choice;
    Tourism tourism;
    cout << "------- 景区信息管理系统 -------\n1.创建景区景点图\n2.查询景点信息\n3.旅游景点导航\n4.搜索最短路径\n5.铺设电缆规划\n0.退出\n";
    // tourism.createGraph();
    cout << "请输入您的选择（0~5）\n";
    while (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            cout << "------- 创建景区景点图 -------\n";
            tourism.createGraph();
            cout << "景区景点图创建完毕！\n";
            break;
        case 2:
            cout << "------- 查询景点信息 -------\n";
            tourism.getSpotInfo();
            break;
        case 3:
            cout << "------- 旅游景点导航 -------\n";
            tourism.travelPath();
            break;
        case 4:
            cout << "------- 搜索最短路径 -------\n";
            tourism.findShortPath();
            break;
        case 5:
            cout << "------- 铺设电缆规划 -------\n";
            break;
        case 0:
            cout << "------- 感谢使用 -------\n";
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        cout << "请重新输入您的选择（0~5）\n";
    }
    system("pause");
    return 0;
}