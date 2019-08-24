#include <iostream>

using namespace std;

int main(){
	int i, a[10] = {0};
	for (i = 0; i < 10; ++i){
		scanf("%d", &a[i]);
	}
	int j, flag = 1;
	if(a[0]){
		for(i = 1; i < 10; i++){
			if(flag && a[i]){
				flag = 0;
				cout << i << string(a[0], '0');
				cout << string(a[i] - 1, i + '0');
			}else if(a[i]){
				cout << string(a[i], i + '0');
			}
		}
	}else{
		for(i = 1; i < 10; i++){
			cout << string(a[i], i + '0');
		}
	}
	system("pause");
}