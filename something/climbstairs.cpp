#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long dp[nums.size()];
        for (long i = 0; i < nums.size(); i++){
            dp[i] = 0;
        }
        dp[0]        = nums[0];
        long max_num = nums[0];
        for (long i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > max_num){
                max_num = dp[i];
            }
        }
        return max_num;
    }
};

int main(){
	
}
