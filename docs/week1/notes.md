# Problem Outline

## Summary Guide

This document contains an outline of the approaches used in the various problems contained in this repository. Besides a rough apporach to the problems at hand, this document also contains an analysis (hopefully correct) of the solutions implemeneted, and if available, alternative solutions/algorithms which might prove to be more optimal than the current solution.

## Approach and Analysis

### Problems

#### 2sum

**Approach:**

I used the approach of 2 pointers for 2sum. This approach involves sorting the array first. Following that, we use 2 pointers, 1 at the start and 1 at the end of the list. If the sum is equal to the target, we return the original indexes of the numbers (pre-sorting). If the sum of the two numbers is less than the target, we increment the left pointer by 1. If the sum of the two numbers is more than the target, we decrement the right pointer by 1. If the right pointer becomes lesser or equal to the right pointer, the loop breaks and no solution exists (this should not happen in the context of the question as a solution is guaranteed).

**Analysis:**

The sorting of the list is O(n log n) while the obtaining the result is O(n). Hence the overall time complexity of this approach would be O(n log n).

Since we use a second vector to store the original indexes pre-sorting, the space complexity of this approach would be O(n).

**Possible Improvements:**

There is a possible theorectically better solution to 2sum, utilising a hashmap. The theorectical time complexity of using such a solution would be O(n).
