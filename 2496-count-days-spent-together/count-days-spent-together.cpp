class Solution {
public:
    const vector<pair<string, int>> days = {{"01", 31}, {"02", 28}, {"03", 31}, {"04", 30}, {"05", 31}, {"06", 30}, {"07", 31}, {"08", 31}, {"09", 30}, {"10", 31}, {"11", 30}, {"12", 31}};

    int convertToDays(string date) {
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        for(int i = 0; i < month - 1; i++) day += days[i].second;

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startAlice = convertToDays(arriveAlice);
        int endAlice = convertToDays(leaveAlice);

        int startBob = convertToDays(arriveBob);
        int endBob = convertToDays(leaveBob);

        int start = max(startAlice, startBob);
        int end = min(endAlice, endBob);

        return max(0, end - start + 1);
    }
};