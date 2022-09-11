#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> table;

    for (auto i = 0; i < participant.size(); i++) {
        auto it = table.find(participant[i]);
        if (it != table.end())
            table[participant[i]]++;
        else
            table[participant[i]] = 0;
    }

    for (auto i = 0; i < completion.size(); i++) {
        auto it = table.find(completion[i]);
        if (it != table.end()) {
            if (table[completion[i]] > 0)
                table[completion[i]]--;
            else
                table.erase(completion[i]);
        }
    }

    for (auto i = table.begin(); i != table.end(); i++)
        answer += i->first;

    return answer;
}

int main() {
    return 0;
}