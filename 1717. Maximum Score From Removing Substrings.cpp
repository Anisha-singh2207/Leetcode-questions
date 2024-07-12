
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // If x is greater than y, we prioritize removing "ab" first
        if (x < y) {
            swap(x, y);
            reverse(s.begin(), s.end());
        }

        // First remove all "ab" if x >= y
        int score = removeAndScore(s, 'a', 'b', x);

        // Then remove all "ba"
        score += removeAndScore(s, 'b', 'a', y);

        return score;
    }

private:
    int removeAndScore(string &s, char first, char second, int points) {
        int score = 0;
        string result;

        for (char c : s) {
            if (!result.empty() && result.back() == first && c == second) {
                result.pop_back(); // Remove the valid pair
                score += points; // Increment the score
            } else {
                result.push_back(c); // Append the current character to the result
            }
        }

        s = result; // Update the original string
        return score;
    }
};