class Solution {
public:
    string removeOccurrences(string s, string part) {

        while(s.find(part)!=string::npos){
            //agar loop ke andar ho means string exists in s string

            s.erase(s.find(part),part.length());
        }
        return s;
    }
};