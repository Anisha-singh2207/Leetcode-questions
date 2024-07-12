class Solution {
public:
    void reverseString(string &s, int i, int j) {
        while(i < j)  {
            if(s[i] == '(') i++;
            if(s[j] == ')') j--;
            swap(s[i++], s[j--]);
        }
    }

    string reverseParentheses(string s)    {
        stack<int> st; // Stack to store the indices of '('
        int n = s.size();
        for(int i = 0; i < n; i++){
            // If the character is '(', push its index onto the stack
            if(s[i] == '(') st.push(i);
            // If the character is ')', reverse the substring from the last '(' to the current ')'
            if(s[i] == ')')
            {
              
                reverseString(s, st.top(), i);
                // Pop the index of the last '(' from the stack
                st.pop();
            }
        }

        string ans;
        for(auto ch : s)
        //if it is character then append it in our ans
            if(isalpha(ch)) ans += ch;
        return ans;
    }
};
