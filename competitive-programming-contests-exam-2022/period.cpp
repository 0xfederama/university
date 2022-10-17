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

void compute_prefix_kmp(string a) {
	int len = a.length();
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
		// Directly print the solution
		if (j > 0 && (i+1)%(i+1-j)==0) {
			cout << i+1 << " " << (i+1)/(i+1-j) << endl;
		}
	}
	//print_vec(pi);
}

int main() {

	int tests;
	cin >> tests;

	for (int i=0; i < tests; i++) {
		cout << "Test case #" << i+1 << endl;
		int len;
		string input;
		cin >> len >> input;

		compute_prefix_kmp(input);
		cout << endl;
	}

	return 0;

}