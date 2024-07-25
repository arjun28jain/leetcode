#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpone;
        vector<int> result;

        for (auto x : nums1) {
            mpone[x]++;
        }

        for (auto y : nums2) {
            if (mpone[y] > 0) {
                result.push_back(y);
                mpone[y] = 0;
            }
        }

        return result;
    }
};
