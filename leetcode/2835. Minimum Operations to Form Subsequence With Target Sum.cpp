#define ll long long
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        vector<ll> set_bits(32, 0);
        ll n = nums.size();
        ll s = 0;
        for(ll i=0;i<n;i++){
            set_bits[log2(nums[i])]++;
            s+=nums[i];
        }
        if(s<target) return -1;
        ll i = 0;
        ll cnt = 0;
        while(i<31){
            if((1<<i) & target){
                if(set_bits[i]){
                    set_bits[i]--;
                }
                else{
                    ll j = i;
                    while(j<31 && set_bits[j]==0){
                        j++;
                    }
                    cnt += (j-i);
                    set_bits[j]--;
                    while(j>i){
                        set_bits[--j]++;
                    }
                }
            }
            set_bits[i+1] += set_bits[i]/2;
            i++;
        }
        return cnt;
    }
};