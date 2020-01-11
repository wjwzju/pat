// 简单模拟
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 54;
char s[5] = {'S', 'H', 'C', 'D', 'J'};

int main(){
    int n, i, j;
    int start[N], end[N], order[N];
    scanf("%d", &n);
    for(i = 0; i < N; i++){
        start[i] = i;
        scanf("%d", &order[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < N; j++){
            end[order[j]-1] = start[j];
        }
        for(j = 0; j < N; j++){
            start[j] = end[j];
        }
    }
    for(i = 0; i < N; i++){
        printf("%c%d", s[end[i]/13], end[i]%13 + 1);
        if(i != N - 1){
            printf(" ");
        }
    }
    //system("pause");
    return 0;
}