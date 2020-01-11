// 简单模拟
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, i, j;
    int order[54];
    string cards[54];
    string cards2[54];
    string s = "SHCD";
    cin >> n;
    for(i = 0; i < 54; i++){
        cin >> order[i];
    }
    for(i = 0; i < 4; i++){
        for (j = 1; j < 14; j++){
            cards[i*13 + j - 1] = s[i] + to_string(j); 
        }
    }
    cards[52] = "J1";
    cards[53] = "J2";

    for(i = 0; i < n; i++){
        for(j = 0; j < 54; j++){
            cards2[order[j]-1] = cards[j];
        }
        for(j = 0; j < 54; j++){
            cards[j] = cards2[j];
        }
    }
    for(i = 0; i < 53; i++){
        cout << cards2[i] << " ";
    }
    cout << cards2[53];
    system("pause");
    return 0;
}