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
	cin >> input;
	
	vector<int> pi = compute_prefix_kmp(input);
	// print_vec(pi);

	// If the last element of the array is 0, it means we don't have a common prefix/suffix of the whole string
	if (pi[input.length()-1] == 0) {
		cout << "Just a legend" << endl;
		return 0;
	}

	// Initialize max to the longest prefix length and found to the character before that
	int max = pi[input.length()-1];
	int found = pi[max-1];
	// Search for the prefix/suffix in the string
	for (int i=1; i < input.length()-1; i++) {
		if (pi[i]==max) {
			// cout << "qui " << max << endl;
			found = max;
		}
	}

	// Found now has the index+1 of the prefix/suffix
	

	return 0;

}