#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<sstream>
#include<climits>


using namespace std;

int get_digit(int in)
{
    int cur = 0;
    while(in) {
        in = in / 10;
        cur++;
    }
    return cur;
}


int evaluate(int cur_stack, int i)
{
    if (cur_stack == 0) {
        return 0;
    }
    if (cur_stack == 1) {
        return i;
    }
    
    int digit = get_digit(cur_stack);
    
    return digit + i;
}


int solution(string s) {
    
    int max_size = s.size();
    
    
    int min_length = INT_MAX;
    for (int i = 1; i <= max_size; i++) {
        
        int cur_pos = 0;
        int cur_stack = 0;
        int cur_length = 0;
        
        string last_string = "";
        string sub_string;
        while (cur_pos < max_size) {
            sub_string = s.substr(cur_pos, i);
            if (sub_string.size() < i) {
                cur_length += evaluate(cur_stack, i);
                cur_length += sub_string.size();
                cur_stack = 0;
                break;
            }
            if (sub_string == last_string) {
                cur_stack++;
            }
            else {
                cur_length += evaluate(cur_stack, i);
                last_string = sub_string;
                cur_stack = 1;
            }
            cur_pos = cur_pos + i;
        }
        
        if (cur_stack) {
            if (sub_string == last_string) {
                cur_length += evaluate(cur_stack, i);
            }
            else {
                cur_length += evaluate(cur_stack, i);
            }
        }
        
        if (cur_length < min_length) {
            min_length = cur_length;
        }
        
    }
    
    
    return min_length;
}