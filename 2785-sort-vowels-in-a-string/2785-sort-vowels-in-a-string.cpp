class Solution {
public:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string sortVowels(string s) {
        // Approach --> 1 Using sorting
        string temp;
        for(char &ch : s) {
            if(isVowel(ch)) {
                temp.push_back(ch);
            }
        }

        sort(temp.begin(), temp.end());
        int j = 0;

        for(int i = 0; i < s.length(); i++) {
            if(isVowel(s[i])) {
                s[i] = temp[j];
                j++;
            }
        }

        return s;
    }
};