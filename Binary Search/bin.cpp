#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N;
    cin>>N;
    int nums[N];
    for(int i =0 ; i<N ; i++)cin>>nums[i];
    int target;
    cin>>target;
    int left=0;
    int right=N-1;
    while(left<=right){
        int middle=(left+right)/2;
        if(middle==target){
            cout<<nums[middle];
            return 0;
        }
        else if(middle<target)right=middle-1;
        else if(middle>target)left=middle+1;
    }
}