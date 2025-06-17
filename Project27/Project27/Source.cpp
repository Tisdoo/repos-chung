#include<iostream>
using namespace std;

typedef struct node
{
	int info;
	struct node* left;
	struct node* right;
}NODE;

typedef NODE* TREE;

void init(TREE& Root)
{
	Root = NULL;
}

void insertNode(TREE& Root, int x)
{
	if (Root == NULL)
	{
		NODE* p = new NODE;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
		Root = p;
	}
	else
	{
		if (Root->info == x)
			return;
		if (Root->info > x)
			insertNode(Root->left, x);
		else
			insertNode(Root->right, x);

	}
}

	int DemNode(TREE Root)
	{
		if (Root == NULL)
			return 0;
		int a = DemNode(Root->left);
		int b = DemNode(Root->right);
		return a + b + 1;
	}

	int TongNode(TREE Root)
	{
		if (Root == NULL)
			return 0;
		int a = TongNode(Root->left);
		int b = TongNode(Root->right);
		return a + b + Root->info;
	}

	void testcase(TREE & Root)
	{
		init(Root);

		insertNode(Root, 10);
		insertNode(Root, 5);
		insertNode(Root, 15);
		insertNode(Root, 3);
		insertNode(Root, 7);
		insertNode(Root, 12);
		insertNode(Root, 18);
		insertNode(Root, 1);
		insertNode(Root, 4);
		insertNode(Root, 6);
		insertNode(Root, 8);

		cout << "So luong nut trong cay: " << DemNode(Root) << endl;
		cout << "Tong gia tri cac nut trong cay: " << TongNode(Root) << endl;
	}int main()
	{
		TREE Root;
		testcase(Root);
		return 0;
	}
