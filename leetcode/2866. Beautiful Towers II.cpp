//here we have to use the concept of next smallest element
//so for that we have to use queue and the concept
//here is we will use the prev_sum and after_sum for a 
//particular index and use the concept of dp
#define ll long long
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        ll n = maxHeights.size();
        vector<ll> left(n,0);
        vector<ll> right(n,0);
        stack<ll> st;
        for(ll i=0;i<n;i++){
            while(!st.empty() && maxHeights[st.top()]>=maxHeights[i]) st.pop();
            if(st.empty()){
                left[i] = (i+1) *1ll* maxHeights[i];
            }else{
                left[i] = (i-st.top()) *1ll* maxHeights[i] + left[st.top()];
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(ll i=n-1;i>=0;i--){
            while(!st.empty() && maxHeights[st.top()]>=maxHeights[i]) st.pop();
            if(st.empty()){
                right[i] = (n-i) *1ll* maxHeights[i];
            }else{
                right[i] = (st.top()-i) *1ll* maxHeights[i] + right[st.top()];
            }
            st.push(i);
        }
        ll ans = 0;
        for(ll i=0;i<n;i++){
            ans = max(ans, left[i]+right[i]-maxHeights[i]);
        }
        return ans;
    }
};