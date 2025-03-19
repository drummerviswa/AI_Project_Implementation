# AI Project - Implementation of Searching Algorithm (Uninformed Search)

This project implements **Depth-Limited Search (DLS)** and **Iterative Deepening Search (IDS)** as part of **Uninformed Search Algorithms** in **Artificial Intelligence**. The implementation follows concepts from **Tim Jones.M**.

---

## 📌 Features
- Graph implementation using an adjacency matrix.
- Stack-based **Depth-Limited Search (DLS)**.
- **Iterative Deepening Search (IDS)** for better goal reachability.
- Supports adding and searching for edges.
- Dynamically allocated memory for flexibility.

---

## 📁 File Structure
```
/project-folder
    ├── graph.h      # Header file for graph functions
    ├── graph.c      # Implementation of graph functions
    ├── stack.h      # Header file for stack operations
    ├── stack.c      # Implementation of stack functions
    ├── main.c       # Main program (DLS & IDS implementation)
    ├── README.md    # Project documentation
```

---

## 🚀 How to Compile and Run

### **1. Compile the project**
```sh
gcc main.c graph.c stack.c -o search_program
```

### **2. Run the program**
```sh
./search_program
```

---

## 🛠 Implementation Details

### **Graph Representation**
The graph is represented as an **adjacency matrix**, where each edge has a weight.

### **Stack Implementation**
A stack is used for Depth-First traversal.

### **Depth-Limited Search (DLS)**
DLS is a depth-first search with a **maximum depth limit** to avoid infinite recursion in cyclic graphs.

### **Iterative Deepening Search (IDS)**
IDS combines the advantages of depth-first and breadth-first search by repeatedly running DLS with increasing depth limits until the goal is found.

---

## 📝 Example Output
For `dls(g_p, 0, 5, 2);`, the output will be:
```sh
0 (depth 0)
2 (depth 1)
5 (depth 2)
Goal node 5 found at depth 2
```
For `ids(g_p, 0, 5);`, the output will be:
```sh
Trying depth limit: 0
Trying depth limit: 1
Trying depth limit: 2
Goal node 5 found at depth 2
```

---

## 📖 Reference
This project is based on concepts from **Tim Jones.M - Artificial Intelligence: Search Algorithms and Applications**.

---

## 📜 License
This project is **open-source** under the MIT License.

---

## 🤝 Contributing
Feel free to **fork** this repo, add new search algorithms, and submit a **pull request**! 🚀

### Suggested Contributions:
- Implement **Breadth-First Search (BFS)**
- Implement **Depth-First Search (DFS)**
- Implement **A* Search Algorithm**
- Implement **Hill Climbing Algorithm**
- Implement **Tabu Search**
- Add test cases and performance benchmarks
- Improve memory efficiency and optimization

Your contributions will help enhance the project and make it a valuable resource for AI search algorithms! 🔥