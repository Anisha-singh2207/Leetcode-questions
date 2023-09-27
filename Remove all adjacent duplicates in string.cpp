class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        int index=0;

        while(index<s.length()){
            //if same 
            if(ans.length()>0 && ans[ans.length()-1]==s[index]){
                //agar previous element same hai toh pop karo
                ans.pop_back();
            }
            else{
                //aur agar different hai toh push karo incoming elements ko
                ans.push_back(s[index]);
            }
            index++;

        }

        return ans;

        
    }
};