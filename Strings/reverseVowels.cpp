class Solution {
public:
    string reverseVowels(string s) {
        set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        //take two pointers and move one from left and one from right
        int left = 0;
        int right = s.size()-1;

        while(left<right){
            //find vowels in set and swap
            if(vowels.find(s[left]) != vowels.end() && vowels.find(s[right]) != vowels.end()){
                swap(s[left], s[right]);
                left++;
                right--;
            }
            else if(vowels.find(s[left]) != vowels.end() && vowels.find(s[right]) == vowels.end()){
                right--;
            }
            else{
                left++;
            }
        }
        return s;
    }
};
