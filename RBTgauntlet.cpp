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

	cout << "\n\tRunning The Gauntlet\n" << endl;

	cout << "\n\t____1st Challenge____\n" << endl;

    RBTree<int,int> T1;
	for (int i=1;i<1001000;i++) T1.insert(i,i);
	for (int i=1;i<1001000;i++) {
		if (i % 100000 == 0) {
			if (i < 1000000)
				cout << "\t    " << i/10000 << "% complete" << endl;
			else cout << "\t        DONE" << endl;
		}
		if (i % 15000 == 0) {
			uniform_int_distribution<>
			distrib(1,i);
			tmp = distrib(gen);
			if (T1.remove(tmp))
				++offSet;
		}
		if(T1.rank(i) != i-offSet) ++rankErr;
		if(T1.select(i-offSet) != i) ++selectErr;
		if(*(T1.search(i)) != i) ++searchErr;
	}
	cout << "\n\t ";
	cout << rankErr << " Rank Errors\n\t ";
	cout << selectErr << " Select Errors\n\t ";
	cout << searchErr << " Search Errors\n" << endl;

	totRankErr += rankErr;
	rankErr = 0;
	totSelectErr += selectErr;
	selectErr = 0;
	totSearchErr += searchErr;
	searchErr = 0;

	cout << "\n\t____2nd Challenge____\n" << endl;

	RBTree<int,int> T2(T1);

	cout << "\tpart 1: " << endl;

	for (int i=1;i<555555;i++) {
		if (i % 55555 == 0) {
			if (i < 505000)
				cout << "\t    " << i/5555 << "% complete" << endl;
			else cout << "\t        DONE" << endl;
		}
		uniform_int_distribution<>
		distrib(1, T1.size());
		tmp = distrib(gen);
		if (T1.remove(tmp))
			++offSet;
		if (i % 5000 == 0) {
			uniform_int_distribution<>
			distrib(1, 1000000);
			tmp = distrib(gen);
			if (!T1.search(tmp))
				T1.insert(tmp, tmp/10*7);
		}
	}

	cout << "\tpart 2: " << endl;

	for (int i = 1; i < T1.size(); i++) {
		if (i % (T1.size()/10) == 0) {
			if (i < (T1.size()-(T1.size()/10)))
				cout << "\t    " << i/(T1.size()/100) << "% complete" << endl;
			else cout << "\t        DONE" << endl;
		}
		tmp = i;
		if (i != T1.rank(T1.select(tmp)))
			++selectErr;
		if (T1.rank(i))
			if (i != T1.select(T1.rank(tmp)))
				++rankErr;
	}

	cout << "\n\t ";
	cout << rankErr << " Rank Errors\n\t ";
	cout << selectErr << " Select Errors\n\t ";
	cout << searchErr << " Search Errors\n" << endl;

	totRankErr += rankErr;
	rankErr = 0;
	totSelectErr += selectErr;
	selectErr = 0;
	totSearchErr += searchErr;
	searchErr = 0;

	cout << "\n\t____3rd Challenge____\n" << endl;

	cout << "\t Initalizing Tree...\n" << endl;
	cout << "\t     Testing...\n" << endl;

	int treeSize = 7777777;
	RBTree<int,int> T3;

	for (int i = treeSize; i >= 0; i--) T3.insert(i,treeSize-i);
	for (int i = 1; i < treeSize; i++) {
		if (i % 777777 == 0) {
			if (i < 7770000)
				cout << "\t    " << i/77777 << "% complete" << endl;
			else cout << "\t        DONE" << endl;
		}
		if(T3.rank(i) != i+1) rankErr++;
		if(T3.select(i) != i-1) selectErr++;
		if(*(T3.search(i)) != treeSize-i) searchErr++;
	}

	cout << "\n\t ";
	cout << rankErr << " Rank Errors\n\t ";
	cout << selectErr << " Select Errors\n\t ";
	cout << searchErr << " Search Errors\n" << endl;

	totRankErr += rankErr;
	rankErr = 0;
	totSelectErr += selectErr;
	selectErr = 0;
	totSearchErr += searchErr;
	searchErr = 0;

	cout << "\n\t____4th Challenge____\n" << endl;

	RBTree<int,double> T4;

	for (int i=31313131; i > 0; i--) {
		if (i % 3131313 == 0) {
			if (i > 31313131/10)
				cout << "\t    " << 10+((31313131-i)/313131) << "% complete" << endl;
			else cout << "\t        DONE" << endl;
		}
		uniform_int_distribution<>
		intDis(10000000,99999999);
		uniform_real_distribution<>
		realDis(0.0001,9999.9999);
		T4.insert(intDis(gen), realDis(gen));
		uniform_int_distribution<>
		distrib(1, 1000000);
		tmp = distrib(gen);
	}

	cout << "\n\t       Hol Up\n\t  it Didn't Crash?\n" << endl;

	if (!totRankErr
	&& !totSelectErr
	&& !totSearchErr)
		yas();

	//Should be no output and should take seconds, not minutes

	return 0;
}
