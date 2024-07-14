class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int num : asteroids) {
            bool flag = false;
            
            while (!st.empty() && num < 0 && st.top() > 0) {
                if (abs(st.top()) < abs(num)) {
                    st.pop();
                    continue;
                } else if (abs(st.top()) == abs(num)) {
                    st.pop();
                }
                flag = true;
                break;
            }

            if (!flag) {
                st.push(num);
            }
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }

        return result;
    }
};