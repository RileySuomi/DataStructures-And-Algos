#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);

        int mid = 0;

        if (str.length() % 2 == 0) {
            mid = str.length() / 2;
            mid--;
        }
        else {
            mid = str.length() / 2;
        }
        int j = str.length() - 1;

        if (str.length() == 2) {
            if (str[0] == str[1]) {
                return true;
            }
            else{
                return false;
            }
        }
        for (int i = 0; i <str.length(); i++) {
            if (i == mid && str.length() % 2 == 0) {
                if (str[i] != str[i+1]) {
                    return false;
                }
            }
            else if (i == mid && str.length() % 2 != 0){
                return true;
            }

            if (str[i] != str[j]) {
                return false;
            }
            j--;
        }
        return true;
    }
};