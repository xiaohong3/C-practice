#include "../std_lib_facilities.h"

bool isDislikedWord(string word, vector<string> dislikedList) {
    for (string dislikedWord : dislikedList) {
        if (dislikedWord == word) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<string> words;
    vector<string> disliked = {
        "Broccoli"
    };

    for(string word; cin >> word;) {
        words.push_back(word);
    }

    for(string word : words) {
        if (isDislikedWord(word, disliked)) {
            cout << "BLEEP";
        } else {
            cout << word;
        }
        cout << "\n";
    }

    return 0;
}