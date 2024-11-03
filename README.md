# Algorithm Repository

This repository contains various algorithms, including sorting, searching, divide and conquer, greedy, and Huffman coding algorithms. Each algorithm includes a performance evaluation and time complexity analysis.

## Sorting Algorithms

## Insertion Sort

### Introduction

Insertion Sort is a simple and efficient sorting algorithm that builds the final sorted array one item at a time. It is an in-place comparison-based algorithm and works well for small datasets or nearly sorted datasets.

### How it Works

1. **Start with the second element:** Assume the first element is already sorted. Start the sorting process with the second element of the array.
2. **Compare and Insert:** Compare the second element with the first element. If the second element is smaller, swap them. Now, the first two elements are sorted.
3. **Extend the sorted portion:** Move to the third element. Compare it with the elements in the sorted portion (from left to right) and insert it at the correct position within the sorted portion.
4. **Repeat:** Continue this process for all elements in the array until the entire array is sorted.

### Algorithm Steps

1. **Start Loop:** Start a loop from the second element (index 1) to the last element (index n-1) of the array.
2. **Select Key:** Select the current element as the key to be inserted into the sorted portion.
3. **Compare and Shift:** Compare the key with the elements in the sorted portion (from right to left). If an element is greater than the key, shift it one position to the right.
4. **Insert Key:** Insert the key into its correct position in the sorted portion.
5. **Repeat:** Repeat steps 2-4 until all elements are sorted.

### Example

Let's sort an array [5, 2, 4, 6, 1, 3] using Insertion Sort:

- Start with the second element (2).
- Compare 2 with 5 (first element), as 2 is smaller, swap them: [2, 5, 4, 6, 1, 3].
- Now, consider the third element (4).
- Compare 4 with elements in the sorted portion (5, 2). As 4 is greater than 2 and smaller than 5, insert it between them: [2, 4, 5, 6, 1, 3].
- Continue this process for all elements until the array is sorted: [1, 2, 3, 4, 5, 6].

### Complexity Analysis

- **Time Complexity:**
  - Best Case: O(n) - When the array is already sorted.
  - Worst Case: O(n^2) - When the array is sorted in reverse order.
  - Average Case: O(n^2)
- **Space Complexity:** O(1) - It sorts the array in-place without requiring additional space other than a few variables.

### Advantages

- Simple implementation.
- Efficient for small datasets or nearly sorted datasets.
- In-place sorting algorithm with space complexity of O(1).

### Disadvantages

- Not suitable for large datasets due to its quadratic time complexity.
- Performance degrades significantly for inversely sorted or nearly inversely sorted datasets.

### Conclusion

Insertion Sort is a straightforward sorting algorithm that builds the sorted array incrementally by inserting each element into its correct position in the already sorted portion of the array. While it may not be the most efficient for large datasets, it is easy to implement and works well for small or nearly sorted datasets.

<p align="center"><img src="https://miro.medium.com/v2/resize:fit:1400/format:webp/0*81Yk_fwfCB3iCwRP.png" alt="project-image"></p>

### Merge Sort

Merge Sort is a divide-and-conquer algorithm that divides the input array into two halves, sorts each half recursively, and then merges the sorted halves to produce a sorted array. It is a stable sorting algorithm and works efficiently for large datasets.

### How it Works

1. **Divide:** Divide the input array into two halves until each sub-array contains only one element (base case).
2. **Conquer:** Sort each sub-array recursively using Merge Sort.
3. **Merge:** Merge the sorted sub-arrays to produce a single sorted array.

### Algorithm Steps

1. **Merge Sort Function:**
   - If the array has one or zero elements, return the array (base case).
   - Divide the array into two halves.
   - Recursively call Merge Sort on each half.
   - Merge the sorted halves using a merge function.

2. **Merge Function:**
   - Create a temporary array to store the merged result.
   - Compare elements from both halves and merge them into the temporary array in sorted order.
   - Copy the merged result back to the original array.

### Example

Let's sort an array [38, 27, 43, 3, 9, 82, 10] using Merge Sort:

- Divide the array into [38, 27, 43] and [3, 9, 82, 10].
- Recursively sort each half: [27, 38, 43] and [3, 9, 10, 82].
- Merge the sorted halves: [3, 9, 10, 27, 38, 43, 82].

