#include <iostream>

void format(int n){
	if(n < 1000){
		printf("%d", n);
	}else{
		format(n/1000);
		printf(",%03d", n%1000);
	}
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int c = a + b;
	if(c < 0){
		printf("-");
		c = 0 - c;
	}
	format(c);
	system("pause");
}