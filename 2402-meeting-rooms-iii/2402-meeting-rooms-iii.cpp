class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int m = meetings.size();
        sort(meetings.begin(), meetings.end()); //sort by starting time of meetings

        vector<long long> lastAvailableAt(n, 0);  //lastAvailableAt[i] = Room number i will be last available at

        vector<int> roomsUsedCount(n, 0);  //roomsUsedCount[i] = Room i is used how many times

        for(vector<int>& meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            bool found = false;

            long long earlyEndRoomTime = LLONG_MAX;
            int earlyEndRoom = 0;

            // Find the first available meeting room for my current meeting
            for(int room = 0; room < n; room++) {
                if(lastAvailableAt[room] <= start) {
                    lastAvailableAt[room] = end;  //current meeting will finish at end
                    roomsUsedCount[room]++;
                    found = true;
                    break;
                }

                if(lastAvailableAt[room] < earlyEndRoomTime) {
                    earlyEndRoomTime = lastAvailableAt[room];
                    earlyEndRoom = room;
                }
            }

            // I could'n find any room 
            if(!found) {
                // Pick that room which will end first
                lastAvailableAt[earlyEndRoom] += duration;
                roomsUsedCount[earlyEndRoom]++;               
            }
        }

        int ans = -1;
        int maxUse = 0;

        for(int room = 0; room < n; room++) {
            if(roomsUsedCount[room] > maxUse) {
                maxUse = roomsUsedCount[room];
                ans = room;
            }
        }

        return ans;
    }
};