### Complexity Analysis

- **Time Complexity:**
  - Best Case: O(n log n) - When the array is evenly divided at each level of recursion.
  - Worst Case: O(n log n) - Same as the average case due to consistent splitting and merging.
  - Average Case: O(n log n)
- **Space Complexity:** O(n) - Requires additional space for temporary arrays during the merging process.

### Advantages

- Stable sorting algorithm.
- Efficient for large datasets.
- Consistent time complexity regardless of input distribution.

### Disadvantages

- Requires additional space for temporary arrays during the merging process.
- Recursive implementation may lead to stack overflow for very large arrays.

### Conclusion

Merge Sort is a divide-and-conquer sorting algorithm that efficiently sorts large datasets by dividing them into smaller sub-arrays, sorting them recursively, and then merging the sorted halves. While it requires additional space for merging, its consistent time complexity makes it suitable for a wide range of applications.


<p align="center"><img src="https://www.w3schools.com/dsa/img_mergesort_long.png" alt="project-image"></p>

## Searching Algorithms

### Binary Search

Binary Search is a fast search algorithm that works on sorted arrays. It repeatedly divides the search interval in half until the target element is found or the interval is empty. It is an efficient algorithm for searching in large datasets.

### How it Works

1. **Initialize:** Set low to the first index and high to the last index of the array.
2. **Loop:** Repeat until low is less than or equal to high.
   - Calculate mid as (low + high) / 2.
   - If the target element is equal to the element at mid, return mid.
   - If the target element is less than the element at mid, set high to mid - 1.
   - If the target element is greater than the element at mid, set low to mid + 1.
3. **Return:** If the loop exits without finding the target element, return -1 (not found).

### Algorithm Steps

1. **Binary Search Function:**
   - Set low to 0 and high to n-1 (where n is the size of the array).
   - Repeat the loop until low is less than or equal to high.
     - Calculate mid as (low + high) / 2.
     - If the target element is equal to the element at mid, return mid.
     - If the target element is less than the element at mid, set high to mid - 1.
     - If the target element is greater than the element at mid, set low to mid + 1.
   - If the loop exits without finding the target element, return -1.

### Example

Let's search for the element 35 in a sorted array [10, 20, 30, 40, 50, 60, 70, 80]:

- Initialize low = 0, high = 7.
- First iteration: mid = (0 + 7) / 2 = 3 (element 40).
  - 35 < 40, so set high = 3 - 1 = 2.
- Second iteration: mid = (0 + 2) / 2 = 1 (element 20).
  - 35 > 20, so set low = 1 + 1 = 2.
- Third iteration: mid = (2 + 2) / 2 = 2 (element 30).
  - 35 > 30, so set low = 2 + 1 = 3.
- Fourth iteration: low > high, exit loop (element not found).

### Complexity Analysis

- **Time Complexity:**
  - Best Case: O(1) - When the target element is found at the first comparison.
  - Worst Case: O(log n) - When the target element is at the middle or not in the array.
  - Average Case: O(log n)
- **Space Complexity:** O(1) - Requires constant space for variables.

### Advantages

- Efficient search algorithm for sorted arrays.
- Time complexity of O(log n) ensures fast search even in large datasets.

### Disadvantages

- Requires the array to be sorted beforehand.
- Not applicable for unsorted or dynamically changing arrays.

### Conclusion

Binary Search is a fast search algorithm that efficiently finds a target element in a sorted array by repeatedly dividing the search interval in half. It offers a time complexity of O(log n), making it suitable for large datasets where quick searches are required.


<p align="center"><img src="https://miro.medium.com/v2/resize:fit:1400/format:webp/1*M8nxu1oYQy2vpWRjlVdXNA.png" alt="project-image"></p>

## Divide and Conquer Technique

Divide and conquer is a fundamental algorithmic technique for solving problems. It works by breaking down a complex problem into several subproblems of the same type, solving them independently, and combining their solutions to solve the original problem.

- **Performance Evaluation:**
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
- **Time Complexity Classes:**
  - Time Complexity: O(n log n)
  - Space Complexity: O(log n)

## Greedy Technique

### Activity Selection Problem

