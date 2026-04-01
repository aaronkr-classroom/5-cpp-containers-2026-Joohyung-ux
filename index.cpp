#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    vector<vector<string>> all_rotations;
    string line = "The quick brown fox jumped over the fence";

    // process the fixed input once
    {
        // 수동으로 공백을 체크해 단어 분리 (연속된 공백 무시)
        vector<string> words;
        string temp = "";
        for (size_t i = 0; i <= line.length(); ++i) {
            if (i == line.length() || line[i] == ' ') {
                if (!temp.empty()) {
                    words.push_back(temp);
                    temp.clear();
                }
            } else {
                temp += line[i];
            }
        }

        // 단어가 없으면 아무 것도 하지 않습니다
        int n = words.size();
        if (n != 0) {
            // 각 회전(rotation)을 생성하여 저장
            for (int i = 0; i < n; i++) {
                all_rotations.push_back(words);

                // 2. 첫 단어를 맨 뒤로 이동
                string firstWord = words.front();
                for (int j = 0; j < n - 1; j++) words[j] = words[j + 1];
                words[n - 1] = firstWord;
            }
        }
    }

    // 3. 사전순 정렬
    sort(all_rotations.begin(), all_rotations.end());

    // 4. 결과 출력
    cout << "\n[result]" << endl;
    for (int i = 0; i < all_rotations.size(); i++) {
        for (int j = 0; j < all_rotations[i].size(); j++) {
            cout << all_rotations[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
