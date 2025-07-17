#include<bits/stdc++.h>

bool helper(int n , int x){
    if(n==x)return true;
    if(x>n)return false;
    return (n , x*2);
}
int count_stairs(int n){
    std::cout<<helper(3 , 2);
    return 0;
}