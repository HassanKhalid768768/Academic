**Snake Game Pathfinding Solver**

Group Members

Sohaib Ahmed 21L-5635
Muhammad Hassan Khalid 21L-5692
Muhammad Hamza 21L-5636

This repository contains a Python implementation of a pathfinding solver for the Snake game. The solver utilizes various search algorithms, including A*, Breadth-First Search (BFS), and Greedy Best-First Search (Greedy BFS), to find the optimal path for the Snake to reach its food within a fixed time frame.

**Instructions:**

To run the program, simply execute the `main.py` file. This will start the Snake game with the default pathfinding algorithm (A*).

If you wish to change the pathfinding algorithm used by the Snake, follow these steps:

1. Open the `agentsnake.py` file.
2. Locate the `SearchSolution` method within the `AgentSnake` class.
3. Modify the `algorithm` parameter to one of the following values:
   - `"A*"`: A* search algorithm.
   - `"BFS"`: Breadth-First Search algorithm.
   - `"GBFS"`: Greedy Best-First Search algorithm.

Save the file after making changes.

Run the `main.py` file again to observe the Snake using the updated pathfinding algorithm.


**Acknowledgments:**

The pathfinding algorithms implemented in this project are based on classic algorithms widely used in artificial intelligence and computer science. Special thanks to the contributors to the Python community for their valuable resources and documentation.

Enjoy playing Snake with intelligent pathfinding! 🐍🕹️