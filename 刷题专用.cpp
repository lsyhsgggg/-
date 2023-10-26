#include<iostream>
using namespace std;
int main(){
	int arr1[7];//存放中奖代码
	int arr2[7];//存放奖票号码
	int arr3[7] = {0};//存放中奖情况
	int n;
	cin >> n;
	for (int i = 0; i < 7; i++) {
		int j;
		cin >> j;
		arr1[i] = j;
	}//存放中奖代码
	
	
		for (int l = 0; l < n; l++) {
			
				for (int j = 0; j < 7; j++) {
					int k;
					cin >> k;
					arr2[j] = k;
				}//存放奖票号码
			int num = 0;
			for (int a = 0; a < 7; a++) {
				for (int b = 0; b < 7; b++) {
					if (arr1[a] == arr2[b]) {
						num++;
					}
				}
			}
			if(num!=0) arr3[num - 1]++;
		}
	
	
	for (int i = 6; i >= 0; i--) {
		cout << arr3[i] << " ";
	}
	return 0;
}
