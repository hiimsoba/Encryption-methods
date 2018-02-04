#include <iostream>
#include <string>

using namespace std ;

bool subtract(char &c) {
    if(islower(c)) {
        c -= 'a' ;
        return 1 ;
    }
    else {
        c -= 'A' ;
        return 0 ;
    }
}

char add(char &c, bool lwr) {
    if(lwr) {
        return c + 'a' ;
    }
    else {
        return c + 'A' ;
    }
}

void createKey(string &key, string text) {
    int index = 0 ;
    while(key.size() != text.size()) {
        if(isalpha(text[index])) {
           key += text[index++] ;
        }
        else {
            index++ ;
        }
    }
}

string compute(string input, string key, bool option) {
    int kIndex = 0 ;
    string res ;
    for(int i = 0 ; i < input.size() ; i++) {
        char c = input[i] ;
        char k = key[kIndex] ;
        if(isalpha(c)) {
            bool lwrc = subtract(c) ;
            bool lwrk = subtract(k) ;
            char r = option ? k + c : c - k ;
            r += r < 0 ? 26 : 0 ;
            r -= r >= 26 ? 26 : 0 ;
            res += add(r, lwrc) ;
            if(!option && key.size() != input.size()) {
                key += add(r, lwrc) ;
            }
            kIndex++ ;
        }
        else {
            res += c ;
        }
    }
    return res ;
}

int main() {
    string text = "ATTACK THE EAST WALL AT DAWN" ;
    string key = "QUEEN" ;
    bool option = 1 ;
    /**
        1 = encrypt
        0 = decrypt
    **/
    if(option) {
        createKey(key, text) ;
    }
    cout << compute(text, key, option) ;
}
