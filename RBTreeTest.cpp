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

  cout << "Starting RBTreeTest" << endl;
  cout << "==========================\n" << endl;
  cout << "test set: index: key | val" << endl;
  int K[15];
  string V[15] = {
    "clown", "car", "scuba", "donkey",
    "masha", "syd", "food", "target",
    "haley", "linux", "water", "bread",
    "thirteen", "eleven", "simon"};
  random_device rd;
  mt19937 gen(rd());
  for (int i = 0; i < 15; i++) {
    uniform_int_distribution<>
    distrib(1000,9999);
    K[i] = distrib(gen);
    if (i < 10) cout << 0;
    cout << i << ": [" << K[i] << " | " << V[i] << "]" <<  endl;
  } cout << "==========================\n" << endl;

  RBTree<int, string> tree0(K, V, 15);

  cout << "==========================\n" << endl;

  tree0.view(tree0.getroot(), "", true);

  cout << "==========================\n" << endl;

  RBTree<int, string> tree1(tree0);

  tree1.view(tree1.getroot(), "", true);

  cout << "==========================\n" << endl;

  RBTree<int, string> tree2;
  tree2.insert(7, "salmon");
  tree2.insert(1, "forza");
  tree2.insert(3, "mount");
  tree2.insert(4, "blade");
  tree2.insert(2, "orange");
  tree2.insert(6, "pink");
  tree2.insert(9, "purple");

  tree2.view(tree2.getroot(), "", true);

  cout << "==========================\n" << endl;

  tree2 = tree1;

  tree2.view(tree2.getroot(), "", true);

  cout << "==========================\n" << endl;

  return 0;
}
