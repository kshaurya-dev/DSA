#include<bits/stdc++.h>
int count_stairs(int n){
    if(n==1)return 1;
    if(n==2)return 2;
    return count_stairs(n-1)+count_stairs(n-2);
    /*we can go either with 1 step or 2 step 
    so for 1 step stairway - > only 1 step possible | for a 2 way -> you either take 1 step
    or 2 step , so 2 ways are possible
    lets say stairway is 3 - you either take one step = your newposition is same as if you
    are on a 2 length stairway ! 
    either you take 2 step ,uhhh then the situation like a 1 length stairway
    So the number possible steps to reach n'th step depends on HOW MANY POSSIBLE STEPS
    WERE TAKEN TO REACH THE LAST 2 STEPS*/

    //it just an application of fibonacci series XD
}
int dp(int n){
    int n1=1;
    int n2=2;
    if(n==1)return n1;
    if (n==2)return n2;
    int count=0;
    for(int i =3 ; i<=3 ; i++){
        count=n1+n2;
        n1=n2;
        n2=count;
    }
    return count;
    /*huh , you thought DP is some optimus prime shit ?? neeewwwwbbbbb*/
}
int main(){
    int n=3;
    std::cout<<"No. of ways(by recursion)="<<count_stairs(n);
    std::cout<<"\nNo. of ways(by dp)="<<dp(n);
    return 0;
}