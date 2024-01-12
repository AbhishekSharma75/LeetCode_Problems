class Solution {
public:
    bool isVowel(char &c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    bool halvesAreAlike(string s) {
        int n = s.length();
        int i = 0, j = n/2;
        int leftCount = 0, rightCount = 0;

        while(i < n/2 && j < n) {
            if(isVowel(s[i])) leftCount++;
            if(isVowel(s[j])) rightCount++;
                
            i++;
            j++;
        }
        
        if(leftCount == rightCount) return true;
        return false;
    }
}; 