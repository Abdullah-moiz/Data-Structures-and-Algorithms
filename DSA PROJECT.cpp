/*
NOTE:
There are 3 categories:
1. Personal
2. University
3. Family

Each Category is actually a linked list and photo is a node 
Photo may be present in one category or more than one category
Deleting Category means to delete all photos present in that category
Deleting photo function deletes that photo from every category in which that photo inserted by user

POINTERS:
Node** category means category is a pointer to Node pointer like we pass any pointer which is of Node pointer
and we pass the head/start of any category
'&' means the value or anything present on that pointer(location/Address) and we pass &categoryname in main function
to pass firstnode/head/start of category to tell that function that in which category we want to make changes
*/

//***********************************************************************************************

#include <iostream>
using namespace std;

// Node Structure for doubly linked list
class Node{
	// access modifier
	public:
		//declaring variables
		string title;
		string path;
		string date;
		
		// pointers for address
		Node* previous;
		Node* next;
		
		// constructor
		Node(){
			next=NULL;
			previous=NULL;
		}
};

// defining start points of three linked lists with NULL value
Node *personal=NULL, *university=NULL, *family=NULL;

// global variables
string title1, path1, date1;

// bool variable for searching whether photo is present in linked list (category) or not
bool personalCheck=false;
bool universityCheck=false;
bool familyCheck=false;

// inserting photo function with arguments (category name, title name, path name, and date of photo)
void addPhoto(Node** category, string title, string path, string date){
	// creating new node to insert
	Node *node = new Node();
	
	//assigning values given by user to that node
	node->title=title;
	node->path=path;
	node->date=date;
	
	// condition if start of category is NULL then it means that category or linked list is empty
	if(*category==NULL){
		//assign that node to start of node
		*category=node;
	}
	// if category is not empty
	else{
		// creating temporary node to traverse from starting node to last node of that category
		Node *temp = *category;
		// while loop condition: we will not react to the final node
		while(temp->next!=NULL){
			// jump to next node
			temp=temp->next;
		}
		
		// address of present node assign to previous of new node
		node->previous=temp;
		// address of new node assign to next of present node
		temp->next=node;
	}
}

// deleting first node of category
void deleteAtStart(Node** category){
	// creating temporary node which is starting or first node of category
	Node *temp=*category;
	// previous of next node of first node of category assign to NULL
	temp->next->previous=NULL;
	// now next node is assigned to be the starting node of category
	*category=temp->next;
	// delete previous node which is actually starting node before this deletion
	delete(temp);
}

/*
deleteAtStart and deleteHead is same but this function is used when 
there is only one node in category which is head of that node
*/

// deleting first node of category
void deleteHead(Node** category){
	// creating temporary node which is starting or first node of category
	Node *temp=*category;
	// deleting that node, after this category is empty
	delete(temp);
	// now again first node is NULL, category is empty
	*category=NULL;
}

// deleting final/last node of category
void deleteAtEnd(Node** category){
	// creating temporary node to traverse from starting node to last node of that category
	Node *temp=*category;
	// while loop condition: we will not react to the final node
	while(temp->next!=NULL){
		// jump to next node
		temp=temp->next;
	}
	// previous of next node of first node of category assign to NULL
	temp->previous->next=NULL;
	// delete previous node which is actually starting node before this deletion
	delete(temp);
}

