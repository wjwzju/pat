/*这道题有一个测试点一直通过不了，最后发现，库存和售价没有规定都是整数
所以要用float而不是int(⊙o⊙)。好阴啊*/
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 1000
struct product{
	float store;
	float price;
	float per_price;
};

bool cmp(const product &a, const product &b){
	return a.per_price > b.per_price;
}

int main(){
	int n, d, i;
	struct product p[MAX];
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; ++i){
		scanf("%f", &p[i].store);
	}
	for (i = 0; i < n; ++i){
		scanf("%f", &p[i].price);
		p[i].per_price = p[i].price / p[i].store;
	}
	sort(p, p+n, cmp);
	/*for(i = 0; i < n; i++)
		printf("%d %d %f\n", p[i].store, p[i].price, p[i].per_price);*/
	float profit = 0.0;
	for(i = 0; i < n; i++){
		if(d <= p[i].store){
			profit += p[i].price / p[i].store * d;
			break;
		}else{
			profit += p[i].price;
			d -= p[i].store;
		}
	}
	printf("%.2f\n", profit);
	system("pause");
}
