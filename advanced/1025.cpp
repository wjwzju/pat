//排序
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define MAX_NUM 30000

struct ranklist
{
    int location_number; //考场号
    int score; //分数
    int local_rank; //考场内排名
    char reg_num[14]; //准考证号
}list[MAX_NUM];

bool cmp(ranklist a, ranklist b){
    if(a.score != b.score) return a.score > b.score; //分数从高到低
    else return strcmp(a.reg_num, b.reg_num) < 0; //准考证号从小到大
}

int main(){
    int i, j, N, K, idx=0, start, end=0, rank = 1; 
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &K);
        for(j = 0; j < K; j++){
            scanf("%s %d", &list[idx].reg_num, &list[idx].score);
            list[idx].location_number = i + 1;
            list[idx].local_rank = -1;
            idx++;
        }
        start = end;
        end = idx;
        sort(list + start, list + end, cmp);
        list[start].local_rank = 1;
        for(j = start + 1; j < end; j++){
            if(list[j].score == list[j - 1].score) {
                list[j].local_rank = list[j - 1].local_rank;
            }else {
                list[j].local_rank = j - start + 1;
            }
        }
    }
    sort(list, list + idx, cmp);
    printf("%d", idx);
    printf("\n%s %d %d %d", list[0].reg_num, rank, list[0].location_number, list[0].local_rank);
    for(i = 1; i < idx; i++){
        if(list[i].score != list[i - 1].score){
            rank = i + 1;
        }
        printf("\n%s %d %d %d", list[i].reg_num, rank, list[i].location_number, list[i].local_rank);
    }
    system("pause");
    return 0;
}