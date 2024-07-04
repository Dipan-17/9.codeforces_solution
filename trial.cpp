#include <vector>
#include <algorithm>
using namespace std;

// Helper function to build adjacency list from edge list
vector<vector<int>> buildGraph(const vector<vector<int>>& edges, int n) {
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    return graph;
}

// DFS to find the maximum depth and calculate the diameter
void dfs(const vector<vector<int>>& graph, int node, int parent, int depth, int& maxDepth, int& farthestNode) {
    if (depth > maxDepth) {
        maxDepth = depth;
        farthestNode = node;
    }
    for (int child : graph[node]) {
        if (child != parent) {
            dfs(graph, child, node, depth + 1, maxDepth, farthestNode);
        }
    }
}

// Function to find the diameter and height of a tree
pair<int, int> findDiameterAndHeight(const vector<vector<int>>& edges, int n) {
    auto graph = buildGraph(edges, n);
    int maxDepth = 0, farthestNode = 0;
    // First DFS to find the farthest node from node 0
    dfs(graph, 0, -1, 0, maxDepth, farthestNode);
    // Second DFS from the farthest node to find the diameter
    int diameter = maxDepth;
    maxDepth = 0;
    dfs(graph, farthestNode, -1, 0, maxDepth, farthestNode);
    diameter = max(diameter, maxDepth);
    // The height is the maximum depth found in the second DFS
    int height = maxDepth;
    return {diameter, height};
}


    int minimumDiameter(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto [diameter1, height1] = findDiameterAndHeight(edges1, edges1.size() + 1);
        auto [diameter2, height2] = findDiameterAndHeight(edges2, edges2.size() + 1);
        // Calculate the minimum possible diameter of the combined tree
        return max({diameter1, diameter2, height1 + height2 + 1});
    }
