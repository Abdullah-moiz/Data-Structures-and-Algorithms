#include<iostream>
#include<conio.h>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;

};
class tree{
	node *root, *cur, *temp,*parent;
public:
	tree()
	{
		root = NULL;

	}
	void create(int x) // x take user input 
	{
		// if tree is empty
		if (root == NULL)
		{
			//creating a new node 
			root = new node;
			root->data = x;
			root->left = NULL;
			root->right = NULL;
			cout<<"root node added"<<endl;
		}
		else
		{
		//moving cur to root then move cur according to condition to insert new node on the 
		//left or right
		cur = root;	
		
		//keep iterating until cur is not NULL
		while (cur != NULL)
		{
			//check if data exists alredy or not 
			if (cur->data == x)
			{
				cout << "data already exit:"<<endl;
				return;
			}
			// matching cur data with user new input and moving cur to the leaf node 
			//here we are just finding the leaf node to insert the data in left or right
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
		//now we reach where we can insert node on right or left
		
		//creating a new node
		temp = new node;
		temp->data = x;
		temp->left = NULL;
		temp->right = NULL;
		if (parent == NULL)
		{
			parent = temp;
		}
		// check if parent data is greater then x then add new node to left
		else if (parent->data > x)
		{
			parent->left = temp;
			cout<<"left node added"<<endl;
		}
		//else add to right
		else
		{
			parent->right = temp;
			cout<<"right node added"<<endl;
		}
	}

	}
	void preorder()
	{	
		node *s = root;
		if (s != NULL)
		{
			cout << s->data << endl;
			preord(s->left);
			preord(s->right);
		}
	}
	void inorder()
	{
		node *s = root;
				if (s != NULL)
		{
			inord(s->left);
			cout << s->data << endl;
			inord(s->right);
		}
	}

	
	void postorder()
	{
	node *s = root;
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
	tree obj;
	int val;

			for (int i = 0; i < 5; i++)
			{
				cout<<"enter value : ";
				cin >> val;
				//cout<< i;
				obj.create(val);
			}
cout<<"\n Pre-Order \n";
obj.preorder();
cout<<"\n In-Order \n";
obj.inorder();
cout<<"\n Post-Order \n";
obj.postorder();

}
