/*LEETCODE 69 - find square root */
#include <bits/stdc++.h>
using namespace std;
int  main(){
    int N=43;
    /*so we can iterate over each num from 1 to N , square 
    them and  check if it is equal to N , this take linear time but instead to 
    improve complexity we can use binary search as 1 to N is sorted by nature 
    , thus reducing our search space ! 
    */
   int low=1;
   int high =N;
   while(low<=high){
    cout<<"SEARCH SPACE : ";
    for(int i =low ; i<=high ; ++i ) cout<<i<<' ';
    cout<<'\n';

    int middle=low+(high-low)/2;
    if(middle*middle>N)high=middle-1;
    else if (middle*middle<N)low=middle+1;
    else{
        cout<<"squre root = "<<middle;
        return 0;
    }
   }
   cout<<"squre root (rounded off) = "<<low-1;
   /*hmmmmm interesting ! if N isn't a perfect square , we should round off to
   the nearest int , and it "low" has the ceiling value , so we return low-1 
   , flooring it ! */
    return 0;

}