/*
Function to search photo, whether that photo asked by user is present in any category or not
This function check photo in each category
This function return 0 or 1 value
if we get 0 then it means that photo is not present
if we get 1 then it means that photo is present
*/
int searchPhoto(string title){
	// creating temporary node which is starting or first node of personal, university and family category
	Node* temp1 = personal;
	Node* temp2 = university;
	Node* temp3 = family;
	
	// check variables
	int check=0,check2=0;
	// if personal category is not empty
	if(personal!=NULL){
		// while loop condition: title of photo asked by user is not matched by any title present in personal category
		while(temp1->title!=title){
			// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
			if(temp1->next==NULL){check=0; break;}
			// if not then jump to next node and assume that photo is present so assign 1 to check variable
			else{temp1=temp1->next; check=1;}
		}
		// if title matched than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		if(temp1->title==title){check2=1; goto returnStatement;}
		// if photo found than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		else if(check==1){check2=1; goto returnStatement;}
		// if not found than assign 0 to check2 variable
		else{check2=0;}
	}
	
	// if university category is not empty
	if(university!=NULL){
		// while loop condition: title of photo asked by user is not matched by any title present in university category
		while(temp2->title!=title){
			// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
			if(temp2->next==NULL){check=0; break;}
			// if not then jump to next node and assume that photo is present so assign 1 to check variable
			else{temp2=temp2->next; check=1;}
		}
		// if title matched than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		if(temp2->title==title){check2=1; goto returnStatement;}
		// if photo found than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		else if(check==1){check2=1; goto returnStatement;}
		// if not found than assign 0 to check2 variable
		else{check2=0;}
	}
	
	// if family category is not empty
	if(family!=NULL){
		// while loop condition: title of photo asked by user is not matched by any title present in university category
		while(temp3->title!=title){
			// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
			if(temp3->next==NULL){check=0; break;}
			// if not then jump to next node and assume that photo is present so assign 1 to check variable
			else{temp3=temp3->next; check=1;}
		}
		// if title matched than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		if(temp3->title==title){check2=1; goto returnStatement;}
		// if photo found than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		else if(check==1){check2=1; goto returnStatement;}
		// if not found than assign 0 to check2 variable
		else{check2=0;}
	}
	
	// goto label
	returnStatement:
		// if photo found return 1
		if(check2==1){return 1;}
		// if not then return 0
		else if(check2==0){return 0;}
}

/*
searchPhoto and searchForDeletingPhoto function is same but
this function is specifically used to search photo in specific category
asked by user
*/

/*
Search function for deleting photo
This function assign true to global variables of categories if photo found
*/
void searchForDeletingPhoto(string title, string category){
	// declaring check variable
	int check=0;
	// if category given by user is personal
	if(category=="personal"){
		// if personal category is not empty
		if(personal!=NULL){
			// creating temporary node for personal category which is actually the first node
			Node* temp = personal;
			// while loop condition: title of photo asked by user is not matched by any title present in university category
			while(temp->title!=title){
				// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
				if(temp->next==NULL){check=0; break;}
				// if not then jump to next node and assume that photo is present so assign 1 to check variable
				else{temp=temp->next; check=1;}
			}
			/* 
			if title matched than assign personalCheck (global variable) to true
			and directly goto returnstatement (goto label) without executing next lines of function
			*/
			if(temp->title==title){personalCheck=true;}
			/*
			if photo found than assign personalCheck (global variable) to true and directly goto 
			returnstatement (goto label) without executing next lines of function
			*/
			else if(check==1){personalCheck=true;}
			// if not found than assign personalCheck (global variable) to false
			else{personalCheck=false;}
		}
	}
	
	// if category given by user is university
	else if(category=="university"){
		// if university category is not empty
		if(university!=NULL){
			// creating temporary node for university category which is actually the first node
			Node* temp = university;
			// while loop condition: title of photo asked by user is not matched by any title present in university category
			while(temp->title!=title){
				// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
				if(temp->next==NULL){check=0; break;}
				// if not then jump to next node and assume that photo is present so assign 1 to check variable
				else{temp=temp->next; check=1;}
			}
			/* 
			if title matched than assign universityCheck (global variable) to true
			and directly goto returnstatement (goto label) without executing next lines of function
			*/
			if(temp->title==title){universityCheck=true;}
			/*
			if photo found than assign universityCheck (global variable) to true and directly goto 
			returnstatement (goto label) without executing next lines of function
			*/
			else if(check==1){universityCheck=true;}
			// if not found than assign personalCheck (global variable) to false
			else{universityCheck=false;}
		}
	}
	
	// if category given by user is family
	else if(category=="family"){
		// if family category is not empty
		if(family!=NULL){
			// creating temporary node for family category which is actually the first node
			Node* temp = family;
			// while loop condition: title of photo asked by user is not matched by any title present in university category
			while(temp->title!=title){
				// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
				if(temp->next==NULL){check=0; break;}
				// if not then jump to next node and assume that photo is present so assign 1 to check variable
				else{temp=temp->next; check=1;}
			}
			/* 
			if title matched than assign familyCheck (global variable) to true
			and directly goto returnstatement (goto label) without executing next lines of function
			*/
			if(temp->title==title){familyCheck=true;}
			/*
			if photo found than assign universityCheck (global variable) to true and directly goto 
			returnstatement (goto label) without executing next lines of function
			*/
			else if(check==1){familyCheck=true;}
			// if not found than assign personalCheck (global variable) to false
			else{familyCheck=false;}
		}
	}
}

