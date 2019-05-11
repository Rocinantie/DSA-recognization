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
    cout << "------- ������Ϣ����ϵͳ -------\n1.������������ͼ\n2.��ѯ������Ϣ\n3.���ξ��㵼��\n4.�������·��\n5.������¹滮\n0.�˳�\n";
    // tourism.createGraph();
    cout << "����������ѡ��0~5��\n";
    while (cin >> choice)
    {
        switch (choice)
        {
        case 1:
            cout << "------- ������������ͼ -------\n";
            tourism.createGraph();
            cout << "��������ͼ������ϣ�\n";
            break;
        case 2:
            cout << "------- ��ѯ������Ϣ -------\n";
            tourism.getSpotInfo();
            break;
        case 3:
            cout << "------- ���ξ��㵼�� -------\n";
            tourism.travelPath();
            break;
        case 4:
            cout << "------- �������·�� -------\n";
            tourism.findShortPath();
            break;
        case 5:
            cout << "------- ������¹滮 -------\n";
            break;
        case 0:
            cout << "------- ��лʹ�� -------\n";
            break;
        default:
            break;
        }
        if (choice == 0)
            break;
        cout << "��������������ѡ��0~5��\n";
    }
    system("pause");
    return 0;
}