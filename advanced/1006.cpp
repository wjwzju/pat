#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct student{
    char ID[16];
    char in_time[9], out_time[9];
}stu[1000];

bool cmp1(student a, student b){
    return strcmp(a.in_time, b.in_time) < 0;
}

bool cmp2(student a, student b){
    return strcmp(a.out_time, b.out_time) > 0;
}

int main(){
    int i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s %s %s", &stu[i].ID, &stu[i].in_time, &stu[i].out_time);
    }
    sort(stu, stu + n, cmp1);
    printf("%s ", stu[0].ID);
    sort(stu, stu + n, cmp2);
    printf("%s", stu[0].ID);
    return 0;
}