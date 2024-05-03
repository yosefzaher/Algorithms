# Algorithm Repository

This repository contains various algorithms, including sorting, searching, divide and conquer, greedy, and Huffman coding algorithms. Each algorithm includes a performance evaluation and time complexity analysis.

## Sorting Algorithms

### Insertion Sort

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
