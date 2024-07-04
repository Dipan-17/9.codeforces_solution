#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int V, vector<vector<pair<int, int>>> adj[]) {
    // Priority queue to store (weight, (node, parent node)) pairs
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
    greater<pair<int, pair<int, int>>>> pq;
    
    // Vector to track visited nodes
    vector<int> visited(V, 0);
    
    // To store the MST edges
    vector<pair<int, pair<int, int>>> mstEdges;
    
    int sum = 0;
    
    // Start from the source node 0 with a dummy parent node -1
    pq.push({0, {0, -1}});
    
    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        
        int currentDistance = top.first;
        int currentNode = top.second.first;
        int parentNode = top.second.second;
        
        // If the node is already visited, skip it
        if (visited[currentNode] == 1) continue;
        
        // Mark the node as visited
        visited[currentNode] = 1;
        
        // Add the edge to the MST (ignore the initial push with parent -1)
        if (parentNode != -1) {
            mstEdges.push_back({currentDistance, {parentNode, currentNode}});
        }
        
        // Add the current distance to the total sum
        sum += currentDistance;
        
        // Explore all adjacent nodes
        for (auto& neigh : adj[currentNode]) {
            int neighNode = neigh.first;
            int neighDistance = neigh.second;
            
            // If the neighbor is not visited, push it to the priority queue
            if (!visited[neighNode]) {
                pq.push({neighDistance, {neighNode, currentNode}});
            }
        }
    }
    
    // Print the MST edges
    cout << "Edges in the MST:\n";
    for (auto& edge : mstEdges) {
        int weight = edge.first;
        int node1 = edge.second.first;
        int node2 = edge.second.second;
        cout << "Edge: " << node1 << " - " << node2 << " with weight: " << weight << endl;
    }
    
    return sum;
}

int main() {
    // Example usage
    int V = 5;
    vector<vector<pair<int, int>>> adj[V];

    // Add edges (this is just an example; modify accordingly)
   
