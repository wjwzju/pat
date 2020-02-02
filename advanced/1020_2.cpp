#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const int MAXI = 30;
int post_order[MAXI], in_order[MAXI];
int N;

struct node{
    int index, value;
};
vector<node> ans;
bool cmp(node a, node b){
    return a.index < b.index;
}

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
void pre(int post_left, int post_right, int in_left, int in_right, int index){
    if(post_left < post_left || in_right < in_left){
        return ;
    }
    int root_data = post_order[post_right];
    int root = post_right;
    ans.push_back({index, root_data});
    int root_idx = search(root_data); //结点在中序序列的索引
    int left_num = root_idx - in_left; //结点左子树结点数
    int right_num = in_right - root_idx; //结点右子树结点数
    pre(post_left, post_left + left_num - 1, in_left, root_idx - 1, 2 * index + 1);
    pre(post_left + left_num, post_right - 1, root_idx + 1, in_right, 2 * index + 2);
}

int main(){
    int i;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &post_order[i]);
    }
    for(i = 0; i < N; i++){
        scanf("%d", &in_order[i]);
    }
    pre(0, N - 1, 0, N - 1, 0);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d",ans[i].value);
    }
    return 0;
}