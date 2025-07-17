/*LEETCODE 74 - search an element in a sorted 2D matrix , i.e all elements in 
subsequent rows are sorted */
#include <bits/stdc++.h>
using namespace std;
int  main(){
    int target=105;
    vector<vector<int>>matrix={
        {1,3,5,7},
        {10,11,16,20},
        {23,30,34,60},
        {61,62,63,64},
        {80,81,82,83},
        {84,85,86,87},
        {88,89,90, 91},
        {
            100,101,102,105}
        };
    /*brute force will be to check each and every row , using two for loops
    , since elements are sorted and row indices are inherently sorted --- 
    -> we can half the matrix , to search for the correct row
    -> half the row to search the element
    -> complexity -  O(m*n)= O(m)+o(n)*/
    int m = matrix.size();
    int n = matrix[0].size();
    //searching the row
    int low=0;
    int high = m-1;
    while(low<=high){
        int middle=low+(high-low)/2;
        cout<<"search space : \n";
        for(int i = low ; i<=high ; ++i){
            for(int j=0 ; j<n; ++j)cout<<matrix[i][j]<<' ';
            cout<<'\n';
        }
        if ( matrix[middle][0]>target) high = middle-1;
        else if (matrix[middle][0]<target)low=middle+1;
        else{cout<<"found !";
            return 0;}
    }
    int left=0;
    int right=n-1;
    int row=low-1;//this is the row to search , which might contain target
    //if row is negative , it means element is out of range of every row
    if (row<0){
        cout<<"element out of range of matrix";
        return 0;}
    while(left<=right){
        int mid=left+(right-left)/2;
        if(matrix[row][mid]<target)left=mid+1;
        else if (matrix[row][mid]>target)right=mid-1;
        else {cout<<"found";
            return 0;}
    }
    cout<< "not found !";
    return 0;

}