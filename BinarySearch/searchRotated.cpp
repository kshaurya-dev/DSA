/*leetcode 353 - search an element in a rotated sorted array*/
#include <bits/stdc++.h>
using namespace std;
/*let's take a no bullshit approach -----
--> find the pivot
--> binary search to the left and right of pivot , as both parts are sorted*/

bool binarySearch(vector<int>nums , int target , int left , int right){
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]>target)right=mid-1;
        else if (nums[mid]<target)left=mid+1;
        else return true;
    }
    return false;
}

int  main(){
    vector<int>nums={7,8,9,1,2,3,4,5};
    int target=100;
    //finding the pivot
    int low=0;
    int high=nums.size()-1;
    while(low<high){
        int mid=low+(high-low)/2;
        if(nums[mid]>nums[high])low=mid+1;//pivot must be on left,as subarray to right of mid is not sorted
        else if(nums[mid]<nums[high])high=mid;//subarray to right of mid is sorted, pivot is in the left subarray
        else{//when nums[mid]==nums[high]
            if(high>0 && nums[high]>=nums[high-1])high--;
            else low=high; /*potential pivot found  ,as this will be executed only when nums[mid-1]>nums[mid]
            hecne subarray is clearly  not sorted and high is the pivot...
            this is peculiar edge case handling method where we have a lot of 
            dulicates , i do understand why it works , but still this not at all
            intuitive ! */
            } 
    }
    int pivot = low;//now we have pivot , just implement binary search in left&right subarrays
    int result=binarySearch(nums,target , 0 , pivot-1);
    if(result){
        cout<<"found";
        return 0;
    }
    int res=binarySearch(nums,target , pivot ,nums.size()-1);
    if(res)cout<<"found";
    else cout<<"not found";
    return 0;
}



