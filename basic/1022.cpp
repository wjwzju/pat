#include <iostream>

int main(){
	int A, B, d, i = 0;
	int a[31] = {0};
	scanf("%d %d %d", &A, &B, &d);
	int c = A + B;
	if(c == 0){
		//需要考虑结果为0的情况，顺便吐槽一下牛客的测评结果真是不靠谱，测试点比pat官网少了很多
		printf("0");
	}
	while(c) {
	    a[i++] = c % d;
	    c = c / d;
	}
	for(int j = i - 1; j >= 0; j--){
		printf("%d", a[j]);
	}
	system("pause");
}