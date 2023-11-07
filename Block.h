#pragma once
#include<easyx.h>

struct Pos {
	int y;//行
	int x;//列
};
class Block
{
	friend class Gameplay;

	//全局的：
	static IMAGE* imgs[7];
	static int size;

	//

	int blockType;//方块形状
	Pos Blockpos[4];//方块的位置
	IMAGE* blockimage;
	int vv;//方块下降的速度


public:
	Block();// 初始化函数
	void move_RL();//左右移动
	void move_D();//下移动
	int turn(int j, int k);//旋转方块
	void draw();
	void drawNext();
	void judge();
	static IMAGE** getPic();
	Block& operator=(const Block& other) {
		if (&other == this) return *this;
		this->blockType = other.blockType;
		for (int i = 0; i < 4; i++) {
			this->Blockpos[i] = other.Blockpos[i];
		}
		return *this;
	}

private:

	void stop_Move();
};

