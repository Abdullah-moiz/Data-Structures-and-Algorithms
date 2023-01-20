
																					//ABDULLAH MOIZ FA20-BSE-078
																					//AWAAB KHAN FA20-BSE_092



// dividing categories into classes to create three different linkedlist
//in main method calling all classes using classes objects



#include <iostream>

using namespace std;

//creating node

struct node {
  node * next;
  node * prev;
  string title;
  string file;
  string date;
};

//Family class
class familyPics {
  //pointers
  node * head;
  node * cur;
  //constructor
  public:
    familyPics() {
      head = NULL;
      cur = NULL;
    }

  //Creation of node 
  void create(string userDate, string userTitle, string userFile) {
    node * temp = new node(); //creating node 
    temp -> next = NULL; //setting node next to null
    temp -> prev = NULL; //setting node prev to null
    temp -> date = userDate; // add user inpty  in date 
    temp -> file = userFile;//adding user file path
    temp -> title = userTitle; //adding user title
    //IF node is empty 
    if (head == NULL) {
      head = temp;
      cur = temp;
    }
	 else  //if any node exists
	{ 
      cur -> next = temp;
      temp -> prev = cur;
      cur = cur -> next;
    }

  }

  //update nodes
  //this only work for those node who aren't first and last 
  void update(string loc, string data, string data2, string data3) {

    cout << "kindly type title of pic you want to update : ";
    cin >> loc; //loc variable take user input to find nodes
    cur = head;
	
	//search data by title name 
    while (cur -> next != NULL && cur -> title != loc) {
      cur = cur -> next;
    }
    if (cur -> title == loc) {

      cout << "NEW TITLE : ";
      cin >> data; //this data take user input and store as title
      cout << "NEW DATE : ";
      cin >> data2; // this data2 take input and store as Date
      cout << "NEW PATH : ";
      cin >> data3;  //this data3 take input and store as path

		//storing  all inputs into node
      cur -> date = data;
      cur -> file = data2;
      cur -> title = data3;
      cout << "\n\t\tUpdated Successfully\t\t\n \n";
      //displaying data that is updated successfully
      cout << "Pic date is " << cur -> date << endl;
      cout << "Pic Name is " << cur -> title << endl;
      cout << "Pic File is " << cur -> file << endl;
    } else {
      cout << "\n\n\t\t*************** ALERT no Data found ************\n\n\t\t";
    }
  }

  //deletion of nodes
  //titlename is used to search node to be deleted
  //delete from middle using title name
  //this method only runs if you have one node before and one node after so once center node delete  rest two linked up
  void deleted(string titlename) {
    cout << "ALERT : THIS OPTION UNABLE TO DELETE FIRST AND LAST PICTURE \n IF You Want to delete First and last picture kindly select option x and y " << endl;
    cout << "Enter File TITLE , You want to delete : ";
    cin >> titlename;
    node * temp = head;
    while (temp -> title != titlename && temp -> next != NULL) {
      temp = temp -> next;
    }
    if (temp -> title == titlename) {
      temp -> prev -> next = temp -> next;
      temp -> next -> prev = temp -> prev;
      temp -> next = NULL;
      temp -> prev = NULL;
      cout << "PIC WITH TITLE NAME : " << temp -> title << " has been deleted successfully ";
      delete temp;
    } else {
      cout << "\n\n\t\t*************** ALERT no Data found ************\n\n\t\t";
    }
  }
  //delete the first node
  void deleteFirst() {
  	 node * temp = head;
  	 if(temp==NULL)
  	 {
  		cout<<"Category is already empty " 	<<endl;
	 }
	else
	{
    cout << "\n***********************\n";
    cout << "ALERT THIS METHOD ONLY DELETE YOUR FIRST PIC " << endl;
    cout << "\n***********************\n";
   
    head = temp -> next;
    temp -> next -> prev = NULL;
    temp -> next = NULL;
    cout << "\n***********************\n";
    cout << "Pic with TITLE NAME : " << temp -> title << " Is going to be deleted ";
    cout << "\n***********************\n";
    delete temp;
	}
  }
  //delete the last node
  void deleteLast() {
  	   node * temp = head;
  	if(temp==NULL)
  	 {
  		cout<<"Category is already empty " 	<<endl;
	 }
	 else
	{
    cout << "\n***********************\n";
    cout << "ALERT THIS METHOD ONLY DELETE YOUR LAST PIC " << endl;
    cout << "\n***********************\n";
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    cout << "\n***********************\n";
    cout << "Pic with TITLE NAME : " << temp -> title << " Is going to be deleted ";
    cout << "\n***********************\n";
    temp -> prev -> next = NULL;
    temp -> prev = NULL;
    delete temp;
	}
  }

