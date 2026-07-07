class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size() == 0) return 0;
        sort(courses.begin(), courses.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        
        priority_queue<int> pq;
        int time = 0;
        for(auto it : courses){
            time += it[0];
            pq.push(it[0]);
            if(time > it[1]){
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};