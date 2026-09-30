class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> combinedArray;

        int i = 0;
        int j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] < nums2[j]){
                combinedArray.push_back(nums1[i]);
                i += 1;
            }else{
                combinedArray.push_back(nums2[j]);
                j += 1;
            }
        }

        while(i < n1){
            combinedArray.push_back(nums1[i]);
            i += 1;
        }

        while(j < n2){
            combinedArray.push_back(nums2[j]);
            j += 1;
        }

        int sz = combinedArray.size();
        if(sz%2 == 0){
            return (double)((combinedArray[(sz)/2-1] + combinedArray[sz/2])/2.0);
        }else{
            return (double)(combinedArray[(sz)/2]);
        }
        return 0.0;
    }
};
