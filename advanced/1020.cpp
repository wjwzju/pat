#include<cstdio>

using namespace std;

const int MAXI = 30;
int post_order[MAXI], in_order[MAXI], result[MAXI];
int N;

struct TNode{
    int data;
    int lchild;
    int rchild;
    TNode(){
        lchild = rchild = -1;
    }
}Node[MAXI];

//在中序序列中查找元素
int search(int k){
    int i;
    for(i = 0; i < N; i++){
        if(in_order[i] == k){
            return i;
        }
    }
    return -1;
}

//根据后序序列和中序序列构建树
int create_tree(int post_left, int post_right, int in_left, int in_right){
    if(post_left < post_left || in_right < in_left){
        return -1;
    }
    int root_data = post_order[post_right];
    int root = post_right;
    Node[root].data = root_data;
    int root_idx = search(root_data); //结点在中序序列的索引
    int left_num = root_idx - in_left; //结点左子树结点数
    int right_num = in_right - root_idx; //结点右子树结点数
    Node[root].lchild = create_tree(post_left, post_left + left_num - 1, in_left, root_idx - 1);
    Node[root].rchild = create_tree(post_left + left_num, post_right - 1, root_idx + 1, in_right);
    return post_right;
}

//层序遍历
void level_order(int root){
    int Queue[MAXI];
    int front = 0, rear = 0, i = 0;
    Queue[rear++] = root;
    while (front < rear){
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
    return;
}

int main(){
    int i;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &post_order[i]);
        Node[i].data = post_order[i];
    }
    for(i = 0; i < N; i++){
        scanf("%d", &in_order[i]);
    }
    create_tree(0, N - 1, 0, N - 1);
    level_order(N - 1);
    printf("%d", result[0]);
    for (i = 1; i < N; i++){
        printf(" %d", result[i]);
    }
    return 0;
}