class Solution {
public:
    int characterReplacement(string s, int k) {
     int maxFreq=0; int ans=0;
     int l=0,r=0;
     vector<int> freq(26,0);
    while(r<s.size()){
            freq[s[r]-'A']++;//hashing
            maxFreq=max(maxFreq,freq[s[r]-'A']);
            while((r-l+1)-maxFreq>k) {//window-maxfreq
                freq[s[l]-'A']--;
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
