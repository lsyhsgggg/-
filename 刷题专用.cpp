#include<iostream>
using namespace std;
string arr[101];//定义一个字符串数组,用于后面存放字符串
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {//循环n次操作字符串
		string gg;
		for (int j = 0; j < 8; j++) {
			cin >> gg;
			arr[i] += gg;/*向arr[i]里面存放一个棋盘的字符串(初学者自己的感悟, for循环无法保存数据, 下一次循环这一次的数据就会清零,
			所以某些情况我们可以像这样找一个载体每轮循环给它加上去,也就保存了下来)*/
		}
		//接下来应该把刚刚保存的字符串拿去对比
		int jishuqi = 1;//计数器记录出现次数,默认情况出现次数为1;
		for (int k = 0; k < i; k++) {
			if (arr[i] == arr[k]) { jishuqi++; }
		}//对比,计数
		cout << jishuqi << endl;//输出出现次数
	}
	return 0;
}