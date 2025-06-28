class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
               if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto& [card, count] : freq) {
            minHeap.push(card);
        }

        while (!minHeap.empty()) {
            int start = minHeap.top();  

            for (int i = 0; i < groupSize; i++) {
                int current = start + i;
                if (freq[current] == 0) return false;

                freq[current]--;
                if (freq[current] == 0) {
                    
                    if (current != minHeap.top()) return false;
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};
