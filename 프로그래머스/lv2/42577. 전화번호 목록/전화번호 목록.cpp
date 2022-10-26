#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 정렬
// 2. 앞 뒤로 비교
// 3. 같으면 바로 중지 후 false 리턴

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++){
        string str = phone_book[i + 1].substr(0, phone_book[i].length());

        if(phone_book[i] == str){
            answer = false;
            break;
        }
    }
    
    return answer;
}