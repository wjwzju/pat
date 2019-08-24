#include <iostream>
#include <algorithm>

using namespace std;

void quicksort(int a[], int low, int high){
	if(low < high){
		int poi;
		int start = low, end = high;
		poi = a[start];
		while(start < end){
			while(start < end && a[end] >= poi) {
			    end--;
			}
			a[start] = a[end];
			while(start < end && a[start] <= poi) {
			    start++;
			}
			a[end] = a[start];
		}
		a[start] = poi;
		quicksort(a, low, start-1);
		quicksort(a, start+1, high);
	}
}


int main()
{
	int n, l = 0, h = 0;
	int a[4] = {0};
	scanf("%d", &n);
	int i = 0;
	while(h - l != 6174) {
		a[0] = n % 10;
		a[1] = (n  / 10) % 10;
		a[2] = (n / 100) % 10;
		a[3] = (n / 1000) % 10;
		if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]){
			printf("%04d - %04d = %04d\n", n, n, 0);
			break;
		}
		quicksort(a, 0, 3);
		h = 1000 * a[3] +  100 * a[2] + 10 * a[1] + a[0];
		l = 1000 * a[0] +  100 * a[1] + 10 * a[2] + a[3];
		n = h - l;
		printf("%04d - %04d = %04d\n", h, l, n);
	}
	system("pause");
}