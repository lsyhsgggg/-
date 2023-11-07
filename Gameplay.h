#pragma once
#include<vector>
#include<easyx.h>
#include"Block.h"
using namespace std;
class Gameplay
{
	friend class Block;

public:
	Gameplay(int y, int x);
	void init();//初始化
	void play();//开始游戏
	vector<vector<int>>& returnData();

private:
	int delay;
	int rows;//窗口行数
	int cols;//窗口列数
	static int Blocksize;
	vector<vector<int>> data;
	vector<vector<int>> data2;
	Block* curBlock;
	Block* nextBlock;
	Block Beiyong;


	bool Borderjudge();
	bool crash_BorderL();
	bool crash_BorderR();
	bool Crashblock_R();
	bool Crashblock_L();
	bool IsFull(int i);

	//
	void clickmes(int timer);
	void rewindow();
	int getDelay();//返回距离上一次调用这个函数，过了多少时间（ms）
	void drop();
	void clear();
	void turnn();
	void Swap();



};

