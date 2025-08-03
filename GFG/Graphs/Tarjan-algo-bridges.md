# Critical Connections in a Network (Tarjan's Algorithm)

## Problem Description
Given an undirected connected network of `n` servers labeled from `0` to `n-1`, represented as connections where `connections[i] = [a, b]` represents a connection between servers `a` and `b`, find all critical connections in the network. A critical connection is a connection that, if removed, will make some servers unable to reach some other servers.

## Approach (Tarjan's Algorithm)
The solution uses Tarjan's algorithm to find bridges (critical connections) in an undirected graph. A bridge is an edge whose removal increases the number of connected components.

### Key Concepts:
1. **Discovery Time (disc)**: The time when a node is first visited in DFS.
2. **Lowest Link (low)**: The earliest discovered node reachable from the current node.
3. **Bridge Condition**: An edge `u-v` is a bridge if `disc[u] < low[v]`.

### Solution Code
```cpp
class Solution {
public:
    vector<int> disc, low;
    vector<vector<int>> graph;
    vector<vector<int>> ans;
    int time;

    void dfs(int node, int parent) {
        disc[node] = time;
        low[node] = time;
        time++;

        for(int v : graph[node]) {
            if(disc[v] == -1) { // If not visited
                dfs(v, node);
                low[node] = min(low[node], low[v]);

                // Check for bridge condition
                if(disc[node] < low[v]) {
                    ans.push_back({node, v});
                }
            }
            else if(v != parent) { // Back edge
                low[node] = min(low[node], disc[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        time = 0;
        graph.resize(n);
        disc.assign(n, -1);
        low.assign(n, -1);

        // Build adjacency list
        for(auto& edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Start DFS from node 0 (arbitrary choice for connected graph)
        dfs(0, -1);
        return ans;
    }
};
```

## Explanation
1. **Initialization**: 
   - `disc` and `low` arrays are initialized to -1 (unvisited).
   - The adjacency list `graph` is built from the input connections.
   - `time` is initialized to 0 to track discovery times.

2. **DFS Traversal**:
   - When visiting a node for the first time, set its `disc` and `low` values to the current `time`.
   - For each neighbor:
     - If unvisited (`disc[v] == -1`), recursively call DFS and update `low[node]`.
     - If the neighbor is already visited and not the parent (back edge), update `low[node]` with the neighbor's discovery time.

3. **Bridge Detection**:
   - After visiting all neighbors, check if `disc[node] < low[v]`. If true, the edge `node-v` is a bridge (critical connection).

4. **Result**:
   - All detected bridges are collected in `ans` and returned.

## Complexity Analysis
- **Time Complexity**: O(V + E) - Each node and edge is visited exactly once.
- **Space Complexity**: O(V) - The `disc`, `low`, and recursion stack each use O(V) space.

This approach efficiently identifies all critical connections in a network using Tarjan's algorithm, which is optimal for this problem.