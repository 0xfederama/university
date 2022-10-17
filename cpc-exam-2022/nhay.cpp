#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vec(vector<T> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
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

	int tests;
	cin >> tests;

	while(tests--) {
		int len_pattern;
		string text, pattern;
		cin >> len_pattern >> pattern >> text;

		if (len_pattern > text.length()) {
			cout << endl;
			continue;
		}

		vector<int> pi = compute_prefix_kmp(pattern);
		// print_vec(pi);
		
		int len_text = text.length();
		int q = 0;
		bool sol_found = false;
		for (int i=0; i < len_text; i++) {
			// cout << "i=" << i << endl;
			while (q > 0 && pattern[q] != text[i]) {
				// cout << "q=" << q << endl;
				q = pi[q];
			}
			if (pattern[q] == text[i]) {
				q++;
			}
			if (q == len_pattern) {
				sol_found = true;
				cout << i-q+1 << endl;
				q = pi[q-1];
			}
		}
		if (!sol_found) cout << endl;
	}

	return 0;

}