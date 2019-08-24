#include <iostream>

using namespace std;

char find_max(int a[], int n){
	int max = a[0], index = 0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] > max){
			index = i;
			max = a[i];
		}
	}
	if(index == 0){
		return 'B';
	}else if(index == 1){
		return 'C';
	}else{
		return 'J';
	}
}

int main(){
	int n, a[3] = {0}, b[3] = {0};
	int count1 = 0, count2 = 0, count3 = 0;
	char c1, c2;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		cin >> c1 >> c2;
		//scanf("%c%c", &c1, &c2);
		if(c1 == 'B'){
			if(c2 == 'B'){
				count3++;
			}else if(c2 == 'C'){
				count1++;
				a[0]++;
			}else if(c2 == 'J'){
				count2++;
				b[2]++;
			}
		}else if(c1 == 'C'){
			if(c2 == 'B'){
				count2++;
				b[0]++;
			}else if(c2 == 'C'){
				count3++;
			}else if(c2 == 'J'){
				count1++;
				a[1]++;
			}
		}else if(c1 == 'J'){
			if(c2 == 'B'){
				count1++;
				a[2]++;
			}else if(c2 == 'C'){
				count2++;
				b[1]++;
			}else if(c2 == 'J'){
				count3++;
			}
		}
	}
	printf("%d %d %d\n", count1, count3, count2);
	printf("%d %d %d\n", count2, count3, count1);
	printf("%c %c\n", find_max(a, 3), find_max(b, 3));
	system("pause");
}
