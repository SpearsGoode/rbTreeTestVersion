//Spears Goode
//RBTree

/*=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=-\
\   _____   _____   ______   ___    _____   _____       ____    ___     ___    ___    ______  /
/  /     \ |     \ |        /   \  |     \ /     \     /    \  /   \   /   \  |   \  |        \
\  \_____  |_____/ |_____  |_____| |_____/ \_____     /       /     \ /     \ |    \ |_____   /
/        \ |       |       |     | |    \        \    \   ___ \     / \     / |    / |        \
\  \_____/ |       |______ |     | |     \ \_____/     \____/  \___/   \___/  |___/  |______  /
/                                                                                             \
\^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=_=-=^=-=*/

#include <iostream>
#include <string>
#include <new>

using namespace std;


   /* // = = = = = = = = = // */
  /* //===================// */
 /* // RBNode /// RBNode // */
/* //===================// */

template <typename keyT, typename valT>
struct RBNode {
  keyT key;
  valT val;
  RBNode* p;
  RBNode* l;
  RBNode* r;
  int black;
  RBNode();           // working
  RBNode(keyT, valT); // working
  bool leaf();        // working
  bool red();         // working
};


   /* // = = = = = = = = = = = = = = = = = = = = = = = = = = // */
  /* //=====================================================// */
 /* // RBNode Public Functions /// RBNode Public Functions // */
/* //=====================================================// */

  //RBNode Default Constructor
template <typename keyT, typename valT>
RBNode<keyT, valT>::
RBNode() {
  p = l = r = nullptr;
  black = 0;
}

  //RBNode Key/Val Constructor
template <typename keyT, typename valT>
RBNode<keyT, valT>::
RBNode(keyT k, valT v) {
  p = l = r = nullptr;
  key = k; val = v;
  black = 0;
}

  // Returns True If Leaf Node
template <typename keyT, typename valT>
bool RBNode<keyT, valT>::
leaf() {
  if (l == nullptr
  && r == nullptr)
    return true;
  else return false;
}

  // Returns True If Red Node
template <typename keyT, typename valT>
bool RBNode<keyT, valT>::
red() {
  if (this == nullptr)
    return false;
  else return !black;
}


   /* // = = = = = = = = = // */
  /* //===================// */
 /* // RBTree /// RBTree // */
/* //===================// */

template <typename keyT, typename valT>
class RBTree {
  struct RBNode<keyT, valT> *root;
  int count;
  void mkRoot();
  RBNode<keyT, valT> *clone(  // makeMe
    RBNode<keyT, valT>,
    RBNode<keyT, valT>);
  void destroy(               // working
    RBNode<keyT, valT>*);
  RBNode<keyT, valT> * add(   // test
    RBNode<keyT, valT>*,
    RBNode<keyT, valT>*);
  void fixAdd(                // test
    RBNode<keyT, valT>*);     // test
  void rotateL(
    RBNode<keyT, valT>*);    // test
  void rotateR(
    RBNode<keyT, valT>*);    // test
public:
  RBTree() {mkRoot();}        // working
  RBTree(keyT*, valT*, int);  // test
  RBTree(RBTree&);            // makeMe
  ~RBTree() {destroy(root);}  // working
  RBTree& operator=(RBTree);  // makeMe
  valT *search(keyT);         // makeMe
  void insert(keyT, valT);    // test
  int remove(keyT);           // makeMe
  int rank(keyT);             // makeMe
  keyT select(int);           // makeMe
  keyT *successor(keyT);      // makeMe
  keyT *predecessor(keyT);    // makeMe
  int size() {return count;}  // working
  void preorder();            // makeMe
  void inorder();             // makeMe
  void postorder();           // makeMe
  void printk(int);           // makeMe

// TESTING TESTING TESTING
  void view(                        // REMOVE ME !!!!!!!
    RBNode<keyT, valT>*,
    string, bool);
  RBNode<keyT, valT> *getroot();    // REMOVE ME !!!!!!!
};


   /* // = = = = = = = = = = = = = = = = = = = = = = = = = = // */
  /* //=====================================================// */
 /* // RBTree Public Functions /// RBTree Public Functions // */
