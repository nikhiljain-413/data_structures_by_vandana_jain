class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        for(int i=1;i<=k;i++) st.insert(i);
        int cnt = 0;
        while(true){
            // if(st.count(nums.back()))
                st.erase(nums.back());
            nums.pop_back();
            cnt++;
            if(st.size()==0) return cnt;
        }
        return -1;
    }
};