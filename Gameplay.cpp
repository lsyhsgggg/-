#include "Gameplay.h"
#include"Block.h"
#include<ctime>
#include<iostream>
#include<ctime>
#include<conio.h>

int Gameplay::Blocksize = 35;
Gameplay::Gameplay(int rows, int cols)
{
	this->rows = rows;
	this->cols = cols;

	data.resize(rows);
	vector<vector<int>>::iterator it = data.begin();
	for (; it != data.end(); it++) {
		(*it).resize(cols, 0);//数据为零，表示没有方块
	}

	data2.resize(rows);
	vector<vector<int>>::iterator itt = data2.begin();
	for (; itt != data2.end(); itt++) {
		(*itt).resize(cols, 0);//数据为零，表示没有方块
	}
}

void Gameplay::init()
{
	this->delay = 500;
	//配置一下随机数种子
	srand(time(NULL));
	//绘制窗口
	initgraph(350, 700);
	//初始化游戏数据
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			data[i][j] = 0;
		}
	}
}
void Gameplay::play()
{
	init();
	//创建方快
	curBlock = new Block;
	nextBlock = new Block;
	//定时器
	int timer = 0;
	bool flagg = false;
	while (1) {

		//接受用户输入(注意到时候优化一下用户输入移动键时，立马渲染)
		clickmes(timer);
		timer += getDelay();
		if (timer >= delay) {

			timer = 0;
			drop();
			//更新游戏画面
			rewindow();
			//更改游戏数据
			clear();
		}

	}

}
vector<vector<int>>& Gameplay::returnData()
{
	return this->data;
}
bool Gameplay::Borderjudge()
{
	for (int i = 0; i < 4; i++) {
		int xx = curBlock->Blockpos[i].x;
		int yy = curBlock->Blockpos[i].y;
		if (yy == this->rows) return true;
		if (data[yy][xx] != 0) return true;
	}
	return false;
}
bool Gameplay::crash_BorderL()
{
	for (int i = 0; i < 4; i++) {
		if (curBlock->Blockpos[i].x == 0) return false;
	}
	return true;
}
bool Gameplay::crash_BorderR()
{
	for (int i = 0; i < 4; i++) {
		if (curBlock->Blockpos[i].x == cols - 1) return false;
	}
	return true;
}
bool Gameplay::Crashblock_R()
{
	for (int i = 0; i < 4; i++) {
		int xx = curBlock->Blockpos[i].x;
		int yy = curBlock->Blockpos[i].y;

		if (data[yy][xx + 1] != 0) return false;

	}
	return true;
}
bool Gameplay::Crashblock_L()
{
	for (int i = 0; i < 4; i++) {
		int xx = curBlock->Blockpos[i].x;
		int yy = curBlock->Blockpos[i].y;


		if (data[yy][xx - 1] != 0) return false;

	}
	return true;
}
bool Gameplay::IsFull(int i)
{
	//遍历一遍二维数组i
	for (vector<int>::iterator it = data[i].begin(); it != data[i].end(); it++)
		//判断最后一行是否已满，如果满了，返回真，否则返回假
	{
		if (*it == 0)return false;
	}


	return true;
}
void Gameplay::clickmes(int timer)
{
	int input;
	if (_kbhit()) {
		input = _getch();
		switch (input) {
		case'a':
		case'A':
			if (this->crash_BorderL()) {
				if (Crashblock_L()) {
					for (int i = 0; i < 4; i++) {
						curBlock->Blockpos[i].x -= 1;
					}
					timer = 0;
					drop();
					//更新游戏画面
					rewindow();
					//更改游戏数据
					clear();
					break;
				}

			}

			break;
		case 'D':
		case 'd':

			if (this->crash_BorderR()) {
				if (Crashblock_R()) {
					for (int i = 0; i < 4; i++) {
						curBlock->Blockpos[i].x += 1;
					}
					timer = 0;
					drop();
					//更新游戏画面
					rewindow();
					//更改游戏数据
					clear();
					break;
				}

			}
			break;
		case's':
		case'S':

			this->delay = 1500;
			timer = 0;
			drop();
			//更新游戏画面
			rewindow();
			//更改游戏数据
			clear();
			break;
		case 32:

			turnn();
			timer = 0;
			drop();
			//更新游戏画面
			rewindow();
			//更改游戏数据
			clear();

			//to  Do

			break;
		}

	}
}


void Gameplay::rewindow()//更新游戏画面
{
	cleardevice();
	BeginBatchDraw();
	IMAGE** imgs = Block::getPic();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (data[i][j] == 0) continue;
			putimage(j * Blocksize, i * Blocksize, imgs[data[i][j] - 1]);
		}
	}
	curBlock->draw();
	nextBlock->drawNext();
	EndBatchDraw();

}

int Gameplay::getDelay()
{
	static unsigned long long lastTime = 0;
	unsigned long long currentTime = GetTickCount();
	if (lastTime == 0) {
		lastTime = currentTime;
		return 0;
	}
	else {
		int gap = currentTime - lastTime;
		lastTime = currentTime;
		return gap;
	}
}

void Gameplay::drop()
{
	Beiyong = *curBlock;
	curBlock->move_D();
	this->delay = 500;

	if (this->Borderjudge()) {
		for (int i = 0; i < 4; i++) {
			data[Beiyong.Blockpos[i].y][Beiyong.Blockpos[i].x] = (Beiyong.blockType);
		}
		delete curBlock;
		curBlock = NULL;
		curBlock = nextBlock;
		nextBlock = NULL;
		nextBlock = new Block;
	}
}

void Gameplay::clear()
{
	Swap();
}

void Gameplay::turnn()
{
	Beiyong = *curBlock;
	Block beiyong2 = *curBlock;

	curBlock->turn(rows, cols);
	bool gg = false;
	for (int i = 0; i < 4; i++) {

		if (data[curBlock->Blockpos[i].y][curBlock->Blockpos[i].x] == 0) {
			gg = false;
		}
		gg = true;
	}

	if (!gg) *curBlock = Beiyong;
}

void Gameplay::Swap()
{

	int i = rows - 1;//扫描指针
	int k = rows - 1;//存储指针
	while (i >= 0) {
		if (IsFull(i)) {
			i--;

		}
		else {
			for (int g = 0; g < 10; g++) {
				data2[k][g] = data[i][g];
			}
			i--;
			k--;
		}
	}
	data = data2;

}
