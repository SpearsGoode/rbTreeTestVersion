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
  return !black;
}


   /* // = = = = = = = = = // */
  /* //===================// */
 /* // RBTree /// RBTree // */
/* //===================// */

template <typename keyT, typename valT>
class RBTree {
  struct RBNode<keyT, valT> *root;
  int count;
  void mkRoot();                // working
  RBNode<keyT, valT> *getMin(   // working
    RBNode<keyT, valT> *
  );
  RBNode<keyT, valT> *getMax(   // working
    RBNode<keyT, valT> *
  );
  RBNode<keyT, valT> *up1(      // working
    RBNode<keyT, valT> *
  );
  RBNode<keyT, valT> *dn1(      // working
    RBNode<keyT, valT> *
  );
  void clone(                   // working
    RBNode<keyT, valT>*
  );
  void destroy(                 // working
    RBNode<keyT, valT>*
  );
  RBNode<keyT, valT> *find(     // working
    RBNode<keyT, valT>*, keyT
  );
  int tally(bool*,              // working
    RBNode<keyT, valT>*, keyT
  );
  RBNode<keyT, valT> *add(      // working
    RBNode<keyT, valT>*,
    RBNode<keyT, valT>*);
  void fixAdd(                  // working
    RBNode<keyT, valT>*);
  void rotateL(                 // working
    RBNode<keyT, valT>*);
  void rotateR(                 // working
    RBNode<keyT, valT>*);
public:
  RBTree() {mkRoot();}          // working
  RBTree(keyT*, valT*, int);    // working
  RBTree(RBTree&);              // working
  ~RBTree() {destroy(root);}    // working
  RBTree& operator=(RBTree);    // working
  valT *search(keyT);           // working well
  void insert(keyT, valT);      // working
  int remove(keyT);             // makeMe
  int rank(keyT);               // too slow
  keyT select(int);             // too slow
  keyT *successor(keyT);        // working
  keyT *predecessor(keyT);      // makeMe
  int size() {return count;}    // working
  void preorder();              // makeMe
  void inorder();               // makeMe
  void postorder();             // makeMe
  void printk(int);             // makeMe

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
  mkRoot();
  insert(src.root->key, src.root->val);
    // recursivly duplicate each node
  clone(src.root);
}

  // Cppy Assignment Operator
template <typename keyT, typename valT>
RBTree<keyT, valT>& RBTree<keyT, valT>::
operator=(RBTree src) {
    // recursivly delete & duplicate each node
  destroy(this->root);
  mkRoot();
  insert(src.root->key, src.root->val);
  clone(src.root);
  return *this;
}

  // Find Value @ Key Location
template <typename keyT, typename valT>
valT* RBTree<keyT, valT>::
search(keyT k) {
  RBNode<keyT, valT> *loc = find(root, k);
  if (loc) return &loc->val;
  else return NULL;
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
    // cout << "[" << k << " | " << v << "] added" << endl;    // TEST
    return;
  }
    // create new node
  struct RBNode<keyT, valT> *node
  = new RBNode<keyT, valT>(k, v);
    // add node to tree
  RBNode<keyT, valT> *tree = root;
  root = add(node, tree);
  // cout << "[" << k << " | " << v << "] added" << endl;      // TEST
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
  int i;
  bool found = false;
  bool *f = &found;
  if (k == root->key) {
    i = 1; *f=true;
    if (root->l)
      i += tally(f, root->l, k);
  }
  if (k < root->key) {
    i = 0;
    if (root->l)
      i += tally(f, root->l, k);
  }
  if (k > root->key) {
    i = count; ++i;
    if (root->r)
      i -= tally(f, root->r, k);
  }
  if (!found) return 0;
  else return i;
}

  // Returns Key @ Position
template <typename keyT, typename valT>
keyT RBTree<keyT, valT>::
select(int pos) {
  RBNode<keyT, valT> *node = getMin(root);
  for (int i = 1; i < pos; i++) {
    node = up1(node);
  } return node->key;
}

  // Returns Successor
template <typename keyT, typename valT>
keyT* RBTree<keyT, valT>::
successor(keyT k) {
  RBNode<keyT, valT> *node;
  node = find(root, k);
  if (!node) return NULL;
  node = up1(node);
  if (node)
    return &node->key;
  else return NULL;
}

  // Returns Predecessor
