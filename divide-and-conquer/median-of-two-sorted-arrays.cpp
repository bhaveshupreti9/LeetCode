class Solution {
public:
    vector<int> Merge(vector<int>arr1,int n1,vector<int>arr2,int n2){
        vector<int>temp;
        int low = 0;
        int high = 0;
        while(low < n1 && high < n2){
            if(arr1[low]>arr2[high]){
                temp.push_back(arr2[high]);
                high++;
            }
            else {
                temp.push_back(arr1[low]);
                low++;
            }
        }
        while(low < n1){
            temp.push_back(arr1[low]);
            low++;
        }
        while(high<n2){
            temp.push_back(arr2[high]);
            high++;
        }
        return temp;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int>arr = Merge(nums1,n1,nums2,n2);
        int n = arr.size();
        if(n %2 != 0)return arr[n/2];
        else return (double)(arr[(n)/2-1]+arr[n/2])/2;
    }
};