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

string compute(string input, int key) {
    string res ;
    for(int i = 0 ; i < input.size() ; i++) {
        char c = input[i] ;
        if(isalpha(c)) {
            bool lwrc = subtract(c) ;
            char r = c + key ;
            r %= 26 ;
            r += r < 0 ? 26 : 0 ;
            res += add(r, lwrc) ;
        }
        else {
            res += c ;
        }
    }
    return res ;
}

int main() {
    string text = "efgfoe uif fbtu xbmm pg uif dbtumf" ;
    int key = 53 ;
    bool option = 0 ;
    /**
        1 = encrypt
        0 = decrypt
    **/
    key %= 26 ;
    if(!option) {
        key *= -1 ;
    }
    cout << compute(text, key) ;
}