// deleting Photo through title of photo
void deletePhoto(string title){
	// calling searchForDeletingPhoto function to first search that photo in specific category
	// if category is personal
	searchForDeletingPhoto(title, "personal");
	// if photo found in personal category
	if(personalCheck==true){
		// creating temporary node for personal category which is actually the first node
		Node *temp1=personal;
		// while loop condition: title of photo asked by user is not matched by any title present in university category
		while(temp1->title!=title){
			// jump to next node
			temp1=temp1->next;
		}
		// If we are on first node (there is only one node in category) and title of node is matched 
		// with title given by user than call deleteHead function and pass personal category
		if(temp1==personal && temp1->next==NULL){deleteHead(&personal);}
		// If photo found on first node then call deleteAtStart function to delete first node
		else if(temp1==personal){deleteAtStart(&personal);}
		// If photo found on last node then call deleteAtEnd function to delete last node
		else if(temp1->next==NULL){deleteAtEnd(&personal);}
		// If photo found in anyother location
		else{
			// assign next of previous node to previous of next node
			temp1->next->previous=temp1->previous->next;
			// assign next of present node on which are standing to next of previous node
			temp1->previous->next=temp1->next;
			// delete present node
			delete(temp1);
		}
		// assign personalCheck back to false
		personalCheck=false;
	}
	
	// if category is university
	searchForDeletingPhoto(title, "university");
	// if photo found in university category
	if(universityCheck==true){
		// creating temporary node for university category which is actually the first node
		Node *temp2=university;
		// while loop condition: title of photo asked by user is not matched by any title present in university category
		while(temp2->title!=title){
			// jump to next node
			temp2=temp2->next;
		}
		// If we are on first node (there is only one node in category) and title of node is matched 
		// with title given by user than call deleteHead function and pass personal category
		if(temp2==university && temp2->next==NULL){deleteHead(&university);}
		// If photo found on first node then call deleteAtStart function to delete first node
		else if(temp2->next==NULL){deleteAtEnd(&university);}
		// If photo found on last node then call deleteAtEnd function to delete last node
		else if(temp2==university){deleteAtStart(&university);}
		// If photo found in anyother location
		else{
			// assign next of previous node to previous of next node
			temp2->next->previous=temp2->previous->next;
			// assign next of present node on which are standing to next of previous node
			temp2->previous->next=temp2->next;
			// delete present node
			delete(temp2);
		}
		// assign universityCheck back to false
		universityCheck=false;
	}
	
	// if category is family
	searchForDeletingPhoto(title, "family");
	// if photo found in family category
	if(familyCheck==true){
		// creating temporary node for family category which is actually the first node
		Node *temp3=family;
		// while loop condition: title of photo asked by user is not matched by any title present in university category
		while(temp3->title!=title){
			// jump to next node
			temp3=temp3->next;
		}
		// If we are on first node (there is only one node in category) and title of node is matched 
		// with title given by user than call deleteHead function and pass personal category
		if(temp3==family && temp3->next==NULL){deleteHead(&family);}
		// If photo found on first node then call deleteAtStart function to delete first node
		else if(temp3->next==NULL){deleteAtEnd(&family);}
		// If photo found on last node then call deleteAtEnd function to delete last node
		else if(temp3==family){deleteAtStart(&family);}
		// If photo found in anyother location
		else{
			// assign next of previous node to previous of next node
			temp3->next->previous=temp3->previous->next;
			// assign next of present node on which are standing to next of previous node
			temp3->previous->next=temp3->next;
			// delete present node
			delete(temp3);
		}
		// assign familyCheck back to false
		familyCheck=false;
	}	
}

