# Leetcode C Solutions

A curated collection of Leetcode problems implemented in C, organized by categories, data structures, and algorithmic paradigms.

---

## 📊 Summary of Solutions

### 📁 Array & String Problems (`Leetcode-C/Array/`)

| # | Problem | File Name | Time Complexity | Space Complexity | Approach / Algorithm |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | **Two Sum** | [`Two_sum.c`](./Leetcode-C/Array/Two_sum.c) | $O(N^2)$ | $O(1)$ | Brute Force / Double Loop |
| 3 | **Longest Substring Without Repeating Characters** | [`Longest_Substring.c`](./Leetcode-C/Array/Longest_Substring.c) | $O(N^3)$ | $O(1)$ | Brute Force Substring Search |
| 5 | **Longest Palindromic Substring** | [`Longest_palindrome.c`](./Leetcode-C/Array/Longest_palindrome.c) | $O(N^2)$ | $O(1)$ | Expand Around Center |
| 7 | **Reverse Integer** | [`Reverse_integer.c`](./Leetcode-C/Array/Reverse_integer.c) | $O(\log_{10} X)$ | $O(1)$ | Modulo Digit Extraction with Overflow Check |
| 9 | **Palindrome Number** | [`Palindrome.c`](./Leetcode-C/Array/Palindrome.c) | $O(\log_{10} X)$ | $O(1)$ | Reverse Half Number Comparison |
| 14 | **Longest Common Prefix** | [`Longest_common.c`](./Leetcode-C/Array/Longest_common.c) | $O(S)$ | $O(1)$ | Vertical Character Scanning |
| 15 | **3Sum** | [`3SUm.c`](./Leetcode-C/Array/3SUm.c) | $O(N^2)$ | $O(\log N)$ | Sorting + Two Pointers |
| 20 | **Valid Parentheses** | [`Valid_parentheses.c`](./Leetcode-C/Array/Valid_parentheses.c) | $O(N)$ | $O(N)$ | Stack-Based Matching |
| 21 | **Merge Two Sorted Lists** | [`Merge_list.c`](./Leetcode-C/Array/Merge_list.c) | $O(N + M)$ | $O(1)$ | Iterative Pointer Splicing with Dummy Node |
| 26 | **Remove Duplicates from Sorted Array** | [`Remove_duplicates.c`](./Leetcode-C/Array/Remove_duplicates.c) | $O(N)$ | $O(1)$ | Two Pointers (In-place) |
| 28 | **Find the Index of the First Occurrence in a String** | [`Find_index.c`](./Leetcode-C/Array/Find_index.c) | $O((N - M + 1) \cdot M)$ | $O(1)$ | Sliding Window Substring Matching (strStr) |
| 32 | **Longest Valid Parentheses** | [`Longest_valid_parentheses.c`](./Leetcode-C/Array/Longest_valid_parentheses.c) | $O(N)$ | $O(N)$ | Index-tracking Stack |
| 44 | **Wildcard Matching** | [`Wildcard_matching.c`](./Leetcode-C/Array/Wildcard_matching.c) | $O(N)$ avg | $O(1)$ | Greedy Backtracking Two-Pointers |
| 75 | **Sort Colors** | [`Sort_colors.c`](./Leetcode-C/Array/Sort_colors.c) | $O(N)$ | $O(1)$ | Dutch National Flag Algorithm (3-way partition) |
| 80 | **Remove Duplicates from Sorted Array II** | [`Remove_duplicates_II.c`](./Leetcode-C/Array/Remove_duplicates_II.c) | $O(N)$ | $O(1)$ | Two Pointers (At most 2 occurrences) |
| 128 | **Longest Consecutive Sequence** | [`Longest_consecutive.c`](./Leetcode-C/Array/Longest_consecutive.c) | $O(N \log N)$ | $O(\log N)$ | Quick Sort + Linear Streak Scan |
| 151 | **Reverse Words in a String** | [`Reverse_word.c`](./Leetcode-C/Array/Reverse_word.c) | $O(N)$ | $O(1)$ | Full Reverse + Word Reverse + Whitespace Cleanup |
| 189 | **Rotate Array** | [`Rotate_words.c`](./Leetcode-C/Array/Rotate_words.c) | $O(N)$ | $O(1)$ | 3-Step Array Reversal |
| 202 | **Happy Number** | [`Happy_Number.c`](./Leetcode-C/Array/Happy_Number.c) | $O(\log N)$ | $O(1)$ | Floyd's Cycle-Finding Algorithm |
| 287 | **Find the Duplicate Number** | [`Find_duplicates.c`](./Leetcode-C/Array/Find_duplicates.c) | $O(N)$ | $O(1)$ | Floyd's Tortoise and Hare (Cycle Detection) |

