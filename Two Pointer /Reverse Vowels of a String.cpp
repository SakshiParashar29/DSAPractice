//Time Complexity : O(N) and Space Complexity : O(1)
class Solution {
public:
    int isVow(char c){
        int cnt = 0;
        switch(toupper(c)){
            case 'A' :
            case 'E' :
            case 'I' :
            case 'O' :
            case 'U' :
            cnt++;
        }
        if(cnt) return true;
        else return false;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            if(isVow(s[i]) && isVow(s[j])){
                swap(s[i], s[j]);
                i++;
                j--;
            }
            else if(!(isVow(s[i])) && isVow(s[j])){
                i++;
            }
            else if(!(isVow(s[j])) && isVow(s[i])){
                j--;
            }
            else{
                i++; j--;
            }
        }
        return s;
    }
};
