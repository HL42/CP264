/* 
 * Code example for CP264 Data Structures II
 * simple BST
 * search, insert, delete by recursive and iterative algorithms
 * HBF 
*/

#include<stdlib.h>
#include<stdio.h>

typedef struct tree_node {
  int data;
  struct tree_node *left; 
  struct tree_node *right;
} tnode;


// for BST
tnode *recursive_search(tnode *, int); // recursion version
int recursive_insert(tnode **, int);   // return 1 if successful, 0 otherwise; recursion version
int recursive_delete(tnode **, int);    // return 1 if successful, 0 otherwise; recursion version
tnode *extract_smallest_node(tnode **); // recursion version
tnode *find_smallest_element(tnode *); //return the smallest node, recursion version 

// space efficient BST algorithms
tnode *iterative_search(tnode *, int); //recursion version
int iterative_insert(tnode **, int);   //return 1 if successful, 0 otherwise; recursion version
int iterative_delete(tnode **, int);   //return 1 if successful, 0 otherwise; recursion version
tnode *iterative_extract_smallest_node(tnode **); // iterative version
tnode *iterative_find_largest_element(tnode *);  //return the smallest node, iterative version

// for general binary tree
tnode *new_node(int);
void print_preorder(tnode *);
void print_inorder(tnode *);
void print_postorder(tnode *);
void print_tree(tnode *, int);
void clean_tree(tnode **);

int main() {
  tnode *root = NULL, *np;
  printf("\nTest BST recursive algorithm\n");  
  recursive_insert(&root, 5);  
  recursive_insert(&root, 7);
  recursive_insert(&root, 2);
  recursive_insert(&root, 4);
  recursive_insert(&root, 3);
  recursive_insert(&root, 6);
  recursive_insert(&root, 9);
  recursive_insert(&root, 1);
  recursive_insert(&root, 8);
  
  printf("\n");
  print_tree(root, 0);

  printf("\nin-order: ");
  print_inorder(root);

  printf("\npre-order: ");
  print_preorder(root);

  printf("\npos-torder: ");
  print_postorder(root);

  np = recursive_search(root, 7);
  if (np)
    printf("\nFound %d by recursive search", np->data);
  else
    printf("\nNot found");

  np = recursive_search(root, 10);
  if (np)
    printf("\nFound %d by recursive search", np->data);
  else
    printf("\nNot found");
    
  printf("\nSmallest element: %d\n", find_smallest_element(root)->data);
  printf("\nLargestest element: %d\n", iterative_find_largest_element(root)->data);
  
  print_tree(root, 0);
  printf("\nDelete %d\n", 7);
  recursive_delete(&root, 7);  
  print_tree(root, 0);
  printf("Delete %d\n", 3);
  recursive_delete(&root, 3);
  print_tree(root, 0);
  printf("Delete %d\n", 5);
  recursive_delete(&root, 5);    
  print_tree(root, 0);
  clean_tree(&root);
  
  printf("\niterative insert algorithm\n");
  iterative_insert(&root, 5);  
  iterative_insert(&root, 7);
  iterative_insert(&root, 2);
  iterative_insert(&root, 4);
  iterative_insert(&root, 3);
  iterative_insert(&root, 6);
  iterative_insert(&root, 9);
  iterative_insert(&root, 1);
  iterative_insert(&root, 8);

  printf("\ntree style\n");
  print_tree(root, 0);

  printf("\niterative search algorithm\n");
  np = iterative_search(root, 7);
  if (np)
    printf("\nFound %d by iterative search", np->data);
  else
    printf("\nNot found");

  np = iterative_search(root, 10);
  if (np)
    printf("\nFound %d by iterative search", np->data);
  else
    printf("\nNot found");
      
  printf("\niterative delete algorithm without extracting\n");    
  print_tree(root, 0);
  printf("\nDelete %d\n", 7);
  iterative_delete(&root, 7);  
  print_tree(root, 0);
  printf("Delete %d\n", 3);
  iterative_delete(&root, 3);
  print_tree(root, 0);
  printf("Delete %d\n", 5);
  iterative_delete(&root, 5);    
  print_tree(root, 0);  
  clean_tree(&root);
  
  printf("\niterative extrace and delete algorithm\n");
  iterative_insert(&root, 5);  
  iterative_insert(&root, 7);
  iterative_insert(&root, 2);
  iterative_insert(&root, 4);
  iterative_insert(&root, 3);
  iterative_insert(&root, 6);
  iterative_insert(&root, 9);
  iterative_insert(&root, 1);
  iterative_insert(&root, 8);
  print_tree(root, 0);
  
  printf("delete 5:");
  iterative_delete_extract(&root, 5);
  printf("\n");
  print_tree(root, 0);
  
  printf("delete 3:");
  iterative_delete_extract(&root, 3);
  printf("\n");
  print_tree(root, 0);
  
  printf("delete 6:");
  iterative_delete_extract(&root, 6);
  printf("\n");
  print_tree(root, 0);
  
  printf("delete 9:");
  iterative_delete_extract(&root, 9);
  printf("\n");
  print_tree(root, 0);
  
  clean_tree(&root);
  return 0;
}

