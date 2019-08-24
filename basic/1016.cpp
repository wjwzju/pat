#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
	string a, b;
	char da, db;
	cin >> a >> da >> b >> db;
	double count1 = 0, count2 = 0;
	int suma = 0, sumb = 0;
	int numa, numb;
	unsigned int i;
	numa = da - '0';
	numb = db - '0';
	for(i = 0; i < a.length(); i++){
		if(a[i] == da){
			suma += numa * (int)pow(10,count1++);
		}
	}
	for(i = 0; i < b.length(); i++){
		if(b[i] == db){
			sumb += numb * (int)pow(10,count2++);
		}
	}
	cout << suma + sumb;
	system("pause");
}