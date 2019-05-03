//
// Created by Rocinantie on 2019/4/30.
//

#pragma once

struct Vex
{
	int num;
	char name[20];
	char description[1024];
};

struct Edge
{
	int vex1;
	int vex2;
	int weight;
};

class Graph
{
  private:
	int ajdMatrix[20][20];
	Vex vexs[10];
	int vexNum;

  public:
	void init();
	void initialize();
	void print();
	Vex getVex(int v);
	int findEdge(int v);
};