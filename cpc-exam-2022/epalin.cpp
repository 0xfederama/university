#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
void print_vec(vector<T> a) {
	for (int i=0; i<a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

vector<int> compute_prefix_kmp(string a) {
	vector<int> pi(a.length());
	pi[0] = 0;
	for (int i=1; i < a.length(); i++) {
		int j = pi[i-1];
		while (j>0 && a[i]!=a[j]) {
			j = pi[j-1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		pi[i] = j;
	}
	return pi;
}

int main() {
	char input[100001];

	while (scanf("%s", input) != EOF) {
		string word = input;
		// Reverse and join the strings
		string reversed = word;
		reverse(reversed.begin(), reversed.end());
		string word_double = reversed + "*" + word;

		// Build the pi array with prefix function
		vector<int> pi = compute_prefix_kmp(word_double);
		// cout << word_double << endl;
		// print_vec(pi);
		
		// Build the palindrome
		int ok = pi[word.length()*2];
		// cout << ok << endl;
		string sol = word;
		for (int i = ok; i < word.length(); i++) {
			// cout << word_double[i] << " ";
			sol += word_double[i];
		}
		// cout << endl;
		cout << sol << endl;
	}	

	return 0;
}