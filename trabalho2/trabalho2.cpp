#include <stdio.h>
#include <utility>
#include <queue>
#include <vector>

using namespace std;

#define MAX 51
#define INF 112345678

typedef pair<int, int> ii;

void bfs(int G[][MAX], ii dist[], int u, int n){
  int v,fila[MAX],ini,fim;
  fila[ini = fim = 0] = u;
  dist[u].second = 0;
  dist[u].first = u;
  while(ini <= fim){
    u = fila[ini++];
    for(v = 0; v < n; v++)
      if(G[u][v] > 0 && dist[v].second > dist[u].second + 1){
	dist[v].second = dist[u].second + 1;
	dist[v].first = u;
        fila[++fim] = v;
      }
  }
}

void dijkstra(int G[][MAX], ii dist[], int u, int n){
  int v;
  priority_queue< ii, vector<ii>, greater<ii> > Q;
  dist[u].second = 0;
  dist[u].first = u;
  Q.push(ii(0, u));
  while(!Q.empty()){
    u = Q.top().second; Q.pop();
    for(v = 0; v < n; v++)
      if(G[u][v] > 0 && dist[v].second > dist[u].second + G[u][v]){
	dist[v].second = dist[u].second + G[u][v];
	dist[v].first = u;
	Q.push(ii(dist[v].second, v));
      }
  }
}

void caminho(ii dist[], int u, int v){
  if(u) caminho(dist, dist[u].first, v);
  char c;
  v > 10 ? c = 'a' : c = 'A';
  printf("%c%s", u == 20 ? c + u + 5 : c + u, u == v ? "\n" : " -> ");
}

int main(){
  int n,i,j,G[MAX][MAX];
  ii dist[MAX];
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++)
      scanf("%d",&G[i][j]);
    dist[i].second = INF;
  }
  bfs(G, dist, 0, n);
  printf("Distancia ate z: %d\n",dist[n-1].second);
  caminho(dist, n-1, n-1);
  for(i = 0; i < n; i++)
    printf("%c:%d ", i  == 20 ? 'a' + 25 : 'a' + i, dist[i].second);
  printf("\n");
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++)
      scanf("%d",&G[i][j]);
    dist[i].second = INF;
  }
  dijkstra(G, dist, 0, n);
  printf("Distancia ate G: %d\n",dist[n-1].second);
  caminho(dist, n-1, n-1);
  for(i = 0; i < n; i++)
    printf("%c:%d ", 'A' + i , dist[i].second);
  printf("\n");
  return 0;
}
  
