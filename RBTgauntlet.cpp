#include <iostream>
#include <random>

#include "RBTree.cpp"

using namespace std;

void yas() {
	cout << "\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "      ___    ___ ________  ________\n";
	cout << "     |\\  \\  /  /|\\   __  \\|\\   ____\\\n";
	cout << "     \\ \\  \\/  / | \\  \\|\\  \\ \\  \\___|_\n";
	cout << "      \\ \\    / / \\ \\   __  \\ \\_____  \\\n";
	cout << "       \\/  /  /   \\ \\  \\ \\  \\|____|\\  \\\n";
	cout << "     __/  / /      \\ \\__\\ \\__\\____\\_\\  \\\n";
	cout << "    |\\___/ /        \\|__|\\|__|\\_________\\\n";
	cout << "    \\|___|/                  \\|_________|\n";
	cout << "  ________  ___  _________  ________  ___  ___\n";
	cout << " |\\   __  \\|\\  \\|\\___   ___\\\\   ____\\|\\  \\|\\  \\\n";
	cout << " \\ \\  \\|\\ /\\ \\  \\|___ \\  \\_\\ \\  \\___|\\ \\  \\\\\\  \\\n";
	cout << "  \\ \\   __  \\ \\  \\   \\ \\  \\ \\ \\  \\    \\ \\   __  \\\n";
	cout << "   \\ \\  \\|\\  \\ \\  \\   \\ \\  \\ \\ \\  \\____\\ \\  \\ \\  \\\n";
	cout << "    \\ \\_______\\ \\__\\   \\ \\__\\ \\ \\_______\\ \\__\\ \\__\\\n";
	cout << "     \\|_______|\\|__|    \\|__|  \\|_______|\\|__|\\|__|\n";
	cout << "\n  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}

int main() {

	random_device rd;
  mt19937 gen(rd());
	int rankErr = 0;
	int totRankErr = 0;
	int selectErr = 0;
	int totSelectErr = 0;
	int searchErr = 0;
	int totSearchErr = 0;
	int tmp = 0;
	int offSet = 0;

	cout << "\n\trunning the gauntlet\n" << endl;

    RBTree<int,int> X;
	for (int i=1;i<1001000;i++) X.insert(i,i);
	for (int i=1;i<1001000;i++) {
		if (i % 100000 == 0) {
			if (i < 1000000) cout << "\t    ";
			else cout << "\t   ";
			cout << i/10000 << "% complete" << endl;
		}
		if (i % 15000 == 0) {
			uniform_int_distribution<>
			distrib(1,i);
			tmp = distrib(gen);
			if (X.remove(tmp))
				++offSet;
		}
		if(X.rank(i) != i-offSet) ++rankErr;
		if(X.select(i-offSet) != i) ++selectErr;
		if(*(X.search(i)) != i) ++searchErr;
	}
	cout << "\n\t ";
	cout << rankErr << " Rank Errors\n\t ";
	cout << selectErr << " Select Errors\n\t ";
	cout << searchErr << " Search Errors\n" << endl;

	if (!rankErr
	&& !selectErr
	&& !searchErr)
		yas();

	//Should be no output and should take seconds, not minutes

	return 0;
}