  //searching the node 
  void search(string title) {
    node * temp = head;
    if(temp==NULL)
    {
    	cout<<"Family Category is empty "<<endl;
	}
	else
	{
    while (temp -> next != NULL && temp -> title != title) {
      temp = temp -> next;
    }
    if (temp -> title == title) {
      cout << "\n\n\t\tResult found in Family Photos" << endl;
      cout << "\n***********************\n";
      cout << "Pic date is " << temp -> date << endl;
      cout << "Pic Name is " << temp -> title << endl;
      cout << "Pic File is " << temp -> file << endl;
      cout << "\n***********************\n";

    } else {
      cout << "\n\n\t\tResult NOT found in Family Photos" << endl;
    }
}
  }

  //printing  results 
  void display() {
    node * temp = head;
    if (temp == NULL) {
      cout << "Category is empty  " << endl;
    } else {

      while (temp != NULL) {
        cout << "\n***********************\n";
        cout << "Pic date is " << temp -> date << endl;
        cout << "Pic Name is " << temp -> title << endl;
        cout << "Pic File is " << temp -> file << endl;
        cout << "\n***********************\n";
        temp = temp -> next;
      }
    }
  }

};

//friend pictures

class friendPics {
  node * head;
  node * cur;
  public:
    friendPics() {
      head = NULL;
      cur = NULL;
    }

  //Creation of node 
  void create(string userDate, string userTitle, string userFile) {
    node * temp = new node();
    temp -> next = NULL;
    temp -> prev = NULL;
    temp -> date = userDate;
    temp -> file = userFile;
    temp -> title = userTitle;

    if (head == NULL) {
      head = temp;
      cur = temp;
    } else {
      cur -> next = temp;
      temp -> prev = cur;
      cur = cur -> next;
    }

  }
  //update nodes
  void update(string loc, string data, string data2, string data3) {

    cout << "kindly type title of pic you want to update : ";
    cin >> loc;
    node * temp = new node();
    cur = head;

    while (cur -> next != NULL && cur -> title != loc) {
      cur = cur -> next;
    }
    if (cur -> title == loc) {

      cout << "NEW TITLE : ";
      cin >> data;
      cout << "NEW DATE : ";
      cin >> data2;
      cout << "NEW PATH : ";
      cin >> data3;

      cur -> date = data;
      cur -> file = data2;
      cur -> title = data3;
      cout << "\n\t\tUpdated Successfully\t\t\n \n";
      cout << "Pic date is " << cur -> date << endl;
      cout << "Pic Name is " << cur -> title << endl;
      cout << "Pic File is " << cur -> file << endl;
    } else {
      cout << "\n\n\t\t*************** ALERT no Data found ************\n\n\t\t";
    }
  }

