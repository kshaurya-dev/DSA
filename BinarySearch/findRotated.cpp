/*leetcode 153 - find minimum in rotated sorted array*/
#include <bits/stdc++.h>
//fuck this question
using namespace std;
int  main(){
    vector<int>nums={7,8,9,1,2,3,4,5};
    int low=0;
    int high=nums.size()-1;
    while(low<high){
        int middle = low+(high-low)/2;
        cout<<"middle="<<middle<<"  search Space : ";
        for(int i =low ; i<=high ; ++i)cout<<nums[i]<<' ';
        cout<<'\n';
        if (nums[middle]>nums[high])low=middle+1;
        else high = middle;
    }
        /* if mid is lower than high means ,hence array is sorted from mid to high,
        so pivot must be on left of mid ,if its actually greater than mid , means our pivot is on the right
        of mid .......
        BIG BIG BIG , FUKCIN HUGE , MASSIVE , GODAMMN humangasour shit \`o`/
        --> the pivot is actually the lowest/smallest element , use this 
        godsend note in search rotated array 
        but but but bruhhh , why not just search the smallest elemet 🤓 , 
        it will be O(n)  , this is O(log n ) !!       */
    cout<<nums[low];
    return 0;
}