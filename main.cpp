#include<iostream>
#include<easyx.h>
#include"Gameplay.h"
#include"Block.h"
using namespace std;
bool Timer(int duration, int id)
{
	static int startTime[10];
	int endtime = clock();
	if (endtime - startTime[id] > duration) {
		startTime[id] = endtime;
		return true;
	}
	else return false;
}

int main() {
	/*Gameplay game(350, 700, 35);*/
	//initgraph(350, 700);
	//srand(time(NULL));//����һ�����������
	//Block bl;
	//
	//
	//while (1) {
	//	
	//	cleardevice();
	//	bl.judge();
	//	bl.draw();
	//	if (Timer(20, 0)) {
	//		bl.move_D();
	//	}
	//	FlushBatchDraw();
	//	
	//};
	//EndBatchDraw();
	//closegraph();       ǰ�ڲ��Դ���
	Gameplay Game(20, 10);

	Game.play();



}






