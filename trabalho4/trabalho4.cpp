#include<stdio.h>
#include<string.h>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair <int, int> ii;

#define MAX 29

void welsh_powell(int G[][MAX], int n, ii degree[], int color[]){
  int i, j, k, u, v, c = 1, flag;
  for(i = n -1; i >= 0; i--){
    u = degree[i].second;
    if(color[u] != -1) continue;
    color[u] = c;
    for(j = n-1; j >= 0; j--){
      v = degree[j].second;
      if(!G[u][v] && color[v] == -1){
	flag = 1;
	for(k = 0; flag && k < n; k++)
	  if(G[v][k] && color[k] == c) flag = 0;
	if(flag) color[v] = c;
      }
    }
    c++;
  }
}

int main(){
  int G[MAX][MAX],d[MAX], u, v, n, color[MAX];
  memset(d, 0, sizeof(d));
  memset(color, -1, sizeof(color));
  scanf("%d", &n);
  for(u = 0; u < n; u++)
    for(v = 0; v < n; v++){
      scanf("%d", &G[u][v]);
      if(G[u][v]) d[u]++;
    }
  ii degree[MAX];
  for(u = 0; u < n; u++)
    degree[u] = ii(d[u], u);
  sort(degree, degree+n);
  welsh_powell(G, n, degree, color);
  for(u = n-1; u >= 0; u--)
    printf("Vertice: %c Grau: %d Cor: %d\n", 'A' + degree[u].second, degree[u].first, color[degree[u].second]);
  return 0;
}
