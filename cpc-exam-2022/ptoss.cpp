#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000007;
int pi[1000100];

template <typename T>
void print_vec(vector<T> v) {
	for (int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

template <typename T>
void print_arr(T a[], size_t size) {
	for (int i=0; i<size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int value(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a';
	} else if (c >= 'A' && c <= 'F') {
		return c - 'A' + 26;
	} else {
		cout << "Unexpected character " << c << endl;
		exit(1);
	}
}

vector<bool> int_to_binary(int n) {
	// Transform int to binary string
	string s;
	while (n!=0) {
		s = (n%2==0 ? "0" : "1") + s; 
		n/=2;
	}
	// Fill string with 0
	while (s.length() < 5) {
		s.insert(0, "0");
	}
	// Transform string to list of boolean
	vector<bool> binary;
	for (int i=0; i<5; i++) {
		binary.push_back(s[i]=='1' ? true : false);
	}
	return binary;
}

string str_to_fb(string s) {
	// Initialize a list of boolean
	vector<bool> binary_list;
	binary_list.reserve(5 * s.length());
	for (int i=0; i < s.length(); i++) {
		int v = value(s[i]);
		// Transform v in binary
		vector<bool> binary = int_to_binary(v);
		binary_list.insert(binary_list.end(), binary.begin(), binary.end());
	}
	// Transform binary_list in string with FB
	string fb(5 * s.length(), ' ');
	for (int i=0; i < 5*s.length(); i++) {
		fb[i] = binary_list[i]==true ? 'B' : 'F';
	}
	// cout << s << " -> " << fb << "\n";
	return fb;
}

void compute_prefix_kmp(string a) {
	pi[0] = 0;
	for (int i=1; i<a.length(); i++) {
		int j = pi[i-1];
		while (j>0 && a[i]!=a[j]) {
			j = pi[j-1];
		}
		if (a[i] == a[j]) {
			j++;
		}
		pi[i] = j;
	}
}

int main() {
	int tests;
	cin >> tests;

	while (tests--) {
		// Read the two lines in input
		int n, m;
		string s1, s2;
		cin >> n >> s1 >> m >> s2;

		// Transform s1 and s2
		string lucky_seq = str_to_fb(s1);
		string toss_history = str_to_fb(s2);
	
		// Compute the prefix on the lucky sequence
		compute_prefix_kmp(lucky_seq);
		// cout << "pi: ";
		// print_arr(pi, n);

		// Solve the problem
		// string output = "lucky sequence: " + lucky_seq.substr(0,n) + "\nhistory: " + toss_history.substr(0,m);
		// cout << output << endl;

		// Build the arrays to use to find the solution
		int tmp1[1000100]; // number of tosses for each letter in the lucky sequence
		int tmp2[1000100]; // support array
		tmp1[0] = 0;
		tmp1[1] = -2;
		tmp2[0] = 0;
		for (int i=1; i<n; i++) {
			if (lucky_seq[pi[i-1]] == lucky_seq[i]) {
				tmp1[i + 1] = 2*tmp1[i] - tmp1[tmp2[pi[i - 1]]] - 2;
				tmp2[i] = tmp2[pi[i - 1]];
			} else {
				tmp1[i + 1] = 2*tmp1[i] - tmp1[pi[i - 1] + 1] - 2;
				tmp2[i] = pi[i - 1] + 1;
      		}
			// tmp1[i+1] %= mod;
			while (tmp1[i+1] > mod) tmp1[i+1] -= mod;
			while (tmp1[i+1] < 0) tmp1[i+1] += mod;
		}

		// cout << "tmp1: ";
		// print_arr(tmp1, n+1);
		// cout << "tmp2: ";
		// print_arr(tmp2, n+1);

		// Find curr as the index of the state of the history the chef is
		int curr = 0;
		for (int i=0; i<m && curr!=n; i++) {
			// cout << "curr=" << curr << endl;
			while (curr > 0 && toss_history[i] != lucky_seq[curr]) {
				// cout << "while i=" << i << endl;
				curr = pi[curr - 1];
			}
			if (toss_history[i] == lucky_seq[curr]) {
				// cout << "uguali i=" << i << endl;
				curr++;
			}
		}
		// cout << "curr: " << curr << endl;
		
		// Print solution
		long sol = (mod - (tmp1[n] - tmp1[curr] + mod) % mod) % mod;
		cout << sol << "\n";
	}

	return 0;
}