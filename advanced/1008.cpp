#include <cstdio>

int main(){
    int i, n, sum = 0, pre = 0, now;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &now);
        sum += (now > pre)? 6 * (now - pre) : 4 * (pre - now);
        pre = now;
    }
    sum += 5 * n;
    printf("%d", sum);
    return 0;
}
