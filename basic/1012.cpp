//
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int i, n, num;
	cin >> n;
	int count1=0, count2=0, count3=0, count5=0;
	int sum1=0, sum2=0;
	float sum4=0, count4=0;
	int max5=0;
	for (i = 0; i < n; ++i)
	{
		cin >> num;
		switch(num % 5){
			case 0:
				if(num%2 == 0){
					sum1 += num;
					count1++;
				}
				break;
			case 1:
				sum2 += (count2%2)?(0-num):num;
				count2++;
				break;
			case 2:
				count3++;
				break;
			case 3:
				sum4 += num;
				count4++;
				break;
			case 4:
				max5 = (num>max5)?num:max5;
				count5++;
				break;
			default:
				break;
		}
	}
	if(count1){
		cout << sum1 << ' ';
	}else{
		cout << "N ";
	}
	if(count2){
		cout << sum2 << ' ';
	}else{
		cout << "N ";
	}
	if(count3){
		cout << count3 << ' ';
	}else{
		cout << "N ";
	}
	if(count4){
		cout << setiosflags(ios::fixed) << setprecision(1) << float(sum4/count4) << ' ';
	}else{
		cout << "N ";
	}
	cout.unsetf( ios::fixed ); 
	if(count5){
		cout << max5;
	}else{
		cout << "N";
	}
	system("pause");
}

