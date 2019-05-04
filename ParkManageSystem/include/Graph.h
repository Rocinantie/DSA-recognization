//
// Created by Rocinantie on 2019/4/30.
//

#pragma once

// 定义顶点结构体
struct Vex
{
	int num;
	char name[20];
	char description[1024];
};

// 定义边结构体
struct Edge
{
	int vex1;
	int vex2;
	int weight;
};

// 定义导航路径结构体
typedef struct Path
{
	int vexs[10];
	Path *pNext;
} * pathList;

// 定义图结构体
class Graph
{
private:
	// 邻接矩阵
	int ajdMatrix[20][20];
	// 顶点
	Vex vexs[10];
	//顶点数目
	int vexNum;

public:
	// 初始化
	void init();
	// 初始化图
	void initialize();
	// 打印图的信息
	void print();
	// 返回图的顶点
	int getVexNumber();
	// 返回顶点结构体
	Vex getVex(int v);
	// 查找邻接边
	int findEdge(int v);
	// 深度优先
	void DFS(int nVex, bool bVisited[], int &index, pathList &pList);
	// 深度优先遍历图
	void DFSTraverse(int nVex, pathList &pList);
};