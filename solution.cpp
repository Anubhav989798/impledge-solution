#include <fstream>
#include<bits/stdc++.h>

using namespace std;


bool split(string word, unordered_set<string>& dict) {
    int n = word.length();
    
    if (dict.find(word) != dict.end()) {
        return true;
    }
    
    for (int i = 1; i < n; i++) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);
        
        if (dict.find(prefix) != dict.end() && split(suffix, dict)) {
            return true;
        }
    }

    return false;
}

string findLongestCompoundWord(vector<string>& words) {
    unordered_set<string> dict(words.begin(), words.end());
    
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        return a.length() > b.length();
    });
    
    for (const string& word : words) {
        if (split(word, dict)) {
            return word;
        }
    }
    
    return "";
}

int main() {
    ifstream file("dictionary.txt");
    
    if (!file) {
        cout << "Failed to open the dictionary file." << endl;
        return 1;
    }
    
    vector<string> words;
    string word;
    
    while (file >> word) {
        words.push_back(word);
    }
    
    file.close();
    
    string longestCompoundWord = findLongestCompoundWord(words);
    
    if (longestCompoundWord.empty()) {
        cout << "no compound word is found" << endl;
    } else {
        cout << "Your longest compound word  " << longestCompoundWord << endl;
    }
    
    return 0;
}
