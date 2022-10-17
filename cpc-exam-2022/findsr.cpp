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

	string input;

	while(cin >> input && input != "*") {
		vector<int> pi = compute_prefix_kmp(input);
		// print_vec(pi);

		int len = input.length();
		int max = pi[len-1];
		int period_k = 1;
		// Find the period of the string
		if (len % (len-max) == 0) {
			period_k = len/(len-max);
		}
		cout << period_k << endl;
	}

	return 0;

}