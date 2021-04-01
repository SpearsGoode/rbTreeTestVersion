//Spears Goode
//RBTreeTest

/*=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=-\
\   _____   _____   ______   ___    _____   _____       ____    ___     ___    ___    ______  /
/  /     \ |     \ |        /   \  |     \ /     \     /    \  /   \   /   \  |   \  |        \
\  \_____  |_____/ |_____  |_____| |_____/ \_____     /       /     \ /     \ |    \ |_____   /
/        \ |       |       |     | |    \        \    \   ___ \     / \     / |    / |        \
\  \_____/ |       |______ |     | |     \ \_____/     \____/  \___/   \___/  |___/  |______  /
/                                                                                             \
\^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=*/

#include "RBTree.cpp"
#include <iostream>
#include <random>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  RBTree<int,int> X;
	for (int i=102;i>=0;i--)
    X.insert(i,102-i);

  RBTree<int,int> Y = X;
  for (int i=0; i < 50; i++){
  	X.rank(i);
  	X.remove(i);
  }


  cout << "\noutput: ";
  Y.preorder();
	cout << "expect: 71 55 39 23 15 11 7 5 3 1 0 2 4 6 9 8 10 13 12 14 19 17 16 18 21 20 22 31 27 25 24 26 29 28 30 35 33 32 34 37 36 38 47 43 41 40 42 45 44 46 51 49 48 50 53 52 54 63 59 57 56 58 61 60 62 67 65 64 66 69 68 70 87 79 75 73 72 74 77 76 78 83 81 80 82 85 84 86 95 91 89 88 90 93 92 94 99 97 96 98 101 100 102" << endl;

  cout << "\noutput: ";
  Y.postorder();
	cout << "expect: 0 2 1 4 3 6 5 8 10 9 7 12 14 13 11 16 18 17 20 22 21 19 15 24 26 25 28 30 29 27 32 34 33 36 38 37 35 31 23 40 42 41 44 46 45 43 48 50 49 52 54 53 51 47 39 56 58 57 60 62 61 59 64 66 65 68 70 69 67 63 55 72 74 73 76 78 77 75 80 82 81 84 86 85 83 79 88 90 89 92 94 93 91 96 98 97 100 102 101 99 95 87 71" << endl;
  

  // cout << "Starting RBTreeTest" << endl;
  // cout << "==========================\n" << endl;
  // cout << "test set: index: key | val" << endl;
  int K0[30];
  string V0[30] = {
    "clown", "car", "scuba", "donkey",
    "masha", "syd", "food", "target",
    "haley", "linux", "water", "bread",
    "thirteen", "eleven", "simon",
    "flavor", "mars", "steep", "enemy",
    "eject", "real", "grave", "desire",
    "boom", "stand", "room", "wrong",
    "risk", "spot", "jacket"};
  random_device rd;
  mt19937 gen(rd());
  for (int i = 0; i < 30; i++) {
    uniform_int_distribution<>
    distrib(1000,9999);
    K0[i] = distrib(gen);
    // if (i < 10) cout << 0;
    // cout << i << ": [" << K0[i] << " | " << V0[i] << "]" <<  endl;
  }
  // cout << "==========================\n" << endl;

  RBTree<int, string> tree0(K0, V0, 30);

  // cout << "==========================\n" << endl;

  // tree0.view(tree0.getroot(), "", true);

  // cout << "==========================\n" << endl;

  RBTree<int, string> tree1(tree0);

  // tree1.view(tree1.getroot(), "", true);

  // cout << "==========================\n" << endl;

  // RBTree<int, string> tree2;
  // tree2.insert(7, "salmon");
  // tree2.insert(1, "forza");
  // tree2.insert(3, "mount");
  // tree2.insert(4, "blade");
  // tree2.insert(2, "orange");
  // tree2.insert(6, "pink");
  // tree2.insert(9, "purple");

  // tree2.view(tree2.getroot(), "", true);

  // cout << "==========================\n" << endl;

  // tree2 = tree1;

  // tree2.view(tree2.getroot(), "", true);

  // cout << "==========================\n" << endl;

  int K1[30];
  string V1[30] = {
    "dylan", "george", "kink", "diamond",
    "gme", "hand", "ape", "john",
    "phase", "manjaro", "link", "eth",
    "btc", "twelve", "ocean",
    "rip", "testing", "is", "hard",
    "why", "did", "I", "pick",
    "this", "major", "oof", "im",
    "dead", "inside", "lmao"};
  for (int i = 0; i < 30; i++) {
    uniform_int_distribution<>
    distrib(1000,9999);
    K1[i] = distrib(gen);
    // cout << i+30 << ": [" << K1[i] << " | " << V1[i] << "]" <<  endl;
  }
  // cout << "==========================\n" << endl;

  for (int i = 0; i < 30; i++)
    tree1.insert(K1[i], V1[i]);



  // cout << "==========================\n" << endl;
  //
  // cout << "there are " << tree0.size() << " elements in tree0;" << endl;
  //
  // cout << "there are " << tree1.size() << " elements in tree1;" << endl;

  // cout << "==========================\n" << endl;
  //
  // cout << "\nsearching for " << K1[5] << endl;
  // cout << "should get " << V1[5] << endl;
  // cout << "result: " << *tree1.search(K1[5]) << endl;
  //
  // cout << "\nsearching for " << K0[5] << endl;
  // cout << "should get " << V0[5] << endl;
  // cout << "result: " << *tree1.search(K0[5]) << endl;
  //
  // cout << "\nsearching for " << K0[7] << endl;
  // cout << "should get " << V0[7] << endl;
  // cout << "result: " << *tree1.search(K0[7]) << endl;
  //
  // cout << "\nsearching for " << K0[11] << endl;
  // cout << "should get " << V0[11] << endl;
  // cout << "result: " << *tree1.search(K0[11]) << endl;
  //
  // cout << "\nsearching for -1" << endl;
  // cout << "should get NULL" << endl;
  // if (tree1.search(-1) == NULL)
  //   cout << "result: NULL" << endl;
  // else cout << "error" << endl;
  //
  // cout << "\nsearching for " << K1[7] << endl;
  // cout << "should get " << V1[7] << endl;
  // cout << "result: " << *tree1.search(K1[7]) << endl;
  //
  // cout << "\nsearching for " << K0[13] << endl;
  // cout << "should get " << V0[13] << endl;
  // cout << "result: " << *tree1.search(K0[13]) << endl;

  // cout << "==========================\n" << endl;

  // for (int i = 0; i < 15; i++) {
  //   cout << "rank of " << K0[i] << ": " << tree1.rank(K0[i]) << endl;
  //   cout << "rank of " << K1[i] << ": " << tree1.rank(K1[i]) << endl;
  // }

  // cout << "==========================\n" << endl;

  // cout << "rank of " << 7777 << ": " << tree1.rank(7777) << endl;
  // cout << "rank of " << 1234 << ": " << tree1.rank(1234) << endl;
  //
  // for (int i = 0; i < 15; i++) {
  //   uniform_int_distribution<>
  //   distrib(1000,9999);
  //   int tmp = distrib(gen);
  //   cout << "rank of " << tmp << ": " << tree1.rank(tmp) << endl;
  // }

  // for (int i = 1; i <= 30; i++) {
  //   cout << "key at rank " << i << ": " << tree1.select(i) << endl;
  // }

  // cout << "==========================\n" << endl;
  //
  // tree1.view(tree1.getroot(), "", true);
  //
  // cout << "==========================\n" << endl;
  //
  // cout << "preorder:\n" << endl;
  // tree1.preorder();
  //
  // cout << "==========================\n" << endl;
  //
  // cout << "inorder:\n" << endl;
  // tree1.inorder();
  //
  // cout << "==========================\n" << endl;
  //
  // cout << "postorder:\n" << endl;
  // tree1.postorder();
  //
  // cout << "==========================\n" << endl;

  // for (int i = 0; i < 16; i++) {
  //   if (tree1.predecessor(K0[i]) != NULL)
  //     cout << "predecessor of " << K0[i] << " -> " << *tree1.predecessor(K0[i]) << endl;
  //   else cout << K0[i] << " has no predecessor" << endl;
  //   if (tree1.successor(K0[i]) != NULL)
  //     cout << "successor of " << K0[i] << " -> " << *tree1.successor(K0[i]) << endl;
  //   else cout << K0[i] << " has no successor" << endl;
  //   if (tree1.predecessor(K1[i]) != NULL)
  //     cout << "predecessor of " << K1[i] << " -> " << *tree1.predecessor(K1[i]) << endl;
  //   else cout << K1[i] << " has no predecessor" << endl;
  //   if (tree1.successor(K1[i]) != NULL)
  //     cout << "successor of " << K1[i] << " -> " << *tree1.successor(K1[i]) << endl;
  //   else cout << K1[i] << " has no successor" << endl;
  // }

  // cout << "==========================\n" << endl;

  // tree1.printk(5);

  // tree1.view(tree1.getroot(), "", true);

  for (int i = 0; i < 9; i++) {
    uniform_int_distribution<>
    distrib(0,14);
    int tmp = distrib(gen);
    if (tree1.remove(K0[tmp])) {
      // cout << "   ---> deleted " << K0[tmp] << endl;
      // tree1.view(tree1.getroot(), "", true);
    }
    if (tree1.remove(K1[tmp])) {
      // cout << "   ---> deleted " << K1[tmp] << endl;
      // tree1.view(tree1.getroot(), "", true);
    }
    // cout << "results:\n" << tree1.remove(K0[tmp]) << endl;

    // cout << "----\n" << endl;
    // cout << "results:\n" << tree1.remove(K1[tmp]) << endl;

    // cout << "----\n" << endl;

  }
  // tree1.view(tree1.getroot(), "", true);
  // cout << "==========================\n" << endl;

  // cout << "key to delete: " << endl;
  // int sel;
  // cin >> sel;
  //
  // cout << "results:\n" << tree1.remove(sel) << endl;
  // tree1.view(tree1.getroot(), "", true);
  // cout << "----\n" << endl;


  return 0;
}
