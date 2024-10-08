#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class GNode {
public:
    int id; 
    vector<GNode*> neighbors; 

    GNode(int id) : id(id) {}
};

class Graph {
private:
    vector<GNode*> nodes; 

public:
    void addNode(int id); 
    void addEdge(int from, int to); 
    int subGraph(GNode* p); 
    void toUndirected(); 
    int maxSubgraph(); 
    // Ostatak implementacije...
};

int Graph::subGraph(GNode* p) {
    if (p == nullptr) return 0;

    unordered_set<int> visited; 
    return dfs(p, visited); 
}

int Graph::dfs(GNode* node, unordered_set<int>& visited) {
    visited.insert(node->id);

    int count = 1; 
    for (GNode* neighbor : node->neighbors) {
        if (visited.find(neighbor->id) == visited.end()) { 
            count += dfs(neighbor, visited); 
        }
    }
    return count; 
}

void Graph::toUndirected() {
    for (GNode* node : nodes) {
        for (GNode* neighbor : node->neighbors) {
            
            neighbor->neighbors.push_back(node);
        }
    }
}

int Graph::maxSubgraph() {
    unordered_set<int> visited;
    int maxCount = 0;

    for (GNode* node : nodes) {
        if (visited.find(node->id) == visited.end()) { 
            int count = subGraph(node); 
            maxCount = max(maxCount, count); 
            visited.insert(node->id); 
        }
    }
    return maxCount; 
}
