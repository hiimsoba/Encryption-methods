#include <iostream>
#include <string>

// normalize the 'c' character to be in the range 0-26 or something like that
// and return true if it's lowercase, false if it's uppercase
bool subtract(char &c) {
    if (islower(c)) {
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

std::string createKey(const std::string& key, const std::string& text) {
    // create the key from the "seed" key
    std::string new_key;
    for (size_t i = 0; i < key.size(); i++) {
        // only add the letter characters from the new key
        if (isalpha(key[i])) {
            new_key += key[i];
        }
    }
    // and then keep adding characters from the plain text to the key until the key and the plain text have the same size
    int index = 0;
    while (new_key.size() != text.size()) {
        // only add if it's a letter, as well
        if (isalpha(text[index])) {
            new_key += text[index++];
        } else {
            index++;
        }
    }
    // return the key
    return new_key;
}

// magic...
std::string compute(std::string input, std::string key, bool option) {
    int kIndex = 0;
    std::string res;
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        char k = key[kIndex];
        if (isalpha(c)) {
            bool lwrc = subtract(c);
            subtract(k);
            char r = option ? k + c : c - k;
            r += r < 0 ? 26 : 0;
            r -= r >= 26 ? 26 : 0;
            res += add(r, lwrc);
            if (!option && key.size() != input.size()) {
                key += add(r, lwrc);
            }
            kIndex++;
        } else {
            res += c;
        }
    }
    return res;
}

int main() {
    std::string text = "ATTACK THE EAST WALL AT DAWN";
    std::string key = "QUEEN";

    /**
        1 = encrypt
        0 = decrypt
    **/
    bool option = 1;

    if (option) {
        key = createKey(key, text);
    }

    std::cout << compute(text, key, option);
    return 0;
}
