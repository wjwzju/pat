#include <iostream>
#include <cstring>

#define MAX 1001

int main(){
	float p1[MAX], p2[MAX], p3[MAX];
	memset(p1, 0 , sizeof(p1));
	memset(p2, 0, sizeof(p2));
	memset(p3, 0, sizeof(p3));
	int n1, n2, i, k, count = 0;
	scanf("%d", &n1);
	for(i = 0; i < n1; i++){
		scanf("%d", &k);
		scanf("%f", &p1[k]);
	}
	scanf("%d", &n2);
	for(i = 0; i < n2; i++){
		scanf("%d", &k);
		scanf("%f", &p2[k]);
	}
	for(i = 0; i < MAX; i++){
		p3[i] = p1[i] + p2[i];
		if(p3[i]){
			count++;
		}
	}
	printf("%d", count);
	for(i = MAX - 1; i >= 0; i--){
		if(p3[i]){
			printf(" %d", i);
			printf(" %.1f", p3[i]);
		}
	}
	system("pause");
}