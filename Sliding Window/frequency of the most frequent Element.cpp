//Non-shrinkable template
int i = 0, j = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    if (invalid()) { // Increment the left edge ONLY when the window is invalid. In this way, the window GROWs when it's valid, and SHIFTs when it's invalid
        // CODE: update state using A[i]
        ++i;
    }
    // after `++j` in the for loop, this window `[i, j)` of length `j - i` MIGHT be valid.
}
return j - i;

//Shrinkable template
int i = 0, j = 0, ans = 0;
for (; j < N; ++j) {
    // CODE: use A[j] to update state which might make the window invalid
    for (; invalid(); ++i) { // when invalid, keep shrinking the left edge until it's valid again
        // CODE: update state using A[i]
    }
    ans = max(ans, j - i + 1); // the window [i, j] is the maximum window we've found thus far
}
return ans;

//always question this two what is the state and what is invalid then accordingly you can adjust the window size and solve.
// What should we use as the state? It should be the sum of numbers in the window
// How to determine invalid? The window is invalid if (j - i + 1) * A[j] - sum > k.



// Non-shrinkable approach
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int i = 0, res = 1, j = 0;
        long long sum = 0;

        for(j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            // number of elements * target - sum
            if((j - i + 1) * 1LL * nums[j] - sum > k)
               sum -= nums[i++];
            
            // res = max(res, j - i  + 1);
        }
        return j - i;
    }
};

//Shrinkable approach
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int i = 0, res = 1;
        long long sum = 0;

        for(int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            while((j - i + 1) * 1LL * nums[j] - sum > k)
               sum -= nums[i++];
            
            res = max(res, j - i  + 1);
        }
        return res;
    }
};
