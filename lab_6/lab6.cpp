#include <iostream>
#include <map>
#include <vector>
class Graph
{
public:
    std::map<int, bool> visited;
    std::map<int, std::vector<int>> adj;

    void addEdge(int v, int w);
    void DFS(int v, int end);
private:
    bool exit = false;
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v); 
}
 
void Graph::DFS(int v, int end)
{
    visited[v] = true;
    std::cout << v << " ";
    if(v == end) {
        exit = true;
        return;
    }

    std::vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i])
            DFS(*i, end);
        if(exit) return;
    }
}

int main()
{
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 0);
    g.addEdge(3, 4);
    g.addEdge(2, 5);
    g.addEdge(8, 5);
    g.addEdge(8, 6);
    g.addEdge(8, 7);
    g.addEdge(8, 9);
    g.addEdge(0, 9);

    g.DFS(0, 7);
    return 0;
}