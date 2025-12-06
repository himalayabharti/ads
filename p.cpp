// kmp pattern
#include <iostream>
#include <string>
using namespace std;

void computeLPSArray(string pattern, int lps[]) {
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    
    int* lps = new int[m];
    computeLPSArray(pattern, lps);
    
    int i = 0; // index for text
    int j = 0; // index for pattern
    bool found = false;
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            found = true;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    if (!found) {
        cout << "Pattern not found in text!" << endl;
    }
    
    delete[] lps;
}

int main() {
    string text, pattern;
    
    cout << "Enter the text: ";
    getline(cin, text);
    
    cout << "Enter the pattern to search: ";
    getline(cin, pattern);
    
    KMPSearch(text, pattern);
    
    return 0;
}
