//简单模拟
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(){
    int i, n, grade, max_grade_f = -1, min_grade_m = 101;
    char name[11], gender, ID[11], max_f_name[11], max_f_ID[11], min_m_name[11], min_m_ID[11];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s %c %s %d", name, &gender, ID, &grade);
        if(gender == 'M'){
            //男生
            if(grade < min_grade_m){
                min_grade_m = grade;
                strcpy(min_m_name, name);
                strcpy(min_m_ID, ID);
            }
        }else if(gender == 'F'){
            //女生
            if(grade > max_grade_f){
                max_grade_f = grade;
                strcpy(max_f_name, name);
                strcpy(max_f_ID, ID);
            }
        }
    }
    if(max_grade_f == -1){
        printf("Absent\n");
    }else{
        printf("%s %s\n", max_f_name, max_f_ID);
    }
    if(min_grade_m == 101){
        printf("Absent\n");
    }else{
        printf("%s %s\n", min_m_name, min_m_ID);
    }
    if(max_grade_f == -1 or min_grade_m == 101){
        printf("NA");
    }else{
        printf("%d", max_grade_f - min_grade_m);
    }
    //system("pause");
    return 0;
}