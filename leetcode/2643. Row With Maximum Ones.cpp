class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = 0;
        int mx = -1;
        int n = mat.size();
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(auto num: mat[i]){
                if(num) cnt++;
            }
            if(cnt>mx){
                row = i;
                mx = cnt;
            }
        }
        return {row, mx};
    }
};