The Activity Selection Problem is a scheduling algorithm that aims to maximize the number of activities that can be performed within a given time frame. It involves selecting a subset of mutually compatible activities that do not overlap in their time intervals.

### How it Works

1. **Sort Activities:** Sort the activities based on their finish times in ascending order.
2. **Select First Activity:** Select the first activity with the earliest finish time.
3. **Iterate:** For each remaining activity:
   - If the start time of the current activity is greater than or equal to the finish time of the previously selected activity, select the current activity.
4. **Repeat:** Continue this process until all activities are processed.

### Algorithm Steps

1. **Activity Selection Function:**
   - Sort activities based on finish times.
   - Select the first activity as the first selected activity.
   - Iterate through remaining activities:
     - If start time >= finish time of last selected activity, select the current activity.
   - Return the selected activities.

### Example

Let's consider the following activities with their start and finish times:
- Activity A: (1, 3)
- Activity B: (2, 5)
- Activity C: (4, 7)
- Activity D: (6, 9)

Sorted by finish times: A(1, 3), B(2, 5), C(4, 7), D(6, 9)

Selected activities: A(1, 3), C(4, 7)

### Complexity Analysis

- **Time Complexity:** O(n log n) - Due to sorting the activities by finish times.
- **Space Complexity:** O(1) - Requires constant space for variables.

### Advantages

- Maximizes the number of activities performed within a given time frame.
- Efficient scheduling algorithm for resource optimization.

### Disadvantages

- Requires activities to be sorted based on finish times.
- May not always select the optimal subset of activities for all scenarios.

### Conclusion

The Activity Selection Problem is a scheduling algorithm that efficiently selects a subset of mutually compatible activities to maximize utilization within a given time frame. While it requires sorting activities initially, it offers an efficient solution for resource optimization and scheduling tasks.

 <p align="center"><img src="https://iq.opengenus.org/content/images/2019/03/Example1.png" alt="project-image"></p>
 <p align="center"><img src="https://iq.opengenus.org/content/images/2019/03/Example2-2.png" alt="project-image"></p>

### Huffman Coding

Huffman coding is a data compression algorithm that assigns variable-length codes to input characters based on their frequencies. It achieves compression by replacing frequently occurring characters with shorter codes and less frequently occurring characters with longer codes.

### How it Works

1. **Frequency Calculation:** Calculate the frequency of each character in the input data.
2. **Build Huffman Tree:**
   - Create leaf nodes for each character with their frequencies as weights.
   - Combine two nodes with the lowest frequencies to create a new internal node with a combined frequency.
   - Repeat this process until all nodes are combined into a single tree.
3. **Generate Codes:**
   - Traverse the Huffman tree to assign codes to each character.
   - Left branches represent '0' and right branches represent '1'.
   - The code for each character is the path from the root to that character in the tree.
4. **Encode Data:**
   - Replace each character in the input data with its corresponding Huffman code.
   - Create a compressed bitstream using the generated codes.
5. **Decode Data:**
   - Use the Huffman tree to decode the compressed bitstream back into the original data.

### Algorithm Steps

1. **Frequency Calculation Function:**
   - Calculate the frequency of each character in the input data.
2. **Build Huffman Tree Function:**
   - Create leaf nodes for each character with their frequencies.
   - Combine nodes with lowest frequencies to build the Huffman tree.
3. **Generate Codes Function:**
   - Traverse the Huffman tree to assign codes to each character.
4. **Encode Data Function:**
   - Replace characters with their Huffman codes to create a compressed bitstream.
5. **Decode Data Function:**
   - Use the Huffman tree to decode the compressed bitstream back into original data.

### Example

Let's compress the string "ABRACADABRA" using Huffman coding:
- Frequencies: A(5), B(2), R(2), C(1), D(1)
- Huffman Tree:
            _____
           /     \
        A(5)   ____
               /    \
            B(2)   ___
                   /    \
                R(2)  ___
                      /    \
                   C(1)  D(1)
- Codes: A(0), B(10), R(110), C(1110), D(1111)
- Compressed Data: 010011010011110101010

### Complexity Analysis

- **Time Complexity:** O(n log n) - Constructing the Huffman tree.
- **Space Complexity:** O(n) - Storage for the Huffman tree and codes.

