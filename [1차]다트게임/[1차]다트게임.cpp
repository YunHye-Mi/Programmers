#include <string>
#include <stack>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    stack<int> score;

    for(auto i = dartResult.begin(); i != dartResult.end(); i++){
        if(isdigit(*i)){
            if(isdigit(*(i-1))){
                string s = to_string(*(i-1)-'0') + to_string(*i-'0');
                score.pop();
                score.push(stoi(s));
            }
            else
                score.push(*i-'0');
        }
        else if(!score.empty()){
            if(isalpha(*i)){
                int s1 = score.top();
                score.pop();
                if(*i == 'S')
                    score.push(s1);
                else if(*i == 'D')
                    score.push(pow(s1,2));
                else if(*i == 'T')
                    score.push(pow(s1,3));
            }
            else if(ispunct(*i)){
                if(*i == '*'){
                    if(score.size() > 1){
                        int s1 = score.top()*2;
                        score.pop();
                        int s2 = score.top()*2;
                        score.pop();
                        score.push(s1+s2);
                    }
                    else{
                        int s1 = score.top()*2;
                        score.pop();
                        score.push(s1);
                    }
                }
                else if(*i == '#'){
                    int s1 = -score.top();
                    score.pop();
                    score.push(s1);
                }
            }
        }
    }
    while(!score.empty()){
        answer += score.top();
        score.pop();
    }

    return answer;
}