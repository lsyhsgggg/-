#include<iostream>
using namespace std;
string arr[101];//����һ���ַ�������,���ں������ַ���
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {//ѭ��n�β����ַ���
		string gg;
		for (int j = 0; j < 8; j++) {
			cin >> gg;
			arr[i] += gg;/*��arr[i]������һ�����̵��ַ���(��ѧ���Լ��ĸ���, forѭ���޷���������, ��һ��ѭ����һ�ε����ݾͻ�����,
			����ĳЩ������ǿ�����������һ������ÿ��ѭ����������ȥ,Ҳ�ͱ���������)*/
		}
		//������Ӧ�ðѸոձ�����ַ�����ȥ�Ա�
		int jishuqi = 1;//��������¼���ִ���,Ĭ��������ִ���Ϊ1;
		for (int k = 0; k < i; k++) {
			if (arr[i] == arr[k]) { jishuqi++; }
		}//�Ա�,����
		cout << jishuqi << endl;//������ִ���
	}
	return 0;
}