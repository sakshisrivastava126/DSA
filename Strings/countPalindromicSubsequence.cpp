class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> st; //set lenge sare unique char store krenge
        
        int n =s.size();
        int ans = 0;

        for(char ch : s){ 
            st.insert(ch);
        }
        
        for(char ch : st){. //har ek char ko trverse krenge
            int l = -1, r = -1;
            
            for(int i=0; i<n; i++){ //unka first and last index nikalenge
                if(s[i] == ch){
                    if(l == -1) l = i;
                    r = i;
                }
            }
            set<char> st2; //ek aur set le kr first and last index ke bich ke unique char store krenge
            if(l != r){
                for(int i=l+1; i<r; i++){
                    st2.insert(s[i]);
                }
                ans += st2.size();
            }
            
        }
        return ans;
    }
};
