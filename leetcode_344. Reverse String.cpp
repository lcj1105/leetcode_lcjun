class Solution {
public:
    string reverseString(string s) {
        string sTemp;
        sTemp = s;
        for(int i=0;i<s.size();i++)
            s [i]= sTemp[s.size() - 1 -i];
        return s;
    }
};