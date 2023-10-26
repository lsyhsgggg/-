#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<ctime>
using namespace std;
class ball {
	 friend void drawball(const ball& a);
	 friend void moveball(ball& a);
	 friend void crash(ball& a);
	 friend void keyborad(ball& a);
	 friend void ballcrash(ball& a, ball& b);
	 friend void kamo(ball& a);
	int x;
	int y;
	int r;
	int dx = 6;
	int dy = 4;
public:
	ball(int x,int y,int r):x(x),y(y),r(r) {
	}
};
void drawball(const ball&a) {
	setfillcolor(RED);
	solidcircle(a.x, a.y, a.r);
}
void moveball( ball&a) {
	a.x += a.dx;
	a.y -= a.dy;
}
void crash(ball&a) {
	if (a.x + a.r >= 400 || a.x - a.r <= 0) {
		a.dx *= -1;
	}
	if (a.y + a.r >= 400 || a.y - a.r <= 0){
		a.dy *= -1;
	}
}
void ballcrash(ball& a, ball& b) {
	int distance = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	int rr =(a.r + b.r) * (a.r + b.r);
	if (distance<=rr) {
		a.dx *= -1;
		a.dy *= -1;
		
	}
}
void kamo(ball& a) {//·ÀÖ¹Ð¡Çò¿¨Ä£
	char ans;
	if(a.x - a.r > 0 && a.x + a.r < 400 && a.y - a.r > 0 && a.y + a.r < 400) 
	{
		ans = 'a';
	}
	else if (a.x + a.r >= 400&& a.y - a.r > 0&& a.y+a.r<400) {
		ans = 'A';
	}
	else if (a.x + a.r >= 400&& a.y - a.r <=0) {
		ans = 'B';
	}
	else if (a.x + a.r >= 400 && a.y +a.r >=400) {
		ans = 'C';
	}
	else if (a.x-a.r>0&&a.x+a.r<400&&a.y-a.r<=0) {
		ans = 'D';
	}
	else if (a.x - a.r > 0 && a.x + a.r < 400 &&a.y+a.r>=400) {
		ans = 'E';
	}
	else if (a.x -a.r<=0 && a.y - a.r > 0 && a.y + a.r < 400) {
		ans = 'F';
	}
	else if (a.x - a.r <= 0 && a.y + a.r >= 400) {
		ans = 'G';
	}
	else if (a.x - a.r <= 0 && a.y - a.r <= 0) {
		ans = 'H';
	}
	switch (ans) {
	case 'a':
		break;
	case 'A':
		a.x = 400 - a.r;
		break;
	case 'B':
		a.x = 400 - a.r;
		a.y = a.r;
		break;
	case 'C':
		a.x = 400 - a.r;
		a.y = 400 - a.r;
		break;
	case 'D':
		a.y = a.r;
		break;
	case 'E':
		a.y = 400 - a.r;
		break;
	case 'F':
		a.x = a.r;
		break;
	case 'G':
		a.x = a.r;
		a.y = 400 - a.r;
		break;
	case 'H':
		a.x = a.r;
		a.y = a.r;
		break;
	}

}
bool Timer(int duration ,int id)
{
	static int startTime[10];
	int endtime = clock();
	if (endtime - startTime[id] > duration) {
		startTime[id] = endtime;
		return true;
	}
	else return false;
}
	void keyborad(ball&a) {
	int input = _getch();
	switch (input) {
	case'w':
	case'W':
	case 72:
		a.y -= 5;
		break;
	case'a':
	case'A':
	case 80:
		a.x -= 5;
		break;
	case's':
	case'S':
	case 75:
		a.y += 5;
		break;
	case'd':
	case'D':
	case 77:
		a.x += 5;
		break;
	}
}
int main() {
	initgraph(400, 400);
	setbkcolor(WHITE);
	ball a(50, 100, 15);
	ball b(200, 150, 15);
	BeginBatchDraw();
	while (1) {
		cleardevice();
		kamo(a);
		kamo(b);
		crash(a);
		ballcrash(a, b);
		drawball(a);
		drawball(b);
		if (Timer(20, 0)) {
			moveball(a);
		}
	  if (_kbhit()) {
	  	keyborad(b);
	  }
	  FlushBatchDraw();
	}
	EndBatchDraw();
	closegraph();
	return 0;
}