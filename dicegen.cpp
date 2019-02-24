#include <iostream>
#include <random>
#include <chrono>
#include "diceware_list.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "\033[1mUsage:\033[0m " << argv[0]
			<< " \033[4mnumber\033[0m\n\tGenerates a diceware password "
			"consisting of \033[4mnumber\033[0m words\n";
		return 1;
	}
	random_device r;
	
	long len = strtol(argv[1], NULL, 10);
	if (len < 0) {
		cerr << "Some people don't think it be like it is but it do" << endl;
		return 2;
	}
	string s;
	for (int i = 0; i < len; i++) {
		int idx = 0;
		idx += (10000 * (r() % 6 + 1));
		idx += (1000 * (r() % 6 + 1));
		idx += (100 * (r() % 6 + 1));
		idx += (10 * (r() % 6 + 1));
		idx += r() % 6 + 1;
		s += wordlist(idx);
		s += ' ';
	}
	cout << s << endl;
	return 0;
}