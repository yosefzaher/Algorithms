# Algorithm Repository

This repository contains various algorithms, including sorting, searching, divide and conquer, greedy, and Huffman coding algorithms. Each algorithm includes a performance evaluation and time complexity analysis.

## Sorting Algorithms

### Insertion Sort

Insertion sort is a simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

- **Performance Evaluation:**
  - Best Case: O(n) when the input is already sorted.
  - Average Case: O(n^2) due to the nested loop structure.
  - Worst Case: O(n^2) when the input is in reverse order.
- **Time Complexity Classes:**
  - Time Complexity: O(n^2)
  - Space Complexity: O(1)
<p align="center"><img src="https://miro.medium.com/v2/resize:fit:1400/format:webp/0*81Yk_fwfCB3iCwRP.png" alt="project-image"></p>

### Merge Sort

Merge sort is a divide and conquer algorithm that splits an array into two halves, sorts them, and then merges them. Merge sort always divides the array into two halves, which means that thereare no worst or best cases for merge sort.

- **Performance Evaluation:**
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
- **Time Complexity Classes:**
  - Time Complexity: O(n log n)
  - Space Complexity: O(n)

<p align="center"><img src="https://www.w3schools.com/dsa/img_mergesort_long.png" alt="project-image"></p>

## Searching Algorithms

### Binary Search

Binary search is a searching algorithm that operates on a sorted array. It works by repeatedly dividing the search interval in half.

- **Performance Evaluation:**
  - Best Case: O(1) when the search key is found at the first comparison.
  - Average Case: O(log n)
  - Worst Case: O(log n)
- **Time Complexity Classes:**
  - Time Complexity: O(log n)
  - Space Complexity: O(1)

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

## Greedy Algorithm

### Activity Selection Algorithm

Activity selection is a classic algorithmic problem that can be solved using a greedy algorithm. The problem is to select a maximum-size set of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

- **Performance Evaluation:**
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
- **Time Complexity Classes:**
  - Time Complexity: O(n log n)
  - Space Complexity: O(n)

 <p align="center"><img src="https://iq.opengenus.org/content/images/2019/03/Example1.png" alt="project-image"></p>
 <p align="center"><img src="https://iq.opengenus.org/content/images/2019/03/Example2-2.png" alt="project-image"></p>

## Huffman Coding

Huffman coding is a lossless data compression algorithm. The idea is to assign variable-length codes to input characters, lengths of the assigned codes are based on the frequencies of corresponding characters. The most frequent character gets the smallest code and the least frequent character gets the largest code.

- **Performance Evaluation:**
  - Best Case: O(n log n)
  - Average Case: O(n log n)
  - Worst Case: O(n log n)
- **Time Complexity Classes:**
  - Time Complexity: O(n log n)
  - Space Complexity: O(n)
 
<p align="center"><img src="https://kamilmysliwiec.com/wp-content/uploads/2017/04/chart.png" alt="project-image"></p>

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
