#include <iostream>
#include <string>

// normalize the 'c' character to be in the range 0-26 or something like that
// and return true if it's lowercase, false if it's uppercase
bool subtract(char &c) {
    if(islower(c)) {
        c -= 'a';
        return true;
    } else {
        c -= 'A';
        return false;
    }
}

// return the character at its initial state, keeping track of whether it was lowercase or uppercase
char add(char &c, bool lwr) {
    return c + (lwr ? 'a' : 'A');
}

// again, magic
std::string compute(const std::string& input, int key) {
    std::string res;
    for(int i = 0; i < input.size(); i++) {
        char c = input[i];
        if (isalpha(c)) {
            bool lwrc = subtract(c);
            char r = c + key;
            r %= 26;
            r += r < 0 ? 26 : 0;
            res += add(r, lwrc);
        } else {
            res += c;
        }
    }
    return res;
}

int main() {
    std::string text = "efgfoe uif fbtu xbmm pg uif dbtumf";
    int key = 53;
    bool option = 0;
    /**
        1 = encrypt
        0 = decrypt
    **/
    key %= 26;
    if (!option) {
        key *= -1;
    }

    std::cout << compute(text, key);
    return 0;
}
