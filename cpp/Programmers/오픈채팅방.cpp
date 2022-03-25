#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>

using namespace std;

string split_record[100001][3];

map<string, string> m;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    for (int i = 0; i < record.size(); i++) {
        istringstream ss(record[i]);
        string buffer;
        int j = 0;
        while(getline(ss, buffer, ' ')) {
            split_record[i][j++] = buffer;
        }

        if (split_record[i][0] == "Enter" || split_record[i][0] == "Change") {
           m[split_record[i][1]] = split_record[i][2];
        }

    }

    for (int i = 0; i < record.size(); i++) {
        if (split_record[i][0] == "Change") {
            continue;
        }
        string final_result;
        string id = split_record[i][1];
        string name = m[id];
        string message;
        if (split_record[i][0] == "Enter") {
            message = "님이 들어왔습니다.";
        }
        if (split_record[i][0] == "Leave") {
            message = "님이 나갔습니다.";
        }
        final_result = name + message;

        answer.push_back(final_result);
    }

        return answer;
}
