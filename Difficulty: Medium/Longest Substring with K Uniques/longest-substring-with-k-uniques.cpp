class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int len = -1;
        map<char, int> mp;
        while (r < n) {
            mp[s[r]]++;

            while (mp.size() > k) {
                mp[s[l]]--;
                if (mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            if (mp.size() == k)
                len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};