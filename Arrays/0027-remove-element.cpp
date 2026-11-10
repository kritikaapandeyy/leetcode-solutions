 27. Remove Element

**Platform:** LeetCode  
**Difficulty:** Easy  
**Topics:** Arrays, Two Pointers  
**Language:** C++

1. Problem Description

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` from the array.

The removal must be done **in-place**, which means we must modify the original array instead of creating a new one.

We need to:
- Keep all elements that are not equal to `val` at the beginning of the array.
- Return `k`, the number of elements remaining.
- The order of the remaining elements does not matter.
- The elements after the first `k` positions can be ignored.

 Example

**Input:**
```cpp
nums = [3, 2, 2, 3]
val = 3
```

**Explanation:**

We need to remove all occurrences of `3`.

The remaining elements are `2` and `2`.

After modifying the original array:

```cpp
nums = [2, 2, _, _]
```

Therefore, the number of remaining elements is:

```cpp
k = 2
```

**Output:** `2`

2. Approach – Two Pointer Technique

We use a single traversal of the array with two variables, `i` and `k`.

- `i` acts as the iterator that traverses the entire array.
- `k` keeps track of the number of valid elements and the next available position where a valid element should be placed.

Algorithm

1. Initialise `k = 0`.
2. Traverse the array using `i`, starting from index `0`.
3. For every element, check whether `nums[i] != val`.
4. If the condition is true:
   - Copy the element at index `i` to index `k` using `nums[k] = nums[i]`.
   - Increment `k` by `1`.
5. If the element is equal to `val`, skip it without changing `k`.
6. Continue until the entire array has been traversed.
7. Return `k`, which represents the number of elements that are not equal to `val`.

Complexity Analysis

- **Time Complexity: O(n)** – The array is traversed only once.
- **Space Complexity: O(1)** – The operation is performed in the original array without using any additional array.

3. Code
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int i,k = 0;
   for (i=0;i<nums.size();i++) {
    if(nums[i] != val){
        nums[k] = nums[i];
        k +=1;     }
    }
      return k;
 }

  
};
