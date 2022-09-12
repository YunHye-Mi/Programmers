#include <string>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    stack<char> str;

    for (auto i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            str.push(s[i]);
        else if (s[i] == ')') {
            if (str.empty()) {
                return answer = false;
            }
            else str.pop();
        }
    }

    if (!str.empty()) answer = false;

    return answer;
}

int main() {
    return 0;
}