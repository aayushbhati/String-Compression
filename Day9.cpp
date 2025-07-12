class Solution {
public:
    int compress(vector<char>& chars) {
        int count = 1;
        vector<string> ans;
        
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i - 1] == chars[i]) {
                count++;
            } else {
                ans.push_back(string(1, chars[i - 1]));
                if (count > 1) {
                    ans.push_back(to_string(count)); 
                }
                count = 1;
            }
        }
        
        
        ans.push_back(string(1, chars[chars.size() - 1]));
        if (count > 1) {
            ans.push_back(to_string(count));
        }
        
        
        chars.clear();
        for (const auto& str : ans) {
            for (char c : str) {
                chars.push_back(c);
            }
        }
        
        return chars.size();
    }
};
