#include <iostream>
#include <string>

std::string encrypt(const std::string& plain, int key) {
    std::string res;
    for (size_t i = 0; i < key; i++) {
        for (size_t j = 0; i + j < plain.size(); j += key) {
            res += plain[i + j];
        }
    }
    return res;
}

std::string decrypt(const std::string& plain, int key) {
    std::string res = "good luck with this";
    // TODO... yikes
    return res;
}

int main() {
    /**
        true - encrypt
        false - decrypt
    **/
    bool option = false;

    std::string text = "welp, this is almost working";
    int key = 4;

    std::cout << (option ? encrypt(text, key) : decrypt(text, key));
    return 0;
}
