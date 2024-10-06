#include <stdio.h>
#define MAX 100
typedef struct
 {
 int u, v, w;
}
Edge;
Edge edges[MAX];
int parent[MAX], n, e;
int find(int i)
{
 return (parent[i] == i) ? i : find(parent[i]);
}
void unionSets(int u, int v)
{
 parent[u] = v;
}
void sortEdges()
 {
 for (int i = 0; i < e - 1; i++) {
 for (int j = 0; j < e - i - 1; j++)
    {
 if (edges[j].w > edges[j + 1].w)
 {
 Edge temp = edges[j];
 edges[j] = edges[j + 1];
 edges[j + 1] = temp;
 }
 }
 }
}
void kruskal()
{
 int mst_weight = 0;
 sortEdges();
 for (int i = 0; i < n; i++) parent[i] = i;
 for (int i = 0; i < e; i++)
    {
 int u = find(edges[i].u);
 int v = find(edges[i].v);
 if (u != v)
 {
 printf("Edge (%d, %d) -> Weight: %d\n", edges[i].u, edges[i].v,
edges[i].w);
 mst_weight += edges[i].w;
 unionSets(u, v);
 }
 }
 printf("Total weight of MST: %d\n", mst_weight);
}
int main() {
 printf("Enter the number of vertex: ");
 scanf("%d", &n);
 printf("Enter the number of edges: ");
 scanf("%d", &e);

 for (int i = 0; i < e; i++) {
 printf("Enter edge (u, v, w): ");
 scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
 }
 kruskal();
 return 0;
}

