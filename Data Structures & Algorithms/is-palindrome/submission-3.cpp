class Solution {
public:
    bool isPalindrome(string s) {
        int i=0; int j=s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){i++; continue;}//if not continue,"a."
            if(!isalnum(s[j])){j--; continue;}//j=a, then shows palin
            if(tolower(s[i])!=tolower(s[j])) return false;
            i++; j--; 
        }
        return true;
    }
};
