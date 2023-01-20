#include  <iostream>
using namespace std;
struct node
{
	int data;
	node *left;
	node *right;
};
class keepLearning
{
	node *root;
	node *parent;
	node *cur;	
	public :
		keepLearning()
		{
			root=NULL;
			parent=NULL;
		
		}
	
	void create(int data)
	{
		node *temp = new node();
		if(root==NULL)
		{
			root->data=data;
			root->left=NULL;
			root->right=NULL;
			parent=root;
		}
		else
		{
			temp->data=data;
			if(temp->data<root->data)
			{
				parent=temp;
				root->left=temp;
			}
			else
			{
				parent=temp;
				root->right=temp;
			}
		}
	}
	
	//PLR
	void preOrder()
	{
		node *temp=root;
		if(temp!=NULL)
		{
			cout<<parent->data;
			cout<<temp->left->data;
			cout<<temp->right->data;
		}
	}
	//
	void postOrder()
	{
		
	}
	//LPR
	void inOrder()
	{
		
	}
};
int main()
{
	keepLearning obj;
	int x;
	
	for(int i =0 ; i < 4 ; i++)
	{
		cout<<"Please enter data : ";
		cin>>x;
		obj.create(x);
	}
	obj.preOrder();
}