#include <iostream>
#include <set>
#include <vector>
#include <map>

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

    vector<string>content;
    string word;

    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                content.push_back(word);
                word.clear();
            }
        }
        word += c;
    }
    if (!word.empty()) {
        content.push_back(word);
    }
    return content;
}

set<string>StopWords(const string& stop) {

    vector<string>stops = SplitIntoWords(stop);
    set<string>stop_words(stops.begin(), stops.end());
    return stop_words;
}

vector<string>DocsNoStop(const vector<string>& doc, const set<string>& stop) {

    vector<string>no_stop;

    for (const string& word : doc) {
        if (!stop.count(word)) {
            no_stop.push_back(word);
        }
    }
    return no_stop;
}

int MatchDocuments(const set<string>& stop_words, const vector<string>& query, const pair<int, vector<string> >& document) {

    vector<string> query_no_stop = DocsNoStop(query, stop_words);
    set<string>query_set(query_no_stop.begin(), query_no_stop.end());
    int count = 0;
    for (const string& word : document.second) {
        if (query_set.count(word)) {
            ++count;
        }
    }
    return count > 0 ? count : -1;

}

map<int,string>FindDocuments(const vector<pair<int, vector<string>>>& documents, const set<string>& stop_words,
                                                                                        const string& query) {

    map<int, string>result;
    vector<string>query_words = SplitIntoWords(query);

    for (const auto& document : documents) {
        int count = MatchDocuments(stop_words, query_words, document);
        if (count > 0) {
            string text;
            for (const string& word : document.second) {
                text += (" " +  word);
            }
            result[count] = text;
        }
    }
    return result;
}

void PrintRespons(const map<int,string>& founded) {

    for (auto it = founded.rbegin(); it != founded.rend(); ++it) {
        cout << "{ Релевантность: " << it->first << " | Текст: " << it->second << " }" << endl;
    }

}

int main() {

    string stop = Readline();
    int count = ReadNumber();

    vector<pair<int, vector<string>>>documents;

    for (int document_id = 0; document_id < count; ++document_id) {
        string text = Readline();
        documents.emplace_back(document_id + 1, SplitIntoWords(text));
    }

    set<string>stop_words = StopWords(stop);
    string query = Readline();

    map<int,string>founded = FindDocuments(documents, stop_words, query);

    PrintRespons(founded);


}
