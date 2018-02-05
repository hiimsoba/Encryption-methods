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

string compute(string input, string key, bool option) {
    int kIndex = 0 ;
    string res ;
    for(int i = 0 ; i < input.size() ; i++) {
        char c = input[i] ;
        char k = key[kIndex] ;
        if(isalpha(c)) {
            bool lwrc = subtract(c) ;
            bool lwrk = subtract(k) ;
            char r = option ? c + k : c - k ;
            r += r < 0 ? 26 : 0 ;
            r -= r >= 26 ? 26 : 0 ;
            res += add(r, lwrc) ;
            kIndex = (kIndex + 1) % key.size() ;
        }
        else {
            res += c ;
        }
    }
    return res ;
}

int main() {
    string text = "LXFOPV EF RNHR" ;
    string key = "lemon" ;
    bool option = 0 ;
    /**
        1 = encrypt
        0 = decrypt
    **/
    cout << compute(text, key, option) ;
}
