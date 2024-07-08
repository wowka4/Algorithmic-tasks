#include <iostream>
#include <set>
#include <vector>

using namespace std;

string Readline() {
    string text;
    getline(cin, text);
    return text;
}

int ReadNumber() {
    int number;
    cin >> number;
    cin >> ws;
    return number;
}

vector<string>SplitIntoWords(const string& text) {
    vector<string>words;
    string word;

    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) words.push_back(word);
    return words;
}

set<string>GetStopWords(const string& stop_words) {
    set<string>stop;

    for (string& word : SplitIntoWords(stop_words)) {
        if (!stop.count(word)) stop.insert(word);
    }
    return stop;
}

vector<string>WordsNoStop(const set<string>& stop_words, const string& text) {
    vector<string>words_no_stop;

    for (string& word : SplitIntoWords(text)) {
        if (!stop_words.count(word)) {
            words_no_stop.push_back(word);
        }
    }
    return words_no_stop;
}

bool MatchDocuments(const pair<int, vector<string>>& content, const vector<string>& query) {
    set<string>query_no_stop(query.begin(), query.end());
    for (const string& word : content.second) {
        if (query_no_stop.count(word)) return true;
    }
    return false;
}

vector<vector<string>>FindDocuments(const vector<pair<int, vector<string>>>& documents, const string& query,
                                                                            const set<string>& stop) {
    vector<vector<string>>content;

    for (auto& document : documents) {
        if (MatchDocuments(document, WordsNoStop(stop, query))) {
            content.push_back(document.second);
        }
    }

    return content;
}

int main() {
    const string stop_words = Readline();
    int number = ReadNumber();
    set<string>stop = GetStopWords(stop_words);

    vector<pair<int, vector<string>>>documents;

    for (int document_id = 0; document_id < number; ++document_id) {
        string text;
        getline(cin, text);
        documents.emplace_back(document_id + 1, SplitIntoWords(text));
    }

    string query = Readline();

    for (const auto& content : FindDocuments(documents, query, stop)) {
        for (const string& word : content) {
            cout << word << " ";
        }
        cout << endl;
    }








}