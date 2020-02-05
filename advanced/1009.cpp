#include <cstdio>
#include <map>

using namespace std;

struct poly{
    int exp;
    double coe;
}p1[10], p2[10];

map<int, double> p3;

int main(){
    int i, j, k1, k2;
    scanf("%d", &k1);
    for(i = 0; i < k1; i++){
        scanf("%d %lf", &p1[i].exp, &p1[i].coe);
    }
    scanf("%d", &k2);
    for(i = 0; i < k2; i++){
        scanf("%d %lf", &p2[i].exp, &p2[i].coe);
    }
    for(i = 0; i < k1; i++){
        for(j = 0; j < k2; j++){
            p3[p1[i].exp + p2[j].exp] += p1[i].coe * p2[j].coe;
        }
    }
    //要排除掉系数为0的项
    printf("%d", p3.size() - p3.count(0));
    map<int, double>::iterator iter = p3.end();
    iter--;
    for(; iter != p3.begin(); iter--){
        if(iter->second){
            printf(" %d %.1lf", iter->first, iter->second);
        }
    }
    iter = p3.begin();
    if(iter->second){
        printf(" %d %.1lf", iter->first, iter->second);
    }
    return 0;
}