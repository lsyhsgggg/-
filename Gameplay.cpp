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
		(*it).resize(cols, 0);//����Ϊ�㣬��ʾû�з���
	}

	data2.resize(rows);
	vector<vector<int>>::iterator itt = data2.begin();
	for (; itt != data2.end(); itt++) {
		(*itt).resize(cols, 0);//����Ϊ�㣬��ʾû�з���
	}
}

void Gameplay::init()
{
	this->delay = 500;
	//����һ�����������
	srand(time(NULL));
	//���ƴ���
	initgraph(350, 700);
	//��ʼ����Ϸ����
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			data[i][j] = 0;
		}
	}
}
void Gameplay::play()
{
	init();
	//��������
	curBlock = new Block;
	nextBlock = new Block;
	//��ʱ��
	int timer = 0;
	bool flagg = false;
	while (1) {

		//�����û�����(ע�⵽ʱ���Ż�һ���û������ƶ���ʱ��������Ⱦ)
		clickmes(timer);
		timer += getDelay();
		if (timer >= delay) {

			timer = 0;
			drop();
			//������Ϸ����
			rewindow();
			//������Ϸ����
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
	//����һ���ά����i
	for (vector<int>::iterator it = data[i].begin(); it != data[i].end(); it++)
		//�ж����һ���Ƿ�������������ˣ������棬���򷵻ؼ�
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
					//������Ϸ����
					rewindow();
					//������Ϸ����
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
					//������Ϸ����
					rewindow();
					//������Ϸ����
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
			//������Ϸ����
			rewindow();
			//������Ϸ����
			clear();
			break;
		case 32:

			turnn();
			timer = 0;
			drop();
			//������Ϸ����
			rewindow();
			//������Ϸ����
			clear();

			//to  Do

			break;
		}

	}
}


void Gameplay::rewindow()//������Ϸ����
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

	int i = rows - 1;//ɨ��ָ��
	int k = rows - 1;//�洢ָ��
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
