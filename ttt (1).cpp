#include<iostream>
#include<conio.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
class tree{
	node *head, *cur, *temp,*parent;
	//head = root node 
	//cur will point child nodes
	//parent will point parent node which may have left or right child
public:
	tree()
	{
		head = NULL;
	}
	//creation of node
	void create(int x){
		
		if (head == NULL)
		{

			head = new node;
			head->data = x;
			head->left = NULL;
			head->right = NULL;
			cout<<"root node is added : "<<endl;
		}
		else
	{
		//pointing cur to root node 
		cur = head;
	
		//this while loop take cur  pointer to leaf node and make that leaf node as parent
		//then new node will be added to left or right as a  child node 
		while (cur != NULL)
		{
			if (cur->data == x)
			{
				cout << "data already exit:";
				return;
			}
			else if (cur->data < x)
			{
				parent = cur;
				cur = cur->right;
			}
			else{
				parent = cur;
				cur = cur->left;
			}
		}
		//inserting new child node 
		temp = new node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		if (parent == NULL)
		{
			parent = temp;

		}
		else if (parent->data > x)
		{
			parent->left = temp;
			cout<<"left  node added "<<endl;
		}
		else
		{
			parent->right = temp;
			cout<<"right node added "<<endl;
		}
	}

	}
	
	//recursive function to print all type of tree display
	void preorder()
	{
		preord(head);
	}

	void preord(node *s)
	{
		
		if (s != NULL)
		{
			cout << s->data << endl;
			preord(s->left);
			preord(s->right);
		}

	}
	void inorder()
	{
		inord(head);
	}
	void inord(node *s)
	{
		if (s != NULL)
		{
			inord(s->left);
			cout << s->data << endl;
			inord(s->right);
		}
	}
	void postorder()
	{
		post(head);
	}
	void post(node *s)
	{
		if (s != NULL)
		{
			post(s->left);
			post(s->right);
			cout << s->data << endl;
			
		}
	}

};
int main()
{
	tree obj;//object of class tree
	int val;//to take user input

			for (int i = 0; i < 5; i++)
			{
				cout<<"enter value : ";
				cin >> val;
				obj.create(val);
			}
cout<<"\n Pre-Order \n";
obj.preorder();
cout<<"\n In-Order \n";
obj.inorder();
cout<<"\n Post-Order \n";
obj.postorder();

}
