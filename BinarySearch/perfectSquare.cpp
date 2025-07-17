/*LEETCODE 367 - tell if an integer is a perfect square
, no use of built in functions */
#include <bits/stdc++.h>
using namespace std;
int  main(){
    int N=37;
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
        cout<<"perfect square ! ";
        return 0;
    }
   }
   cout<<"NOT a perfect square !";
    return 0;

}