// In this problem, we will see the index as node's value and number<int> as pointer
// FloyD's Algorithm to find the first intersection of slow and fast pointer called A
// Then Use another slow pointer and keep incrementing it (and slow also) until they intersec called B
// Why the intersec is the answer
// We know that:
//              2 * slow = fast
// slow will travel: p : length to B destination
//                   C - x: length to A destionation

// fast will travel: p : length to B destination
//                   C - x: length to A destionation
//                   C : one more time because it is fast

// => 2 (p + C - x) = p + C - x + C
// => p = x
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        int slow2 = 0;

        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) break;
        }

        while(true) {
            slow = nums[slow];
            slow2 = nums[slow2];

            if(slow == slow2) return slow;
        }
    }
};
