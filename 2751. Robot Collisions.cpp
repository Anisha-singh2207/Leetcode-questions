class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size(); // Get the number of robots
        map<int, pair<int, char>> mp; // Map to store positions and corresponding health and direction

        // Populate the map with positions, healths, and directions
        for(int i = 0; i < n; i++) {
            mp[positions[i]] = {healths[i], directions[i]};
        }

        stack<pair<int, pair<int, char>>> st; // Stack to process robots and their interactions

        // Iterate through the map
        for(auto it : mp) {
            // If the stack is not empty and the current robot is moving left
            if(!st.empty() && it.second.second == 'L') {
                // If the top robot in the stack is moving right
                if(st.top().second.second == 'R') {
                    // Case 1: Current robot's health is less than the top robot's health
                    if(it.second.first < st.top().second.first) {
                        st.top().second.first -= 1; // Decrease top robot's health by 1
                        continue; // Skip to the next iteration
                    }
                    // Case 2: Current robot's health is greater than the top robot's health
                    else if(st.top().second.first < it.second.first) {
                        // Process the collision until the current robot's health is no longer greater than the top robot's health
                        while(!st.empty() && it.second.first > st.top().second.first && st.top().second.second == 'R') {
                            it.second.first -= 1; // Decrease current robot's health by 1 for each collision
                            st.pop(); // Remove the top robot from the stack
                        }
                        // If the current robot's health equals the top robot's health
                        if(!st.empty() && it.second.first == st.top().second.first && st.top().second.second == 'R') {
                            st.pop(); // Remove both robots (they destroy each other)
                            continue; // Skip to the next iteration
                        }
                        // If the current robot's health is less than the top robot's health
                        if(!st.empty() && it.second.first < st.top().second.first && st.top().second.second == 'R') {
                            st.top().second.first -= 1; // Decrease top robot's health by 1
                            continue; // Skip to the next iteration
                        }
                    }
                    // Case 3: Current robot's health equals the top robot's health
                    else {
                        st.pop(); // Remove both robots (they destroy each other)
                        continue; // Skip to the next iteration
                    }
                }   
            }
            st.push(it); // Push the current robot onto the stack
        }

        vector<int> res; // Result vector to store the healths of surviving robots
        unordered_map<int, int> mp1; // Map to store the surviving robots' positions and healths

        // Transfer surviving robots' healths from the stack to the map
        while(!st.empty()) {
           mp1[st.top().first] = st.top().second.first;
            st.pop();
        }

        // Populate the result vector with surviving robots' healths in the original order
        for(int i = 0; i < n; i++) {
            if(mp1.find(positions[i]) != mp1.end()) {
                res.push_back(mp1[positions[i]]);
            }
        }

        return res; // Return the result
    }
};
