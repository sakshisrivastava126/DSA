class Solution {
public:
    string get_my_line(vector<string>& words, int i, int j, int maxWidth, int ns, int es){
        string s = "";
        for(int k=i; k<j; k++){
            s += words[k];
            if(k != j-1){
                int c_ns=ns;
                while(c_ns--){
                    s += ' ';
                }
                if(es){
                    s += ' ';
                    es--;
                }
            }
        }
        if(s.size() < maxWidth){
            string temp(maxWidth-s.size(), ' ');
            s += temp;
        }
        return s;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i=0, j=0;
        while(i < n){
            int letter_count=words[i].size();
            int gaddha_count=0;
            j = i+1;
            while(j<n && (words[j].size() + 1 + letter_count + gaddha_count <= maxWidth)){
                letter_count += words[j].size();
                gaddha_count += 1;
                j++;
            }
            
            int remaining_spaces = maxWidth - letter_count;
            int needed_spaces = 1;
            int extra_spaces = 0;
            if(gaddha_count != 0){
                needed_spaces = remaining_spaces/gaddha_count;
                extra_spaces = remaining_spaces%gaddha_count;
            }
            if(j==n){
                needed_spaces = 1;
                extra_spaces = 0;
            }
            string line = get_my_line(words, i, j, maxWidth, needed_spaces, extra_spaces);
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};