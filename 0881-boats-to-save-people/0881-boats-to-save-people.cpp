class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int left = 0, right = people.size() - 1;
        int boats = 0;
        
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                left++; // lightest person can join the heaviest
            }
            right--; // heaviest person always leaves on this boat
            boats++;
        }
        
        return boats;
    }
};