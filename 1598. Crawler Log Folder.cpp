class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0; 
        for (const string& log : logs) {
            if (log == "../") {
                if (depth > 0) {
                    depth--;
                }
            } else if (log == "./") {
                // Do nothing
            } else {
                depth++;
            }
        }
        
        return depth;
    }
};