---

### 📁 LIFO, Trees & Expression Nesting (`Leetcode-C/LIFO And Expression Nesting/`)

| # | Problem | File Name | Time Complexity | Space Complexity | Approach / Algorithm |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 94 | **Binary Tree Inorder Traversal** | [`Binary_Tree_Inorder.c`](./Leetcode-C/LIFO%20And%20Expression%20Nesting/Binary_Tree_Inorder.c) | $O(N)$ | $O(N)$ | Recursive DFS (Left $\to$ Root $\to$ Right) |
| 145 | **Binary Tree Postorder Traversal** | [`Binary_Tree_Postoder.c`](./Leetcode-C/LIFO%20And%20Expression%20Nesting/Binary_Tree_Postoder.c) | $O(N)$ | $O(N)$ | Recursive DFS (Left $\to$ Right $\to$ Root) |
| 225 | **Implement Stack using Queues** | [`Stack_Queue.c`](./Leetcode-C/LIFO%20And%20Expression%20Nesting/Stack_Queue.c) | Push: $O(N)$, Pop: $O(1)$ | $O(N)$ | Dynamic Circular Queue with Push Rotation |

---

## 🛠️ Technical Details & Explanations

### Leetcode #1: Two Sum
- **File:** [`Two_sum.c`](./Leetcode-C/Array/Two_sum.c)
- **Description:** Finds the two indices in an integer array that sum up to `target`.
- **Approach:** Uses a nested loop to check every possible pair $(i, j)$ until a match is found.

### Leetcode #3: Longest Substring Without Repeating Characters
- **File:** [`Longest_Substring.c`](./Leetcode-C/Array/Longest_Substring.c)
- **Description:** Finds the length of the longest substring with unique characters.
- **Approach:** Brute-force substring inspection with early termination upon encountering duplicate characters.

### Leetcode #5: Longest Palindromic Substring
- **File:** [`Longest_palindrome.c`](./Leetcode-C/Array/Longest_palindrome.c)
- **Description:** Finds the longest contiguous palindromic substring.
- **Approach:** Centers at each index and expands outwards for both odd-length (`i, i`) and even-length (`i, i+1`) palindromes.

### Leetcode #7: Reverse Integer
- **File:** [`Reverse_integer.c`](./Leetcode-C/Array/Reverse_integer.c)
- **Description:** Reverses the digits of a 32-bit signed integer.
- **Approach:** Extracts digits via modulo and checks bounds against `INT_MAX/10` and `INT_MIN/10` before multiplying.

### Leetcode #9: Palindrome Number
- **File:** [`Palindrome.c`](./Leetcode-C/Array/Palindrome.c)
- **Description:** Checks if an integer reads the same forwards and backwards.
- **Approach:** Reverses the second half of the number and directly compares it against the first half.

### Leetcode #14: Longest Common Prefix
- **File:** [`Longest_common.c`](./Leetcode-C/Array/Longest_common.c)
- **Description:** Finds the longest common prefix string among an array of strings.
- **Approach:** Vertical scanning compares characters across all strings at index `i` until a mismatch occurs.

### Leetcode #15: 3Sum
- **File:** [`3SUm.c`](./Leetcode-C/Array/3SUm.c)
- **Description:** Finds all unique triplets that sum to zero.
- **Approach:** Sorts the array and applies two-pointer (`left`, `right`) narrowing for each pivot, skipping duplicate elements.

### Leetcode #20: Valid Parentheses
- **File:** [`Valid_parentheses.c`](./Leetcode-C/Array/Valid_parentheses.c)
- **Description:** Determines if input string containing brackets is valid.
- **Approach:** Pushes opening brackets onto an array-based stack and pops them upon encountering corresponding closing brackets.

### Leetcode #21: Merge Two Sorted Lists
- **File:** [`Merge_list.c`](./Leetcode-C/Array/Merge_list.c)
- **Description:** Merges two sorted singly-linked lists into one sorted list.
- **Approach:** Uses a dummy node and a tail pointer, advancing the list pointer with the smaller value.

### Leetcode #26: Remove Duplicates from Sorted Array
- **File:** [`Remove_duplicates.c`](./Leetcode-C/Array/Remove_duplicates.c)
- **Description:** In-place deduplication of a sorted array.
- **Approach:** Two pointers: a read pointer scans and a write pointer `k` records new unique values.

