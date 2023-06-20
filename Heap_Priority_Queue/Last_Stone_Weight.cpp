class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &stone: stones) pq.push(stone);
        while(pq.size() >= 2) {
            auto r1 = pq.top(); pq.pop();
            auto r2 = pq.top(); pq.pop();
            if(r1 == r2) continue;
            else {
                pq.push(abs(r1 - r2));
            }
        }

        if(pq.size()) {
            return pq.top();
        }
        else return 0;
    }
};
