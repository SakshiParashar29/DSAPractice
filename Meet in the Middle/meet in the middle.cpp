#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main() {
    long long n, x;
    cin >> n >> x;
    
    vector<long long> arr(n);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    long long n1 = n/2;
    long long n2 = n - n1;
    
    vector<long long> subsetA;
    vector<long long> subsetB;
    
    for(int i = 0; i < pow(2, n1); i++){
        long long sum = 0;
        for(int mask = 0; mask < n1; mask++){
            if(i & (1 << mask)){
                sum += arr[mask];
            }
        }
        subsetA.push_back(sum);
    }
    
    for(int i = 0; i < pow(2, n2); i++){
        long long sum = 0;
        for(int mask = 0; mask < n2; mask++){
            if(i & (1 << mask)){
                sum += arr[n1 + mask];
            }
        }
        subsetB.push_back(sum);
    }
    
    sort(begin(subsetB), end(subsetB));
    long long count = 0;
    
    for(int i = 0; i < subsetA.size(); i++){
        long long num = subsetA[i];
        long long sum = x - num;
        auto lower = lower_bound(begin(subsetB), end(subsetB), sum);
        auto upper = upper_bound(begin(subsetB), end(subsetB), sum);
        
        long long total = upper - lower;
        count += total;
    }
    cout << count << endl;
    return 0;
}
