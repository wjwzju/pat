//cin、cout果然耗时要比scanf和printf大得多

#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>

using namespace std;
struct student{
	int id;
	int score1;
	int score2;
}s1[100000],s2[100000],s3[100000],s4[100000];

bool cmp(const student &a, const student &b){
	if((a.score1 + a.score2) == (b.score1 + b.score2)){
		if(a.score1 != b.score1){
			return a.score1 > b.score1;
		}else{
			return a.id < b.id;
		}
	}else{
		return (a.score1 + a.score2) > (b.score1 + b.score2);
	}
}

int main(){
	//取消cin与stdin，cout与stdout的同步。减少输入输出的开销
	std::ios::sync_with_stdio(false);
	int n, l, h;
	//cin >> n >> l >> h;
	scanf("%d %d %d",&n, &l, &h);	
  	int i, id, score1, score2;
	int index1 = 0, index2 = 0, index3 = 0, index4=0;
	memset(s1,0,sizeof(s1));
	memset(s2,0,sizeof(s2));
	memset(s3,0,sizeof(s3));
	memset(s4,0,sizeof(s4));
	for(i = 0; i< n; i++){
		//cin >> id >> score1 >>score2;
		scanf("%d %d %d", &id, &score1, &score2);
		if(score1 >= l && score2 >= l){
			if(score1 >= h &&score2 >= h){
				//才德全尽
				s1[index1].id = id;
				s1[index1].score1 = score1;
				s1[index1++].score2 = score2;
			}else if(score1 >= h && score2 < h){
				//德胜才
				s2[index2].id = id;
				s2[index2].score1 = score1;
				s2[index2++].score2 = score2;
			}else if(score1 <= h && score2 <= h && score1 >= score2){
				//才德兼亡中德胜才
				s3[index3].id = id;
				s3[index3].score1 = score1;
				s3[index3++].score2 = score2;
			}else{
				//其他
				s4[index4].id = id;
				s4[index4].score1 = score1;
				s4[index4++].score2 = score2;
			}
		}
	}

	cout << index1 + index2 + index3 + index4 <<endl;

	sort(s1, s1+index1, cmp);
	sort(s2, s2+index2, cmp);
	sort(s3, s3+index3, cmp);
	sort(s4, s4+index4, cmp);

	for(i = 0; i< index1; i++){
		//cout << s1[i].id << ' ' << s1[i].score1 << ' ' << s1[i].score2 << endl;
        printf("%d %d %d\n", s1[i].id, s1[i].score1, s1[i].score2);
	}
	for(i = 0; i< index2; i++){
		//cout << s2[i].id << ' ' << s2[i].score1 << ' ' << s2[i].score2 << endl;
        printf("%d %d %d\n", s2[i].id, s2[i].score1, s2[i].score2);
	}
	for(i = 0; i< index3; i++){
		//cout << s3[i].id << ' ' << s3[i].score1 << ' ' << s3[i].score2 << endl;
        printf("%d %d %d\n", s3[i].id, s3[i].score1, s3[i].score2);
	}
	for(i = 0; i< index4; i++){
		//cout << s4[i].id << ' ' << s4[i].score1 << ' ' << s4[i].score2 << endl;
		printf("%d %d %d\n", s4[i].id, s4[i].score1, s4[i].score2);
    }
	system("pause");
}