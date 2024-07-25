#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        if (nums.empty()) return nums;

        int minVal = findMin(nums);
        int maxVal = findMax(nums);

        int bucketCount = nums.size();
        int bucketRange = (maxVal - minVal) / bucketCount + 1;

        std::vector<std::vector<int>> buckets(bucketCount);

        for (int num : nums) {
            int bucketIndex = (num - minVal) / bucketRange;
            buckets[bucketIndex].push_back(num);
        }

        std::vector<int> sortedArray;
        for (auto& bucket : buckets) {
            insertionSort(bucket);
            for (int num : bucket) {
                sortedArray.push_back(num);
            }
        }

        return sortedArray;
    }

private:
    int findMin(const std::vector<int>& nums) {
        int minVal = nums[0];
        for (int num : nums) {
            if (num < minVal) {
                minVal = num;
            }
        }
        return minVal;
    }

    int findMax(const std::vector<int>& nums) {
        int maxVal = nums[0];
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        return maxVal;
    }

    void insertionSort(std::vector<int>& bucket) {
        for (int i = 1; i < bucket.size(); ++i) {
            int key = bucket[i];
            int j = i - 1;
            while (j >= 0 && bucket[j] > key) {
                bucket[j + 1] = bucket[j];
                --j;
            }
            bucket[j + 1] = key;
        }
    }
};
