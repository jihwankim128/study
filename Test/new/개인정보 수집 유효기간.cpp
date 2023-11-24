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
    1�� ~ n������ �з��Ǵ� �������� n��
    ���������� ��ȿ�Ⱓ �������� ���� ����
    ��ȿ�Ⱓ�� ������ �ı�
    
    ex) ��ȿ�Ⱓ 12��
    2021�� 1�� 5�Ͽ� ������ ���������� A������� ����
    -> 2022�� 1�� 4�ϱ��� ���� ����
    
    ��¥ - YYYY.MM.DD
    term - A~Z_1~100
    privacies - ������¥_term
*/
