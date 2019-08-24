#include <iostream>
#include <string>
using namespace std;

int main(){
	string Week[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
	string s1, s2, s3, s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int index = 0, count = 0;
	int length1, length2;
	length1 = (s1.length() > s2.length())? s2.length():s1.length();
	length2 = (s3.length() > s4.length())? s4.length():s3.length();
	for(int i = 0; i < length1; i++){
		if(count == 1 && s1[i] == s2[i]){
			if(s1[i] <= '9' && s1[i] >= '0'){
				//printf("%02d:", s1[i]-'0');
				cout << '0' << s1[i]-'0' << ':';
				break;
			}else{
				if(s1[i] >= 'A' && s1[i] <= 'N'){
					cout << s1[i]-55 << ':';
					break;
				}
			}
		}
		if(count == 0 && (s1[i] >= 'A' && s1[i] <= 'Z') && s1[i] == s2[i]){
			count ++;
			cout << Week[s1[i] - 'A'] << ' ';
		}
	}
	for(int i = 0; i < length2; i++){
		if(((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')) && s3[i] == s4[i]){
			//printf("%02d", i);
			if(i < 10){
				cout << '0' << i;
			}else{
				cout << i;
			}
			break;
		}
	}

	system("pause");
}