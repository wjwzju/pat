#include <cstdio>
#include <cstring>

char eng[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(){
    char N[101];
    scanf("%s", N);
    int sum = 0, i, j;
    for(i = 0; i < strlen(N); i++){
        sum += N[i] - '0';
    }
    i = 0;
    int res[101];
    while(sum){
        res[i++] = sum % 10;
        sum /= 10;
    }
    printf("%s", eng[res[i - 1]]);
    for(j = i - 2; j >= 0; j--){
        printf(" %s", eng[res[j]]);
    }
    return 0;
}