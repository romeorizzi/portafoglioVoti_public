/**
* user:  VR411086
* fname: ZANOTTI
* lname: MATTIA
* task:  mst
* score: 100.0
* date:  2019-02-26 09:44:19.288416
*/
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 struct Edge{
     int src, dest, weight;
 };

 struct Graph{
     int V, E;

     struct Edge* edge;
 };

 struct Graph* createGraph(int V, int E){
     struct Graph* graph = new Graph;
     graph->V = V;
     graph->E = E;
     graph->edge = new Edge[E];

     return graph;
 };

 struct subset{
     int parent;
     int rank;
 };

 int find(struct subset subsets[], int i){
     if(subsets[i].parent != i){
        subsets[i].parent = find(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
 };

 void Union(struct subset subsets[], int x, int y){
     int xroot = find(subsets, x);
     int yroot = find(subsets, y);

     if(subsets[xroot].rank < subsets[yroot].rank){
        subsets[xroot].parent = yroot;
     } else if(subsets[xroot].rank > subsets[yroot].rank){
         subsets[yroot].parent = xroot;
     } else{
         subsets[yroot].parent = xroot;
         subsets[xroot].rank++;
     }
 };

 int myComp(const void* a, const void* b){
     struct Edge* a1 = (struct Edge*) a;
     struct Edge* b1 = (struct Edge*) b;

     return a1->weight > b1->weight;
 };

 int minimo(struct Graph* graph, int* C, int* D){
     int V = graph->V;
     struct Edge result[V];
     int e = 0;
     int i = 0;

     qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp);

     struct subset *subsets = (struct subset*) malloc(V * sizeof(struct subset));

     for(int v = 0 ; v < V ; ++v){
         subsets[v].parent = v;
         subsets[v].rank = 0;
     }

     while(e < V - 1){
         struct Edge next_edge = graph->edge[i++];

         int x = find(subsets, next_edge.src);
         int y = find(subsets, next_edge.dest);

         if(x != y){
             result[e++] = next_edge;
             Union(subsets, x, y);
         }
     }

     //printf("Following are the edge in the constructed MST\n");

     for(i = 0 ; i < e ; ++i){
         C[i] = result[i].src;
         D[i] = result[i].dest;
        // printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
     }

    int total_weight = 0;
     for(i = 0 ; i < e ; ++i){
         total_weight += result[i].weight;
     }

     return total_weight;
 };

int mst(int N, int M, int* A, int* B, int* P, int* C, int* D) {
	   struct Graph* graph = createGraph(N, M);

	for (int i0 = 0; i0 < M; i0++) {
		graph->edge[i0].src = A[i0];
        graph->edge[i0].dest = B[i0];
        graph->edge[i0].weight = P[i0];   
        //fscanf(fr, " %d %d %d", &graph->edge[i0].src, &graph->edge[i0].dest, &graph->edge[i0].weight);
	}
	
	return minimo(graph, C, D);
}