### Advantages

- Achieves efficient data compression by assigning shorter codes to frequently occurring characters.
- Can be used for lossless compression, preserving the original data.

### Disadvantages

- Requires the frequency of characters in the input data, which may add overhead for small datasets.
- Huffman coding may not always achieve optimal compression for all types of data.

### Conclusion

Huffman coding is a widely used data compression algorithm that efficiently reduces the size of data by assigning variable-length codes to characters based on their frequencies. While it requires initial overhead for constructing the Huffman tree, it offers effective compression for various types of data.

 
<p align="center"><img src="https://kamilmysliwiec.com/wp-content/uploads/2017/04/chart.png" alt="project-image"></p>

## Dynamic Programming

### Longest Common Subsequence (LCS)

The Longest Common Subsequence (LCS) problem aims to find the longest sequence that appears in the same order in two different sequences. It is often used in applications such as file comparison and bioinformatics.

### How it Works

1. **Create a 2D Table:** Initialize a table to store lengths of longest common subsequence lengths.
2. **Fill the Table:** Iterate through both sequences:
   - If characters match, increment the value from the diagonal cell.
   - If they do not match, take the maximum value from the left or top cell.
3. **Trace Back:** Once the table is filled, trace back to find the actual LCS.

### Algorithm Steps

1. **Initialize a 2D array:** Create an array of size (m+1) x (n+1), where m and n are the lengths of the two sequences.
2. **Populate the array:** Loop through the characters of both sequences and fill the array based on matches.
3. **Retrieve LCS:** Backtrack through the array to reconstruct the LCS.

### Example

Given two sequences:
- Sequence 1: `ABCBDAB`
- Sequence 2: `BDCAB`

The LCS is `BCAB` or `BDAB`, both of which have a length of 4.

### Complexity Analysis

- **Time Complexity:** O(m * n), where m and n are the lengths of the two sequences.
- **Space Complexity:** O(m * n) for the 2D table.

### Advantages

- Provides a systematic approach to find the longest subsequence.
- Applicable in various fields such as computational biology and data comparison.

### Disadvantages

- Can consume significant memory for large sequences due to the 2D table.

### Conclusion

The Longest Common Subsequence algorithm effectively identifies the longest sequence that appears in both sequences, providing insights into data similarities and differences. Despite its space complexity, its applications in comparison and analysis make it a valuable algorithm.

<p align="center"><img src="https://www.dotnetlovers.com/images/coolnikhilj2265da340b-f1ff-41a2-8f17-670bf36a4ab1.png" alt="LCS Example"></p>

---

### Stagecoach Problem

The Stagecoach Problem is a dynamic programming problem that deals with maximizing the total profit from transporting passengers along a given route with constraints on the number of passengers.

### How it Works

1. **Define States:** Each state represents a combination of passengers and the current stage.
2. **Recurrence Relation:** Use previous states to determine the maximum profit for the current stage based on the number of passengers transported.
3. **Compute Solutions:** Calculate the maximum profit iteratively or recursively.

### Algorithm Steps

1. **Define Profit Table:** Create a table to store the maximum profit for each stage and passenger count.
2. **Iterate Through Passengers:** Loop through each stage and update the profit table based on the current passengers.
3. **Retrieve Maximum Profit:** The result will be the maximum value in the last row of the profit table.

### Example

Consider a scenario where you can transport a maximum of `k` passengers and the profit per passenger varies with each stage.

### Complexity Analysis

- **Time Complexity:** O(n * k), where n is the number of stages and k is the maximum number of passengers.
- **Space Complexity:** O(n) for the profit table.

### Advantages

- Efficiently solves problems involving resource allocation and profit maximization.
- Applicable in logistics and transportation planning.

### Disadvantages

- Requires accurate profit data for each stage.
- Complexity increases with more stages or constraints.

### Conclusion

The Stagecoach Problem provides a systematic approach to maximize profits in transportation scenarios. Through careful state definition and iteration, it efficiently finds the best solution within given constraints.

<p align="center"><img src="https://www.ii.uib.no/saga/SC96EPR/images/stagecoach.gif" alt="Stagecoach Example"></p>

---

### 0/1 Knapsack Problem

