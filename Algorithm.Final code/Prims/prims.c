#include <stdio.h>
#define MAX 20
#define INF 999
int main() {
 int n, i, j, cost[MAX][MAX], visited[MAX] = {0};
 int edge = 1, min, totalCost = 0;
 int node1, node2, u, v;
 printf("Enter the number of nodes: ");
 scanf("%d", &n);
 printf("Enter the adjacency matrix: \n");
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 scanf("%d", &cost[i][j]);
 if (cost[i][j] == 0) {
 cost[i][j] = INF;
 }
 }
 }
 visited[0] = 1;
 while (edge < n) {
 min = INF;
 for (i = 0; i < n; i++) {
 for (j = 0; j < n; j++) {
 if (cost[i][j] < min && visited[i]) {
 min = cost[i][j];
 node1 = u = i;
 node2 = v = j;
 }
 }
 }
 if (visited[u] == 0 || visited[v] == 0) {
 printf("Edge %d: (%d - %d) = %d\n", edge++, node1 + 1, node2 +
1, min);
 totalCost += min;
 visited[node2] = 1;
 }
 cost[node1][node2] = cost[node2][node1] = INF;
 }
 printf("The minimum cost = %d\n", totalCost);
 return 0;
}
