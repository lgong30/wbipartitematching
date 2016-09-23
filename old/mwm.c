#include "mwm.h"

void MWM(int N, int **B, int *S)
{
    int i, k;

    Edge edge, other_edge;

    int *Mate;

    Graph graph = NewGraph(2*N);
        
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            if (B[i][k] > 0) {
                AddEdge(graph, i + 1, k + 1 + N, B[i][k]);
            }
        }
    }
 
    /* perform MWM */
    Mate = Weighted_Match((intptr_t)graph, 1);

    /* read results */
    for (i = 0; i < N; i++) {
        if (Mate[i+1] > 0) {
            if ((Mate[i+1] - 1 - N) < 0) {
                (void) fprintf(stderr, "ERROR: MWM 4\n");
                (void) exit(-1);
            }
            S[i] = Mate[i+1] - 1 - N;
        } else {
            S[i] = -1;
        }
    } 
    free(Mate); 
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            if (B[i][k] > 0) {
                edge = FindEdge(graph, i + 1, k + 1 + N);
                // other_edge = edge = FindEdge(graph, k + 1 + N, i + 1);
                RemoveEdge(graph, edge);
            }
        }
    } 
    free(graph);
}