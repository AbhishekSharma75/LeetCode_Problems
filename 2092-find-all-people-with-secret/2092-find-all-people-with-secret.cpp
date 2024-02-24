class Solution {
public:
    typedef pair<int, int> P;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        map<int, vector<P>> timeMeetings;

        for(vector<int>& meeting : meetings) {
            int person1 = meeting[0];
            int person2 = meeting[1];
            int time = meeting[2];

            timeMeetings[time].push_back({person1, person2});
        }

        // 0, firstPerson
        vector<bool> knowsSecret(n, false);
        knowsSecret[0] = true;
        knowsSecret[firstPerson] = true;

        for(auto &it : timeMeetings) {
            int t = it.first;   //key
            vector<P> meets = it.second;  //value

            unordered_map<int, vector<int>> adj;  // a -> {b, c, d}
            queue<int> que;
            unordered_set<int> alreadyAdded;

            for(auto& [person1, person2] : meets) {
                adj[person1].push_back(person2);
                adj[person2].push_back(person1);

                if(knowsSecret[person1] == true && alreadyAdded.find(person1) == alreadyAdded.end()) {
                    que.push(person1);
                    alreadyAdded.insert(person1);
                }
                
                if(knowsSecret[person2] == true && alreadyAdded.find(person2) == alreadyAdded.end()) {
                    que.push(person2);
                    alreadyAdded.insert(person2);
                }
            }

            // Now, I know who meet who based on increasing times.
            // Let's spread the news with BFS
            while(!que.empty()) {
                int person = que.front();
                que.pop();

                for(auto &nextPerson : adj[person]) {
                    if(knowsSecret[nextPerson] == false) {
                        knowsSecret[nextPerson] = true;
                        que.push(nextPerson);
                    }
                }
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++) {
            if(knowsSecret[i] == true) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};