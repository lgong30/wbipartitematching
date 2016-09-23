/**Maximum Weighted matching
*/

#include <iostream>
#include <lemon/list_graph.h>
#include <lemon/matching.h>

#include "wmatching.h"
#define MWM_NOEDGE 0
#define MWM_NOMATE -1

/**\brief Maximum weighted matching for bipartite graph
 *
 *  Produces a simpler interface for bipartite maximum weighted matching
 *  for lemon c++ library.
 *
 * @param n            number of vertexes in A
 * @param m            number of vertexes in B
 * @param weights      weights of each edges, weights[i][j] i in A, j in B
 * @param mate         maximum weighted matching, length of mate is n, mate[i] in B, i in A
 * 
 */
template<class T>
T wmatch(int n, int m, T** weights, int *mate)
{
  typedef lemon::ListGraph Graph;
  typedef Graph::Node Node;
  typedef Graph::EdgeMap<T> WeightMap;
  typedef lemon::MaxWeightedMatching<Graph, WeightMap> MaxWeightedMatching;
  using lemon::INVALID;

  int tn = n + m; /* total number of vertexes */
  Graph g; 
  WeightMap weight(g);
  std::vector<Node> node_vec;

  node_vec.reserve(tn); /* node vector */

  for (int i = 0;i < tn;++ i) node_vec[i] = g.addNode(); /* add nodes and recording */

  /* add edge and its weight */
  int k; 
  for (int i = 0;i < n;++ i){
    for (int j = 0;j < m;++ j){
        k = n + j; /* output */
        if (weights[i][j] != MWM_NOEDGE)
            weight[g.addEdge(node_vec[i], node_vec[k])] = weights[i][j];
    }
  }

  MaxWeightedMatching mwm(g, weight); /* initialize an instance of mwm */
  mwm.run(); /* run mwm */

  for (int i = 0;i < n;++ i) {
    Node v = mwm.mate(node_vec[i]);
    if (v == INVALID) mate[i] = MWM_NOMATE;
    else mate[i] = g.id(v) - n; /* read results */
  }

  node_vec.clear(); /* release space */

  return mwm.matchingWeight();
}

int wmatch_gbp_int(int n, int m, int** weights, int *mate)
{
    return wmatch<int>(n, m, weights, mate);
}

double wmatch_gbp_double(int n, int m, double** weights, int *mate)
{
    return wmatch<double>(n, m, weights, mate);
}

int wmatch_sbp_int(int n, int** weights, int *mate)
{
    return wmatch<int>(n, n, weights, mate);
}

double wmatch_sbp_double(int n, double** weights, int *mate)
{
    return wmatch<double>(n, n, weights, mate);
}








