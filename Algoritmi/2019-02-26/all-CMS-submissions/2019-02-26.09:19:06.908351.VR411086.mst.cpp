/**
* user:  VR411086
* fname: ZANOTTI
* lname: MATTIA
* task:  mst
* score: 0.0
* date:  2019-02-26 09:19:06.908351
*/
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

static FILE *fr, *fw;

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

 void mst(struct Graph* graph){
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

     printf("Following are the edge in the constructed MST\n");

     for(i = 0 ; i < e ; ++i){
         printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
     }

	fw = stdout;

    int total_weight = 0;
     for(i = 0 ; i < e ; ++i){
         total_weight += result[i].weight;
     }

	// Writing output
	fprintf(fw, "%d\n", total_weight);
	for (int i0 = 0; i0 < e; i0++) {
		fprintf(fw, "%d %d\n", result[i].src, result[i].dest);
	}

    fclose(fw);
     return;
 };

 int main(){
	fr = stdin;
    struct Graph* graph;

    int V;
    int E;

	// Reading input
	fscanf(fr, " %d %d", &V, &E);
	for (int i0 = 0; i0 < E; i0++) {
		fscanf(fr, " %d %d %d", &graph->edge[i0].src, &graph->edge[i0].dest, &graph->edge[i0].weight);
	}

    graph = createGraph(V, E);

    mst(graph);

    fclose(fr);
/*
     int V = 7;
     int E = 9;

    struct Graph* graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 7;

    graph->edge[1].src = 1;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 21;

    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 14;

    graph->edge[3].src = 0;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 30;

    graph->edge[4].src = 3;
    graph->edge[4].dest = 2;
    graph->edge[4].weight = 10;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 1;

    graph->edge[6].src = 4;
    graph->edge[6].dest = 5;
    graph->edge[6].weight = 6;

    graph->edge[7].src = 4;
    graph->edge[7].dest = 6;
    graph->edge[7].weight = 9;

    graph->edge[8].src = 5;
    graph->edge[8].dest = 6;
    graph->edge[8].weight = 4;

    mst(graph);
*/
    return 0;
 }