#include <stdio.h>
#include <string.h>

#define INF 12345678

int visita_ad(int G[][10], int vis[],int u, int n){
  vis[u] = 1;
  if(u == 6){
    printf("%d com custo de ", u+1);
    return 0;
  }
  int v, V, d = INF;
  for(v = 0; v < n; v++){
    if(!vis[v] && G[u][v] > 0 && G[u][v] < d){
      d = G[u][v];
      V = v;
    }
  }
  printf("%d -> ", u+1);
  return d + visita_ad(G, vis, V, n);
}

int visita_in(int G[][10], int vis[], int u, int n, int m){
  vis[u] = 1;
  if(u == 6){
    printf("%d com custo de ", u+1);
    return 0;
  }
  int v, V, d = INF,j,J;
  for(j = 0; j < m; j++)
    if(G[u][j] > 0)
      for(v = 0; v < n; v++)
	if(!vis[v] && G[v][j] && G[u][j] < d){
	  d = G[u][j];
	  V = v;
	  J = j;
	}
  printf("%d (%c)-> ", u+1, 'a'+J);
  return d + visita_in(G, vis, V, n ,m);  
}

int main(){
  int G[10][10],vis[10],n,m,i,j;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    for(j = 0; j < n; j++)
      scanf("%d", &G[i][j]);
  memset(vis, 0, sizeof(vis));
  printf("%d\n", visita_ad(G, vis, 0, n));
  scanf("%d %d", &n, &m);
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++)
      scanf("%d", &G[i][j]);
  memset(vis, 0, sizeof(vis));
  printf("%d", visita_in(G, vis, 0, n, m));
  return 0;
}
  
