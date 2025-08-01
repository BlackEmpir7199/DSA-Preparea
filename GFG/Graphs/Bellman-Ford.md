# Bellman-Ford Algorithm Implementation

## Problem Description
Implement the Bellman-Ford algorithm to find the shortest paths from a single source vertex to all other vertices in a weighted directed graph. The algorithm should also detect negative weight cycles.

### Input
- `V`: Number of vertices
- `edges`: List of directed edges in the format [u, v, weight]
- `src`: Source vertex

### Output
- Shortest distance from the source to all vertices
- `{-1}` if a negative weight cycle is detected

## Approach
The Bellman-Ford algorithm works by relaxing all edges `V-1` times to find the shortest paths. An additional pass is made to detect negative weight cycles.

### Key Steps:
1. **Initialization**: Set all distances to infinity except the source vertex (distance 0).
2. **Relaxation**: For each edge, update the distance to the destination vertex if a shorter path is found. Repeat this `V-1` times.
3. **Negative Cycle Detection**: After `V-1` relaxations, check if any distance can still be improved. If yes, a negative cycle exists.

### Solution Code
```cpp
// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        // Relax all edges V-1 times
        for(int i = 0; i < V-1; i++) {
            for(auto edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
        
        // Check for negative weight cycles
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];
            
            if(dist[u] != 1e8 && dist[u] + weight < dist[v]) {
                return {-1};
            }
        }
        
        return dist;
    }
};
```

## Explanation
1. **Initialization**: All distances are set to a large value (`1e8`) except the source vertex which is set to 0.
2. **Relaxation**: For each edge `(u, v)`, if the distance to `u` plus the edge weight is less than the current distance to `v`, update `v`'s distance. This is repeated `V-1` times to ensure the shortest paths are found.
3. **Negative Cycle Detection**: After `V-1` relaxations, if any distance can still be improved, it indicates the presence of a negative weight cycle, and `{-1}` is returned.

## Complexity Analysis
- **Time Complexity**: `O(V*E)` - The algorithm relaxes all edges `V-1` times.
- **Space Complexity**: `O(V)` - Only the distance array is stored.

This implementation efficiently computes shortest paths in graphs with negative weights and detects negative cycles, making it suitable for various applications like network routing and currency arbitrage detection.