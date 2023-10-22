#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class gg {
public:
	string data;
	int len;
	int num;
};//创建一个类，类的属性包括一个字符串存放数据，一个整数存放字符串长度（数据位数），还有一个整数存放对象在数组中下标
gg arr[21];
bool cmp(gg a,gg b) {
	return a.data > b.data;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string ff;
		cin >> ff;
		arr[i].data = ff;
		arr[i].len = ff.length();
		arr[i].num = i;
	}
	int maxx = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i].len > maxx) { maxx = arr[i].len; }
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (maxx - arr[i].len); j++) {
			arr[i].data += "0";//将所有对象的数据末尾补零，补到与对象中最长字符串长度相同。
		}
	}
	sort(&arr[1], &arr[1] + n, cmp);//比较不同字符串的大小，从大到小排好序
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < arr[i].len; j++) {
			cout << arr[i].data[j];
		}
		}
}