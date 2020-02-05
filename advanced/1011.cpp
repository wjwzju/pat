#include <cstdio>

int main(){
    int i, j, max_idx, idx[3];
    double max_odd, odd, sum = 1;
    char t[4] = "WTL";
    for(j = 0; j < 3; j++){
        max_odd = 0;
        for(i = 0; i < 3; i++){
            scanf("%lf", &odd);
            if(odd > max_odd){
                max_odd = odd;
                max_idx = i;
            }
        }
        sum *= max_odd;
        idx[j] = max_idx;
    }
    for(i = 0; i < 3; i++){
        printf("%c ", t[idx[i]]);
    }
    sum = (sum * 0.65 - 1) * 2;
    printf("%.2lf", sum);
    return 0;
}