#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class gg {
public:
	string data;
	int len;
	int num;
};//����һ���࣬������԰���һ���ַ���������ݣ�һ����������ַ������ȣ�����λ����������һ��������Ŷ������������±�
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
			arr[i].data += "0";//�����ж��������ĩβ���㣬�������������ַ���������ͬ��
		}
	}
	sort(&arr[1], &arr[1] + n, cmp);//�Ƚϲ�ͬ�ַ����Ĵ�С���Ӵ�С�ź���
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < arr[i].len; j++) {
			cout << arr[i].data[j];
		}
		}
}