class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = (nums1.size()+nums2.size()+1)/2;
        int flag = (nums1.size()+nums2.size())%2;
        nums1.push_back(11111111);
        nums2.push_back(11111111);
        int index1=0,index2=0;
        double middle = -1;
        for(int i=0;i<len;i++)
        {
            if(nums1[index1]<nums2[index2])
            {
                middle = nums1[index1];
                index1++;
            }
            else
            {
                middle = nums2[index2];
                index2++;
            }
        }
        if(flag)
            return middle;
        double middle2 = 0;
        if(nums1[index1]<nums2[index2])
            middle2 = nums1[index1];
        else
            middle2 = nums2[index2];
        return (middle+middle2)/2;
    }
};

//1 1
//2 1
//3 2
//4 2
//5 3