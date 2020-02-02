#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXI = 100;
static int index = 0; //中序遍历时用来确定结点对应数组d的值

struct TNode{
    int data;
    int lchild;
    int rchild;
}Node[MAXI];

int d[MAXI], result[MAXI]; //输入序列， 中序遍历输出序列

//中序遍历
void mid_order(int root){
    if(root == -1){
        return;
    }
    mid_order(Node[root].lchild);
    Node[root].data = d[index++];
    mid_order(Node[root].rchild);
    return;
}

//层序遍历
void layer_order(){
    int Queue[MAXI];
    int front = 0, rear = 0, root, i = 0;
    Queue[rear++] = 0;
    while (rear > front){
        root = Queue[front++];
        //printf("%d ", Node[root].data);
        result[i++] = Node[root].data;
        if(Node[root].lchild != -1){
            Queue[rear++] = Node[root].lchild;
        }
        if(Node[root].rchild != -1){
            Queue[rear++] = Node[root].rchild;
        }
    }
}

int main(){
    int i, n, l_index, r_index;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d", &l_index, &r_index);
        Node[i].lchild = l_index;
        Node[i].rchild = r_index;
    }
    for(i = 0; i < n; i++){
        scanf("%d", &d[i]);
    }
    sort(d, d+n);
    mid_order(0);
    layer_order();
    printf("%d", result[0]);
    for (i = 1; i < n; i++){
        printf(" %d", result[i]);
    }
    //system("pause");
    return 0;
}