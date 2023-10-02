#define ll long long
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll n = maxHeights.size();
        ll ans = 0;
        for(ll i=0;i<n;i++){
            ll indx = i;
            ll temp = maxHeights[i];
            ll prev = maxHeights[i];
            for(ll j=indx+1;j<n;j++){
                prev = min(prev, maxHeights[j]*1ll);
                temp += prev;
            }
            prev = maxHeights[i];
            for(ll j=indx-1;j>=0;j--){
                prev = min(prev, maxHeights[j]*1ll);
                temp += prev;
            }
            ans = max(ans, temp);
        }
        return ans;
    }
};