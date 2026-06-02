class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        int ans = INT_MAX;

        for (int i = 0; i < landStartTime.size(); i++) {
            int landFinish = landStartTime[i] + landDuration[i];

            for (int j = 0; j < waterStartTime.size(); j++) {

                int waterFinish = waterStartTime[j] + waterDuration[j];

                int landThenWater =
                    max(waterStartTime[j], landFinish) + waterDuration[j];

                int waterThenLand =
                    max(landStartTime[i], waterFinish) + landDuration[i];

                ans = min(ans, min(landThenWater, waterThenLand));
            }
        }

        return ans;
    }
};