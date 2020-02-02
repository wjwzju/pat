//简单贪心
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

struct mooncake{
    float amount; //月饼总量
    float price; //价格
    float price_per; //单价
}mc[1000];

bool cmp(mooncake a, mooncake b){
    return a.price_per > b.price_per;
}

int main(){
    int i, N; float D;
    scanf("%d %f", &N, &D);
    for(i = 0; i < N; i++){
        scanf("%f", &mc[i].amount);
    }
    for(i = 0; i < N; i++){
        scanf("%f", &mc[i].price);
        mc[i].price_per = mc[i].price / mc[i].amount;
    }
    sort(mc, mc + N, cmp);
    float max_profit = 0;
    for(i = 0; D - mc[i].amount >= 0 && i < N; i++){
        max_profit += mc[i].price;
        D -= mc[i].amount;
    }
    if(i != N){    
        max_profit += mc[i].price * D / mc[i].amount;
    }
    printf("%.2f", max_profit);
    //system("pause");
    return 0;
}