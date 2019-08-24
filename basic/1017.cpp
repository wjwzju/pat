#include <iostream>
#include <string>
using namespace std;

int main(){
	string a;
	int b, num, q = 0;
	cin >> a >> b;
	for (unsigned int i = 0; i < a.length(); ++i)
	{
		num = a[i] - '0';
		if(a.length() == 1){
			cout << (10 * q + num) / b;
		}else if(i || (10 * q + num) / b){
			cout << (10 * q + num) / b;
		}
		q = (10 * q + num) % b;	
	}
	cout << ' ' << q;
	system("pause");
}