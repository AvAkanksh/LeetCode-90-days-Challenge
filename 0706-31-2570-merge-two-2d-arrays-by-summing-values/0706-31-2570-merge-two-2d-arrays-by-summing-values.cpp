class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int idx1 = 0;
        int idx2 = 0;
        while(idx1<nums1.size() && idx2<nums2.size()){
            if(nums1[idx1][0]<nums2[idx2][0]){
                ans.push_back(nums1[idx1]);
                idx1++;
            }else if(nums1[idx1][0]>nums2[idx2][0]){
                ans.push_back(nums2[idx2]);
                idx2++;
            }else{
                ans.push_back({nums1[idx1][0],nums1[idx1][1]+nums2[idx2][1]});
                idx1++;
                idx2++;
            }
        }
        while(idx1<nums1.size()){
            ans.push_back(nums1[idx1]);
            idx1++;
        }
        while(idx2<nums2.size()){
            ans.push_back(nums2[idx2]);
            idx2++;
        }
        return ans;
    }
};