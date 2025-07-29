### The Ultimate Graph Algorithms Revision Guide

This guide is structured to build your knowledge from the ground up, providing the depth needed for effective problem-solving and interview preparation.

#### **Part 1: Graph Fundamentals**

##### **1. Introduction to Graphs**
*   **Core Idea:** A mathematical structure used to model relationships between objects.
*   **Components:**
    *   **Vertices (Nodes):** Represent the objects (e.g., cities, users, tasks).
    *   **Edges:** Represent the connections or relationships (e.g., roads, friendships, dependencies).
*   **Key Terminology:**
    *   **Directed vs. Undirected:** Edges have direction (A → B ≠ B → A) vs. no direction (A-B is a two-way street).
    *   **Weighted vs. Unweighted:** Edges have a cost/distance/time vs. all edges are considered equal (cost of 1).
    *   **Degree:** Number of edges connected to a vertex. In a directed graph, this is split into **in-degree** (incoming) and **out-degree** (outgoing).
    *   **Path:** A sequence of vertices connected by edges.
    *   **Cycle:** A path that starts and ends at the same vertex.

##### **2. Graph Representation**
*   **Core Idea:** How we store the graph's structure in memory. Choosing the right representation is crucial for performance.

| Feature               | Adjacency Matrix (`vector<vector<int>>`)                                | Adjacency List (`vector<vector<pair<int, int>>>`)                        |
| --------------------- | ----------------------------------------------------------------------- | ------------------------------------------------------------------------ |
| **Concept**           | A `V x V` matrix where `M[i][j]` stores edge info.                     | An array of lists, where `adj[i]` stores all neighbors of `i`.             |
| **Space Complexity**  | **`O(V^2)`**                                                            | **`O(V + E)`**                                                           |
| **Edge Check `(u, v)`** | **`O(1)`** - The biggest advantage.                                     | `O(degree(u))` or `O(log(degree(u)))` with a sorted list/set.          |
| **Iterate Neighbors** | `O(V)` - Must scan the entire row.                                      | **`O(degree(u))`** - Highly efficient.                                   |
| **Best For**          | **Dense Graphs** (`E ≈ V^2`), where `V` is small.                       | **Sparse Graphs** (`E << V^2`) - The most common case in problems.         |
| **General Advice**    | **Almost always use an Adjacency List.** It is more flexible and memory-efficient for the vast majority of problems. |

##### **3. Graph Traversal: BFS & DFS**
*   **Core Idea:** A systematic way to visit every vertex and edge in a graph.

| Traversal | Breadth-First Search (BFS)                                                                                             | Depth-First Search (DFS)                                                                                                   |
| --------- | ---------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------- |
| **Intuition** | Explores **layer by layer**. Like a wave expanding from a central point.                                               | Explores as **deep as possible** along one path before backtracking.                                                       |
| **Data Structure** | **Queue** (First-In, First-Out).                                                                                       | **Recursion Stack** (or an explicit Stack) (Last-In, First-Out).                                                           |
| **Use Cases** | - **Shortest Path in Unweighted Graphs.** <br> - Finding the level of each node. <br> - Multi-source shortest path. | - **Cycle Detection.** <br> - **Connectivity Problems** (components, bridges). <br> - **Topological Sorting.**                 |
| **Gotcha** | To handle disconnected graphs, wrap the main traversal logic in a loop: `for(i=0..V-1) if(!visited[i]) bfs(i);` | The recursive nature can lead to stack overflow on large, deep graphs. Iterative DFS with a stack can prevent this. |

---

### **Part 2: Core Graph Properties & Algorithms**

##### **4. Cycle Detection in an Undirected Graph**
*   **Core Idea:** During a traversal, if we encounter an already visited node that is not our immediate parent, we have found a back-edge, forming a cycle.
*   **DFS Implementation:**
    *   The `dfs(u, parent)` function is key.
    *   For each neighbor `v` of `u`:
        *   If `v == parent`, `continue`. (This is just the edge we came from).
        *   If `v` is visited, `return true` (Cycle detected!).
        *   Else, `if(dfs(v, u)) return true;`.
*   **BFS Implementation:**
    *   Store `(node, parent)` pairs in the queue.
    *   When processing `u`, for each neighbor `v`:
        *   If `v == parent`, `continue`.
        *   If `v` is visited, `return true`.
        *   Else, `q.push({v, u})`.

