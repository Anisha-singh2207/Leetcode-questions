class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {


        //empty wala case mai break ka use karke solve kar sakti hu

       sort(strs.begin(),strs.end());
       int a=strs.size();
       string n=strs[0],m=strs[a-1];
       string ans="";

       for(int i=0;i<n.size();i++){
           if(n[i]==m[i]){
               ans+=n[i];
           }
           else{
               break;
           }
       }
       return ans;
    }
};