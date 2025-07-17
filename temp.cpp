#include<bits/stdc++.h>
#include<numeric>
using namespace std;
int main(){
    int t;
    cin >>t;
    while(t--){
        int n ;
        vector<int> v(n);
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
        }
        int result = v[0];
        for (int i = 1; i < v.size(); ++i) {
            result = __gcd(result, v[i]);  
        }
        int count  = 0;
        for(int i = 0 ; i < n ; i++){
            if(v[i] != result) count++;
        }
        cout <<  result << endl;
    }
    return 0;
}