tnode *new_node(int data) {
  tnode *np = (tnode *) malloc(sizeof(tnode));
  if (np == NULL) return NULL;
  np->data = data;
  np->left = NULL;
  np->right = NULL;
  return np;
}
//recursive, time complexity O(height), space complexity O(height)
tnode *recursive_search(tnode *root, int val) {
  if (root==NULL) return NULL;
  else if (val == root->data) return root;
  else if (val < root->data) {
    return recursive_search(root->left, val);
  } else {
    return recursive_search(root->right, val);
  }
}

//recursive, time complexity O(height), space complexity O(height)
int recursive_insert(tnode **rootp, int val) {
  if (*rootp == NULL) {
    *rootp = new_node(val);
    if (*rootp) return 1;
    else return 0;
  } else {
    if (val == (*rootp)->data) {
      return 0;
    }
    else if (val < (*rootp)->data)
     return recursive_insert(&(*rootp)->left, val);
    else 
     return recursive_insert(&(*rootp)->right, val);
  }    
}

//recursive, time complexity O(height), space complexity O(height)
int recursive_delete(tnode **rootp, int val) {
  tnode *root = *rootp, *tnp;
  if (root == NULL) {
    return 0;
  }   
  else if(val == root->data ) {
    if(root->left == NULL && root->right == NULL) {
      free(root);
      *rootp = NULL;
    }
    else if (root->left != NULL && root->right == NULL) {
      tnp = root->left;
      free(root);        
      *rootp = tnp;
    }
    else if (root->left == NULL && root->right != NULL) {
      tnp = root->right;  
      free(root);        
      *rootp = tnp;
    }    
    else if( root->left!= NULL && root->right != NULL ) {
      tnp = extract_smallest_node(&root->right);
      tnp->left = root->left;
      tnp->right = root->right;      
      *rootp = tnp;
      free(root);
    }
    return 1;
  }
  else {
    if(val < root->data) {
      return recursive_delete(&root->left, val);
    }
    else {
      return recursive_delete(&root->right, val);
    }
  }
}


