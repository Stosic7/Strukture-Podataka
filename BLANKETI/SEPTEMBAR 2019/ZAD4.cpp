void DFS(int v, bool visited[], std::stack<int> &Stack) {
        visited[v] = true;
        for (LinkedNodeInt* i = adj[v]; i != nullptr; i = i->next) {
            if (!visited[i->value])
                DFS(i->value, visited, Stack);
        }
        Stack.push(v);
    }

    
GraphInt* getTranspose() {
        Graph* g(V);
        for (int v = 0; v < V; ++v) {
            for (LinkedNodeInt* i = adj[v]; i != nullptr; i = i->next) {
                g.addEdge(i->value, v);
            }
        }
        return g;
    }

    
void DFSUtil(int v, bool visited[], int &size) {
        visited[v] = true;
        size++;
        for (LinkedNodeInt* i = adj[v]; i != nullptr; i = i->next) {
            if (!visited[i->value])
                DFSUtil(i->value, visited, size);
        }
    }


LinkedNodeInt* FindMaxReachableWithRoundTrip() {
    std::stack<int> Stack;
    bool* visited = new bool[V];  

    for (int i = 0; i < V; i++)
        visited[i] = false;

    
    for (int i = 0; i < V; i++)
        if (!visited[i])
            DFS(i, visited, Stack);

   
    Graph gr = getTranspose();

    
    for (int i = 0; i < V; i++)
        visited[i] = false;

    int maxSize = 0;
    int resultNode = -1;

   
    while (!Stack.empty()) {
        int v = Stack.top();
        Stack.pop();

        
        if (!visited[v]) {
            int size = 0;
            gr.DFSUtil(v, visited, size);  

            
            if (size > maxSize) {
                maxSize = size;
                resultNode = v;
            }
        }
    }

    delete[] visited;
    return intToNode(resultNode); 
}
