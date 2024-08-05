class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        int count = 0;

        // Count the occurrences of each string
        for (const auto& x : arr) {
            mp[x]++;
        }

        // Iterate over the array to maintain the order of appearance
        for (const auto& x : arr) {
            if (mp[x] == 1) { // Check if the string is distinct
                count++;
                if (count == k) {
                    return x; // Return the kth distinct string
                }
            }
        }

        return ""; // If there are fewer than k distinct strings, return an empty string
    }
};