//recursive, time complexity O(height), space complexity O(height)
tnode *extract_smallest_node(tnode **rootp) {
  tnode *root = *rootp;
  if (root == NULL) {
     return NULL;
  }  
  else if (root->left == NULL) {
    *rootp = root->right;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  else {
    return extract_smallest_node(&root->left);
  }
}

//iterative, time complexity O(height), space complexity O(1)
tnode *find_smallest_element(tnode *root) {
  if (root == NULL) return root;
  while (root->left != NULL) root=root->left;
  return root;
}

//iterative, time complexity O(height), space complexity O(1)
tnode *iterative_find_largest_element(tnode *root) {
  if ( root == NULL) return root;
  while (root->right != NULL) root=root->right;
  return root;
}

//iterative algorithm, time complexity O(height), space complexity O(1)
tnode *iterative_search(tnode *root, int val) {
  while (root) {
    if (val == root->data) 
       return root;
    else if (val < root->data) 
       root = root->left;
        else 
      root = root->right;  
  }
  return NULL;
}

int iterative_insert(tnode **rootp, int val) {
  if (*rootp == NULL) { *rootp = new_node(val); return 1;}
  else {
    tnode *tnp = *rootp;
    while (1) {
      if (val == tnp->data) {
          printf("\nThe same key value is found");
        return 0;
      }
      else if (val < tnp->data) {
         if (tnp->left == NULL) {
           tnp->left = new_node(val); break;
         }
         else tnp = tnp->left;
      }   
      else {
         if (tnp->right == NULL) {
            tnp->right = new_node(val);
          break;
         }    
         else tnp = tnp->right;
      }
    }
    return 1;
    }
}

tnode *iterative_extract_smallest_node(tnode **rootp) {
  if (*rootp == NULL) return NULL;
  
  tnode *tnp = *rootp, *ptnp = NULL;
  while (tnp->left != NULL) {
    ptnp = tnp;
    tnp = tnp->left;
  }
  
  if (tnp->right == NULL) {
  if (ptnp == NULL)
    *rootp = NULL;
    else 
     ptnp->left = NULL;
  } else {
    if (ptnp == NULL)
    *rootp = tnp->right;
  else 
    ptnp->left = tnp->right;
  }
  return tnp;
}

int iterative_delete_extract(tnode **rootp, int val) {
  tnode *tnp = *rootp, *ptnp = NULL, *smallest_node;
  // find the node
  while (tnp != NULL && val != tnp->data) {
    ptnp = tnp;
    tnp = (val < tnp->data) ? tnp->left : tnp->right;
  }
  
  if (tnp == NULL) {  // not found
    printf("Not found");
    return 0;
  }
  else { // found
  
    if (tnp->right == NULL) {
      if (ptnp == NULL) {
        *rootp = tnp->left;
      } 
      else {
        if (ptnp->left == tnp)
          ptnp->left = tnp->left;
        else
          ptnp->right = tnp->left;
      }
    }
    else {
      smallest_node = iterative_extract_smallest_node(&tnp->right);
      if (ptnp == NULL) {
        *rootp = smallest_node;
      }
      else {
        if (ptnp->left == tnp)
      	ptnp->left = smallest_node;
        else
      	ptnp->right = smallest_node;
      }
      smallest_node->left = tnp->left;
      smallest_node->right = tnp->right; 
    }
    free(tnp);  
  
    return 1;
  }  
}

//iterative, time complexity O(height), space complexity O(1)
int iterative_delete(tnode **rootp, int val) {
  tnode *tnp, *parentp, *suc, *psuc, *ptr;
  if (*rootp == NULL) {
    printf("\nThe tree is empty ");
    return 0;
  }
  else 
  {
    //find the node of the given value
    parentp = NULL;
    tnp = *rootp;
    while (tnp != NULL && val != tnp->data) {
      parentp = tnp;
      tnp = (val < tnp->data) ? tnp->left : tnp->right;
    }
    
    // value node not found
    if (tnp == NULL) {
      printf("\nThe value to be deleted is not present in the tree");
      return 0;
    }

    //tnp->data == val, node tnp will be deleted,    
    if (tnp->left == NULL)
      ptr = tnp->right;
    else if (tnp->right == NULL)
      ptr = tnp->left;
    else {
      // find the smallest on right subtree
      psuc = tnp;
      suc = tnp->right;
      while (suc->left != NULL) {
        psuc = suc;
        suc = suc->left;
      }

      if (tnp == psuc) {
        suc->left = tnp->left;
      } else {
        psuc->left = suc->right;
        suc->left = tnp->left;
        suc->right = tnp->right;
      }
      ptr = suc;
    }
    
  // Attach ptr to the parent node
    if (parentp == NULL) 
      *rootp = ptr;
    else if (parentp->left == tnp) 
      parentp->left = ptr;
    else 
      parentp->right = ptr;
    
    free(tnp);
  }
}

void clean_tree(tnode **rootp) {
  tnode *root = *rootp;
  if (root) {
    if (root->left)
      clean_tree(&root->left);
    if (root->right)
      clean_tree(&root->right);
    free(root);
  }
  *rootp = NULL;
}

void print_preorder(tnode *root) {
  if (root) {
    printf("%d ", root->data);
    print_preorder(root->left);
    print_preorder(root->right);
  }
}

void print_inorder(tnode * root) {
  if (root) {
    print_inorder(root->left);
    printf("%d ", root->data);
    print_inorder(root->right);
  }
}

void print_postorder(tnode *root) {
  if (root) {
    print_postorder(root->left);
    print_postorder(root->right);
    printf("%d ", root->data);
  }
}

void print_tree(tnode *root, int prelen) {
  int i;
  if (root) {
    for (i = 0; i < prelen; i++) printf("%c", ' ');
    printf("%s", "|___");
    printf("%d\n", root->data);
    print_tree(root->right, prelen + 4);
    print_tree(root->left, prelen + 4);  
  }
}

/*
Test BST recursive algorithm

|___5
    |___7
        |___9
            |___8
        |___6
    |___2
        |___4
            |___3
        |___1

in-order: 1 2 3 4 5 6 7 8 9
pre-order: 5 2 1 4 3 7 6 9 8
pos-torder: 1 3 4 2 6 8 9 7 5
Found 7 by recursive search
Not found
Smallest element: 1

Largestest element: 9
|___5
    |___7
        |___9
            |___8
        |___6
    |___2
        |___4
            |___3
        |___1

Delete 7
|___5
    |___8
        |___9
        |___6
    |___2
        |___4
            |___3
        |___1
Delete 3
|___5
    |___8
        |___9
        |___6
    |___2
        |___4
        |___1
Delete 5
|___6
    |___8
        |___9
    |___2
        |___4
        |___1

iterative insert algorithm

tree style
|___5
    |___7
        |___9
            |___8
        |___6
    |___2
        |___4
            |___3
        |___1

iterative search algorithm

Found 7 by iterative search
Not found
iterative delete algorithm without extracting
|___5
    |___7
        |___9
            |___8
        |___6
    |___2
        |___4
            |___3
        |___1

Delete 7
|___5
    |___8
        |___9
        |___6
    |___2
        |___4
            |___3
        |___1
Delete 3
|___5
    |___8
        |___9
        |___6
    |___2
        |___4
        |___1
Delete 5
|___6
    |___8
        |___9
    |___2
        |___4
        |___1

iterative extrace and delete algorithm
|___5
    |___7
        |___9
            |___8
        |___6
    |___2
        |___4
            |___3
        |___1
delete 5:
|___6
    |___7
        |___9
            |___8
    |___2
        |___4
            |___3
        |___1
delete 3:
|___6
    |___7
        |___9
            |___8
    |___2
        |___4
        |___1
delete 6:
|___7
    |___9
        |___8
    |___2
        |___4
        |___1
delete 9:
|___7
    |___8
    |___2
        |___4
        |___1
*/

