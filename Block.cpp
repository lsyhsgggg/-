#include "Block.h"
#include"Gameplay.h"
#include<iostream>
#include<vector>
IMAGE* Block::imgs[7] = { NULL };
int Block::size = 35;


Block::Block()
{
	if (imgs[0] == NULL) {
		/*loadimage(new IMAGE, "./source/红色方块.png",this->size,this->size);*/
		imgs[0] = new IMAGE;
		loadimage(imgs[0], "./source/红色方块.png", this->size, this->size);
		imgs[1] = new IMAGE;
		loadimage(imgs[1], "./source/黄色方块.png", this->size, this->size);
		imgs[2] = new IMAGE;
		loadimage(imgs[2], "./source/绿色方块.png", this->size, this->size);
		imgs[3] = new IMAGE;
		loadimage(imgs[3], "./source/紫色方块.png", this->size, this->size);
		imgs[4] = new IMAGE;
		loadimage(imgs[4], "./source/紫色方块.png", this->size, this->size);
		imgs[5] = new IMAGE;
		loadimage(imgs[5], "./source/黄色方块.png", this->size, this->size);
		imgs[6] = new IMAGE;
		loadimage(imgs[6], "./source/红色方块.png", this->size, this->size);
	}
	int blocks[7][4] = {
	1,3,5,7,
	2,4,5,7,
	3,5,4,6,
	3,5,4,7,
	2,3,5,7,
	3,5,7,6,
	2,3,4,5
	};
	blockType = rand() % 7 + 1;//1~7
	//初始化blockpos;
	for (int i = 0; i < 4; i++) {
		int value = blocks[blockType - 1][i];
		Blockpos[i].y = value / 2;
		Blockpos[i].x = value % 2;
	}
	blockimage = imgs[blockType - 1];
	this->vv = 1;
}
void Block::move_RL()
{

}
void Block::move_D()
{
	for (int i = 0; i < 4; i++) {
		this->Blockpos[i].y += vv;
	}
}
int Block::turn(int rows, int cols)
{
	Block beiyong = *this;
	int temp1 = 0;
	int temp2 = 0;
	Pos p = Blockpos[1];
	for (int i = 0; i < 4; i++) {
		Pos tmp = Blockpos[i];
		temp1 = this->Blockpos[i].x;
		temp1 = p.x - tmp.y + p.y;
		if (temp1 < 0 || temp1 > cols - 1) {
			*this = beiyong;
			break;
		}
		else {
			this->Blockpos[i].x = temp1;
		}

		temp2 = this->Blockpos[i].y;
		temp2 = p.y + tmp.x - p.x;
		if (temp2 < 0 || temp2 > rows - 1) {
			*this = beiyong;
			break;
		}
		else this->Blockpos[i].y = temp2;
	}
	return 0;
}

void Block::draw()
{

	//分别画四个
	for (int i = 0; i < 4; i++) {
		putimage(Blockpos[i].x * (this->size), Blockpos[i].y * (this->size), this->blockimage);
	}
}

void Block::drawNext()
{
	//分别画四个
	for (int i = 0; i < 4; i++) {
		putimage((Blockpos[i].x + 8) * (this->size), Blockpos[i].y * (this->size), this->blockimage);
	}
}

void Block::judge()
{


}

IMAGE** Block::getPic()
{
	return imgs;

}




void Block::stop_Move()
{
	vv = 0;
}