The 0/1 Knapsack Problem is a classic optimization problem that involves selecting items with given weights and values to maximize the total value in a knapsack with a weight limit.

### How it Works

1. **Define the Knapsack:** Set the maximum weight capacity of the knapsack.
2. **Create a 2D Table:** Use a table to store maximum values for different weights and items.
3. **Fill the Table:** Iterate through items and update the table based on whether to include an item or not.

### Algorithm Steps

1. **Initialize a 2D array:** Create an array of size (n+1) x (W+1), where n is the number of items and W is the weight capacity.
2. **Populate the array:** For each item, check if its weight is less than or equal to the current weight limit:
   - If yes, take the maximum of including the item or excluding it.
3. **Retrieve Maximum Value:** The result will be in the bottom-right cell of the table.

### Example

Given items with the following weights and values:
- Item 1: Weight 2, Value 3
- Item 2: Weight 3, Value 4
- Item 3: Weight 4, Value 5

And a knapsack capacity of 5, the maximum value that can be carried is 7.

### Complexity Analysis

- **Time Complexity:** O(n * W), where n is the number of items and W is the weight capacity.
- **Space Complexity:** O(n * W) for the 2D table.

### Advantages

- Provides an optimal solution for resource allocation problems.
- Can be adapted to various scenarios involving constraints.

### Disadvantages

- Space complexity can be high for large inputs.
- Performance may degrade with large weight capacities or item counts.

### Conclusion

The 0/1 Knapsack Problem offers a robust method for maximizing value within given constraints. Its widespread applicability in resource allocation and optimization makes it a fundamental problem in computer science.

<p align="center"><img src="https://www.tutorialspoint.com/data_structures_algorithms/images/maximum_profit_12.jpg" alt="Knapsack Example"></p>

## Graphs

### Prim's Minimum Spanning Tree (MST)

Prim's algorithm is a greedy algorithm that finds a minimum spanning tree for a weighted undirected graph. This means it finds a subset of the edges that connects all vertices with the minimum possible total edge weight.

### How it Works

1. **Initialization:** Start with a single vertex and include it in the MST.
2. **Expand the MST:** At each step, add the smallest edge that connects a vertex in the MST to a vertex outside the MST.
3. **Repeat:** Continue until all vertices are included in the MST.

### Algorithm Steps

1. **Choose a starting vertex:** Initialize the MST with this vertex.
2. **Create a priority queue:** Store edges with weights, sorted by weight.
3. **While there are vertices not in the MST:**
   - Extract the minimum edge from the queue.
   - Add the edge to the MST and the connected vertex to the MST.
   - Add all edges from the newly added vertex to the queue.

### Example

<p align="center"><img src="https://example.com/prims-example.png" alt="Prim's MST Example"></p>

### Complexity Analysis

- **Time Complexity:** O(E log V), where E is the number of edges and V is the number of vertices.
- **Space Complexity:** O(V) for storing the MST and priority queue.

### Advantages

- Efficient for dense graphs.
- Guarantees the minimum spanning tree.

### Disadvantages

- Requires a priority queue or similar data structure for efficiency.
- Not suitable for graphs with negative weight edges.

### Conclusion

Prim's algorithm efficiently finds the minimum spanning tree of a graph, ensuring that all vertices are connected with minimal edge weight. It is widely used in network design and optimization problems.

---

### Breadth-First Search (BFS)

Breadth-First Search (BFS) is an algorithm for traversing or searching tree or graph data structures. It explores all the neighbor nodes at the present depth before moving on to nodes at the next depth level.

### How it Works

1. **Initialization:** Start with a selected node and enqueue it.
2. **Explore Neighbors:** Dequeue the front node, mark it as visited, and enqueue all its unvisited neighbors.
3. **Repeat:** Continue until all nodes have been visited.

### Algorithm Steps

1. **Create a queue:** For holding nodes to visit.
2. **Enqueue the starting node:** Mark it as visited.
3. **While the queue is not empty:**
   - Dequeue the front node.
   - For each unvisited neighbor, enqueue it and mark it as visited.

### Example

<p align="center"><img src="https://example.com/bfs-example.png" alt="BFS Example"></p>

### Complexity Analysis

- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.
- **Space Complexity:** O(V) for storing the queue and visited nodes.

### Advantages

- Completes in a finite number of steps for finite graphs.
- Finds the shortest path in unweighted graphs.

### Disadvantages

- Requires significant memory for large graphs.
- Not efficient for deep trees.

### Conclusion

BFS is a powerful algorithm for exploring graphs and trees, particularly useful for finding the shortest path in unweighted graphs and level-order traversal.

---

### Depth-First Search (DFS)

Depth-First Search (DFS) is an algorithm for traversing or searching tree or graph data structures. It explores as far as possible along a branch before backtracking.

### How it Works

1. **Initialization:** Start from a selected node, marking it as visited.
2. **Explore Depth:** Visit a neighbor node, mark it as visited, and recursively explore its neighbors.
3. **Backtrack:** If no unvisited neighbors are left, backtrack to the previous node and continue.

### Algorithm Steps

1. **Create a stack:** For holding nodes to visit (or use recursion).
2. **Push the starting node:** Mark it as visited.
3. **While the stack is not empty:**
   - Pop the top node.
   - For each unvisited neighbor, push it to the stack and mark it as visited.

### Example

<p align="center"><img src="https://example.com/dfs-example.png" alt="DFS Example"></p>

### Complexity Analysis

- **Time Complexity:** O(V + E), where V is the number of vertices and E is the number of edges.
- **Space Complexity:** O(V) for storing the stack and visited nodes.

### Advantages

- Uses less memory than BFS for deep graphs.
- Can easily be implemented using recursion.

### Disadvantages

- May get trapped in deep paths without visiting all nodes.
- Cannot find the shortest path in graphs with cycles.

### Conclusion

DFS is a versatile algorithm for traversing graphs, effective for searching and pathfinding, but may not yield the shortest path.

---

### Dijkstra's Shortest Path

Dijkstra's algorithm is a graph search algorithm that finds the shortest path from a starting node to all other nodes in a weighted graph with non-negative weights.

### How it Works

1. **Initialization:** Set the distance to the starting node as 0 and all others as infinity.
2. **Settle Nodes:** Use a priority queue to repeatedly select the node with the smallest distance, updating distances to its neighbors.
3. **Repeat:** Continue until all nodes have been settled.

### Algorithm Steps

1. **Create a priority queue:** For nodes sorted by distance.
2. **Set the starting node's distance to 0.**
3. **While the queue is not empty:**
   - Extract the node with the minimum distance.
   - For each unvisited neighbor, calculate the potential distance and update if it's smaller.

### Example

<p align="center"><img src="https://example.com/dijkstra-example.png" alt="Dijkstra's Shortest Path Example"></p>

### Complexity Analysis

- **Time Complexity:** O((V + E) log V), where V is the number of vertices and E is the number of edges.
- **Space Complexity:** O(V) for the distance table and priority queue.

### Advantages

- Guarantees the shortest path in graphs with non-negative weights.
- Efficiently handles dense graphs.

### Disadvantages

- Cannot handle graphs with negative weight edges.
- Slower than some algorithms for sparse graphs.

### Conclusion

Dijkstra's algorithm provides a reliable method for finding the shortest paths in a graph, extensively used in routing and navigation applications.


## Practice Problems

- Sorting:
  - [Sorting Algorithms](https://leetcode.com/tag/sorting/)
- Searching:
  - [Binary Search](https://leetcode.com/tag/binary-search/)
- Divide and Conquer:
  - [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/)
- Greedy:
  - [Activity Selection](https://leetcode.com/problems/activity-selection-ii/)
  - [Huffman Coding](https://leetcode.com/problems/maximum-binary-tree/)
- Dynamic Programming:
  - [Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
  - [Stagecoach Problem](https://leetcode.com/problems/stagecoach-problem/) (if applicable, otherwise use a relevant link)
- Graphs:
  - [Prim's MST](https://leetcode.com/problems/minimum-spanning-tree/)
  - [Breadth-First Search (BFS)](https://leetcode.com/tag/breadth-first-search/)
  - [Depth-First Search (DFS)](https://leetcode.com/tag/depth-first-search/)
  - [Dijkstra's Shortest Path](https://leetcode.com/problems/path-with-minimum-effort/)

