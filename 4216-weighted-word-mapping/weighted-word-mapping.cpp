class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        unordered_map<int, char> mp;
        mp[0] = 'z';
        mp[1] = 'y';
        mp[2] = 'x';
        mp[3] = 'w';
        mp[4] = 'v';
        mp[5] = 'u';
        mp[6] = 't';
        mp[7] = 's';
        mp[8] = 'r';
        mp[9] = 'q';
        mp[10] = 'p';
        mp[11] = 'o';
        mp[12] = 'n';
        mp[13] = 'm';
        mp[14] = 'l';
        mp[15] = 'k';
        mp[16] = 'j';
        mp[17] = 'i';
        mp[18] = 'h';
        mp[19] = 'g';
        mp[20] = 'f';
        mp[21] = 'e';
        mp[22] = 'd';
        mp[23] = 'c';  
        mp[24] = 'b';
        mp[25] = 'a';

        string ans = "";
        for(int i=0; i<words.size(); i++) {
            string str = words[i];
            int sum = 0;
            for(int j=0; j<str.size(); j++) {
                int val = str[j]-'a';
                sum += weights[val];
            }
            sum = sum%26;
            ans.push_back(mp[sum]);
        }
        return ans;
    }
};