/* //=====================================================// */


  // RBTree Array Constructor
template <typename keyT, typename valT>
RBTree<keyT, valT>::
RBTree(keyT *k, valT *v, int s) {
  mkRoot();
    // insert each element key/val pair
  for (int i = 0; i < s; i++)
    insert(k[i], v[i]);
}

  // RBTree Copy Constructor
template <typename keyT, typename valT>
RBTree<keyT, valT>::
RBTree(RBTree& src) {
    //recursivly duplicate each node
  this->root = clone(this->root, src.root);
}

  // Cppy Assignment Operator
template <typename keyT, typename valT>
RBTree<keyT, valT>& RBTree<keyT, valT>::
operator=(RBTree src) {
    //recursivly delete & duplicate each node
  destroy(this->root);
  this->root = clone(this->root, src.root);
}

  // Find Value @ Key Location
template <typename keyT, typename valT>
valT* RBTree<keyT, valT>::
search(keyT k) {

}

  // Insert New Node
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
insert(keyT k, valT v) {
    // check if empty
  if (++count == 1) {
      // add key/val to root
    root->key = k;
    root->val = v;
    cout << "[" << k << " | " << v << "] added" << endl;    // TEST
    return;
  }
    // create new node
  struct RBNode<keyT, valT> *node
  = new RBNode<keyT, valT>(k, v);
    // add node to tree
  RBNode<keyT, valT> *tree = root;
  root = add(node, tree);
  cout << "[" << k << " | " << v << "] added" << endl;      // TEST
    // fix if needed
  if (node->p->red())
    fixAdd(node);
}

  // Remove Node @ Key Location
template <typename keyT, typename valT>
int RBTree<keyT, valT>::
remove(keyT k) {
  return -1;
}

  // Returns Key Rank
template <typename keyT, typename valT>
int RBTree<keyT, valT>::
rank(keyT k) {
  return -1;
}

  // Returns Key @ Position
template <typename keyT, typename valT>
keyT RBTree<keyT, valT>::
select(int p) {

}

  // Returns Successor
template <typename keyT, typename valT>
keyT* RBTree<keyT, valT>::
successor(keyT k) {

}

  // Returns Predecessor
template <typename keyT, typename valT>
keyT* RBTree<keyT, valT>::
predecessor(keyT k) {

}

  // Prints Preordered Keys
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
preorder() {

}

  // Prints Inordered Keys
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
inorder() {

}

  // Prints Postordered Keys
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
postorder() {

}

  // Prints Smallest Keys
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
printk(int k) {

}

  // Prints Tree
template <typename keyT, typename valT>                     // REMOVE ME !!!!!!!
void RBTree<keyT, valT>::
view(RBNode<keyT, valT> *node, string indent, bool end) {
  if (node != nullptr) {
    cout << indent;
    if (end) {
      cout << "R----";
		  indent += "     ";
    } else {
      cout << "L----";
		  indent += "|    ";
    }
    cout << node->key << "{" << node->black << "}" << endl;
		view(node->l, indent, false);
	  view(node->r, indent, true);
  }
}

  //Returns Root
template <typename keyT, typename valT>                     // REMOVE ME !!!!!!!
RBNode<keyT, valT> *RBTree<keyT, valT>::getroot(){
  return root;
}

   /* // = = = = = = = = = = = = = = = = = = = = = = = = = = = // */
  /* //=======================================================// */
 /* // RBTree Private Functions /// RBTree Private Functions // */
/* //=======================================================// */


// Create Root Node
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
mkRoot() {
  root = new RBNode<keyT, valT>;
  root->black = 1;
  count = 0;
}

  // Recursivly Duplicates RBNodes
