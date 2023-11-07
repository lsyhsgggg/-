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
	void init();//��ʼ��
	void play();//��ʼ��Ϸ
	vector<vector<int>>& returnData();

private:
	int delay;
	int rows;//��������
	int cols;//��������
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
	int getDelay();//���ؾ�����һ�ε���������������˶���ʱ�䣨ms��
	void drop();
	void clear();
	void turnn();
	void Swap();



};

