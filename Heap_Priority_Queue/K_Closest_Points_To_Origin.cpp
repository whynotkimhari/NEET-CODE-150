class Compare {
    public:
    bool operator()(pair<double, vector<int>> below, pair<double, vector<int>> above) {
        return below.first > above.first;
    }
};

class Solution {
public:
    double distance(vector<int> &A) {
        return sqrt(A[0] * A[0] + A[1] * A[1]);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> answer;

        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, Compare> pq;

        for(auto &point: points) {
            pq.push({distance(point), point});
        }

        while(k--) {
            answer.push_back(pq.top().second);
            pq.pop();
        }

        return answer;
    }
};