  //deletion of nodes
  void deleted(string titlename) {
    cout << "ALERT : THIS OPTION UNABLE TO DELETE FIRST AND LAST PICTURE \n IF You Want to delete First and last picture kindly select option x and y " << endl;
    cout << "Enter File TITLE , You want to delete : ";
    cin >> titlename;
    node * temp = head;
    while (temp -> title != titlename && temp -> next != NULL) {
      temp = temp -> next;
    }
    if (temp -> title == titlename) {
      temp -> prev -> next = temp -> next;
      temp -> next -> prev = temp -> prev;
      temp -> next = NULL;
      temp -> prev = NULL;
      cout << "PIC WITH TITLE NAME : " << temp -> title << " has been deleted successfully ";
      delete temp;
    } else {
      cout << "\n\n\t\t*************** ALERT no Data found ************\n\n\t\t";
    }
  }
  //delete first node
  void deleteFirst() {
    cout << "\n***********************\n";
    cout << "ALERT THIS METHOD ONLY DELETE YOUR FIRST PIC " << endl;
    cout << "\n***********************\n";
    node * temp = head;
    head = temp -> next;
    temp -> next -> prev = NULL;
    temp -> next = NULL;
    cout << "\n***********************\n";
    cout << "Pic with TITLE NAME : " << temp -> title << " Is going to be deleted ";
    cout << "\n***********************\n";
    delete temp;

  }
  //delete last node
  void deleteLast() {
    cout << "\n***********************\n";
    cout << "ALERT THIS METHOD ONLY DELETE YOUR LAST PIC " << endl;
    cout << "\n***********************\n";
    node * temp = head;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    cout << "\n***********************\n";
    cout << "Pic with TITLE NAME : " << temp -> title << " Is going to be deleted ";
    cout << "\n***********************\n";
    temp -> prev -> next = NULL;
    temp -> prev = NULL;
    delete temp;

  }
  //search node 
  void search(string title) {
    node * temp = head;
    if(temp==NULL)
    {
    	cout<<"Friend category is empty "<<endl;
	}
	else
	{
    while (temp -> next != NULL && temp -> title != title) {
      temp = temp -> next;
    }
    if (temp -> title == title) {
      cout << "\n\n\t\tResult found in Friend Photos" << endl;
      cout << "\n***********************\n";
      cout << "Pic date is " << temp -> date << endl;
      cout << "Pic Name is " << temp -> title << endl;
      cout << "Pic File is " << temp -> file << endl;
      cout << "\n***********************\n";

    } else {
      cout << "\n\n\t\tResult NOT found in Friend Photos" << endl;
    }
}
  }

  //printing  results 
  void display() {
    node * temp = head;
    if (temp == NULL) {
      cout << "Category is empty  " << endl;
    } else {

      while (temp != NULL) {
        cout << "\n***********************\n";
        cout << "Pic date is " << temp -> date << endl;
        cout << "Pic Name is " << temp -> title << endl;
        cout << "Pic File is " << temp -> file << endl;
        cout << "\n***********************\n";
        temp = temp -> next;
      }
    }
  }

};

//tour pictures

class tourPics {
  node * head;
  node * cur;
  public:
    tourPics() {
      head = NULL;
      cur = NULL;
    }

  //Creation of node 
  void create(string userDate, string userTitle, string userFile) {
    node * temp = new node();
    temp -> next = NULL;
    temp -> prev = NULL;
    temp -> date = userDate;
    temp -> file = userFile;
    temp -> title = userTitle;

    if (head == NULL) {
      head = temp;
      cur = temp;
    } else {
      cur -> next = temp;
      temp -> prev = cur;
      cur = cur -> next;
    }

  }
  //update nodes
  void update(string loc, string data, string data2, string data3) {

    cout << "kindly type title of pic you want to update : ";
    cin >> loc;
    node * temp = new node();
    cur = head;

    while (cur -> next != NULL && cur -> title != loc) {
      cur = cur -> next;
    }
    if (cur -> title == loc) {

      cout << "NEW TITLE : ";
      cin >> data;
      cout << "NEW DATE : ";
      cin >> data2;
      cout << "NEW PATH : ";
      cin >> data3;

      cur -> date = data;
      cur -> file = data2;
      cur -> title = data3;
      cout << "\n\t\tUpdated Successfully\t\t\n \n";
      cout << "Pic date is " << cur -> date << endl;
      cout << "Pic Name is " << cur -> title << endl;
      cout << "Pic File is " << cur -> file << endl;
    } else {
      cout << "\n\n\t\t*************** ALERT no Data found ************\n\n\t\t";
    }
  }