// deleting photo from specific category
void deletePhotoFromSpecificCategory(string category, string title){
	// if category is personal
	if(category=="personal"){
		// searching photo in personal category
		searchForDeletingPhoto(title,"personal");
		// photo found in personal category
		if(personalCheck==true){
			// if personal category is not empty
			if(personal!=NULL){
				// creating temporary node for personal category which is actually the first node
				Node *temp1=personal;
				// while loop condition: title of photo asked by user is not matched by any title present in university category
				while(temp1->title!=title){
					// jump to next node
					temp1=temp1->next;
				}
				// If we are on first node (there is only one node in category) and title of node is matched 
				// with title given by user than call deleteHead function and pass personal category
				if(temp1==personal && temp1->next==NULL){deleteHead(&personal);}
				// If photo found on first node then call deleteAtStart function to delete first node
				else if(temp1==personal){deleteAtStart(&personal);}
				// If photo found on last node then call deleteAtEnd function to delete last node
				else if(temp1->next==NULL){deleteAtEnd(&personal);}
				// If photo found in anyother location
				else{
					// assign next of previous node to previous of next node
					temp1->next->previous=temp1->previous->next;
					// assign next of present node on which are standing to next of previous node
					temp1->previous->next=temp1->next;
					// delete present node
					delete(temp1);
				}
			}
			// if category is empty
			else{
				cout<<"Personal Category is Empty!"<<endl;
			}
			// assigning personalCheck back to false
			personalCheck=false;
		}
		// if photo not found in personal category
		else{
			cout<<"Photo not found in Personal Category"<<endl;
		}
	}
	
	// if category is university
	else if (category=="university"){
		// searching photo in university category
		searchForDeletingPhoto(title,"university");
		// photo found in university category
		if(universityCheck==true){
			// if university category is not empty
			if(university!=NULL){
				// creating temporary node for university category which is actually the first node
				Node *temp2=university;
				// while loop condition: title of photo asked by user is not matched by any title present in university category
				while(temp2->title!=title){
					// jump to next node
					temp2=temp2->next;
				}
				// If we are on first node (there is only one node in category) and title of node is matched 
				// with title given by user than call deleteHead function and pass personal category
				if(temp2==university && temp2->next==NULL){deleteHead(&university);}
				// If photo found on first node then call deleteAtStart function to delete first node
				else if(temp2->next==NULL){deleteAtEnd(&university);}
				// If photo found on last node then call deleteAtEnd function to delete last node
				else if(temp2==university){deleteAtStart(&university);}
				// If photo found in anyother location
				else{
					// assign next of previous node to previous of next node
					temp2->next->previous=temp2->previous->next;
					// assign next of present node on which are standing to next of previous node
					temp2->previous->next=temp2->next;
					// delete present node
					delete(temp2);
				}
			}
			// if category is empty
			else{
				cout<<"University Category is Empty!"<<endl;
			}
			// assigning universityCheck back to false
			universityCheck=false;
		}
		// if photo not found in university category
		else{
			cout<<"Photo not found in University Category"<<endl;
		}	
	}
	
	// if category is family
	else if (category=="family"){
		// searching photo in family category
		searchForDeletingPhoto(title,"family");
		// photo found in family category
		if(familyCheck==true){
			// if family category is not empty
			if(family!=NULL){
				// creating temporary node for family category which is actually the first node
				Node *temp3=family;
				// while loop condition: title of photo asked by user is not matched by any title present in university category
				while(temp3->title!=title){
					// jump to next node
					temp3=temp3->next;
				}
				// If we are on first node (there is only one node in category) and title of node is matched 
				// with title given by user than call deleteHead function and pass personal category
				if(temp3==family && temp3->next==NULL){deleteHead(&family);}
				// If photo found on first node then call deleteAtStart function to delete first node
				else if(temp3->next==NULL){deleteAtEnd(&family);}
				// If photo found on last node then call deleteAtEnd function to delete last node
				else if(temp3==family){deleteAtStart(&family);}
				// If photo found in anyother location
				else{
					// assign next of previous node to previous of next node
					temp3->next->previous=temp3->previous->next;
					// assign next of present node on which are standing to next of previous node
					temp3->previous->next=temp3->next;
					// delete present node
					delete(temp3);
				}
			}
			// if category is empty
			else{
				cout<<"Family Category is Empty!"<<endl;
			}
			// assigning familyCheck back to false
			familyCheck=false;
		}
		// if photo not found in family category
		else{
			cout<<"Photo not found in Family Category"<<endl;
		}
	}
}

// deleting category deletes all of photos present in category
void deleteCategory(Node** category){
	// creating temporary node which is starting or first node of category
	Node *temp=*category;
	// if there is only one node in category which is head/start/first node
	if(temp->next==NULL){
		// delete that first node
		delete(temp);
	}
	// if there are more than one nodes
	else{
		// while loop condition: we will not reach to the final node
		while(temp->next!=NULL){
			// assigning pervious of next node to NULL
			temp->next->previous=NULL;
			// jump to next node
			temp=temp->next;
			// deleting previous node
			delete(temp->previous);
		}
		// now we are on last node, else all nodes are deleted so delete that single node
		// now category is empty
		delete(temp);
	}
	// assigning first node of category back to NULL
	*category=NULL;
}

