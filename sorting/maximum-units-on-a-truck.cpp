class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);

        int ans = 0;

        for (auto &it : boxTypes) {
            int boxes = min(it[0], truckSize);

            ans += boxes * it[1];
            truckSize -= boxes;

            if (truckSize == 0)
                break;
        }

        return ans;
    }
};