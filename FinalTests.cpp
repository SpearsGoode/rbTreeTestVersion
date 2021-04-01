#include <iostream>
#include <cstdlib>
using namespace std;
#include "RBTree.cpp"

void printErrors(string errors, int numOfErrors){
	if(numOfErrors < 5){
		cout << errors << " PASSED " << endl;
	}else if(numOfErrors < 100){
		cout << errors << " caused " << numOfErrors << " of errors Add+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors Add+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors Add+1" << endl;
	}else if (numOfErrors < 1000){
		cout << errors << " caused " << numOfErrors << " of errors Add+1" << endl;
		cout << errors << " caused " << numOfErrors << " of errors Add+1" << endl;
	}else if (numOfErrors < 10000){
		cout << errors << " caused " << numOfErrors << " of errors Add+1" << endl;
	}else{
		cout << errors << " caused " << numOfErrors << " of errors" << endl;
	}
}

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void removeIndex(int removeIndex);

int main(int argc, char **argv){
	int testToRun = atoi(argv[1]);
	switch (testToRun){
		case 1:
			test1();
			break;
		case 2:
			test2();
			break;
		case 3:
			test3();
			break;
		case 4:
			test4();
			break;
		case 5:
			test5();
			break;
		case 6:
			test6();
			break;
	}
	return 0;
}


void test1(){
	string K[11] = {"A","B","C","D","E","F","H","I","J","K","L"};
	int V[11] = {10,9,8,7,6,5,4,3,2,1,0};

	RBTree<string,int> T1, T2(K,V,11);
  cout << "output: ";
	T2.postorder();
	cout << "expect: A C B E H J L K I F D" << endl;
	// A C B E H J L K I F D

	//Test edge case
	T2.remove("J");
	T2.remove("K");

	for(int i=0; i<11; i++) T1.insert(K[i],V[i]);
	// T1 and T2 should be identical trees

  cout << "\noutput: ";
	T1.postorder();
	cout << "expect: A C B E H J L K I F D" << endl;
	// A C B E H J L K I F D

	T1.insert("AF",11);
	T1.insert("AE",12);
	T1.insert("AD",13);
	cout << "\noutput: " << *(T1.search("AF")) << endl;
  cout << "expect: 11" << endl;
	// 11

	cout << "\noutput: " << T1.rank("I") << endl;
  cout << "expect: 11" << endl;
	// 11

	cout << "\noutput: " << T1.select(5) << endl;
  cout << "expect: B" << endl;
	// B

  cout << "\noutput: ";
	T1.preorder();
	cout << "expect: D B AE A AD AF C F E I H K J L" << endl;
	// D B AE A AD AF C E F I H K J L

  cout << "\noutput: ";
	T1.inorder();
	cout << "expect: A AD AE AF B C D E F H I J K L" << endl;
	// A AD AE AF B C D E F H I J K L

	cout << "\noutput: " << T1.remove("HAHA") << endl;
  cout << "expect: 0" << endl;
	// 0

	cout << "\noutput: " << T1.remove("AD") << endl;
  cout << "expect: 1" << endl;
	// 1

	cout << "\noutput: " << T1.rank("K") << endl;
  cout << "expect: 12" << endl;
	// 12

  cout << "\noutput: ";
	T1.inorder();
	cout << "expect: A AE AF B C D E F H I J K L" << endl;
	// A AE AF B C D E F H I J K L

  cout << "\noutput: ";
	T1.preorder();
	cout << "expect: D B AE A AF C F E I H K J L" << endl;

  cout << "\noutput: ";
	T1.postorder();
	cout << "expect: A AF AE C B E H J L K I F D" << endl;

  cout << "\noutput: ";
  T1.printk(5);
	cout << "expect: A AE AF B C" << endl;

	cout << "\nFinished without failing" << endl << endl;
}

