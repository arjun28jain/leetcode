class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> result;
        
        for(auto x:nums){
            mp[x]++;
        }

       for(int i =1;  i<= nums.size(); i++){
            if(mp[i] == 0) result.push_back(i);
       }

        return result;
    }
};