template <typename keyT, typename valT>
RBNode<keyT, valT> *RBTree<keyT, valT>::
clone(RBNode<keyT, valT>, RBNode<keyT, valT>) {

}

  // Recursivly Deletes RBNodes
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
destroy(RBNode<keyT, valT> *node) {
  if (!node) return;
  cout << "destroying node: [" << node->key << " | " << node->val << "]" << endl;
  if (node->l != nullptr) destroy(node->l);
  if (node->r != nullptr) destroy(node->r);
  delete node;
}

  // Adds Node To Tree
template <typename keyT, typename valT>
RBNode<keyT, valT> *RBTree<keyT, valT>::
add(RBNode<keyT, valT> *node, RBNode<keyT, valT> *tree) {
  if (tree == nullptr) return node;
  if (node->key < tree->key) {
    tree->l = add(node, tree->l);
    tree->l->p = tree;
  } else {
    tree->r = add(node, tree->r);
    tree->r->p = tree;
  } return tree;
}

  // Fixes Any Violations Add() Created
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
fixAdd(RBNode<keyT, valT> *node) {
  RBNode<keyT, valT> *p, *g, *u, *n;
  p = g = u = nullptr;
  n = node;
  cout << " fixing Add()" << endl;                 //TEST
  while (n != root && n->red() && n->p->red()){
    p = n->p; g = p->p;
    if (p == g->l) {
        // parent is left child
        cout << "  parent is left child" << endl;   //TEST
      u = g->r;
      if (u->red()) {
          // uncle is red
          cout << "   uncle is red" << endl;         //TEST
          cout << "     recoloring" << endl;         //TEST
        u->black = 1;
        p->black = 1;
        g->black = 0;
        n = g;
      } else {
          // uncle is black
          cout << "   uncle is black" << endl;       //TEST
        if (n == p->r) {
            // node is right child
            cout << "    node is right child" << endl;//TEST
          rotateL(p);
          n = p;
          p = n->p;
        }
        rotateR(g);
          cout << "     swaping clors" << endl;       //TEST
        int t = p->black;
        p->black = g->black;
        g->black = t;
        n = p;
      }
    } else {
        // parent is right child
        cout << "  parent is right child" << endl;    //TEST
      u = g->l;
      if (u->red()) {
          // uncle is red
          cout << "   uncle is red" << endl;          //TEST
          cout << "     recoloring" << endl;          //TEST
        u->black = 1;
        p->black = 1;
        g->black = 0;
        n = g;
      } else {
          // uncle is black
          cout << "   uncle is black" << endl;        //TEST
        if (n == p->l) {
            // node is left child
            cout << "    node is left child" << endl; //TEST
          rotateR(p);
          n = p;
          p = n->p;
        }
        rotateL(g);
          cout << "     swaping clors" << endl;       //TEST
        int t = p->black;
        p->black = g->black;
        g->black = t;
        n = p;
      }
    }
  } root->black = 1;
}

  // Rotates Nodes Left
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
rotateL(RBNode<keyT, valT> *node) {
    cout << "     rotating left" << endl;  //TEST
  RBNode<keyT, valT> *tmp = node->r;
  node->r = tmp->l;
  if (node->l != nullptr)
    node->l->p = node;
  tmp->p = node->p;
  if (node->p == nullptr)
    root = tmp;
  else
    if (node == node->p->r)
      node->p->r = tmp;
  else node->p->l = tmp;
  tmp->r = node;
  node->p = tmp;
}

  // Rotates Nodes Right
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
rotateR(RBNode<keyT, valT> *node) {
    cout << "     rotating right" << endl; ///TEST
  RBNode<keyT, valT> *tmp = node->l;
  node->l = tmp->r;
  if (node->r != nullptr)
    node->r->p = node;
  tmp->p = node->p;
  if (node->p == nullptr)
    root = tmp;
  else
    if (node == node->p->l)
      node->p->l = tmp;
  else node->p->r = tmp;
  tmp->l = node;
  node->p = tmp;

}
