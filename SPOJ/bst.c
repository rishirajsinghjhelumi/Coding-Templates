#include<stdio.h>
#include<stdlib.h>
struct tree
{
	int data;
	int count;
	struct tree* left;
	struct tree* right;
};
struct queue
{
	int value;
	struct queue* next;
};
typedef struct tree tree;
typedef struct queue queue;
tree* insert(tree* ,int );
tree* print_inorder(tree* );
tree* print_preorder(tree* );
tree* print_postorder(tree* );
tree* print_levelorder(tree* ,int );
tree* print_levelorder1(tree*  );
queue* insert_queue(queue* ,int );
queue* delete_queue(queue* );
queue* print_queue(queue* );
int find_num_nodes(tree* );
int find_tree_height(tree* );
int find(tree* , int);
int find_max(tree*);
int find_min(tree*);
tree** createQueue(int *, int *);
void enQueue(tree **, int *, tree *);
tree *deQueue(tree **, int *);
void printLevelOrder(tree* root);
int main()
{
	int x,i;
	tree *t=NULL,*temp=NULL;
	printf("Insert Element ( -1 to Stop !! ) :-> ");
	scanf("%d",&x);
	while(x!=-1)
	{
		t=insert(t,x);
		printf("Insert Element ( -1 to Stop !! ) :-> ");
		scanf("%d",&x);
	}
	printf("Number of nodes in Tree :-> %d\n",find_num_nodes(t));
	printf("Height of the tree is :-> %d\n",find_tree_height(t));
	printf("Inorder Tree Traversal:-> \n");
	print_inorder(t);
	printf("Preorder Tree Traversal:-> \n");
	print_preorder(t);
	printf("Postorder Tree Traveral:-> \n");
	print_postorder(t);
	printf("Levelorder Tree Traversal :-> \n");
	for(i=1;i<=find_tree_height(t);i++)
	{
		print_levelorder(t,i);
		printf("\n");
	}
	printf("\nLevelorder 2 :-> \n");
	printLevelOrder(t);
	//printf("Level Order 3 :-> \n");
	//print_levelorder1(t);
	printf("Enter element to find ( -1 to Stop !! ):-> ",x);
	scanf("%d",&x);
	while(x != -1)
	{
		printf("Found = %d \n",find(t,x));
		printf("Enter element to find ( -1 to Stop !! ):-> ",x);
		scanf("%d",&x);		
	}
	printf("Max Element of The Tree :-> %d\n",find_max(t));
	printf("Mix Element of The Tree :-> %d\n",find_min(t));
	return 0;
}
tree* insert(tree *p,int x)
{
	if(p == NULL)
	{
		p=(tree*)malloc(sizeof(tree));
		p->data=x;
		p->count=1;
		p->left=p->right=NULL;
		return p;
	}
	else
	{
		tree *old = p;
		while(1)
		{
			if(p->data == x)
			{
				p->count = p->count + 1;
				break;
			}
			else if(p->data > x)
			{
				if(p->left == NULL)
				{
					p->left=insert(p->left,x);
					break;
				}
				else
					p=p->left;
			}
			else
			{
				if(p->right == NULL )
				{
					p->right=insert(p->right,x);
					break;
				}
				else
					p=p->right;
			}
		}
		return old;
	}
}
tree* print_inorder(tree* p)
{
	if(p!=NULL)
	{
		if(p->left)
			print_inorder(p->left);
		printf("%d , c = %d\n",p->data,p->count);
		if(p->right)
			print_inorder(p->right);
	}
}
tree* print_preorder(tree* p)
{
	if(p!=NULL)
	{
		printf("%d\n",p->data);
		if(p->left)
			print_preorder(p->left);
		if(p->right)
			print_preorder(p->right);
	}
}
tree* print_postorder(tree* p)
{
	if(p!=NULL)
	{
		if(p->left)
			print_postorder(p->left);
		if(p->right)
			print_postorder(p->right);
		printf("%d\n",p->data);
	}
}
tree* print_levelorder(tree* t ,int height)
{
	if(t==NULL)
		return;
	if(height==1)
		printf("%d ",t->data);
	else if (height > 1)
	{
		print_levelorder(t->left,height-1);
		print_levelorder(t->right,height-1);
	}
}
int find(tree* p , int x)
{
	if(p == NULL )
		return 0;
	if(p->data == x )
		return 1;
	else if (p->data < x)
		find(p->right , x);
	else
		find(p->left , x);

}
int find_max(tree* t)
{
	while(t->right!=NULL)
		t = t->right;
	return t->data;
}
int find_min(tree* t)
{
	while(t->left!=NULL)
		t = t->left;
	return t->data;
}
int find_num_nodes(tree* t)
{
	if(t==NULL)
		return 0;
	else
		return (1 + find_num_nodes(t->left) + find_num_nodes(t->right));
}
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
void printLevelOrder(tree* root)
{
	int rear, front;
	tree **queue = createQueue(&front, &rear);
	tree *temp_tree = root;
	while(temp_tree)
	{
		printf("%d ", temp_tree->data);
		if(temp_tree->left)
			enQueue(queue, &rear, temp_tree->left);
		if(temp_tree->right)
			enQueue(queue, &rear, temp_tree->right);
		temp_tree = deQueue(queue, &front);
	}
	printf("\n");
}
tree** createQueue(int *front, int *rear)
{
	tree **queue =(tree **)malloc(sizeof(tree*)*1000);  
	*front = *rear = 0;
	return queue;
} 
void enQueue(tree **queue, int *rear, tree *new_tree)
{
	queue[*rear] = new_tree;
	(*rear)++;
}     
tree *deQueue(tree **queue, int *front)
{
	(*front)++;
	return queue[*front - 1];
}     
/*tree* print_levelorder1(tree* p)
{
	queue *q=NULL;
	q=insert_queue(q,p->data);
	tree *tt=p;
	while(tt!=NULL)
	{
		printf("%d ",tt->data);
		if(tt->left!=NULL)
			q=insert_queue(q,tt->left->data);
		if(tt->right!=NULL)
			q=insert_queue(q,tt->right->data);
		tt=delete_queue(q);
	}
}
queue* insert_queue(queue *head,int x)
{	
	queue *old=head;
	queue *temp = (queue *)malloc(sizeof(queue));
	temp->value = x;
	temp->next = NULL;
	if(head==NULL)
		return temp;
	else
	{
		while(head->next!=NULL)
			head=head->next;
		head->next=temp;
	}
	return old;
}
queue* delete_queue(queue *head)
{
	queue *old=head;
	while(head->next!=NULL)
		head=head->next;
	head=NULL;
	//return old;
}
queue* print_queue(queue *head)
{
	while(head != NULL )
	{
		printf("%d ",head->value);
		head = head -> next;
	}
	printf("\n");
}*/
