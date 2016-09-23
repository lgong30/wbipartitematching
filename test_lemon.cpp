
#include <iostream>
#include <lemon/list_graph.h>

int main()
{
  typedef lemon::ListGraph Graph;
  typedef Graph::EdgeIt EdgeIt;
  typedef Graph::Edge Edge;
  typedef Graph::NodeIt NodeIt;
  typedef Graph::Node Node;
  typedef Graph::EdgeMap<int> LengthMap;
  using lemon::INVALID;

  Graph g;
  
  Node s=g.addNode();
  Node v2=g.addNode();
  Node v3=g.addNode();
  Node v4=g.addNode();
  Node v5=g.addNode();
  Node t=g.addNode();

  Edge s_v2=g.addEdge(s, v2);
  Edge s_v3=g.addEdge(s, v3);
  Edge v2_v4=g.addEdge(v2, v4);
  Edge v2_v5=g.addEdge(v2, v5);
  Edge v3_v5=g.addEdge(v3, v5);
  Edge v4_t=g.addEdge(v4, t);
  Edge v5_t=g.addEdge(v5, t);
  
  LengthMap length(g);

  length[s_v2]=10;
  length[s_v3]=10;
  length[v2_v4]=5;
  length[v2_v5]=8;
  length[v3_v5]=5;
  length[v4_t]=8;
  length[v5_t]=8;

  std::cout << "Hello World!" << std::endl;
  std::cout <<  std::endl;
  std::cout << "This is library LEMON here! We have a graph!" << std::endl;
  std::cout <<  std::endl;

  std::cout << "Nodes:";
  for (NodeIt i(g); i!=INVALID; ++i)
    std::cout << " " << g.id(i);
  std::cout << std::endl;

  std::cout << "Edges:";
  for (EdgeIt i(g); i!=INVALID; ++i)
    std::cout << " (" << g.id(g.u(i)) << "," << g.id(g.v(i)) << ")";
  std::cout << std::endl;
  std::cout <<  std::endl;

  std::cout << "There is a map on the edges (length)!" << std::endl;
  std::cout <<  std::endl;
  for (EdgeIt i(g); i!=INVALID; ++i)
    std::cout << "length(" << g.id(g.u(i)) << ","
              << g.id(g.v(i)) << ")="<<length[i]<<std::endl;

  std::cout << std::endl;

}