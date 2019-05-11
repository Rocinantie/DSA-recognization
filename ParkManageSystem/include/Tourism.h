//
// Created by Rocinantie on 2019/4/30.
//

#pragma once

class Tourism
{
public:
	// 创建图
	void createGraph(void);
	// 得到景点信息
	void getSpotInfo();
	// 生成导航路线
	void travelPath();
	// 搜索最短路径
	void findShortPath();
};