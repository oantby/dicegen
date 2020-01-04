#include <iostream>
#include <random>
#include <chrono>
#include "diceware_list.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		cerr << "\033[1mUsage:\033[0m " << argv[0] << " \033[4mnumber\033[0m\n"
			"\tGenerates a diceware password consisting of "
			"\033[4mnumber\033[0m words\n";
		return 1;
	}
	random_device r;
	const size_t wl_size = sizeof(wordlist)/sizeof(*wordlist);
	
	long len = strtol(argv[1], NULL, 10);
	if (len < 0) {
		cerr << "Some people don't think it be like it is but it do" << endl;
		return 2;
	}
	
	string s;
	for (int i = 0; i < len; i++) {
		s += wordlist[r() % wl_size];
		if (i + 1 < len) s += ' ';
	}
	cout << s << endl;
	return 0;
}