#include <cstdio>
#include <vector>

using namespace std;

vector<int> pre, in, post;
bool unique = true;

void inOrder(int pre_left, int pre_right, int post_left, int post_right){
    if(pre_left == pre_right){
        in.push_back(pre[pre_left]);
        return;
    }
    int i = pre_left + 1;
    if(pre[pre_left] == post[post_right]){
        //find(post[post_right - 1])
        while(i <= pre_right && pre[i] != post[post_right - 1]){
            i++;
        }
        //左子树
        if(i - pre_left > 1){
            //存在左子树
            inOrder(pre_left + 1, i - 1, post_left, post_left + i - pre_left - 2);
        }else{
            unique = false;
        }
        //根
        in.push_back(post[post_right]);
        //右子树
        inOrder(i, pre_right, post_left + i - pre_left - 1, post_right - 1);
    }
}

int main(){
    int n, i;
    scanf("%d", &n);
    pre.resize(n), post.resize(n);
    for(i = 0; i < n; i++){
        scanf("%d", &pre[i]);
    }
    for(i = 0; i < n; i++){
        scanf("%d", &post[i]);
    }
    inOrder(0, n - 1, 0, n - 1);
    printf("%s\n%d", unique? "Yes": "No", in[0]);
    for(i = 1; i < in.size(); i++){
        printf(" %d", in[i]);
    }
    printf("\n");//???
    return 0;
}