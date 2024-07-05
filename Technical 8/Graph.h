#ifndef GRAPH_H
#define GRAPH_H
 
#include <iostream>
#include <queue>
using namespace std;
 
const int MAX_VERTICES = 100;
 
class Graph {
private:
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
 
public:
    Graph(int vertices);
    void add_edge(int u, int v);
    void remove_edge(int u, int v);
    void bfs(int start_vertex);
    void dfs_traversal(int start_vertex);
    void dfs(int vertex, bool visited[]);
    void display_matrix();
};
 
#endif // GRAPH_H
