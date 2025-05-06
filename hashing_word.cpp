#include <bits/stdc++.h>
using namespace std;

class HashTable {
private:
    vector<list<string>> table; // Each bucket stores words

    int hashfunc(const string& word) {
        int hash = 0;
        int multiplier = 1;
        int mod = table.size();

        for (int i = word.size() - 1; i >= 0; i--) {
            hash = (hash + (word[i] * multiplier)) % mod;
            multiplier = (multiplier * 10) % mod;
        }
        return hash;
    }

public:
    HashTable(int size) {
        table.resize(size);
    }

    void insert(const string& word) {
        int index = hashfunc(word);
        for (const auto& w : table[index]) {
            if (w == word) return; // Word already exists
        }
        table[index].push_back(word);
    }

    bool search(const string& word) {
        int index = hashfunc(word);
        for (const auto& w : table[index]) {
            if (w == word) return true;
        }
        return false;
    }

    void display() {
        cout << "\nHash Table Contents:\n";
        for (int i = 0; i < table.size(); ++i) {
            cout << "Bucket " << i << ": ";
            for (const auto& word : table[i]) {
                cout << "[" << word << "] -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    vector<string> words = {
        "apple", "banana", "orange", "grape", "peach",
        "cherry", "lemon", "mango", "melon", "kiwi",
        "plum", "pear", "berry", "fig", "date",
        "lime", "papaya", "guava", "apricot", "coconut",
        "pineapple", "lychee", "strawberry", "blueberry", "watermelon"
    };

    HashTable dict(20);  // Hash table with 20 buckets

    // Insert all words into the hash table
    for (const auto& word : words) {
        dict.insert(word);
    }

    string userWord;
    cout << "Dictionary loaded with " << words.size() << " words.\n";

    while (true) {
        cout << "\nEnter a word to check spelling (or type 'exit' to quit): ";
        getline(cin, userWord);

        if (userWord == "exit") {
            cout << "Exiting program.\n";
            break;
        }

        if (dict.search(userWord)) {
            cout << "Correct spelling: '" << userWord << "' exists in dictionary.\n";
        } else {
            cout << "Incorrect spelling: '" << userWord << "' not found.\n";
        }
    }

    return 0;
}
