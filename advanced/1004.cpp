#include<cstdio>
#include<cstdlib>

using namespace std;

const int MAXI = 101;

struct TNode{
    int lchild;
    int rsibling;
    int level;
    TNode(){
        lchild = rsibling = -1;
        level = 0;
    }
}Node[MAXI];

int main(){
    int N, M, K, i, j, id;
    int idk[MAXI];
    int count[MAXI] = {0};
    scanf("%d %d", &N, &M);
    for(i = 0; i < M; i++){
        scanf("%d %d", &id, &K);
        for(j = 0; j < K; j++){
            scanf("%d", &idk[j]);
        }
        Node[id].lchild = idk[0];
        for(j = K - 1; j > 0; j--){
            Node[idk[j-1]].rsibling = idk[j];
        }
    }
    int max_level = 0;
    for(i = 1; i <= N; i++){
        if(Node[i].lchild != -1){
            Node[Node[i].lchild].level = Node[i].level + 1;
            max_level = (max_level >= Node[i].level + 1)? max_level: Node[i].level + 1;
        }
        if(Node[i].rsibling != -1){
            Node[Node[i].rsibling].level = Node[i].level;
        }
    }
    for(i = 1; i <= N; i++){
        if(Node[i].lchild == -1){
            count[Node[i].level]++;
        }
    }
    printf("%d", count[0]);
    for(i = 1; i <= max_level; i++){
        printf(" %d", count[i]);
    }
    //system("pause");
    return 0;
}