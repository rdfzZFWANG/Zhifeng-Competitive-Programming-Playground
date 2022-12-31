/*
 * @lc app=leetcode id=1834 lang=cpp
 *
 * [1834] Single-Threaded CPU
 *
 * https://leetcode.com/problems/single-threaded-cpu/description/
 *
 * algorithms
 * Medium (41.69%)
 * Likes:    1472
 * Dislikes: 145
 * Total Accepted:    51.2K
 * Total Submissions: 118.2K
 * Testcase Example:  '[[1,2],[2,4],[3,2],[4,1]]'
 *
 * You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D
 * integer array tasks, where tasks[i] = [enqueueTimei, processingTimei] means
 * that the i^​​​​​​th​​​​ task will be available to process at enqueueTimei
 * and will take processingTimei to finish processing.
 * 
 * You have a single-threaded CPU that can process at most one task at a time
 * and will act in the following way:
 * 
 * 
 * If the CPU is idle and there are no available tasks to process, the CPU
 * remains idle.
 * If the CPU is idle and there are available tasks, the CPU will choose the
 * one with the shortest processing time. If multiple tasks have the same
 * shortest processing time, it will choose the task with the smallest
 * index.
 * Once a task is started, the CPU will process the entire task without
 * stopping.
 * The CPU can finish a task then start a new one instantly.
 * 
 * 
 * Return the order in which the CPU will process the tasks.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
 * Output: [0,2,3,1]
 * Explanation: The events go as follows: 
 * - At time = 1, task 0 is available to process. Available tasks = {0}.
 * - Also at time = 1, the idle CPU starts processing task 0. Available tasks =
 * {}.
 * - At time = 2, task 1 is available to process. Available tasks = {1}.
 * - At time = 3, task 2 is available to process. Available tasks = {1, 2}.
 * - Also at time = 3, the CPU finishes task 0 and starts processing task 2 as
 * it is the shortest. Available tasks = {1}.
 * - At time = 4, task 3 is available to process. Available tasks = {1, 3}.
 * - At time = 5, the CPU finishes task 2 and starts processing task 3 as it is
 * the shortest. Available tasks = {1}.
 * - At time = 6, the CPU finishes task 3 and starts processing task 1.
 * Available tasks = {}.
 * - At time = 10, the CPU finishes task 1 and becomes idle.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
 * Output: [4,3,2,0,1]
 * Explanation: The events go as follows:
 * - At time = 7, all the tasks become available. Available tasks =
 * {0,1,2,3,4}.
 * - Also at time = 7, the idle CPU starts processing task 4. Available tasks =
 * {0,1,2,3}.
 * - At time = 9, the CPU finishes task 4 and starts processing task 3.
 * Available tasks = {0,1,2}.
 * - At time = 13, the CPU finishes task 3 and starts processing task 2.
 * Available tasks = {0,1}.
 * - At time = 18, the CPU finishes task 2 and starts processing task 0.
 * Available tasks = {1}.
 * - At time = 28, the CPU finishes task 0 and starts processing task 1.
 * Available tasks = {}.
 * - At time = 40, the CPU finishes task 1 and becomes idle.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * tasks.length == n
 * 1 <= n <= 10^5
 * 1 <= enqueueTimei, processingTimei <= 10^9
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// @lc code=start
class Solution {
public:
    struct task {
        int start;
        int take;
        int idx;
        task(int s, int t, int i): start(s), take(t), idx(i) {}
        
        bool operator<(const task b) const {
            if (b.idx == idx && b.take == take) {
                return start > b.start;
            } else if (b.take == take) {
                return idx > b.idx;
            } else {
                return take > b.take;
            }
        }
    };
    static bool compare(const task& a, const task& b) {
        if (b.start == a.start && b.take == a.take) {
                return a.idx < b.idx;
            } else if (b.start == a.start) {
                return a.take < b.take;
            } else {
                return a.start < b.start;
        }
    }
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<task> vect;
        const int kSize = tasks.size();
        for (int i = 0; i < kSize; i++) {
            vector<int>& curr = tasks.at(i);
            vect.push_back(task(curr.at(0), curr.at(1), i));
        }
        sort(vect.begin(), vect.end(), compare);
        vector<int> ans; 
        priority_queue<task> pq;
        int i = 0;
        long long curr_time = vect.at(0).start;
        while (i < kSize || pq.size() > 0) {
            while (i < kSize && vect.at(i).start <= curr_time) {
                pq.push(vect.at(i));
                i++;
            }
            if (pq.size() > 0) {
                task next = pq.top();
                ans.push_back(next.idx);
                pq.pop();
                curr_time += next.take;
            } else {
                curr_time = vect.at(i).start;
                
            }
            
        }
        return ans;
    } // [[7,10],[7,12],[7,5],[7,4],[7,2]]
    //[[19,13],[16,9],[21,10],[32,25],[37,4],[49,24],[2,15],[38,41],[37,34],[33,6],[45,4],[18,18],[46,39],[12,24]]
};
// @lc code=end

