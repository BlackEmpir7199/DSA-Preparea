# Eulerian Circuit and Path Detection

## Problem Description
Determine whether a given undirected graph has an Eulerian circuit, Eulerian path, or neither. 

An Eulerian circuit is a path that starts and ends at the same vertex and traverses every edge exactly once. An Eulerian path is a path that traverses every edge exactly once but may start and end at different vertices.

## Approach
The solution checks two key conditions:
1. **Degree Condition**: 
   - For an Eulerian circuit: All vertices must have even degrees.
   - For an Eulerian path: Exactly two vertices must have odd degrees.
2. **Connectivity Condition**: All edges must belong to a single connected component.

### Key Steps:
1. **Degree Calculation**: Count the number of vertices with odd degrees.
2. **Connectivity Check**: Perform DFS to ensure all non-zero degree vertices are connected.
3. **Result Determination**:
   - If all vertices have even degrees and the graph is connected: Eulerian circuit (return 2)
   - If exactly two vertices have odd degrees and the graph is connected: Eulerian path (return 1)
   - Otherwise: Neither (return 0)

## Solution Code
```cpp
class Solution {
  public:
    void dfs(vector<int> adj[], vector<bool> &visited, int node) {
        visited[node] = 1;
        for(int i : adj[node]) {
            if(!visited[i])
                dfs(adj, visited, i);
        }
    }
    
    int isEulerCircuit(int V, vector<int> adj[]) {
        vector<bool> visited(V, 0);
        vector<int> Deg(V, 0);
        int OddDeg = 0;
        
        // Calculate degrees and count odd degree vertices
        for(int i = 0; i < V; i++) {
            Deg[i] = adj[i].size();
            if(Deg[i] % 2)
                OddDeg++;
        }
        
        // Check degree condition
        if(OddDeg != 2 && OddDeg != 0) 
            return 0;
        
        // Find first non-zero degree vertex for DFS
        int start = 0;
        for(int i = 0; i < V; i++) {
            if(Deg[i]) {
                start = i;
                break;
            }
        }
        
        // Perform DFS from start vertex
        dfs(adj, visited, start);
        
        // Check connectivity condition
        for(int i = 0; i < V; i++) {
            if(Deg[i] && !visited[i])
                return 0;
        }
        
        // Determine result
        if(OddDeg == 0) 
            return 2; // Eulerian circuit
        return 1;     // Eulerian path
    }
};
```

## Explanation
1. **Degree Calculation**: We first calculate the degree of each vertex and count how many vertices have odd degrees.
2. **Degree Condition Check**: 
   - If the count of odd-degree vertices is neither 0 nor 2, we immediately return 0 (neither circuit nor path).
3. **Connectivity Check**:
   - We perform DFS starting from the first non-zero degree vertex we find.
   - After DFS, if any non-zero degree vertex remains unvisited, the graph is disconnected, and we return 0.
4. **Result Determination**:
   - If no vertices have odd degrees (all even), return 2 (Eulerian circuit).
   - If exactly two vertices have odd degrees, return 1 (Eulerian path).

## Complexity Analysis
- **Time Complexity**: O(V + E) - We traverse all vertices and edges once for degree calculation and once for DFS.
- **Space Complexity**: O(V) - We use visited and degree arrays of size V.

This approach efficiently checks both the degree and connectivity conditions required for Eulerian circuits and paths in undirected graphs.