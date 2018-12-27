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
std::string compute(const std::string& input, const std::string& key) {
    int kIndex = 0;
    std::string res;
    for(size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        char k = key[kIndex];
        if (isalpha(c)) {
            bool lwrc = subtract(c);
            subtract(k);
            char r = k - c;
            r += r < 0 ? 26 : 0;
            res += add(r, lwrc);
            kIndex = (kIndex + 1) % key.size();
        } else {
            res += c;
        }
    }
    return res;
}

std::string normalizeKey(const std::string& key) {
    // only add the alphabet characters from the key
    std::string res;
    for (size_t i = 0; i < key.size(); i++) {
        if (isalpha(key[i])) {
            res += key[i];
        }
    }
    return res;
}

int main() {
    std::string text = "DEFEND THE EAST SIDE OF THE CASTLE!";
    std::string key = "FORTIFICATION";
    key = normalizeKey(key);
    std::cout << compute(text, key);
    return 0;
}
