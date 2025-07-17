/*LEETCODE 1011 -  you have array weights of n packages
where weights[i] is the weight of i'th package.
A ship has to ship 'em  , ship has a capacity , and each day it can ship packages
within its capacity. find least capacity need to ship packages within D days
     __|_|__|_|__
   _|____________|__
  |o o o o o o o o / 
~'`~'`~'`~'`~'`~'`~'`~
*/
using namespace std;
#include<bits/stdc++.h>
bool possible(vector<int>weights , int days , int capacity){
  int previous=0;//simulating the shipping process
  int time=1;
  for(auto& weight:weights){
    if(previous+weight>capacity){
      time++;
      previous=weight;}
    else previous+=weight;
  }
  return time<=days;
}
int main(){
  vector<int>weights={1,2,3,4,5,6,7,8,9,10};
  int days=5;
  int totalWeight=0;
  int res=0;
  for(auto& weight : weights)totalWeight+=weight;
  int high = totalWeight;//max capacity ,i.e shipping them all in a day
  int low = *max_element(weights.begin(), weights.end());//minimum one package has to be delivered
  while(low<=high){
    int mid =low+(high-low)/2;
    if (possible(weights , days , mid)){//possible to ship within days at this speed , lets minimize
      res=mid;
      high=mid-1;
    }
    else low=mid+1;//not enough speed , time to increase
  }
  cout<<"minimum speed = "<<res;
  return 0;
}