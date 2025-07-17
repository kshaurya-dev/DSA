/*LEETCODE - 875 coco eats bananas(a lot) arranged in an array of n piles ,
 piles[i] is no. of bananas on i'th pile.KOKO eats with a speed of k banans per
hour, an has a habit of eating only 1pile per hour.
your'e given h hours , find minimum speed koko needs to eat all the piles*/

 /*┈┈╱▔▔▔▔▔╲┈┈┈HM┈HM
┈╱┈┈╱▔╲╲╲▏┈┈┈HMMM
╱┈┈╱━╱▔▔▔▔▔╲━╮┈┈
▏┈▕┃▕╱▔╲╱▔╲▕╮┃┈┈
▏┈▕╰━▏▊▕▕▋▕▕━╯┈┈
╲┈┈╲╱▔╭╮▔▔┳╲╲┈┈┈            
┈╲┈┈▏╭━━━━╯▕▕┈┈┈
┈┈╲┈╲▂▂▂▂▂▂╱╱┈┈┈
┈┈┈┈▏┊┈┈┈┈┊┈┈┈╲┈
┈┈┈┈▏┊┈┈┈┈┊▕╲┈┈╲
┈╱▔╲▏┊┈┈┈┈┊▕╱▔╲▕
┈▏ ┈┈┈╰┈┈┈┈╯┈┈┈▕▕
┈╲┈┈┈╲┈┈┈┈╱┈┈┈╱┈╲
┈┈╲┈┈▕▔▔▔▔▏┈┈╱╲╲╲▏
┈╱▔┈┈▕┈┈┈┈▏┈┈▔╲▔▔
┈╲▂▂▂╱┈┈┈┈╲▂▂▂╱┈*/
using namespace std;
#include<bits/stdc++.h>
/*the question seems oogie_boogiely hard , but is quite simple , just check 
if koko can eat at all speed possible and  minimise it  , since 
speed is inherently sorted , we can optimise our speed using binary search
.............aaand that's it !!.......          */
int calculateTime(vector<int>piles , int speed){
    int hours=0;
    for(auto& pile:piles){
        hours += (pile + speed- 1) /speed;
    }
    return hours;
}
int main(){
    vector<int>piles={30,11,23,4,20};
    int h=6;
    int res=0;
    int high = *max_element(piles.begin(), piles.end());//max speed KOKO can eat
    int low=1;
    while(low<=high){
        int mid=low+(high-low)/2;
        int time=calculateTime(piles , mid);
        if(time>h)low=mid+1;//taking too much time , increase speed
        else{//alright , ok speed , let's try to minimise more
            res=mid;
            high=mid-1;
        } 
    }
    cout<<"minimum speed = "<<res;
    return 0;
}


