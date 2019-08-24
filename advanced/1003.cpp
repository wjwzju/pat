#include <iostream>
#include <algorithm>

using namespace std;

int t[501] = {0}, a[501][501];
bool visit[501];
const int inf = 9999999;
int min_depth = inf, max_team = 0, path_count = 0;

int dist[501], num[501], w[501];

void dfs(int start, int end, int n, int depth, int team_count){
	if(start == end){
		if(depth < min_depth){
			min_depth = depth;
			path_count = 1;
			max_team = team_count;
		}else if(depth == min_depth){
			path_count++;
			max_team = (team_count > max_team)? team_count: max_team;
		}
		return;
	}
	if(depth > min_depth){ //剪枝
		return;
	}
	int i;
	visit[start] = true;
	for(i = 0; i < n; i++){
		if(!visit[i]){
			visit[i] = true;
			dfs(i, end, n, depth + a[start][i], team_count + t[i]);
			visit[i] = false;
		}

	}
	return;
}

void dijkstra(int start, int end, int n){
	int min_dis, i, j, s;
	dist[start] = 0;
	for(i = 0; i < n; i++){
		s = -1, min_dis = inf;
		for(j = 0; j < n; j++){
			if(!visit[j] && dist[j] < min_dis){
				s = j;
				min_dis = dist[j];
			}
		}
		if(s == -1){
			break;
		}
		if(s == end){
            return;
        }
		visit[s] = true;
		for(j = 0; j < n; j++){
			if(!visit[j] && a[s][j] != inf){
				if(dist[s] + a[s][j] < dist[j]){
					dist[j] = dist[s] + a[s][j];
					num[j] = num[s];
					w[j] = w[s] + t[j];
				}else if(dist[s] + a[s][j] == dist[j]){
					num[j] = num[s] + num[j];
					w[j] = (w[j] > w[s] + t[j])? w[j]: w[s] + t[j]; 
				}
			}
		}
	}
	return;
}

int main(){
	int n, m, c1, c2;
	scanf("%d %d %d %d", &n, &m, &c1, &c2);
	int i, j, k;
	fill(a[0], a[0] + 501 * 501, inf);
	for(i = 0; i < n; i++){
		scanf("%d", &t[i]);
	}
	for(i = 0; i < m; i++){
		scanf("%d %d", &j, &k);
		scanf("%d", &a[j][k]);
		a[k][j] = a[j][k];
	}
	//dfs(c1, c2, n, 0, t[c1]);
	//printf("%d %d\n", path_count, max_team);

	fill(dist, dist + 501, inf);
	num[c1] = 1;
	w[c1] = t[c1];
	dijkstra(c1, c2, n);
	printf("%d %d\n", num[c2], w[c2]);
	system("pause");
}