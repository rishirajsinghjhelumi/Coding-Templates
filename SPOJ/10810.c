#include<stdio.h>
#include<stdlib.h>
unsigned long long int sum=0;
struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};
typedef struct tree tree;
int find_tree_height(tree* t)
{
	if(t==NULL)
		return 0;
	int height_left = find_tree_height(t->left);
	int height_right = find_tree_height(t->right);
	if(height_left > height_right)
		return height_left + 1;
	else
		return height_right + 1;
}
tree* insert(tree* ,int );
tree* single_left(tree *);
tree* double_left(tree *);
tree* single_right(tree *);
tree* double_right(tree *);
int main()
{
	int test_cases;
	scanf("%d",&test_cases);
	while(test_cases--)
	{
		int x,i;
		tree *t=NULL,*temp=NULL;
		scanf("%d",&x);
		while(x--)
		{
			scanf("%d",&i);
			t=insert(t,i);
		}
	}
	return 0;
}
tree* insert(tree *t,int x)
{
	if(t == NULL)
	{
		t=(tree*)malloc(sizeof(tree));
		t->data=x;
		t->left=t->right=NULL;
		return t;
	}
	else if(x < t->data)
	{
		t->left=insert(t->left,x);
		if(find_tree_height(t->left)-find_tree_height(t->right)==2)
		{
			if(x < t->left->data)
				t=single_left(t);
			else
				t=double_left(t);
		}
	}
	else if(x > t->data)
	{
		t->right=insert(t->right,x);
		if(find_tree_height(t->right)-find_tree_height(t->left)==2)
		{
			if(x > t->right->data)
				t=single_right(t);
			else
				t=double_right(t);
		}
	}
	return t;
}
tree* single_left(tree *k2)
{
	tree *k1;
	k1=k2->left;
	k2->left=k1->right;
	k1->right=k2;
	return k1;
}
tree* double_left(tree *k3)
{
	k3->left=single_right(k3->left);
	return single_left(k3);
}
tree* single_right(tree *k2)
{
	tree *k1;
	k1=k2->right;
	k2->right=k1->left;
	k1->left=k2;
	return k1;
}
tree* double_right(tree *k3)
{
	k3->right=single_left(k3->right);
	return single_right(k3);
}
