#include <iostream>

struct TNode{
	int lchild;
	int rsibling;
	int level;
};

int main(){
	int n, m, i, j, id, k;
	int a[100], l[101] = {0};
	struct TNode t[101];
	t[1].level = 1;
	scanf("%d %d", &n, &m);
	for(i = 1; i <= n; i++){
		t[i].lchild = -1;
		t[i].rsibling = -1;
	}
	for(i = 1; i <= m; i++){
		scanf("%d %d", &id, &k);
		for(j = 0; j < k; j++){
			scanf("%d", &a[j]);
		}
		t[id].lchild = a[0];
		t[a[0]].level = t[id].level + 1;
		for(j = 0; j < k - 1; j++){
			t[a[j]].rsibling = a[j + 1];
			t[a[j + 1]].level = t[a[j]].level;
		}
	}

	for(i = 1; i <= n; i++){
		//printf("%d %d %d %d\n", i, t[i].lchild, t[i].rsibling, t[i].level);
		if(t[i].lchild == -1){
			l[t[i].level]++;
		}
	}
	printf("%d", l[1]);
	int max_level = 1;
	for(i = 1; i <= n; i++){
		max_level = (max_level > t[i].level)? max_level: t[i].level;
	}
	for(i = 2; i <= max_level; i++){
		printf(" %d", l[i]);
	}
	system("pause");
}