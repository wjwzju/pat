#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXI = 100001;

struct TNode{
    int amount;
    vector<int> child;
};

vector<TNode> Node;
double p, r;
double total = 0;
//dfs
void dfs(int root, int depth){
    if(Node[root].amount){
        //叶节点
        total += Node[root].amount * p * pow(1 + r / 100, depth);
    }else{
        for(int i = 0; i < Node[root].child.size(); i++){
            dfs(Node[root].child[i], depth + 1);
        }
    }
}

int main(){
    int n, k, i, j, id;
    scanf("%d %lf %lf", &n, &p, &r);
    Node.resize(n);
    for(i = 0; i < n; i++){
        scanf("%d", &k);
        if(k == 0){
            scanf("%d", &Node[i].amount);
        }else{
            for(j = 0; j < k; j++){
                scanf("%d", &id);
                Node[i].child.push_back(id);
            }
        }
    }
    dfs(0, 0);
    printf("%.1f", total);
    return 0;
}