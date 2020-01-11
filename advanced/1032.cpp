#include <bits/stdc++.h>
using namespace std;
const int MAXINT  = 100010;

struct Node{
    char data;
    int next;
    bool flag;
}node[MAXINT];

int main(){
    int addr1, addr2, n;
    int addr, next;
    char data;
    int i;
    scanf("%d%d%d", &addr1, &addr2, &n);
    for(i = 0; i < MAXINT; i++){
        node[i].flag = 0;
    }
    for(i = 0; i < n; i++){
        scanf("%d %c %d", &addr, &data, &next);
        node[addr].data = data;
        node[addr].next = next;
        node[addr].flag = 0;
    }
    next = addr1;
    while(next != -1){
        node[next].flag = 1;
        next = node[next].next;
    }
    for(next = addr2; next != -1; next = node[next].next){
        if(node[next].flag){
            break;
        }
    }
    if(next == -1){
        printf("-1");
    }else{
        printf("%05d", next);
    }
    return 0;
}