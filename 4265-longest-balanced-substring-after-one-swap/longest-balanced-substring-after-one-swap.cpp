class Solution {
public:
    int longestBalanced(string s) {
        int zs=0, os=0;
        // z and o vectors to store 0s and 1s counts 
        //we are also storing differences
        vector<int> diff, z, o;
        for(char c : s){
            if(c=='0') zs++;
            else os++;
            diff.push_back(os-zs); 
            o.push_back(os);
            z.push_back(zs);
        }

        int sum = 0; int maxi = 0;
        unordered_map<int, int> mp, mp0, mp1;
        mp[0] = -1;

        for(int i=0; i<s.size(); i++){
            int pref = diff[i];

            //diff at two idx is same no swap needed case
            if(mp.count(pref)){
                maxi = max(maxi, i - mp[pref]);
            }

            //-2 case : need '1'
            if(mp.count(pref+2)){
                int j = mp[pref+2]; //index jab pehli baar hme same diff mila

                //number of ones in substring
                int sub1s = o[i] - (j >= 0 ? o[j] : 0);
                //agar substring k bahar ones hai then swap
                if(os > sub1s) maxi = max(maxi, i-j); 
                // ni hai then substring thodi aage move krlo taki 1 mil jaye bahar to swap
                else if(mp1.count(pref+2)) maxi = max(maxi, i - mp1[pref+2]); 
            }

            //+2 case : need '0'
            if(mp.count(pref-2)){
                int j = mp[pref-2];
                int sub0s = z[i] - (j>=0 ? z[j] : 0);

                if(zs > sub0s) maxi = max(maxi, i-j);
                else if(mp0.count(pref-2)) maxi = max(maxi, i-mp0[pref-2]);
            }

            //maps update krdo
            if(!mp.count(pref)) mp[pref] = i;
            if(!mp0.count(pref) && z[i]>0) mp0[pref] = i;
            if(!mp1.count(pref) && o[i]>0) mp1[pref] = i;
        }
        return maxi;
    }
};