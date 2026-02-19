class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans;

        map<string, vector<string>> mp;

        for (string str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
          
            if (mp.find(temp) != mp.end()) {
                auto it = mp.find(temp);
                it->second.push_back(str);
            } else {
                mp[temp] = {str};
            }
        }

        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};