# Leetcode C Solutions

A curated collection of Leetcode problems implemented in C, showing fundamental data structures and algorithms.

## Analysis of Solutions

| Problem | File Name | Time Complexity | Space Complexity | Approach / Algorithm |
| :--- | :--- | :--- | :--- | :--- |
| **Two Sum** | [`Two_SUm.c`](./Leetcode-C/Two_SUm.c) | $O(N^2)$ | $O(1)$ | Brute Force / Double Loop |
| **3Sum** | [`3sum.c`](./Leetcode-C/3sum.c) | $O(N^2)$ | $O(\log N)$ or $O(N)$ | Sorting + Two Pointers |
| **Longest Substring Without Repeating Characters** | [`Longest_Substring.c`](./Leetcode-C/Longest_Substring.c) | $O(N^3)$ | $O(1)$ | Brute Force Substring Search |
| **Reverse Integer** | [`Reverse_Integer.c`](./Leetcode-C/Reverse_Integer.c) | $O(\log_{10} X)$ | $O(1)$ | Digit manipulation with overflow checks |
| **Remove Duplicates from Sorted Array** | [`Remove_Duplicates.c`](./Leetcode-C/Remove_Duplicates.c) | $O(N)$ | $O(1)$ | Two Pointers (In-place) |
| **Remove Duplicates from Sorted Array II** | [`Remove_Duplicates_AsrrayII.c`](./Leetcode-C/Remove_Duplicates_AsrrayII.c) | $O(N)$ | $O(1)$ | Two Pointers (At most 2 occurrences) |
| **Happy Number** | [`Happy_Number.c`](./Leetcode-C/Happy_Number.c) | $O(\log N)$ | $O(1)$ | Floyd's Cycle-Finding Algorithm |
| **Sort Colors** | [`Sort_Colors.c`](./Leetcode-C/Sort_Colors.c) | $O(N)$ | $O(1)$ | Dutch National Flag Algorithm (3-way partition) |
| **Wildcard Matching** | [`Wildcard_Matching.c`](./Leetcode-C/Wildcard_Matching.c) | $O(N)$ average | $O(1)$ | Greedy Backtracking |

---

## Technical Details

### 1. Two Sum ([`Two_SUm.c`](./Leetcode-C/Two_SUm.c))
- **Description:** Finds the indices of two numbers in an array that add up to a specific target.
- **Approach:** Iterates through every possible pair of elements using nested loops to locate the matching pair.

### 2. 3Sum ([`3sum.c`](./Leetcode-C/3sum.c))
- **Description:** Finds all unique triplets in an array that sum up to zero.
- **Approach:** Sorts the array first. Iterates through the elements and uses a classic two-pointer search (`left` and `right`) to find matching pairs for each pivot, skipping duplicate values to prevent duplicate triplets.

### 3. Longest Substring Without Repeating Characters ([`Longest_Substring.c`](./Leetcode-C/Longest_Substring.c))
- **Description:** Returns the length of the longest substring containing no repeating characters.
- **Approach:** Checks the uniqueness of characters in all possible substrings starting from each index, terminating early when a duplicate is encountered.

### 4. Reverse Integer ([`Reverse_Integer.c`](./Leetcode-C/Reverse_Integer.c))
- **Description:** Reverses the digits of a 32-bit signed integer.
- **Approach:** Repeatedly extracts the last digit using modulo and adds it to the reversed number, checking for potential 32-bit overflow/underflow conditions at each step before multiplying.

### 5. Remove Duplicates from Sorted Array ([`Remove_Duplicates.c`](./Leetcode-C/Remove_Duplicates.c))
- **Description:** Modifies a sorted array in-place to keep only unique elements.
- **Approach:** Uses a write-pointer `k` that only advances and writes when the current element is different from the previous element.

### 6. Remove Duplicates from Sorted Array II ([`Remove_Duplicates_AsrrayII.c`](./Leetcode-C/Remove_Duplicates_AsrrayII.c))
- **Description:** Modifies a sorted array in-place allowing each unique element to appear at most twice.
- **Approach:** Keeps a write pointer and compares the current element against the element two positions behind the write pointer (`nums[index-2]`).

### 7. Happy Number ([`Happy_Number.c`](./Leetcode-C/Happy_Number.c))
- **Description:** Checks if replacing a number with the sum of the squares of its digits eventually leads to 1.
- **Approach:** Uses Floyd's Cycle-Finding Algorithm (slow and fast runner) to trace the chain of numbers. If there is a cycle, the slow and fast runners will meet. If the chain reaches 1, it's a happy number.

### 8. Sort Colors ([`Sort_Colors.c`](./Leetcode-C/Sort_Colors.c))
- **Description:** Sorts an array containing 0s, 1s, and 2s in-place (objects of red, white, and blue colors).
- **Approach:** Implements the Dutch National Flag algorithm. It maintains three pointers (`low`, `mid`, `high`) and swaps elements to place all 0s at the start and all 2s at the end in a single pass.

### 9. Wildcard Matching ([`Wildcard_Matching.c`](./Leetcode-C/Wildcard_Matching.c))
- **Description:** Performs wildcard pattern matching for strings with support for `?` (any single character) and `*` (any sequence of characters).
- **Approach:** Employs a greedy search technique with backtracking using pointers to track the last star position and matching index in the string.