template <typename keyT, typename valT>
keyT* RBTree<keyT, valT>::
predecessor(keyT k) {
  RBNode<keyT, valT> *node;
  node = find(root, k);
  if (!node) return NULL;
  node = dn1(node);
  if (node)
    return &node->key;
  else return NULL;
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
RBNode<keyT, valT> *RBTree<keyT, valT>::
getroot(){
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

  // Returns Smallest Element
template <typename keyT, typename valT>
RBNode<keyT, valT> *RBTree<keyT, valT>::
getMin(RBNode<keyT, valT> *node) {
  while (node->l) node = node->l;
  return node;
}

  // Returns Largest Element
template <typename keyT, typename valT>
RBNode<keyT, valT> *RBTree<keyT, valT>::
getMax(RBNode<keyT, valT> *node) {
  while (node->r) node = node->r;
  return node;
}

  // Returns Next Largest Element
template <typename keyT, typename valT>
RBNode<keyT, valT> *RBTree<keyT, valT>::
up1(RBNode<keyT, valT> *node) {
  if (node->r)
    return getMin(node->r);
  RBNode<keyT, valT> *rent = node->p;
  while (rent && node == rent->r) {
    node = rent;
    rent = rent->p;
  }return rent;
}

  // Returns Next Smallest Element
template <typename keyT, typename valT>
RBNode<keyT, valT> *RBTree<keyT, valT>::
dn1(RBNode<keyT, valT> *node) {
  if (node->l)
    return getMax(node->l);
  RBNode<keyT, valT> *rent = node->p;
  while (rent && node == rent->l) {
    node = rent;
    rent = rent->p;
  }return rent;
}

  // Recursivly Duplicates RBNodes
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
clone(RBNode<keyT, valT> *src) {
  if (!src) return;
  if (src->l != nullptr)
    insert(src->l->key, src->l->val);
  if (src->r != nullptr)
    insert(src->r->key, src->r->val);
  clone(src->r); clone(src->l);
}

  // Recursivly Deletes RBNodes
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
destroy(RBNode<keyT, valT> *node) {
  if (!node) return;
  // cout << "destroying node: [" << node->key << " | " << node->val << "]" << endl;
  if (node->l != nullptr)
    destroy(node->l);
  if (node->r != nullptr)
    destroy(node->r);
  delete node;
}

  // Finds Node @ key
template <typename keyT, typename valT>
RBNode<keyT, valT> *RBTree<keyT, valT>::
find(RBNode<keyT, valT> *node, keyT k) {
  if (!node) return nullptr;
  if (node->key == k)
    return node;
  else if (node->key < k)
    node = find(node->r, k);
  else if (node->key > k)
    node = find(node->l, k);
  return node;
}

  // Counts Nodes Recursivly
template <typename keyT, typename valT>
int RBTree<keyT, valT>::
tally(bool *f, RBNode<keyT, valT> *node, keyT k) {
  int t = 0;
  if (k == node->key)
    *f=true;
  if (k > root->key) {
    if (k <= node->key) t = 1;
    if (node->l && k < node->key)
      t += tally(f, node->l, k);
    if (node->r)
      t += tally(f, node->r, k);
  } else {
    if (k >= node->key) t = 1;
    if (node->l)
      t += tally(f, node->l, k);
    if (node->r && k > node->key)
      t += tally(f, node->r, k);
  }
  return t;
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
  p = g = u = nullptr; n = node;
  // cout << " fixing Add()" << endl;                 //TEST
  while (n != root &&
  (n && n->red()) &&
  (n->p && n->p->red())){
    p = n->p; g = p->p;
    if (p == g->l) {
        // parent is left child
        // cout << "  parent is left child" << endl;   //TEST
      u = g->r;
      if (u && u->red()) {
          // uncle is red
          // cout << "   uncle is red" << endl;         //TEST
          // cout << "     recoloring" << endl;         //TEST
        u->black = 1;
        p->black = 1;
        g->black = 0;
        n = g;
      } else {
          // uncle is black
          // cout << "   uncle is black" << endl;       //TEST
        if (n == p->r) {
            // node is right child
            // cout << "    node is right child" << endl;//TEST
          rotateL(p);
          n = p;
          p = n->p;
        }
        rotateR(g);
          // cout << "     swaping clors" << endl;       //TEST
        int t = p->black;
        p->black = g->black;
        g->black = t;
        n = p;
      }
    } else {
        // parent is right child
        // cout << "  parent is right child" << endl;    //TEST
      u = g->l;
      if (u && u->red()) {
          // uncle is red
          // cout << "   uncle is red" << endl;          //TEST
          // cout << "     recoloring" << endl;          //TEST
        u->black = 1;
        p->black = 1;
        g->black = 0;
        n = g;
      } else {
          // uncle is black
          // cout << "   uncle is black" << endl;        //TEST
        if (n == p->l) {
            // node is left child
            // cout << "    node is left child" << endl; //TEST
          rotateR(p);
          n = p;
          p = n->p;
        }
        rotateL(g);
          // cout << "     swaping clors" << endl;       //TEST
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
    // cout << "     rotating left" << endl;  //TEST
  RBNode<keyT, valT> *tmp = node->r;
  node->r = tmp->l;
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

  // Rotates Nodes Right
template <typename keyT, typename valT>
void RBTree<keyT, valT>::
rotateR(RBNode<keyT, valT> *node) {
    // cout << "     rotating right" << endl; ///TEST
  RBNode<keyT, valT> *tmp = node->l;
  node->l = tmp->r;
  if (node->l != nullptr)
    node->l->p = node;
  tmp->p = node->p;
  if (node->p == nullptr)
    root = tmp;
  else
    if (node == node->p->l)
      node->p->l = tmp;
  else node->p->r = tmp;
  tmp->r = node;
  node->p = tmp;

}