### Leetcode #28: Find the Index of the First Occurrence in a String
- **File:** [`Find_index.c`](./Leetcode-C/Array/Find_index.c)
- **Description:** Returns the index of the first occurrence of needle in haystack.
- **Approach:** Sliding window checking match of `needle` characters starting at every valid position in `haystack`.

### Leetcode #32: Longest Valid Parentheses
- **File:** [`Longest_valid_parentheses.c`](./Leetcode-C/Array/Longest_valid_parentheses.c)
- **Description:** Finds the length of the longest valid (well-formed) parentheses substring.
- **Approach:** Uses a stack initialized with `-1` storing indices. On `)`, pops and computes current valid length (`i - stack[top]`).

### Leetcode #44: Wildcard Matching
- **File:** [`Wildcard_matching.c`](./Leetcode-C/Array/Wildcard_matching.c)
- **Description:** Pattern matching supporting `?` and `*`.
- **Approach:** Greedy matching with backtracking pointers for the last seen `*` and matching text position.

### Leetcode #75: Sort Colors
- **File:** [`Sort_colors.c`](./Leetcode-C/Array/Sort_colors.c)
- **Description:** Sorts an array containing 0s, 1s, and 2s in-place.
- **Approach:** Dutch National Flag algorithm maintaining `low`, `mid`, and `high` pointers in a single pass.

### Leetcode #80: Remove Duplicates from Sorted Array II
- **File:** [`Remove_duplicates_II.c`](./Leetcode-C/Array/Remove_duplicates_II.c)
- **Description:** Allows each unique element to appear at most twice in-place.
- **Approach:** Compares `nums[i]` against `nums[index - 2]` to allow a maximum frequency of 2.

### Leetcode #94: Binary Tree Inorder Traversal
- **File:** [`Binary_Tree_Inorder.c`](./Leetcode-C/LIFO%20And%20Expression%20Nesting/Binary_Tree_Inorder.c)
- **Description:** Traverses a binary tree in inorder order (Left -> Root -> Right).
- **Approach:** Recursively counts nodes to allocate exact memory, then performs recursive DFS traversal.

### Leetcode #128: Longest Consecutive Sequence
- **File:** [`Longest_consecutive.c`](./Leetcode-C/Array/Longest_consecutive.c)
- **Description:** Finds the length of the longest consecutive elements sequence.
- **Approach:** Sorts the array with `qsort` and counts consecutive streaks while ignoring duplicates.

### Leetcode #145: Binary Tree Postorder Traversal
- **File:** [`Binary_Tree_Postoder.c`](./Leetcode-C/LIFO%20And%20Expression%20Nesting/Binary_Tree_Postoder.c)
- **Description:** Traverses a binary tree in postorder order (Left -> Right -> Root).
- **Approach:** Recursively counts nodes to allocate exact memory, then traverses subtrees before recording the root.

### Leetcode #151: Reverse Words in a String
- **File:** [`Reverse_word.c`](./Leetcode-C/Array/Reverse_word.c)
- **Description:** Reverses the order of words and removes superfluous spaces.
- **Approach:** In-place three-step process: reverses full string, extracts/reverses individual words, and trims multiple spaces.

### Leetcode #189: Rotate Array
- **File:** [`Rotate_words.c`](./Leetcode-C/Array/Rotate_words.c)
- **Description:** Rotates the array to the right by `k` steps.
- **Approach:** Reverses the entire array, then reverses the first `k` elements, and finally reverses the remaining `N - k` elements.

### Leetcode #202: Happy Number
- **File:** [`Happy_Number.c`](./Leetcode-C/Array/Happy_Number.c)
- **Description:** Determines if repeatedly summing digit squares leads to 1.
- **Approach:** Uses Floyd's Cycle-Finding Algorithm (slow and fast pointers) to detect infinite loops.

### Leetcode #225: Implement Stack using Queues
- **File:** [`Stack_Queue.c`](./Leetcode-C/LIFO%20And%20Expression%20Nesting/Stack_Queue.c)
- **Description:** Implements LIFO stack operations using a circular FIFO queue.
- **Approach:** On `push`, adds the new element and rotates previous elements to the back of the queue so the newest element is always at the front.

### Leetcode #287: Find the Duplicate Number
- **File:** [`Find_duplicates.c`](./Leetcode-C/Array/Find_duplicates.c)
- **Description:** Finds duplicate number in an array of $N+1$ integers in range $[1, N]$.
- **Approach:** Treats array as a linked list and uses Floyd's Tortoise and Hare algorithm to detect the entry point of the cycle in $O(1)$ extra space.
