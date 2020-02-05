#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 2000;

struct student{
    int id;
    int score_c, score_m, score_e;
    double score_a;
    int rank_a, rank_c, rank_m, rank_e; 
    int rank, rank_class;
    student(){
        score_c = -1;
        score_e = -1;
        score_m = -1;
        score_a = -1;
    }
}stu[MAXN];
map<int, student> stu2;

bool cmp1(student a, student b) { return a.score_a > b.score_a;}

bool cmp2(student a, student b) { return a.score_c > b.score_c;}

bool cmp3(student a, student b) { return a.score_m > b.score_m;}

bool cmp4(student a, student b) { return a.score_e > b.score_e;}

//寻找最小值
void find_min(student &s){
    int min = MAXN + 1;
    if(s.rank_e <= min){
        s.rank = s.rank_e;
        s.rank_class = 3;
        min = s.rank_e;
    }
    if(s.rank_m <= min){
        s.rank = s.rank_m;
        s.rank_class = 2;
        min = s.rank_m;
    }
    if(s.rank_c <= min){
        s.rank = s.rank_c;
        s.rank_class = 1;
        min = s.rank_c;
    }
    if(s.rank_a <= min){
        s.rank = s.rank_a;
        s.rank_class = 0;
    }
    return;
}

int main(){
    int i, m, n;
    char c[5] = "ACME";
    int s[2000];
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score_c, &stu[i].score_m, &stu[i].score_e);
        stu[i].score_a = (stu[i].score_c + stu[i].score_m + stu[i].score_e) / 3;
        //printf("%d %d %d %d %lf\n", stu[i].id, stu[i].score_c, stu[i].score_m, stu[i].score_e, stu[i].score_a);
    }
    for(i = 0; i < m; i++){
        scanf("%d", &s[i]);
    }
    //按平均分排序；
    sort(stu, stu + n, cmp1);
    stu[0].rank_a = 1;
    for(i = 1; i < n; i++){
        if(stu[i].score_a == stu[i - 1].score_a) stu[i].rank_a = stu[i - 1].rank_a;
        else stu[i].rank_a = i + 1;
    }
    //按科目c
    sort(stu, stu + n, cmp2);
    stu[0].rank_c = 1;
    for(i = 1; i < n; i++){
        if(stu[i].score_c == stu[i - 1].score_c) stu[i].rank_c = stu[i - 1].rank_c;
        else stu[i].rank_c = i + 1;
    }
    //按科目m
    sort(stu, stu + n, cmp3);    stu[0].rank_m = 1;
    for(i = 1; i < n; i++){
        if(stu[i].score_m == stu[i - 1].score_m) stu[i].rank_m = stu[i - 1].rank_m;
        else stu[i].rank_m = i + 1;
    }
    //按科目e
    sort(stu, stu + n, cmp4);
    stu[0].rank_e = 1;
    for(i = 1; i < n; i++){
        if(stu[i].score_e == stu[i - 1].score_e) stu[i].rank_e = stu[i - 1].rank_e;
        else stu[i].rank_e = i + 1;
    }
    //确定最终排名
    for(i = 0; i < n; i++){
        stu2[stu[i].id] = stu[i];
        find_min(stu2[stu[i].id]);
    }
    if(stu2[s[0]].score_c != -1){
            printf("%d %c", stu2[s[0]].rank, c[stu2[s[0]].rank_class]);
        }else{
            printf("N/A");
        }
    for(i = 1; i < m; i++){
        if(stu2[s[i]].score_c != -1){
            printf("\n%d %c", stu2[s[i]].rank, c[stu2[s[i]].rank_class]);
        }else{
            printf("\nN/A");
        }
    }
    return 0;
}
//其实map可以只存id与stu索引的对应就可以。