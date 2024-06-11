typedef int K;

typedef struct tree_node {
	K key;
	struct tree_node* left;
	struct tree_node* right;
} TreeNode;

typedef struct {
	TreeNode* root;
} BST;

// API
BST* bst_create(void);
void bst_destroy(BST* tree);

void bst_insert(BST* tree, K key);
TreeNode* bst_search(BST* tree, K key);
void bst_delete(BST* tree, K key);

// ������ȱ���
void bst_preorder(BST* tree);
void bst_inorder(BST* tree);
void bst_postorder(BST* tree);
// ������ȱ���
void bst_levelorder(BST* tree);
void bst_levelorder2(BST* tree);

int maxDepth(struct TreeNode* root);