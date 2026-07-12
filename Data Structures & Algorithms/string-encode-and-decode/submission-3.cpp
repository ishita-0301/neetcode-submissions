/*OPTIMAL: #3cat. while decoding, if you see# take next 3 chars
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";

        for (string &s : strs) {
            res += to_string(s.size()) + "#" + s;
        }

        return res;
    }

    vector<string> decode(string s) {

        vector<string> ans;

        int i = 0;

        while (i < s.size()) {

            int j = i;

            // Find the delimiter '#'
            while (s[j] != '#')
                j++;

            // Length of current string
            int len = stoi(s.substr(i, j - i));

            // Extract the string
            ans.push_back(s.substr(j + 1, len));

            // Move to the next encoded string
            i = j + 1 + len;
        }

        return ans;
    }
};
*/
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

