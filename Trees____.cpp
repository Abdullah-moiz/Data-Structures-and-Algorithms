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
public:
	tree()
	{
		head = NULL;

	}
	void create(int x){
		if (head == NULL)
		{

			head = new node;
			head->data = x;
			head->left = NULL;
			head->right = NULL;
		}
		else
	{
		//node *parent;
		cur = head;
	
	
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
		}
		else
		{
			parent->right = temp;
		}
	}

	}
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
	tree obj;
	int val, s, opt,n, c = 1;

			cout << "values" << endl;
			for (int i = 0; i <=5; i++)
			{cout<<"enter value :";
				cin >> val;
				obj.create(val);
			}
obj.preorder();
obj.
return 0;
}