##### **5. Cycle Detection in a Directed Graph**
*   **Core Idea:** A cycle exists if an exploration path (a recursion stack) runs into one of its own ancestors.
*   **DFS Approach (2 Visited Arrays):**
    *   `visited[]`: Marks a node as ever visited.
    *   `path_visited[]`: Marks a node as being in the **current recursion stack**.
    *   **Algorithm:**
        1.  In `dfs(u)`, set `visited[u] = true` and `path_visited[u] = true`.
        2.  For each neighbor `v`:
            *   If `path_visited[v] == true`, a cycle is found. Return `true`.
            *   If `!visited[v]`, `if(dfs(v)) return true;`.
        3.  Before returning from `dfs(u)`, **backtrack**: `path_visited[u] = false`.
*   **BFS Approach (Kahn's Algorithm / Topological Sort):**
    *   **Insight:** A DAG always has a valid topological sort. If a graph has a cycle, you cannot produce a complete topological sort.
    *   **Algorithm:** Run Kahn's algorithm. If the final count of sorted nodes is less than `V`, the graph has a cycle.

##### **6. Bipartite Graph Check**
*   **Core Idea:** Can the graph be colored with two colors such that no two adjacent nodes have the same color?
*   **Problem Pattern:** Look for questions about partitioning items into two groups with constraints between them.
*   **Algorithm (BFS Coloring):**
    1.  Use a `color[]` array initialized to -1 (uncolored).
    2.  For each component of the graph:
        *   Start BFS from a node, color it `0`, and push to queue.
        *   When processing `u`, for each neighbor `v`:
            *   If `v` is uncolored (`color[v] == -1`), color it with the opposite color (`1 - color[u]`) and enqueue.
            *   If `v` is colored and `color[v] == color[u]`, a conflict exists. The graph is **not bipartite**.
    *   **Key Property:** A graph is not bipartite if and only if it contains an **odd-length cycle**.

---

### **Part 3: Shortest Path Algorithms**

| Algorithm              | Graph Type                                            | Complexity       | Key Idea                                                            |
| ---------------------- | ----------------------------------------------------- | ---------------- | ------------------------------------------------------------------- |
| **BFS**                | **Unweighted** (directed or undirected)               | `O(V + E)`       | Explores layer by layer, naturally finding the shortest edge count. |
| **Dijkstra**           | **Weighted**, **No Negative Edges**                     | `O(E log V)`     | Greedy. Always picks the closest unexplored node. Uses a Min-PQ.    |
| **Bellman-Ford**       | **Weighted**, **Handles Negative Edges**, **Detects -ve Cycles** | `O(V * E)`       | Dynamic Programming. Relaxes all edges `V-1` times.                 |
| **DAG Shortest Path**  | **Weighted DAG**, **Handles Negative Edges**          | `O(V + E)`       | Topological sort, then relax edges in that order. Super efficient.  |
| **Floyd-Warshall**     | **All-Pairs Shortest Path**, **Handles -ve Edges**, **Detects -ve Cycles** | `O(V^3)`         | DP. Considers each vertex `k` as an intermediate point in all paths. |

*   **Implementation Gotcha (Relaxation):** The core of all weighted shortest path algorithms is the relaxation step:
    `if (distance[u] + weight(u, v) < distance[v]) { distance[v] = distance[u] + weight(u, v); }`
*   **Path Reconstruction:** To get the actual path, not just the distance, use a `parent[]` array. When you relax the edge `(u,v)` successfully, set `parent[v] = u`. Then backtrack from the destination.

---

### **Part 4: Spanning Trees & Traversal Paths**

##### **12 & 13. Minimum Spanning Tree (MST): Prim's vs. Kruskal's**
*   **Core Idea:** Find a subset of edges that connects all vertices into a single tree with the minimum possible total edge weight.

| Algorithm      | Prim's Algorithm                                                              | Kruskal's Algorithm                                                          |
| -------------- | ----------------------------------------------------------------------------- | ---------------------------------------------------------------------------- |
| **Intuition**  | **Vertex-based**. "Grows" the MST from a starting node, always adding the cheapest edge to a new vertex. | **Edge-based**. Sorts all edges and adds the cheapest ones that don't form a cycle. |
| **Data Structure** | **Min-Priority Queue** to pick the next closest vertex.                       | **Disjoint Set Union (DSU)** to efficiently detect cycles.                      |
| **Best For**   | **Dense Graphs** (`E ≈ V^2`).                                                 | **Sparse Graphs** (`E << V^2`). Often easier to implement.                     |
| **Complexity** | `O(E log V)`                                                                  | `O(E log E)`                                                                 |

##### **14. Eulerian Path and Circuit**
*   **Core Idea:** A path that uses every **edge** exactly once. (Contrast with Hamiltonian Path, which visits every *vertex* once).
*   **Problem Pattern:** Look for "visit every road", "cover all connections", "draw without lifting pen".
*   **Conditions (Undirected Graph):**
    1.  The graph (of non-zero degree nodes) must be connected.
    2.  **Circuit (starts and ends at same point):** All vertices have **even** degree.
    3.  **Path (starts and ends at different points):** Exactly **two** vertices have **odd** degree.

---

### **Part 5: Advanced Connectivity (Tarjan's Algorithms)**

*   **Core Idea:** All these algorithms rely on a single, powerful DFS traversal that computes two key values for each node `u`:
    *   `discovery_time[u]`: The "time" (step number) when `u` was first visited.
    *   `low_time[u]`: The lowest `discovery_time` reachable from `u` (including itself) by traversing zero or more tree edges and at most one **back-edge**.

##### **15. Bridges**
*   **Definition:** An edge whose removal increases the number of connected components.
*   **Intuition:** The edge `(u, v)` (where `u` is parent of `v`) is a bridge if `v` and its descendants **cannot** reach `u` or any of `u`'s ancestors using a back-edge.
*   **Condition:** `low_time[v] > discovery_time[u]`.

##### **16. Articulation Points (Cut Vertices)**
*   **Definition:** A vertex whose removal increases the number of connected components.
*   **Intuition:** A node `u` is a cut vertex if a child `v` and its descendants are "stuck" and can only get to the rest of the graph through `u`.
*   **Conditions:**
    1.  **For a non-root node `u`:** `u` is an AP if it has a child `v` such that `low_time[v] >= discovery_time[u]`.
    2.  **For the root of the DFS tree:** The root is an AP if it has **more than one child**.

##### **17. Strongly Connected Components (SCCs)**
*   **Definition:** In a **directed graph**, a maximal set of vertices where every vertex is reachable from every other.
*   **Kosaraju's Algorithm (Intuitive, 3-Pass):**
    1.  **DFS on G:** Get vertices in order of finishing times (push to stack).
    2.  **Reverse G:** Create `G_rev` by reversing all edges.
    3.  **DFS on G_rev:** Process nodes in the order given by the stack. Each new DFS tree in `G_rev` is one SCC.
*   **Tarjan's Algorithm (Efficient, 1-Pass):**
    *   Uses a single DFS with the `discovery/low` time arrays and an explicit stack.
    *   A node `u` is the "root" of an SCC if `low_time[u] == discovery_time[u]`.
    *   When a root `u` is found, pop `u` and all nodes above it from the stack; they form one SCC.

---

### **Part 6: Applications & Problem-Solving Patterns**

#### **A Problem-Solving Cheat Sheet**

| If the problem asks for...                                          | Think of...                                                                                             |
| ------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| **Shortest path in an unweighted graph**                              | **BFS**                                                                                                 |
| **Shortest path in a weighted graph (no negative edges)**           | **Dijkstra's Algorithm**                                                                                |
| **Shortest path with negative edges**                                 | **Bellman-Ford** (or **DAG Shortest Path** if it's a DAG)                                                 |
| **All-pairs shortest path**                                           | **Floyd-Warshall** or running Dijkstra/Bellman-Ford from every vertex.                                    |
| **Dependencies, prerequisites, ordering of tasks**                    | **Topological Sort** (Kahn's BFS-based algorithm is very common).                                         |
| **Is it possible to do all tasks?**                                   | **Cycle Detection in a Directed Graph**. If there's a cycle, it's impossible.                             |
| **Connecting all points with minimum cost**                           | **Minimum Spanning Tree (MST)** - Prim's or Kruskal's.                                                    |
| **Traversing a grid/maze/chessboard**                                 | Treat it as an implicit graph. Use **BFS for shortest path**, **DFS for pathfinding/reachability**.         |
| **Finding "critical" connections or nodes**                           | **Bridges** and **Articulation Points**.                                                                |
| **Partitioning into two groups with constraints**                     | **Bipartite Graph Coloring**.                                                                           |
| **Finding clusters of mutually reachable items in a directed network** | **Strongly Connected Components (SCCs)**.                                                                 |
| **Traversing every "road" or "link" exactly once**                    | **Eulerian Path / Circuit**.                                                                            |