#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int i, n;
    vector<int> a;
    scanf("%d", &n);
    a.resize(n);
    int sum = -1, tmp_sum = 0, start = 0, end = n - 1, tmp_start = 0;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        tmp_sum += a[i];
        if(tmp_sum > sum){
            end = i;
            start = tmp_start;
            sum = tmp_sum;
        }
        if(tmp_sum < 0){
            tmp_sum = 0;
            tmp_start = i + 1;
        }
    }
    printf("%d %d %d", (sum < 0)? 0: sum, a[start], a[end]);
    return 0;
}