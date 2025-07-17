#include <bits/stdc++.h>
using namespace std;

class LongestKDistinct {
public:
    static int brute_force(const vector<int>& nums, int k) {
/*BRUTE FORCE-Simply generate all possible subarrays ,to check distinct element=k , use set.size()*/
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            set<int> s;
            for (int j = i; j < nums.size(); j++) {
                s.insert(nums[j]);
                if (s.size() > k) break;
                res = max(res, j - i + 1);
            }
        }
        return res;
    }

    static int better(const vector<int>& nums, int k) {
/*now the optimal approach is very iggly-wiggly. So we use a map to store
the elements and also their frequency this time ....so take right pointer ,
add the element to map , until our map's size is more than k...now 
we gotta reduce size of map until it is k ....so keep removing element 
which is at left until it is completely removed*/
        unordered_map<int, int> freq;
        int left = 0, right = 0, res = 0;

        while (right < nums.size()) {
            freq[nums[right]]++;

            while (freq.size() > k) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
/*so this while loop confused me a lot .... but it works by removing value 
at left until its frequency is zero , lets visualise it -
say the subarray is - [1,2,1,2,1,3] ,when right goes at the end , map's size
is more than two, so we move left pointer , decreasig 1's frequency , then 2's
frequency , and then so on .... the very moment left pointers frequency goes 
0 - we erase it , thus map size is now 2 !*/
            res = max(res, right - left + 1);
            right++;
        }

        return res;
    }

    static int optimal(const vector<int>& nums, int k) {
        return better(nums, k); // same for now
    }
};
