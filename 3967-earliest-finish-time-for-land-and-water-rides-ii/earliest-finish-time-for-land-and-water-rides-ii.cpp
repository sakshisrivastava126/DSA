class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        long long minLandFinish = LLONG_MAX;
        long long minWaterFinish = LLONG_MAX;
        
           for (int i = 0; i < n; i++) {
            minLandFinish = min(minLandFinish,
                                (long long)landStartTime[i] + landDuration[i]);
        }

        for (int j = 0; j < m; j++) {
            minWaterFinish = min(minWaterFinish,
                                 (long long)waterStartTime[j] + waterDuration[j]);
        }

        long long ans = LLONG_MAX;

        for (int j = 0; j < m; j++) {
            long long startWater = max(minLandFinish,
                                       (long long)waterStartTime[j]);

            ans = min(ans, startWater + waterDuration[j]);
        }

        for (int i = 0; i < n; i++) {
            long long startLand = max(minWaterFinish,
                                      (long long)landStartTime[i]);

            ans = min(ans, startLand + landDuration[i]);
        }

        return (int)ans;
    }
};