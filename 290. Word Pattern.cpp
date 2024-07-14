
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        vector<string> words;
        stringstream ss(s);
        string word;

        // Split the string s into words and store them in the words vector
        while (ss >> word) {
            words.push_back(word);
        }

        // If the number of words is not equal to the length of the pattern, return false
        if (words.size() != pattern.size()) {
            return false;
        }

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // Check the mapping from character to word
            if (charToWord.find(c) != charToWord.end()) {
                // If the character is already mapped to a different word, return false
                if (charToWord[c] != w) {
                    return false;
                }
            } else {
                charToWord[c] = w;
            }

            // Check the mapping from word to character
            if (wordToChar.find(w) != wordToChar.end()) {
                // If the word is already mapped to a different character, return false
                if (wordToChar[w] != c) {
                    return false;
                }
            } else {
                wordToChar[w] = c;
            }
        }

        return true;
    }
};
