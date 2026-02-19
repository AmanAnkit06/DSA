class Solution {
public:
    bool isAnagram(string s, string t) {
        //approach 1----

        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        return (s==t)?true:false;

        //approach 2---
        
    }
};