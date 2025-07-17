/*LEETCODE 74 - search an element in a  2D matrix with sorted rows and columns */
#include <bits/stdc++.h>
using namespace std;
int  main(){
    int target=26;
    vector<vector<int>>matrix={
            {1,4,7,11,15}
            ,{2,5,8,12,19}
            ,{3,6,9,16,22}
            ,{10,13,14,17,24}
            ,{18,21,23,26,30}
            };
        /*this question is more intuitive than it seems , take the top-right
        corner , if target is smaller than the chosen element , where it 
        could be ? definitly increasing the row cause the lower we go , the
        bigger elements we get  as it is sorted- hence moving
        down  makes sense , we increment row , go down ;) !
        what if chosen el is greater than el ? decrement column , move back-
        wards , why ? cause the backwards we go , elements become smaller 
        and smaller !
        repeat this until we have the target !
         */
        int row=0;
        int col=matrix[0].size()-1;
        while(row<matrix.size() && col>=0 ){
            if(matrix[row][col]>target)col--;
            else if (matrix[row][col]<target)row++;
            else {
                cout<<"found ! ";
                return 0;
            }
        }
        cout<<"not found !";
        return 0;
}