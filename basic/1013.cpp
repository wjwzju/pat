#include <iostream>
#include <cmath>
using namespace std;

#define MAX 10000
int primes[MAX];

void find_prime(){
	primes[0] = 2;
	primes[1] = 3;
	int i, flag = 0, index = 2;
	for(i = 4; index < MAX; i++){
		flag = 0;
		for(int j = 0; primes[j] <= sqrt(float(i)); j++){
			if((i % primes[j]) == 0){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			primes[index++] = i;
		}
	}
}

int main(){
	find_prime();
	int m, n;
	cin >> m >> n;
	int count_prime;
	m--;
	n--;
	for(count_prime = m; count_prime <= n; count_prime++){
		cout << primes[count_prime];
		if((count_prime-m)%10 != 9 && count_prime != n){
			cout << ' ';
		}else if((count_prime-m)%10 == 9){
			cout << endl;
		}
	}
	system("pause");
}