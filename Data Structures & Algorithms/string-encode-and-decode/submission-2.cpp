class Solution {
public:

    string encode(vector<string>& strs) {
        string code="";
        for(auto &s: strs){
            code=code+s+"-";
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        string w="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='-') {
                strs.push_back(w);
                w="";
            }
            else w=w+s[i];
        }
        return strs;
    }
};
