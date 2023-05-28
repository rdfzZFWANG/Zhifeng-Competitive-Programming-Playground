---
title: "Competetive Programming Learning Notes"
author: Zhifeng Wang
date: May 17th, 2023
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output: pdf_document
---

# Leetcode

---

## Leetcode.347. Top K Frequent Elements 

- Independently solved, but slow; 20230522

I used unordered map and priority queue to solve it.

---

## Leetcode.399. Evaluate Division 

- Independently solved; 20230520

Not completely sure how I managed to solve it independently. I'm just having a intuition that all variables can link to a "base" variable and use it to quickly calculate the answer to queries. Therefore, I think a modified version of union-find algorithm would be useful.

---

## Leetcode.703. Kth Largest Element In A Stream 

- Independently solved; 20230523

I used a map, a binary search tree, to solve this problem. This question is a good practice for iterators.

---

## Leetcode.785. Is Graph Bipartite 

- Independently solved; 20230519

I used BFS to solve this problem. I forgot that the graphs might have multiple components at first, and then I added the outer for-loop to check through all graph components.

---

## Leetcode.837. New 21 Game 

- Independently solved (Hinted by Big O); 20230525

Following the main idea of the previous few days, this question also tests the concept of maintaining some data structure of a specific size, popping old elements when new elements arrive. 

In this question, while also examing the basic idea of dynamic programming, the critical point is calculating the sum of probabilities of previously calculated information. To achieve that, instead of looping through, I use a circular queue to quickly calculate the sum of the previous "maxPts" number of probability. The circular queue allows me to update the sum of probabilities in constant time. You can maintain a sum in a variable, deduct the sum of the first element of the queue, and add the incoming new probability to quickly update the sum. 

---

## Leetcode.934. Shortest Bridge 

- Independently solved; 20230521

This question tests the idea of using BFS with multiple starting points. I first find a single starting point of one of the islands, identify all the nodes of the island, and finally use BFS with multiple starting points to find the distance between the two islands.

---

## Leetcode.1140. Stone Game II

- Unknown, probably learned; 20220822

This question tests the idea of memorized DFS. The critical trick would be using the suffix sum to quickly calculate the total score one player gets with the total score their opponent gets.

---

## Leetcode.1547. Minimum Cost To Cut A Stick

- Independently solved (hinted by tags and titles); 20230528

This problem can be solved by dynamic programming. I came up with a bottom-up dynamic programming technique, which calculates the subproblems with a few cuts and builds up information to solve larger subproblems.

---
## Leetcode.1557. Minimum Number of Vertices to Reach All Nodes 

- Independently solved; 20230518

At first, I thought I should try "Union Find" with "merging by size" or other similar ideas. But later, I figured out that I must include all the nodes with zero in-going edges and shouldn't include any nodes with in-going edges.

---

## Leetcode.2542. Maximum Subsequent Score 

- Learned from solution; 20230524

The basic idea is the same as Leetcode.703 from yesterday. You need to maintain some data structure of size k and pop something out when the size is over k.