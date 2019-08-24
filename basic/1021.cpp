#include <iostream>
#include <string>

using namespace std;

int main(){
	string n;
	cin >> n;
	unsigned int i, l = n.length();
	int a[10] = {0};
	for (i = 0; i < l; ++i){
		a[n[i] - '0']++;
	}
	for(i = 0; i < 10; i++){
		if(a[i]){
			printf("%d:%d\n", i, a[i]);
		}
	}
	system("pause");
}
