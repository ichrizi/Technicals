#include "Graph.h"
 
int main() {
    int num_vertices, choice, start_vertex, u, v;
    cout << "Enter the number of vertices in the graph (max 100): ";
    cin >> num_vertices;
 
    Graph graph(num_vertices);
 
    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Add edge" << endl;
        cout << "2. Remove edge" << endl;
        cout << "3. Breadth First Search (BFS)" << endl;
        cout << "4. Depth First Search (DFS)" << endl;
        cout << "5. Display adjacency matrix" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
 
        switch(choice) {
            case 1:
                cout << "Enter the two vertices to add an edge between (0-" << num_vertices-1 << "): ";
                cin >> u >> v;
                graph.add_edge(u, v);
                break;
            case 2:
                cout << "Enter the two vertices to remove the edge between (0-" << num_vertices-1 << "): ";
                cin >> u >> v;
                graph.remove_edge(u, v);
                break;
            case 3:
                cout << "Enter the starting vertex for BFS (0-" << num_vertices-1 << "): ";
                cin >> start_vertex;
                cout << "BFS Traversal: ";
                graph.bfs(start_vertex);
                break;
            case 4:
                cout << "Enter the starting vertex for DFS (0-" << num_vertices-1 << "): ";
                cin >> start_vertex;
                cout << "DFS Traversal: ";
                graph.dfs_traversal(start_vertex);
                break;
            case 5:
                graph.display_matrix();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:e
                cout << "Invalid choice" << endl;
                break;
        }
    } while(choice != 6);
 
    return 0;
}
