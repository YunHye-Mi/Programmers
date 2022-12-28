#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer; //2차원 벡터 정적할당 및 초기화
    vector<int> arr;

    for(auto i = 0; i < arr1.size(); i++){
        for(auto j = 0; j < arr1[0].size(); j++)
            arr.push_back(arr1[i][j]+arr2[i][j]);
        answer.push_back(arr);
        arr.clear();
    }

    return answer;
}