void test2(){

	RBTree<int,int> X;
	for (int i=102;i>=0;i--)
    X.insert(i,102-i);

	cout << "\noutput: ";
  X.preorder();
	cout << "expect: 71 55 39 23 15 11 7 5 3 1 0 2 4 6 9 8 10 13 12 14 19 17 16 18 21 20 22 31 27 25 24 26 29 28 30 35 33 32 34 37 36 38 47 43 41 40 42 45 44 46 51 49 48 50 53 52 54 63 59 57 56 58 61 60 62 67 65 64 66 69 68 70 87 79 75 73 72 74 77 76 78 83 81 80 82 85 84 86 95 91 89 88 90 93 92 94 99 97 96 98 101 100 102" << endl;

  cout << "\noutput: ";
  X.postorder();
	cout << "expect: 0 2 1 4 3 6 5 8 10 9 7 12 14 13 11 16 18 17 20 22 21 19 15 24 26 25 28 30 29 27 32 34 33 36 38 37 35 31 23 40 42 41 44 46 45 43 48 50 49 52 54 53 51 47 39 56 58 57 60 62 61 59 64 66 65 68 70 69 67 63 55 72 74 73 76 78 77 75 80 82 81 84 86 85 83 79 88 90 89 92 94 93 91 96 98 97 100 102 101 99 95 87 71" << endl;

  cout << "\noutput: ";
  X.inorder();
	cout << "expect: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102" << endl;

  cout << "\noutput: ";
  X.printk(50);
	cout << "expect: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49" << endl;

	RBTree<int,int> Y = X;
	for (int i=0; i < 50; i++){
		X.rank(i);
		X.remove(i);
	}

  cout << "\noutput: ";
  X.preorder();
	cout << "expect: 71 63 55 51 50 53 52 54 59 57 56 58 61 60 62 67 65 64 66 69 68 70 87 79 75 73 72 74 77 76 78 83 81 80 82 85 84 86 95 91 89 88 90 93 92 94 99 97 96 98 101 100 102" << endl;

  cout << "\noutput: ";
  X.postorder();
	cout << "expect: 50 52 54 53 51 56 58 57 60 62 61 59 55 64 66 65 68 70 69 67 63 72 74 73 76 78 77 75 80 82 81 84 86 85 83 79 88 90 89 92 94 93 91 96 98 97 100 102 101 99 95 87 71" << endl;

  cout << "\noutput: ";
  X.inorder();
	cout << "expect: 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102" << endl;

  cout << "\noutput: ";
  Y.preorder();
	cout << "expect: 71 55 39 23 15 11 7 5 3 1 0 2 4 6 9 8 10 13 12 14 19 17 16 18 21 20 22 31 27 25 24 26 29 28 30 35 33 32 34 37 36 38 47 43 41 40 42 45 44 46 51 49 48 50 53 52 54 63 59 57 56 58 61 60 62 67 65 64 66 69 68 70 87 79 75 73 72 74 77 76 78 83 81 80 82 85 84 86 95 91 89 88 90 93 92 94 99 97 96 98 101 100 102" << endl;

  cout << "\noutput: ";
  Y.postorder();
	cout << "expect: 0 2 1 4 3 6 5 8 10 9 7 12 14 13 11 16 18 17 20 22 21 19 15 24 26 25 28 30 29 27 32 34 33 36 38 37 35 31 23 40 42 41 44 46 45 43 48 50 49 52 54 53 51 47 39 56 58 57 60 62 61 59 64 66 65 68 70 69 67 63 55 72 74 73 76 78 77 75 80 82 81 84 86 85 83 79 88 90 89 92 94 93 91 96 98 97 100 102 101 99 95 87 71" << endl;

  cout << "\noutput: ";
  Y.inorder();
	cout << "expect: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102" << endl;

  cout << "\noutput: ";
  Y.printk(50);
	cout << "expect: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49" << endl;

  RBTree<int,int> Z;
  for(int i=0; i < 1000200; i++)
    Z.insert(i, 1000200-i);

  cout << "\noutput: ";
  Z.printk(100);
	cout << "expect: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99" << endl;

	cout << "Finished without failing" << endl << endl;
}

void test3(){
	int rankError = 0;
	int selectError = 0;
	int searchError = 0;
	int treeSize = 100200;
    RBTree<int,int> X;
	for (int i=treeSize;i>=0;i--) X.insert(i,treeSize-i);
	for (int i=1;i<treeSize;i++) {
		if(X.rank(i) != i+1) rankError++;
		if(X.select(i) != i-1) selectError++;
		if(*(X.search(i)) != treeSize-i) searchError++;
	}
	printErrors("Rank",rankError);
	printErrors("Select",selectError);
	printErrors("Search",searchError);
	cout << "Finished without failing" << endl << endl;
}

void test4(){
	removeIndex(11);
}

void test5(){
	removeIndex(17);
}

void test6(){
	RBTree<int,int> X;
	int predErrors = 0;
	int succErrors = 0;
    int size = 11000;
	for (int i=size;i>=0;i--) X.insert(i,size-i);
	for (int i=0; i < X.size(); i++){
		if(i == 0){
            if(X.predecessor(i) != NULL) cout << "Doesn't return NULL for predecessor" << endl;
		}
        else if(*(X.predecessor(i)) != i-1){
            predErrors++;
        }
	}
	printErrors("Pred errors",predErrors);

	for (int i=X.size()-1; i >= 0; i--){
		if(i == size){
            if(X.successor(i) != NULL) cout << "Doesn't return NULL for successor" << endl;
		}
        else if(*(X.successor(i)) != i+1){
            succErrors++;
        }
	}
	printErrors("Succ Errors",succErrors);

	cout << "Finished without failing" << endl << endl;
}

void removeIndex(int removeIndex){
	int rankError = 0;
	int selectError = 0;
	int searchError = 0;
    RBTree<int,int> X;
	int size = 100200;
    for (int i=size;i>=0;i--) X.insert(i,size-i);
	for (int i=0;i<size;i+=removeIndex) X.remove(i);
	for (int i=1;i<size-size/removeIndex;i++){

        int part1Answer = i / removeIndex;
		// Needed for round off error
		int answer = i+(i+(i+(i+(i+(i + i / removeIndex)/removeIndex)/removeIndex)/removeIndex)/removeIndex)/removeIndex;

		//printf("i is %d, Select %d, Rank %d, Search %d\n",i, answer, i-i/removeIndex, size-i);

        if(X.select(i) != answer){
			selectError++;
			//cout << "i is " << i << " Select error after delete " << X.select(i)  << " should be " <<  answer << " or " << part1Answer << endl;
		}
		if (i%removeIndex) {
			//cout << i << " is i" << endl;
			if(X.rank(i) != i-i/removeIndex){
                rankError++;
                //cout << "Rank error after delete " << X.rank(i) << " should be " << i << " - " << i-i/removeIndex << endl;
			}
            if(*(X.search(i)) != size-i) searchError++;// cout << "Search error after delete" << endl;
            X.remove(i);
			X.insert(i,size-i);
		}
	}
	printErrors("Rank after delete",rankError);
	printErrors("Select after delete",selectError);
	printErrors("Search after delete",searchError);
	cout << "Finished without failing" << endl << endl;
}
