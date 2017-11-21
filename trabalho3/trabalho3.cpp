#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

#define MAX 31
#define INF 912345678

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

void prim(int G[][MAX], int n, ii p[]){
  int u,v;
  priority_queue<ii, vector<ii>, greater<ii> > Q;
  Q.push(ii(0 ,0)); p[0].first = 0;
  while(!Q.empty()){
    u = Q.top().second; Q.pop();
    for(v = 0; v < n; v++)
      if(G[u][v] > 0 && p[v].first > G[u][v] && p[u].second != v){
	p[v] = ii(G[u][v], u);
	Q.push(ii(G[u][v], v));
      }
  }
}
int find(int u, int k[]){
  if(k[u] == u) return u;
  return find(k[u], k); 
}


void union_(int u, int v, int k[]){
  u = find(u, k);
  v = find(v, k);
  k[v] = u;
}



int kruskal(vector<iii> K, int k[], ii T[]){
  int i, u, v, e, p, t = 0;
  p = 0;
  priority_queue<iii, vector<iii>, greater<iii> > Q;
  for( i = 0; i < (int) K.size(); i++)
    Q.push(K[i]);
  while(!Q.empty()){
    e = Q.top().first; u = Q.top().second.second;
    v = Q.top().second.first; Q.pop();
    if(find(u, k) != find(v, k)){
      T[t++] = ii(v, u);
      p += e;
      union_(u, v, k);
    }
  }
  return p;
}

int main(){
  int G[MAX][MAX], i, j, n, p_c, k[MAX], e, u, v; 
  ii p[MAX], T[MAX];
  vector<iii> K;
  scanf("%d",&n);
  for(i = 0; i <  n; i++){
    for(j = 0; j < n; j++)
      scanf("%d", &G[i][j]);
    p[i] = ii(INF, -1);
  }
  prim(G, n, p);
  printf("Prim:\n");
  for(p_c = i = 0; i < n + 1; i++){
    p_c += p[i].first;
    printf("%d %d -> %d\n",p[i].first, i, p[i].second);
  }
  printf("%d\n",p_c);
  for(i = 0; i < MAX; i++) k[i] = i;
  scanf("%d", &n);
  while( scanf("%d %d %d", &e, &u, &v) != EOF) K.push_back(iii(e, ii(u, v)));

  printf("Kruskal:\n%d\n",kruskal(K,k, T));
  for(i = 0; i < n - 1; i++) printf("%d -> %d\n", T[i].first, T[i].second);
  return 0;
}