  //deletion of nodes
  void deleted(string titlename) {
    cout << "ALERT : THIS OPTION UNABLE TO DELETE FIRST AND LAST PICTURE \n IF You Want to delete First and last picture kindly select option x and y " << endl;
    cout << "Enter File TITLE , You want to delete : ";
    cin >> titlename;
    node * temp = head;
    while (temp -> title != titlename && temp -> next != NULL) {
      temp = temp -> next;
    }
    if (temp -> title == titlename) {
      temp -> prev -> next = temp -> next;
      temp -> next -> prev = temp -> prev;
      temp -> next = NULL;
      temp -> prev = NULL;
      cout << "PIC WITH TITLE NAME : " << temp -> title << " has been deleted successfully ";
      delete temp;
    } else {
      cout << "\n\n\t\t*************** ALERT no Data found ************\n\n\t\t";
    }
  }
  //delete first node
  void deleteFirst() {
    cout << "\n***********************\n";
    cout << "ALERT THIS METHOD ONLY DELETE YOUR FIRST PIC " << endl;
    cout << "\n***********************\n";
    node * temp = head;
    head = temp -> next;
    temp -> next -> prev = NULL;
    temp -> next = NULL;
    cout << "\n***********************\n";
    cout << "Pic with TITLE NAME : " << temp -> title << " Is going to be deleted ";
    cout << "\n***********************\n";
    delete temp;

  }
  //delete last node
  void deleteLast() {
    cout << "\n***********************\n";
    cout << "ALERT THIS METHOD ONLY DELETE YOUR LAST PIC " << endl;
    cout << "\n***********************\n";
    node * temp = head;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    cout << "\n***********************\n";
    cout << "Pic with TITLE NAME : " << temp -> title << " Is going to be deleted ";
    cout << "\n***********************\n";
    temp -> prev -> next = NULL;
    temp -> prev = NULL;
    delete temp;

  }

  //search node
  void search(string title) {
    node * temp = head;
    if(temp==NULL)
    {
    	cout<<"Tour Category Is empty "<<endl;
	}
	else
	{
    while (temp -> next != NULL && temp -> title != title) {
      temp = temp -> next;
    }
    if (temp -> title == title) {
      cout << "\n\n\t\tResult found in Tour Photos" << endl;
      cout << "\n***********************\n";
      cout << "Pic date is " << temp -> date << endl;
      cout << "Pic Name is " << temp -> title << endl;
      cout << "Pic File is " << temp -> file << endl;
      cout << "\n***********************\n";

    } else {
      cout << "\n\n\t\tResult NOT found in Tour Photos" << endl;
    }
}
  }
  //printing  results 
  void display() {
    node * temp = head;
    if (temp == NULL) {
      cout << "Category is empty  " << endl;
    } else {

      while (temp != NULL) {
        cout << "\n***********************\n";
        cout << "Pic date is " << temp -> date << endl;
        cout << "Pic Name is " << temp -> title << endl;
        cout << "Pic File is " << temp -> file << endl;
        cout << "\n***********************\n";
        temp = temp -> next;
      }
    }
  }

};

