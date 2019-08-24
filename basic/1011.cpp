//问题唯一的陷阱就是给出的数值会超过int的长度限制，我还以为要用什么高级的算法模拟比较过程，后来一想直接用long行不行，果然可以..

# include<iostream>
using namespace std;

int main(){
	int n, i;
	long a, b, c;
	cin >> n;
	for(i=1; i<=n; i++){
		cin >> a >> b >> c;
		if(a + b > c){
			cout << "Case #" << i << ": true" << endl;
		}else{
			cout << "Case #" << i << ": false" << endl;
		}
	}
}