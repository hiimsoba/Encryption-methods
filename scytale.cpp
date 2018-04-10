#include <fstream>
#include <iostream>

using namespace std ;

ifstream f("in") ;
ofstream g("out") ;

string encrypt(string text, int key) {
    string res ;

    for(int i = 1 ; i <= key ; i++) {
        for(int j = i - 1 ; j < text.size() ; j += key) {
            res += text[j] ;
        }
    }
    return res ;
}

string decrypt(string text, int key) {
    string res ;

    for(int i = 1 ; i <= key ; i++) {
        for(int j = i - 1 ; ; j += (key + 1)) {
            res += text[j] ;
            if(j > text.size()) break ;
        }
    }
    return res ;
}

int main() {
    bool option ;
    f >> option ;

    string text ;
    f.get() ;
    getline(f, text) ;

    int key ;
    f >> key ;

    double flag = (double) text.size() / key ;

    if(flag != int(flag)) flag = int(flag) + 1 ;

    string result ;

    if(option) result = encrypt(text, flag) ;
    else result = decrypt(text, flag) ;

    g << result ;

    f.close() ;
    g.close() ;
    return 0 ;
}
