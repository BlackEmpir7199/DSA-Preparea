### A Structured Guide to Graph Algorithms

This guide organizes the provided notes into a coherent learning path, starting with the basics of graph theory and progressing to complex algorithms and their real-world applications.

#### **Table of Contents**

**Part 1: Graph Fundamentals**
1.  [Introduction to Graphs](#part-1-graph-fundamentals)
2.  [Graph Representation: Adjacency Matrix & List](#2-graph-representation-adjacency-matrix--list)
3.  [Graph Traversal: BFS & DFS](#3-graph-traversal-bfs--dfs)

**Part 2: Core Graph Properties & Algorithms**
4.  [Cycle Detection in an Undirected Graph](#4-cycle-detection-in-an-undirected-graph)
5.  [Cycle Detection in a Directed Graph](#5-cycle-detection-in-a-directed-graph)
6.  [Bipartite Graph Check](#6-bipartite-graph-check)

**Part 3: Shortest Path Algorithms**
7.  [Shortest Path in Unweighted Graphs (BFS)](#7-shortest-path-in-unweighted-graphs-bfs)
8.  [Shortest Path in Weighted Graphs (Dijkstra's Algorithm)](#8-shortest-path-in-weighted-graphs-dijkstras-algorithm)
9.  [Shortest Path in a Directed Acyclic Graph (DAG)](#9-shortest-path-in-a-directed-acyclic-graph-dag)
10. [Shortest Path with Negative Weights (Bellman-Ford Algorithm)](#10-shortest-path-with-negative-weights-bellman-ford-algorithm)
11. [All-Pairs Shortest Path (Floyd-Warshall Algorithm)](#11-all-pairs-shortest-path-floyd-warshall-algorithm)

**Part 4: Spanning Trees & Traversal Paths**
12. [Minimum Spanning Tree (MST): Prim's Algorithm](#12-minimum-spanning-tree-mst-prims-algorithm)
13. [Minimum Spanning Tree (MST): Kruskal's Algorithm & DSU](#13-minimum-spanning-tree-mst-kruskals-algorithm--dsu)
14. [Eulerian Path and Circuit](#14-eulerian-path-and-circuit)

**Part 5: Advanced Connectivity Algorithms**
15. [Bridges in a Graph (Tarjan's Algorithm)](#15-bridges-in-a-graph-tarjans-algorithm)
16. [Articulation Points in a Graph (Tarjan's Algorithm)](#16-articulation-points-in-a-graph-tarjans-algorithm)
17. [Strongly Connected Components (Kosaraju's & Tarjan's)](#17-strongly-connected-components-kosarajus--tarjans)

**Part 6: Applications of Graph Algorithms**
18. [Topological Sort & Applications](#18-topological-sort--applications)
19. [Grid Traversal Problems (BFS/DFS Applications)](#19-grid-traversal-problems-bfsdfs-applications)
20. [Circle of Strings (Eulerian Circuit Application)](#20-circle-of-strings-eulerian-circuit-application)

---

### Part 1: Graph Fundamentals

#### 1. Introduction to Graphs
*   **Intuition:** A graph is a way to model and visualize **relationships and connections** between various entities.
*   **Core Components:**
    *   **Nodes (Vertices):** The fundamental entities or points (e.g., cities, people, locations).
    *   **Edges:** The connections or relationships between nodes (e.g., roads, friendships, flights).
*   **Real-World Examples:**
    *   **Navigation (Google Maps):** Nodes are locations, edges are roads. Used for finding shortest routes.
    *   **Social Networks (Facebook):** Nodes are users, edges are friendships. Used for friend recommendations.
    *   **Computer Networks (Internet):** Nodes are computers/routers, edges are network connections. Used for data routing.
*   **Basic Types:**
    *   **Weighted Graph:** Edges have associated numerical values (weights) like distance, time, or cost.
    *   **Unweighted Graph:** Edges have no weights; all connections are considered equal.
    *   **Complete Graph:** A graph where every node is directly connected to every other node.

#### 2. Graph Representation: Adjacency Matrix & List

**1. Adjacency Matrix**
*   **Concept:** A **V x V** 2D array where `matrix[i][j]` stores information about the edge between node `i` and `j`.
*   **Usage:**
    *   **Unweighted:** `matrix[i][j] = 1` if edge exists, `0` otherwise.
    *   **Weighted:** `matrix[i][j] = weight` of the edge. No edge is represented by `0` or `infinity`.
*   **Time Complexity:**
    *   **Edge Check (i, j):** `O(1)`
    *   **Find Neighbours of i:** `O(V)`
*   **Space Complexity:** `O(V^2)`
*   **Best For:** Dense graphs where `E ≈ V^2`.

**2. Adjacency List**
*   **Concept:** An array of lists where `adj_list[i]` stores a list of all nodes directly connected to `i`.
*   **Usage:**
    *   **Unweighted:** `adj_list[i]` stores neighbor nodes. `vector<vector<int>>`.
    *   **Weighted:** `adj_list[i]` stores pairs of `(neighbor, weight)`. `vector<vector<pair<int, int>>>`.
*   **Time Complexity:**
    *   **Edge Check (i, j):** `O(degree(i))`
    *   **Find Neighbours of i:** `O(degree(i))`
*   **Space Complexity:** `O(V + E)`
*   **Best For:** Sparse graphs (most common case), saving significant memory.

#### 3. Graph Traversal: BFS & DFS

**Breadth-First Search (BFS)**
*   **Intuition:** Explores the graph **layer by layer**, like a virus spreading to its direct neighbors first.
*   **Algorithm:**
    1.  Use a **queue** and a `visited` array.
    2.  Start at a `source_node`, mark it visited, and push it to the queue.
    3.  While the queue is not empty:
        *   Dequeue a `node`.
        *   For each unvisited `neighbor` of the node:
            *   Mark the `neighbor` as visited.
            *   Enqueue the `neighbor`.
*   **Time Complexity:** `O(V + E)`
*   **Space Complexity:** `O(V)`
*   **Use Case:** Finding the shortest path in an unweighted graph.

**Depth-First Search (DFS)**
*   **Intuition:** Explores as far as possible along a single path before backtracking.
*   **Algorithm:**
    1.  Use **recursion** (or an explicit stack) and a `visited` array.
    2.  Start at a `source_node`.
    3.  Mark the current `node` as visited.
    4.  For each unvisited `neighbor` of the node, recursively call DFS on that neighbor.
*   **Time Complexity:** `O(V + E)`
*   **Space Complexity:** `O(V)` (for recursion stack).
*   **Use Case:** Cycle detection, finding connected components, topological sorting, finding bridges/articulation points.

**Handling Disconnected Graphs:** For both BFS and DFS, to ensure all nodes are visited, use an outer loop: `for i = 0 to V-1`, if `!visited[i]`, start a new traversal from `i`.

---

### Part 2: Core Graph Properties & Algorithms

#### 4. Cycle Detection in an Undirected Graph
*   **Concept:** Find if a path exists that starts and ends at the same vertex.
*   **DFS Approach:**
    *   During DFS, pass the `parent` of the current node.
    *   A cycle is detected if you encounter a `visited` neighbor that is **not the immediate parent** of the current node.
*   **BFS Approach:**
    *   Store `(node, parent)` pairs in the queue.
    *   A cycle is detected if you dequeue a `(node, parent)` and find one of its neighbors is `visited` but is **not** its `parent`.
*   **Time/Space Complexity:** `O(V + E)` / `O(V)`.

#### 5. Cycle Detection in a Directed Graph
*   **Concept:** Find if a directed path exists that starts and ends at the same vertex. This is analogous to a **deadlock**.
*   **DFS Approach:**
    *   Use two `visited` arrays: `visited` (for any visit) and `path_visited` (for the current recursion stack).
    *   A cycle is detected if you encounter a neighbor that is already in the `path_visited` array.
    *   When backtracking from a node `u`, set `path_visited[u] = false`.
*   **BFS Approach (Kahn's Algorithm):**
    *   This approach is based on **Topological Sort**.
    *   A graph has a cycle if and only if a complete topological sort of all its vertices is **not possible**.
    *   Calculate in-degrees of all nodes. Add nodes with in-degree 0 to a queue.
    *   Process the queue, decrementing the in-degrees of neighbors. Add new 0-in-degree nodes to the queue.
    *   If the final count of topologically sorted nodes is less than `V`, a cycle exists.
*   **Time/Space Complexity:** `O(V + E)` / `O(V)`.

#### 6. Bipartite Graph Check
*   **Definition:** A graph is bipartite if its vertices can be divided into two disjoint sets such that no two vertices within the same set are adjacent.
*   **Key Property:** A graph is **not bipartite** if and only if it contains an **odd-length cycle**.
*   **Algorithm (Coloring Method):**
    1.  Use a `color` array (e.g., -1 for uncolored, 0 for color A, 1 for color B).
    2.  Start a traversal (BFS or DFS) from an uncolored node. Assign it color 0.
    3.  For each neighbor:
        *   If uncolored, assign it the opposite color and add it to the traversal queue/stack.
        *   If already colored, check if its color is the **same** as the current node's color. If so, a conflict exists, and the graph is **not bipartite**.
    4.  Ensure you check all disconnected components of the graph.
*   **Time/Space Complexity:** `O(V + E)` / `O(V)`.

---

### Part 3: Shortest Path Algorithms

#### 7. Shortest Path in Unweighted Graphs (BFS)
*   **Problem:** Find the minimum number of edges from a source to all other nodes.
*   **Algorithm:** **BFS** is optimal for this because it explores layer by layer.
    1.  Use a `distance` array, initialized to infinity (except `dist[source]=0`).
    2.  When BFS moves from `u` to an unvisited neighbor `v`, set `distance[v] = distance[u] + 1`.
*   **Path Reconstruction:**
    1.  Use a `parent` array. When moving from `u` to `v`, set `parent[v] = u`.
    2.  To find the path to a `destination`, start from `destination` and backtrack using the `parent` array until you reach the `source`. Reverse the collected path.
*   **Time/Space Complexity:** `O(V + E)` / `O(V)`.

#### 8. Shortest Path in Weighted Graphs (Dijkstra's Algorithm)
*   **Problem:** Find the shortest path (minimum total weight) from a single source in a weighted graph with **non-negative edge weights**.
*   **Intuition:** A greedy algorithm that finalizes the shortest distance to the closest unexplored node at each step.
*   **Algorithm (using Priority Queue - efficient for sparse graphs):**
    1.  Use a `distance` array (initialized to infinity) and a min-priority queue storing `(distance, node)`.
    2.  Push `(0, source)` into the PQ. `distance[source] = 0`.
    3.  While the PQ is not empty:
        *   Extract the node `u` with the smallest distance from the PQ.
        *   For each neighbor `v` of `u`:
            *   **Relaxation:** If `distance[u] + weight(u, v) < distance[v]`, update `distance[v] = distance[u] + weight(u, v)` and push `(distance[v], v)` to the PQ.
*   **Path Reconstruction:** Use a `parent` array as in the unweighted case. When you relax an edge from `u` to `v`, set `parent[v] = u`.
*   **Time Complexity:** `O(E log V)` (with Priority Queue).
*   **Space Complexity:** `O(V + E)`.

#### 9. Shortest Path in a Directed Acyclic Graph (DAG)
*   **Problem:** Find the shortest path from a single source in a weighted DAG. **Handles negative weights**.
*   **Algorithm:**
    1.  **Topological Sort:** Perform a topological sort on the graph (e.g., using DFS and a stack).
    2.  **Initialize Distances:** Create a `distance` array, setting `distance[source] = 0` and all others to infinity.
    3.  **Process in Order:** Iterate through the vertices in their topological order. For each vertex `u`:
        *   If `distance[u]` is not infinity, relax all outgoing edges from `u`.
*   **Reasoning:** By processing in topological order, when we get to a node `u`, we are guaranteed to have already found the shortest paths to all nodes that can reach `u`.
*   **Time/Space Complexity:** `O(V + E)` / `O(V)`.

#### 10. Shortest Path with Negative Weights (Bellman-Ford Algorithm)
*   **Problem:** Find the shortest path from a single source in a graph that may have **negative edge weights**. Also **detects negative cycles**.
*   **Algorithm:**
    1.  **Initialize Distances:** `distance` array with `dist[source]=0` and others as infinity.
    2.  **Relax Edges (V-1 times):** Repeat the following `V-1` times:
        *   Iterate through **all edges** `(u, v, w)` in the graph and apply the relaxation `if (dist[u] + w < dist[v]) dist[v] = dist[u] + w`.
    3.  **Check for Negative Cycles:** After `V-1` iterations, perform one **final iteration**. If any distance value changes, a negative cycle exists.
*   **Time Complexity:** `O(V * E)`.
*   **Space Complexity:** `O(V)`.

#### 11. All-Pairs Shortest Path (Floyd-Warshall Algorithm)
*   **Problem:** Find the shortest path between **every pair of vertices** in a weighted graph. **Handles negative weights**.
*   **Algorithm:** A dynamic programming approach.
    1.  **Initialize Matrix:** Create a `dist[V][V]` matrix where `dist[i][j]` is the direct edge weight, `dist[i][i] = 0`, and non-adjacent pairs are infinity.
    2.  **Iterate via Intermediate Nodes:**
        ```
        for k from 0 to V-1:      // Intermediate node
          for i from 0 to V-1:    // Source node
            for j from 0 to V-1:  // Destination node
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        ```
    3.  **Negative Cycle Detection:** After the loops, if `dist[i][i] < 0` for any `i`, a negative cycle exists.
*   **Time Complexity:** `O(V^3)`.
*   **Space Complexity:** `O(V^2)`.

---

### Part 4: Spanning Trees & Traversal Paths

#### 12. Minimum Spanning Tree (MST): Prim's Algorithm
*   **Definition (MST):** A subgraph that connects all vertices with no cycles and has the minimum possible total edge weight.
*   **Prim's Intuition (Vertex-based):** A greedy algorithm that "grows" the MST from a starting vertex. At each step, it adds the cheapest edge connecting a vertex **in** the MST to a vertex **outside** the MST.
*   **Algorithm (using Priority Queue):**
    1.  Use a `key` array (min weight to connect to MST), an `mst_set` array (is node in MST?), and a min-priority queue `(weight, node)`.
    2.  Start with `(0, source_node)` in the PQ.
    3.  While the PQ is not empty:
        *   Extract the node `u` with the minimum key that is not yet in the MST.
        *   Add `u` to the MST.
        *   For each neighbor `v` of `u`, if a cheaper edge `(u,v)` is found to connect `v` to the MST, update `v`'s key and push it to the PQ.
*   **Time Complexity:** `O(E log V)`.
*   **Best For:** Dense graphs.

#### 13. Minimum Spanning Tree (MST): Kruskal's Algorithm & DSU
*   **Kruskal's Intuition (Edge-based):** A greedy algorithm that sorts all edges by weight and adds the next cheapest edge, as long as it doesn't form a cycle.
*   **Algorithm:**
    1.  Sort all edges in non-decreasing order of weight.
    2.  Use a **Disjoint Set Union (DSU)** data structure, with each vertex initially in its own set.
    3.  Iterate through the sorted edges `(w, u, v)`:
        *   If `u` and `v` are in different sets (checked with `findParent`), the edge does not form a cycle.
        *   Add the edge to the MST and merge the sets of `u` and `v` (with `union`).
        *   Stop when `V-1` edges are added.
*   **Time Complexity:** `O(E log E)` (dominated by sorting).
*   **Best For:** Sparse graphs.

#### 14. Eulerian Path and Circuit
*   **Definition:**
    *   **Eulerian Path:** A path that visits **every edge exactly once**.
    *   **Eulerian Circuit:** An Eulerian Path that starts and ends at the same vertex.
*   **Conditions (Undirected Graph):**
    1.  All non-zero degree nodes must be in a single connected component.
    2.  **Circuit:** All vertices must have an **even degree**.
    3.  **Path:** Exactly **zero or two** vertices must have an **odd degree**. (The path starts and ends at the odd-degree nodes).
*   **Time Complexity (to check existence):** `O(V + E)`.

---

### Part 5: Advanced Connectivity Algorithms

#### 15. Bridges in a Graph (Tarjan's Algorithm)
*   **Definition:** An edge is a **bridge** if its removal increases the number of connected components.
*   **Key Idea:** An edge `(u, v)` (where `u` is the parent of `v` in DFS tree) is a bridge if there is no back-edge from `v` or its descendants to `u` or any of its ancestors.
*   **Algorithm (DFS-based):**
    *   Use `discovery_time` (time of first visit) and `low_time` (lowest discovery time reachable).
    *   During DFS from `u` to `v`:
        *   After the recursive call to `v` returns, update `low_time[u] = min(low_time[u], low_time[v])`.
        *   **Bridge Condition:** If `low_time[v] > discovery_time[u]`, then `(u, v)` is a bridge.
*   **Time/Space Complexity:** `O(V + E)` / `O(V)`.

#### 16. Articulation Points in a Graph (Tarjan's Algorithm)
*   **Definition:** A vertex is an **articulation point** (or cut vertex) if its removal disconnects the graph.
*   **Algorithm (DFS-based):**
    *   Uses `discovery_time` and `low_time` similar to finding bridges.
    *   During DFS from `u` to `v`:
        *   **Condition for non-root node `u`:** `u` is an articulation point if it has a child `v` such that `low_time[v] >= discovery_time[u]`.
        *   **Condition for root node `u`:** `u` is an articulation point if it has **more than one child** in the DFS tree.
*   **Time/Space Complexity:** `O(V + E)` / `O(V)`.

#### 17. Strongly Connected Components (Kosaraju's & Tarjan's)
*   **Definition:** In a directed graph, an SCC is a maximal set of vertices where every vertex is reachable from every other vertex within the set.
*   **Kosaraju's Algorithm (3-pass DFS):**
    1.  **1st DFS:** Run DFS on the original graph and store nodes in a stack based on their finishing times.
    2.  **Reverse Graph:** Create a new graph with all edges reversed.
    3.  **2nd DFS:** Pop nodes from the stack. If a popped node is unvisited in the reversed graph, run DFS from it. All nodes visited in this DFS form one SCC.
*   **Tarjan's Algorithm (1-pass DFS):**
    *   Uses a single DFS with `discovery_time`, `low_time`, and a stack to keep track of nodes in the current exploration path.
    *   A node `u` is the root of an SCC if `discovery_time[u] == low_time[u]`. When this occurs, all nodes on the stack above and including `u` form one SCC.
*   **Time/Space Complexity (both):** `O(V + E)` / `O(V+E)`.

---

### Part 6: Applications of Graph Algorithms

#### 18. Topological Sort & Applications
*   **Definition:** A linear ordering of vertices in a **Directed Acyclic Graph (DAG)** such that for every edge `u -> v`, `u` comes before `v`.
*   **DFS-based:** Run DFS. After visiting all of a node's descendants, push the node onto a stack. The final stack content (popped one by one) is the topological sort.
*   **BFS-based (Kahn's Algorithm):** See [Cycle Detection in a Directed Graph](#5-cycle-detection-in-a-directed-graph). The order in which nodes are dequeued is the topological sort.
*   **Applications:**
    *   **Course Schedule / Prerequisite Tasks:** Can all tasks be completed? This is equivalent to checking for a cycle in the dependency graph.
    *   **Alien Dictionary:** Deduce character ordering from a sorted list of words by building a dependency graph and finding its topological sort.
    *   **Parallel Courses:** Find the minimum time to complete all courses by performing a topological sort and using dynamic programming to track the maximum time to reach each node.

#### 19. Grid Traversal Problems (BFS/DFS Applications)
*   **Concept:** Treat the grid as an implicit graph where cells are nodes and adjacent cells (4 or 8-directional) are connected by edges.
*   **Problems:**
    *   **Number of Islands:** Iterate through the grid. When you find an unvisited land cell ('1'), start a traversal (BFS/DFS) to find all connected land cells and mark them as visited. Increment an island counter.
    *   **Covid Spread / Rotting Oranges:** A multi-source BFS problem. Start a layer-by-layer BFS from all initially infected/rotten cells to find the maximum time it takes to reach all healthy/fresh cells.
    *   **Replace O's with X's (Surrounded Regions):** Find all 'O's connected to the border using BFS/DFS starting from the border. These are "safe". Flip all other 'O's to 'X's.
    *   **Knight's Walk:** Find the minimum moves for a knight on a chessboard. This is a classic shortest path problem on an unweighted graph, perfectly solved with BFS.

#### 20. Circle of Strings (Eulerian Circuit Application)
*   **Problem:** Can a list of strings be arranged in a circle where the last character of one matches the first of the next?
*   **Solution:** Transform the problem into finding an **Eulerian Circuit** in a character-based graph.
    1.  **Nodes:** The characters 'a' through 'z'.
    2.  **Edges:** For each string, draw a directed edge from its first character to its last character.
    3.  **Check Conditions for Eulerian Circuit:**
        *   For every character (node), `in-degree == out-degree`.
        *   All characters involved in the strings form a single strongly connected component.
*   **Time/Space Complexity:** `O(N*L + V+E)` / `O(V+E)`.