// searching photo to add categories
int searchPhotoForUpdate(string title){
	// creating temporary node which is starting or first node of personal, university and family category
	Node* temp1 = personal;
	Node* temp2 = university;
	Node* temp3 = family;
	
	// check variables
	int check=0,check2=0;
	// if personal category is not empty
	if(personal!=NULL){
		// while loop condition: title of photo asked by user is not matched by any title present in personal category
		while(temp1->title!=title){
			// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
			if(temp1->next==NULL){check=0; break;}
			// if not then jump to next node and assume that photo is present so assign 1 to check variable
			else{temp1=temp1->next; check=1;}
		}
		// if title matched than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		if(temp1->title==title){
			check2=1;
			// assigning node variables values to global variables
			title1=temp1->title;
			path1=temp1->path;
			date1=temp1->date;
			goto returnStatement;
		}
		// if photo found than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		else if(check==1){
			check2=1;
			// assigning node variables values to global variables
			title1=temp1->title;
			path1=temp1->path;
			date1=temp1->date;
			goto returnStatement;
		}
		// if not found than assign 0 to check2 variable
		else{check2=0;}
	}
	
	// if university category is not empty
	if(university!=NULL){
		// while loop condition: title of photo asked by user is not matched by any title present in university category
		while(temp2->title!=title){
			// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
			if(temp2->next==NULL){check=0; break;}
			// if not then jump to next node and assume that photo is present so assign 1 to check variable
			else{temp2=temp2->next; check=1;}
		}
		// if title matched than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		if(temp2->title==title){
			check2=1;
			// assigning node variables values to global variables
			title1=temp2->title;
			path1=temp2->path;
			date1=temp2->date;
			goto returnStatement;
		}
		// if photo found than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		else if(check==1){
			check2=1;
			// assigning node variables values to global variables
			title1=temp2->title;
			path1=temp2->path;
			date1=temp2->date;
			goto returnStatement;
		}
		// if not found than assign 0 to check2 variable
		else{check2=0;}
	}
	
	// if family category is not empty
	if(family!=NULL){
		// while loop condition: title of photo asked by user is not matched by any title present in university category
		while(temp3->title!=title){
			// if we reach to last node then break while loop and assign 0 to check which means that photo is not present
			if(temp3->next==NULL){check=0; break;}
			// if not then jump to next node and assume that photo is present so assign 1 to check variable
			else{temp3=temp3->next; check=1;}
		}
		// if title matched than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		if(temp3->title==title){
			check2=1;
			// assigning node variables values to global variables
			title1=temp3->title;
			path1=temp3->path;
			date1=temp3->date;
			goto returnStatement;
		}
		// if photo found than assign 1 to check2 variable and directly goto returnstatement (goto label) without
		// executing next lines of function
		else if(check==1){
			check2=1;
			// assigning node variables values to global variables
			title1=temp3->title;
			path1=temp3->path;
			date1=temp3->date;
			goto returnStatement;
		}
		// if not found than assign 0 to check2 variable
		else{check2=0;}
	}
	// goto label
	returnStatement:
		// if photo found return 1
		if(check2==1){return 1;}
		// if not then return 0
		else if(check2==0){return 0;}
}

// display function to display all of photos in category
void traverse(Node** category){
	// creating temporary node which is starting or first node of category
	Node *temp = *category;
	// if category is empty
	if(*category==NULL){cout<<"Category is Empty"<<endl;}
	// if not empty
	else{
		// while loop condition: we will not reach to last node
		while(temp!=NULL){
			// printing node variables
			cout<<"\n"<<temp->title<<endl;
			cout<<temp->path<<endl;
			cout<<temp->date<<endl;
			// jump to next node
			temp=temp->next;
		}
	}
	cout<<endl;
}