//Main class
int main() {
  familyPics obj; //object of class familyPics
  tourPics obj1; //oject of class tourPics
  friendPics obj2; //object of class friendPics

  string file_del; //to delete picture 

  string f_name, f_date, f_title, f_path; //to update pic data

  string pic_date, pic_name, pic_path; // var of creating nodes

  string searchit;

  //y is used for first main options
  //x is used as input for switch	
  int x, y;

  char ok; //ok is used for yes or no to keep do while loop oin control

  int howmuch; //how much pic want to add;
  do {
    cout << "\n";
    cout << "Please choose an category" << endl;
    cout << "1 : Family photos" << endl;
    cout << "2 : Friends Photos" << endl;
    cout << "3 : Tour Photos" << endl;
    cout << "4 : Search Photos" << endl;
    cout << "5 : Show All Photos" << endl;
    cin >> y;
    cout << "\n";

    //first switch to select option
    switch (y) {
    case 1:
      cout << "\n";
      cout << " 1 : ADD family picture" << endl;
      cout << " 2 : display family pics" << endl;
      cout << " 3 : Delete family pics by Title name" << endl;
      cout << " 4 : delete first pics of family" << endl;
      cout << " 5 : delete last pics of family" << endl;
      cout << " 6 : update picture of family" << endl;
      cin >> x;
      cout << "\n";
      break;
    case 2:
      cout << "\n";
      cout << " 7 : ADD Friends picture" << endl;
      cout << " 8 : display Friends pics" << endl;
      cout << " 9 : Delete Friends pics by Title name" << endl;
      cout << " 10 : delete first pics of Friends" << endl;
      cout << " 11 : delete last pics of Friends" << endl;
      cout << " 12 : update picture of Friends" << endl;
      cin >> x;
      cout << "\n";
      break;
    case 3:
      cout << "\n";
      cout << " 13 : ADD Tour picture" << endl;
      cout << " 14 : display Tour pics" << endl;
      cout << " 15 : Delete Tour pics by Title name" << endl;
      cout << " 16 : delete first pics of Tour" << endl;
      cout << " 17 : delete last pics of Tour" << endl;
      cout << " 18 : update picture of Tour" << endl;
      cin >> x;
      cout << "\n";
      break;
    case 4:
      cout << "\n";
      cout << "19 : Search Photos (type 19  ) :  ";
      cin >> x;
      cout << "\n";
      break;
    case 5:
      cout << "\n";
      cout << "20 : Display Photos (type 20 ) :  ";
      cin >> x;
      cout << "\n";
      break;
    default:
      cout << "catogaries doesn't exist " << endl;
    }

    //    second switch to call methods

    switch (x) {
    case 1:
      cout << "How many Pictures You want to ADD  : " << endl;
      cin >> howmuch;
      for (int i = 0; i < howmuch; i++) {
        cout << "\n****************************\n";
        cout << "ADD FAMILY PICTURES : " << endl;
        cout << "\n****************************\n";
        cout << "enter DATE  ";
        cin >> pic_date;
        cout << "enter file TITLE  ";
        cin >> pic_name;
        cout << "enter file PATH  ";
        cin >> pic_path;
        obj.create(pic_date, pic_name, pic_path);
      }
      break;
    case 2:
      obj.display();
      break;
    case 3:
      obj.deleted(file_del);
      break;
    case 4:
      obj.deleteFirst();
      break;
    case 5:
      obj.deleteLast();
      break;
    case 6:
      obj.display();
      cout << "\n****************************\n";
      cout << "PIC TITLE NAME FROM ABOVE RESULT  : \nThis method allow you update all field \nif you dont want to update all field fill same data ";
      cout << "\n****************************\n";
      obj.update(f_name, f_title, f_date, f_path);
      break;
    case 7:
      cout << "How many Pictures You want to ADD  : " << endl;
      cin >> howmuch;
      for (int i = 0; i < howmuch; i++) {
        cout << "\n****************************\n";
        cout << "ADD Friends PICTURES : " << endl;
        cout << "\n****************************\n";
        cout << "enter DATE  ";
        cin >> pic_date;
        cout << "enter file TITLE  ";
        cin >> pic_name;
        cout << "enter file PATH  ";
        cin >> pic_path;
        obj2.create(pic_date, pic_name, pic_path);
      }
      break;
    case 8:
      obj2.display();
      break;
    case 9:
      obj2.deleted(file_del);
      break;
    case 10:
      obj2.deleteFirst();
      break;
    case 11:
      obj2.deleteLast();
      break;
    case 12:
      obj.display();
      cout << "\n****************************\n";
      cout << "PIC TITLE NAME FROM ABOVE RESULT  : \nThis method allow you update all field \nif you dont want to update all field fill same data ";
      cout << "\n****************************\n";
      obj2.update(f_name, f_title, f_date, f_path);
      break;
    case 13:
      cout << "How many Pictures You want to ADD  : " << endl;
      cin >> howmuch;
      for (int i = 0; i < howmuch; i++) {
        cout << "\n****************************\n";
        cout << "ADD Tour PICTURES : " << endl;
        cout << "\n****************************\n";
        cout << "enter DATE  ";
        cin >> pic_date;
        cout << "enter file TITLE  ";
        cin >> pic_name;
        cout << "enter file PATH  ";
        cin >> pic_path;
        obj1.create(pic_date, pic_name, pic_path);
      }
      break;
    case 14:
      obj1.display();
      break;
    case 15:
      obj1.deleted(file_del);
      break;
    case 16:
      obj1.deleteFirst();
      break;
    case 17:
      obj1.deleteLast();
      break;
    case 18:
      obj2.display();
      cout << "\n****************************\n";
      cout << "PIC TITLE NAME FROM ABOVE RESULT  : \nThis method allow you update all field \nif you dont want to update all field fill same data ";
      cout << "\n****************************\n";
      obj1.update(f_name, f_title, f_date, f_path);
      break;
    case 19:
      cout << "Kindly Input Pic Title you want to search : ";
      cin >> searchit;
      obj.search(searchit);
      obj2.search(searchit);
      obj1.search(searchit);
      break;
    case 20:
      obj.display();
      obj1.display();
      obj2.display();
      break;
    default:
      cout << "invalid  entry ";
      break;
    }
    cout << "You want you exit ? (y/n)";
    cin >> ok;

  } while (ok != 'y' && ok != 'Y');
}



