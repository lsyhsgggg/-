#pragma once
#include<easyx.h>

struct Pos {
	int y;//��
	int x;//��
};
class Block
{
	friend class Gameplay;

	//ȫ�ֵģ�
	static IMAGE* imgs[7];
	static int size;

	//

	int blockType;//������״
	Pos Blockpos[4];//�����λ��
	IMAGE* blockimage;
	int vv;//�����½����ٶ�


public:
	Block();// ��ʼ������
	void move_RL();//�����ƶ�
	void move_D();//���ƶ�
	int turn(int j, int k);//��ת����
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

