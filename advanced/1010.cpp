#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long int to_decimal(char n[], int radix){
    int i, len = strlen(n);
    long long int sum = 0;
    for(i = 0; i < len; i++){
        sum = sum * radix + ((n[i] - '0' > 10)? n[i] - '0' - 39: n[i] - '0');
    }
    return sum;
}

int main(){
    char n1[11], n2[11], tmp[11];
    int tag, radix, i;
    scanf("%s %s %d %d", &n1, &n2, &tag, &radix);
    long long int s1;
    bool imp = true;
    int len, r;
    long long int min_r = 1;
    if(tag == 2){
        strcpy(tmp, n2);
        strcpy(n2, n1);
        strcpy(n1, tmp);
    }
    s1 = to_decimal(n1, radix);
    len = strlen(n2);
    for(i = 0; i < len; i++){
        r = (n2[i] - '0' > 10)? n2[i] - '0' - 39: n2[i] - '0';
        min_r = (r > min_r)? r: min_r;
    }
    //进制上限的确定， 二分法查找， 未知进制转化为十进制数的时候可能会溢出
    long long int low = min_r + 1;
    long long int high = max(min_r + 1, s1 + 1);
    long long int mid, tm;
    while (low <= high){
        mid = (low + high) / 2;
        tm = to_decimal(n2, mid);
        if(s1 == tm){
            printf("%lld", mid);
            imp = false;
            break;
        }else if(tm > s1 || tm < 0){
            high = mid - 1;
        }else if(tm < s1){
            low = mid + 1;
        }
    }
    if(imp){
        printf("Impossible");
    }
    return 0;
}