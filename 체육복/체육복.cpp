#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n-lost.size();
    auto i = lost.begin();
    auto j = reserve.begin();

    for(auto i = lost.begin(); i != lost.end(); i++)
        if(!reserve.empty())
            for(auto j = reserve.begin(); j != reserve.end(); j++){
                if(*i == *j + 1 || *i == *j - 1){
                    cout << *j << endl;
                    reserve.erase(j);
                    lost.erase(i);
                    answer +=1;
                    cout << *j << endl;
                }
            }

    return answer;
}