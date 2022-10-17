#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vec(vector<T> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << ", ";
	}
	cout << endl;
}

vector<string> tokenize(string s, char token) {
	vector<string> t;
	size_t current;
	size_t next = -1;
	do {
		current = next + 1;
		next = s.find_first_of(token, current);
		t.push_back(s.substr(current, next-current));
	} while (next != string::npos);
	return t;
}

string operator * (string a, unsigned int b) {
    string output = "";
    while (b--) {
        output += a;
    }
    return output;
}

int compute_prefix_kmp(string a) {
	int len = a.length();
	int pi[len];
	pi[0] = 0;
	for (int i=1; i<len; i++) {
		int j = pi[i-1];
		while (j > 0 && a[i]!=a[j]) {
			j = pi[j-1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		pi[i] = j;
	}
	// pi[len-1] stores the period of the string
	return len - pi[len - 1];
}

int main() {
	string running;
	string skip;
	getline(getline(cin, skip, '"'), running, '"');
	
	vector<string> tok = tokenize(running, ' ');

	string sign = "";

	// Create the string resulting from the input
	for (int i=0; i < tok.size(); i+=2) {
		string text = tok[i+1] * atoi(tok[i].c_str());
		sign += text;
	}

	//cout << "sign: " << sign << endl;

	// Compute the prefix for the entire sign string
	int sol = compute_prefix_kmp(sign);
	cout << sol << endl;

	return 0;

}