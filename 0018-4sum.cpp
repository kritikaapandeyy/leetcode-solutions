# 18. 4Sum

**Platform:** LeetCode  
**Difficulty:** Medium  
**Topics:** Arrays, Two Pointers, Sorting  
**Language:** C++

## 1. Problem Description

Given an integer array `nums` and an integer `target`, find all unique combinations of four elements whose sum equals the given target.

We need to:
- Select four elements from the array using four distinct indices.
- Ensure that the sum of these four elements equals `target`.
- Return all possible **unique quadruplets**.
- Avoid including duplicate combinations in the answer.

The elements in the original array can contain duplicates, and valid quadruplets can also contain duplicate values.

**Example**

**Input:**
```cpp
nums = [1, 0, -1, 0, -2, 2]
target = 0
```

**Explanation:**

We need to find four numbers whose sum equals `0`.

The valid unique combinations are:

```cpp
[-2, -1, 1, 2]
[-2, 0, 0, 2]
[-1, 0, 0, 1]
```

Each of these combinations adds up to the target value.

**Output:**
```cpp
[
    [-2, -1, 1, 2],
    [-2, 0, 0, 2],
    [-1, 0, 0, 1]
]
```

## 2. Approach – Sorting and Two Pointer Technique

We use sorting, two nested loops to fix two elements, and two pointers to find the remaining two elements.

The array is first sorted in ascending order. This allows us to use the two-pointer technique efficiently and skip duplicate elements.

**Algorithm**

1. Initialise an empty 2D vector `ans` to store all valid quadruplets.
2. Find the size of the array and sort it using `sort(nums.begin(), nums.end())`.
3. Use the first loop with variable `i` to select the first element.
4. Use a second nested loop with variable `j` to select the second element.
5. Initialise two pointers:
   - `left = j + 1`, pointing to the element immediately after `j`.
   - `right = n - 1`, pointing to the last element.
6. Calculate the sum of the four selected elements:
   `nums[i] + nums[j] + nums[left] + nums[right]`.
7. Compare the sum with the target:
   - If the sum is smaller than the target, increment `left` to obtain a larger sum.
   - If the sum is greater than the target, decrement `right` to obtain a smaller sum.
   - If the sum equals the target, store the four elements in `ans`.
8. After finding a valid quadruplet, move both pointers inward and skip duplicate elements to avoid storing the same combination again.
9. Skip duplicate values for `i` and `j` as well.
10. Continue until all possible combinations have been checked.
11. Return `ans`.

**Complexity Analysis**

- **Time Complexity: O(n³)** – Sorting takes O(n log n). The two nested loops combined with the two-pointer traversal take O(n³).
- **Space Complexity: O(1)** – The algorithm uses constant auxiliary space, excluding the sorting implementation and the space required to store the answer.

## 3. Code

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {

                    long long sum = (long long)nums[i] + nums[j]
                                  + nums[left] + nums[right];

                    if (sum < target) {
                        left++;
                    }
                    else if (sum > target) {
                        right--;
                    }
                    else {
                        ans.push_back({
                            nums[i], nums[j],
                            nums[left], nums[right]
                        });

                        left++;
                        right--;

                        while (left < right &&
                               nums[left] == nums[left - 1])
                            left++;

                        while (left < right &&
                               nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }

        return ans;
    }
};
