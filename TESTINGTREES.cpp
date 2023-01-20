#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;	
};

class xyz
{
	node *root;
	node *parent;
	node *cur;
	public:
		xyz()
		{
			root=NULL;
			parent=NULL;
			cur=NULL;
		}	
	
	void create(int data)
	{
		node *temp = new node();//creating new node
		temp->data=data;//inserting user input as data in node
		temp->right=NULL;//making temp right null
		temp->left=NULL;//making temp  left null
		//checking if root is null
		if(root==NULL)
		{
			root=temp;
			parent=temp;
			cout<<" Root Node is added Successfully "<<endl	;
		}
		//if root is not null then add left and right node
		else
		{
			//if data is greater then root data then add node to right
			if(temp->data>parent->data)
			{
				cur=parent;
				parent->right=temp;
				cout<<"right node added"<<endl;
				cur=cur->right;
			}
			//if data is smaller then root data then add node to left
			else if(temp->data<parent->data)
			{
				cur=parent;
				parent->left=temp;
				cout<<"left node added"<<endl;
				cur=cur->left;
			}
			
		}	
	}
	void preorder()//parent left right
	{
		node *ptr = root;
		node *child = root;
		//checking if tree is empty
		if(ptr==NULL)
		{
			cout<<"Tree is Empty"<<endl;
		}
		else
		{
			while(ptr->left !=NULL || ptr->right!=NULL)
			{
				cout<<"parent node  : "<<ptr->data<<endl;
			if(ptr->left!=NULL)
			{
				child=ptr->left;//move child pointer to parent left child
				cout<<"Left child is : "<<child->data<<endl;
				ptr=child;//now parent take the position of child and child can move further right or left
			}
			else if(ptr->right!=NULL)
			{
				child=ptr->right;//move child pointer to parent right child
				cout<<"right child is : "<<child->data<<endl;
				ptr=child;//now parent take the position of child and child can move further right or left
			}
			else
			{
				cout<<"f**king error !!! pc shutdown successfully "<<endl;
			}
			}
		}
		
		
	}
			
};
int main()
{
	int d;
	xyz obj;
	for(int i = 0 ; i < 5 ; i++)
	{
		cout<<"Please enter a node : ";
		cin>>d;
		obj.create(d);
	}
	obj.preorder();
}