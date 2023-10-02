class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.size();
        int indx  = (s.back()=='1')?0:-1;
        for(int i=0;i<n-1;i++){
            if(s[i]=='1'){
                if(indx==-1){
                    swap(s[i],s[n-1]);
                    indx=0;
                } else{
                    swap(s[i],s[indx]);
                    indx++;
                }
            }
        }
        return s;
    }
};