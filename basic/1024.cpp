#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
	string a;
	int i;
	cin >> a;
	unsigned int l = a.length();
	if(a[0] == '-'){
		cout << '-';
	}
	int index_e = a.find('E'); //E的索引
	string e = a.substr(index_e + 2, l - index_e - 2);
	int power;
	stringstream ss(e);
    ss >> power; 
	if(a[index_e + 1] == '+'){
		if(power < index_e - 3){
			cout << a[1] << a.substr(3, power) << '.' << a.substr(3 + power, index_e - 3 - power);
		}else{
			cout << a[1] << a.substr(3, index_e - 3) << string(power - index_e + 3, '0');
		}
	}else{
		if(power){
			cout << "0." << string(power - 1, '0') << a[1] << a.substr(3, index_e - 3);
		}else{
			//要考虑指数为0的情况，很蛋疼的一个测试点
			cout << a[1] << '.' << a.substr(3, index_e - 3);
		}
		
	}
	system("pause");
}