int main(){
	// declaring variables for options
	int opt1, opt2;
	// declaring variables for getting input from user for category, title, path, date
	string category, title, path, date;
	
	// while loop condition: true
	while(1){
		// displaying options
		cout<<endl;
		cout<<"1. Delete Category"<<endl;
		cout<<"2. Add/Delete Photo"<<endl;
		cout<<"3. Update Categories of Photo"<<endl;
		cout<<"4. Display Categories"<<endl;
		cout<<"Choose any option: ";
		cin>>opt1;
		
		// switch statement for options
		switch(opt1){
			case 1:
				// displaying further options of Delete Category option
				cout<<"\n1. Personal"<<endl;
				cout<<"2. University"<<endl;
				cout<<"3. Family"<<endl;
				cout<<"Choose category to delete: ";
				cin>>opt2;
				if(opt2==1){
					// if personal category is empty
					if(personal==NULL){cout<<"Personal Category is Empty"<<endl;}
					// if not
					else{
						// calling deleteCategory function to delete all photos
						deleteCategory(&personal);
						personal=NULL;
					}
				}
				else if(opt2==2){
					// if university category is empty
					if(university==NULL){cout<<"University Category is Empty"<<endl;}
					// if not
					else{
						// calling deleteCategory function to delete all photos
						deleteCategory(&university);
						university=NULL;
					}
				}
				else if(opt2==3){
					// if family category is empty
					if(family==NULL){cout<<"Family Category is Empty"<<endl;}
					// if not
					else{
						// calling deleteCategory function to delete all photos
						deleteCategory(&family);
						family=NULL;
					}
				}
				else{cout<<"Enter correct option"<<endl;}
				break;
			case 2:
				// displaying further options of Add/Delete option
				cout<<"\n1. Add Photo"<<endl;
				cout<<"2. Delete Photo"<<endl;
				cout<<"Choose any option: ";
				cin>>opt2;
				cout<<endl;
				// Adding Photo
				if(opt2==1){
					cout<<"In which category you want to add photo? ";
					cin.ignore();
					getline(cin, category);
					// if category is among personal, university or family
					if(category=="personal" || category=="university" || category=="family"){
						cout<<"Enter Photo Title: ";
						getline(cin,title);
						cout<<"Enter Photo Path: ";
						getline(cin,path);
						cout<<"Enter Photo Date: ";
						getline(cin,date);
						// conditions based on category
						if(category=="personal"){addPhoto(&personal, title, path, date);}
						else if(category=="university"){addPhoto(&university, title, path, date);}
						else if(category=="family"){addPhoto(&family, title, path, date);}
					}
					// if user doesn't enter right category
					else{
						cout<<"Category Doesn't exists"<<endl;
					}
				}
				// Deleting Photo
				else if(opt2==2){
					cout<<"Enter Title of Photo you want to delete: ";
					cin>>title;
					// value 1 or 0 will store in returnValue variable got by searchPhoto function
					int returnValue = searchPhoto(title);
					// if photo found then delete photo by using deletePhoto function
					if(returnValue==1){deletePhoto(title);}
					// if photo not found
					else if(returnValue==0){cout<<"Photo Not Found in any Category"<<endl;}
				}
				else{cout<<"\nEnter correct option"<<endl;}
				break;
			case 3:
				// further options of Update categories option
				cout<<"\n1. Add Categories to Photo"<<endl;
				cout<<"2. Delete Categories of Photo"<<endl;
				cout<<"Choose any option: ";
				cin>>opt2;
				cout<<endl;
				// Adding Photo in anyother Category
				if(opt2==1){
					cout<<"Enter Title of Photo you want to add on anyother category: ";
					cin.ignore();
					getline(cin,title);
					// value 1 or 0 will store in returnValue variable got by searchPhoto function
					int returnValue=searchPhoto(title);
					// if photo found 
					if(returnValue==1){
						cout<<"Enter category in which you want to add photo: ";
						cin>>category;
						// search photo in that category and get title, path and date of that photo
						searchPhotoForUpdate(title);
						// adding photo based on category
						if(category=="personal"){addPhoto(&personal, title1, path1, date1);}
						else if(category=="university"){addPhoto(&university, title1, path1, date1);}
						else if(category=="family"){addPhoto(&family, title1, path1, date1);}
					}
					// if photo not found
					else if(returnValue==0){cout<<"Photo Not Found in any Category"<<endl;}
				}
				// Delting Photo From Specific Category
				else if(opt2==2){
					cout<<"Enter Title of Photo you want to delete: ";
					cin>>title;
					// value 1 or 0 will store in returnValue variable got by searchPhoto function
					int returnValue = searchPhoto(title);
					// if photo found then delete photo from specific category by using 
					// deletePhotoFromSpecificCategory function
					if(returnValue==1){
						cout<<"Enter category from which you want to delete photo: ";
						cin>>category;
						deletePhotoFromSpecificCategory(category, title);
					}
					// if photo not foung
					else if(returnValue==0){cout<<"Photo Not Found in any Category"<<endl;}
				}
				else{cout<<"\nEnter correct option"<<endl;}
				break;
			case 4:
				// Display option
				cout<<"\nEnter Category Name: ";
				cin>>category;
				// displayin all photos based on user input for category
				if(category=="personal"){traverse(&personal);}
				else if(category=="university"){traverse(&university);}
				else if(category=="family"){traverse(&family);}
				// if category entered is not from given categories
				else{cout<<"Category doesn't exists"<<endl;}
			default:
				break;
		}
	}
}
