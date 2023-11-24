/*
    23-11-24 AM 11:11 ~ 
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> createTermsType(vector<string> &terms) {
    vector<int> termsType(26, 0);
    for(string &s: terms) {
        termsType[s[0]-'A'] = stoi(s.substr(2));
    }
    return termsType;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> termsType = createTermsType(terms);
    /*
    for(int i : termsType) {
        cout << i << ' ';
    }
    */
    
    int todayYear = stoi(today.substr(0,4));
    int todayMonth = stoi(today.substr(6,7));
    int todayDay = stoi(today.substr(8,9));
    string todayDate = to_string(todayYear) + to_string(todayMonth) + to_string(todayDay);
    // cout << todayYear << ' ' << todayMonth << ' ' << todayDay << '\n';
    
    for(int i = 0; i < privacies.size(); i++) {
        string privacy = privacies[i];
        int startYear = stoi(privacy.substr(0,4));
        int startMonth = stoi(privacy.substr(5,7));
        int startDay = stoi(privacy.substr(8,10));
        int term = termsType[privacy[11]-'A'];
        // cout << startYear << ' ' << startMonth << ' ' << startDay << ' ' << term << '\n';
        
        int sum = startMonth + term;
        int mod = sum % 12;
        
        int endYear = startYear + sum/12;
        int endMonth = (mod == 0) ? 1 : mod;
        int endDay = startDay;
        // cout << endYear << ' ' << endMonth << ' ' << endDay  << '\n';
        string endDate = to_string(endYear) + to_string(endMonth) + to_string(endDay);
        
        if(todayDate >= endDate) answer.push_back(i+1);
    } 
    return answer;
}

/*
    1번 ~ n번으로 분류되는 개인정보 n개
    개인정보는 유효기간 전까지만 보관 가능
    유효기간이 지나면 파기
    
    ex) 유효기간 12달
    2021년 1월 5일에 수집된 개인정보가 A약관으로 수집
    -> 2022년 1월 4일까지 보관 가능
    
    날짜 - YYYY.MM.DD
    term - A~Z_1~100
    privacies - 수집날짜_term
*/
