#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

// Deatils of car
class car
{
     public:

      int No_of_car=0;
     string Name;
     int seater;
     int rent;
     car *right;
     car *left;
     car(int seats ,int price,int No,string nam)
     {
         No_of_car=No;
         string lic_no[No_of_car];
         right=NULL;
         left= NULL;
         seater=seats;
         rent=price;
         Name=nam;
     }
};
// Details of user
class user
{
   public:

    string username;
    string password;
    user *left;
    user* right;
                                      //done all set
    user(string x,string y)

    {
        left=NULL;
        right=NULL;
        username=x;
        password=y;
    }

};
class car_rented
{
public:

    string username;
    string Name;
    int rent;
    int no_of_days;
    int no_of_car;
    car_rented *next;
  car_rented(string a,string b,int r,int m, int no)
    {
        username = a;
        Name = b;
        rent = r;
         no_of_days=m;
         no_of_car=no;
        next=NULL;
    }
};

class Queue
 {
     public:
    car_rented *front, *rear;
     int revenue =0;
    Queue()
    {
         front = rear = NULL;
    }
     void add_revenue(int rent_of_car,int no_of_days ,int no_of_car)
    {
      revenue=(rent_of_car*no_of_days*no_of_car)+revenue;

  }
void print_revenue()
{
    cout<<endl<<endl<<"\t\t\t Total Revenue = "<<revenue<<endl;

}
    void enQueue(string user_name,string car_name,int rent_of_car,int no_of_days,int no_of_car)
    {

        car_rented * temp = new car_rented(user_name,car_name,rent_of_car,no_of_days,no_of_car);
         add_revenue(rent_of_car,no_of_days,no_of_car);
        // If queue is empty, then
        // new node is front and rear both
        if (rear == NULL)
        {
            front = rear = temp;
            return;
           }

        // Add the new node at
        // the end of queue and change rear
        rear->next = temp;
        rear = temp;
    }

    // Function to remove
    // a key from given queue q
    void deQueue()
    {
        // If queue is empty, return NULL.
        if (front == NULL)
            return;

        // Store previous front and
        // move front one node ahead
        car_rented* temp = front;
        front = front->next;

        // If front becomes NULL, then
        // change rear also as NULL
        if (front == NULL)
            rear = NULL;

        delete (temp);
    }
    void show()
    {
        car_rented *temp;
        temp=front;
        if(temp==NULL)
        {
            cout<<"No car has been rented"<<endl;
        }
        else
    {
        while(temp!=NULL)
        {

            cout<<"\t\t\t\t"<<"---------------------------------------------------------------------------"<<endl;
            cout<<setw(30)<<"|"<<"        Customer Name"<<setw(15)<<"|"<<"    Car name"<<setw(15)<<"|"<<"    Rent of Car"<<setw(15)<<"|"<<"     No_of_cars"<<setw(15)<<"|"<<endl;
            cout<<"\t\t\t\t"<<"---------------------------------------------------------------------------"<<endl;
            cout<<setw(30)<<"|"<<setw(22)<<temp->username<<setw(15)<<"|"<<setw(12)<<temp->Name<<setw(15)<<"|"<<setw(15)<<temp->rent<<setw(15)<<"|"<<setw(15)<<temp->no_of_days<<setw(15)<<"|"<<endl;
            cout<<"\t\t\t\t"<<"---------------------------------------------------------------------------"<<endl;
        temp=temp->next;
        }
    }
    }
    int no_ofcarrented(string carname)
    {
      car_rented *temp;
      temp=front;
      int no=0;
      while(temp!=NULL)
      {
          if(temp->username==carname)
               {
                   no=no+temp->no_of_car;
                   temp=temp->next;
               }
          else
            temp=temp->next;
      }
      return no;
    }
   void showrent(string na)
    {
     car_rented *temp;
      temp=front;
      while(temp!=NULL)
      {
          if(temp->username==na)
            break;
          else
            temp=temp->next;
      }
   if(temp==NULL)
   {
       cout<<"YOU HAVE NOT RENTED ANY CAR"<<endl;
   }
  else
  {
      system("cls");
      cout<<"\n\n\n\n\n";

    cout << "\n\t\t                       Car Rental - Customer Invoice                  "<<endl;
    cout << "\t\t ///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t | Invoice No. :"<<"------------------|"<<setw(10)<<"#Cnb81353"<<" |"<<endl;
    cout << "\t\t | Customer Name:"<<"-----------------|"<<setw(10)<<temp->username<<" |"<<endl;
    cout << "\t\t | Car Model :"<<"--------------------|"<<setw(10)<<temp->Name<<" |"<<endl;
    cout << "\t\t | No. Of Cars Rented :"<<"-----------|"<<setw(10)<<temp->no_of_car<<" |"<<endl;

    cout << "\t\t | Number of days :"<<"---------------|"<<setw(10)<<temp->no_of_days<<" |"<<endl;
    cout << "\t\t | Rental Amount per day is :"<<"-----|"<<setw(10)<<temp->rent<<" |"<<endl;
    cout << "\t\t | Caution Money :"<<"----------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t | Advanced :"<<"---------------------|"<<setw(10)<<"0"<<" |"<<endl;
    cout << "\t\t ________________________________________________________"<<endl;
    cout <<"\n";
    cout << "\t\t | Total Rental Amount is :"<<"-------|"<<setw(10)<<temp->no_of_days*temp->rent*temp->no_of_car<<" |"<<endl;
    cout << "\t\t ________________________________________________________"<<endl;
    cout << "\t\t # This is a computer generated invoce and it does not"<<endl;
    cout << "\t\t require an authorised signture #"<<endl;
    cout <<" "<<endl;
    cout << "\t\t ///////////////////////////////////////////////////////////"<<endl;
    cout << "\t\t You are advised to pay up the amount before due date."<<endl;
    cout << "\t\t Otherwise penelty fee will be applied"<<endl;
    cout << "\t\t ///////////////////////////////////////////////////////////"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t     #####  THANKU FOR VISITING COME AGAIN   #####"<<endl;
    system("PAUSE");

    system ("CLS");
    }
    }
};

user *create_user(user *last,string x,string y )
{
    user* newnode;
    newnode=new user(x,y);
    if(last==NULL)
   {
    last=newnode;
    last->right=last;
   }
else
   {
    newnode->right=last->right;
    last->right=newnode;
    //newnode->left=last;
    last=newnode;
}
return last;
}
// creating the bst for the car by rent
car *create_car(car *root,int seats,int rents,int availability,string name)
{
  car* newnode;
  newnode=new car(seats,rents,availability,name);
    if(root==NULL)
      {
    root=newnode;
    return root;
      }
      else{

       if(root->rent>rents)
       {
           if(root->left==NULL)
             root->left=newnode;
           else
         root->left= create_car(root->left,seats,rents,availability,name);
       }
        else
        {  if(root->right==NULL)
               root->right=newnode;
               else
               root->right=create_car(root->right,seats,rents,availability,name);

        }   return root;
           }
}
// hard coding the users
user *createuser(user*last)
{

    last=create_user(last,"Vaishnavi","2019");
    last=create_user(last,"Vinayak","2026");
    last=create_user(last,"Bhadu","2028");
    last=create_user(last,"rohan","V134w5");
    last=create_user(last,"Ansh","An345");
    last=create_user(last,"Buddy","B1246");
    return last;

}
// hardcoding the car
car* createcar(car *root)
{
    root=create_car(root,4,5000,4,"Dummy");
    root=create_car(root,5,2300,5,"Wagnor");
    root=create_car(root,5,3000,3,"Swift Dezire");
    root=create_car(root,5,4500,2,"Thar");
    root=create_car(root,4,20000,2,"Bmw");
    root=create_car(root,7,7000,4,"Xuv 700");
    root=create_car(root,7,9000,6,"Fortuner");
    root=create_car(root,6,4400,7,"Creta");
    return root;
}
// printing the details of car for owner
void inorder(car *root)
{
    if(root==NULL)
        return;
    else
    {
         inorder(root->left);
    cout<<setw(40)<<"|"<<setw(15)<<root->Name<<setw(8)<<"|"<<setw(10)<<root->rent<<setw(12)<<"|"<<setw(10)<<root->No_of_car<<setw(10)<<"|"<<endl;
       cout<<"\t\t\t\t\t"<<"-----------------------------------------------------------------"<<endl;
        inorder(root->right);
    }

}

void details_of_car(car *root)
{
    system("PAUSE");

    system ("CLS");
    cout<<setw(90)<<"Details of car available\n\n\n\n\n";
    cout<<"\t\t\t\t\t"<<"-----------------------------------------------------------------"<<endl;
    cout<<setw(48)<<"|   Name "<<setw(30)<<"|    Rent/perday"<<setw(23)<<"|    Availability"<<setw(4)<<"|"<<endl;
    cout<<"\t\t\t\t\t"<<"-----------------------------------------------------------------"<<endl;
    inorder(root);

}
// details of particular car
void details_of_particularcar(car *root, int rent_to_search)
{
    while(root->rent!=rent_to_search)
    {
         if(root->rent<rent_to_search)
            root=root->right;
        else
            root=root->left;
    }
    cout<<endl<<endl;
    cout<<"\t\t\t\t\t"<<"-----------------------------------------------------------------"<<endl;
    cout<<setw(48)<<"|   Name "<<setw(30)<<"|    Rent/perday"<<setw(23)<<"|    Availability"<<setw(4)<<"|"<<endl;
    cout<<"\t\t\t\t\t"<<"-----------------------------------------------------------------"<<endl;
   cout<<setw(40)<<"|"<<setw(15)<<root->Name<<setw(8)<<"|"<<setw(10)<<root->rent<<setw(12)<<"|"<<setw(10)<<root->No_of_car<<setw(10)<<"|"<<endl;
   cout<<"\t\t\t\t\t"<<"-----------------------------------------------------------------"<<endl;
}
//search by name
int search_by_name(car *root,string name)
{
   stack<car *>stack1;
   car *temp=root;
   while(temp!=NULL || !stack1.empty())
   {
       while(temp!=NULL)
       {
           stack1.push(temp);
           temp=temp->left;
       }
       temp=stack1.top();
       stack1.pop();
       if(temp->Name==name)
        return temp->rent;
       else
        temp=temp->right;
   }
   return 0;
}
//increasing the avaialability
car* add_availability(car *root,int add,int availabilty)
{
    car* temp=root;
   while(temp->rent!=add && temp!=NULL)
   {
       if(temp->rent<add)
        temp=temp->right;
       else
        temp=temp->left;
   }
    temp->No_of_car=temp->No_of_car+availabilty;
    return root;
}
// adding a new car to list
car *add_car(car *root)
{
    string name_of_car;
    int rent_of_car,avaialability,seats;
    cout<<"Enter the Name of the car:";
    cin>>name_of_car;
    cout<<endl;
    int available=search_by_name(root,name_of_car);
     if(available==0)
   {
     cout<<"Enter the rent/day of the car:";
    cin>>rent_of_car;
    cout<<endl;
    cout<<"Enter the seats available in the car:";
    cin>>seats;
    cout<<endl;
    cout<<"Enter the no of car available to rent:";
    cin>>avaialability;
    cout<<endl;
    root=create_car(root,seats,rent_of_car,avaialability,name_of_car);
   }
    else
    {
          cout<<"Enter the no of car available to rent:";
         cin>>avaialability;
        cout<<endl;
       root=add_availability(root,available,avaialability);

    }
          return root;
}
// reduce the availability
void reduce_availability(car *root,int rent_of_car,int quantity)
{
    car* temp=root;
   while(temp->rent!=rent_of_car && temp!=NULL)
   {
       if(temp->rent<rent_of_car)
        temp=temp->right;
       else
        temp=temp->left;
   }
    temp->No_of_car=temp->No_of_car-quantity;
}
// to delete particular car when the car is not their
car *delete_car(car *root,int rent_of_car)
{
    if(root==NULL)
        return root;
    else
    {
        if(root->rent==rent_of_car)
            {
             cout<<endl<<root->Name<<"  is deleted "<<endl;
             if(root->left==NULL && root->right==NULL)
             return NULL;
           else{
             if(root->right==NULL)
           {
             car *temp=root->left;
             car *temp1=root;
              while(temp->right!=NULL)
              {
                  temp1=temp;
                temp=temp->right;
              }
              root->rent=temp->rent;
              root->Name=temp->Name;
              root->seater=temp->seater;
              root->No_of_car=temp->No_of_car;
              if(temp1==root)
              {
                  temp1->left=temp->left;
              }
              else
                  temp1->right=temp->left;
              delete temp;
           }
             else
             {car *temp=root->right;
             car *temp1=root;
              while(temp->left!=NULL)
              {
                  temp1=temp;
                temp=temp->left;
              }
              root->rent=temp->rent;
               root->Name=temp->Name;
              root->seater=temp->seater;
              root->No_of_car=temp->No_of_car;
              if(temp1==root)
              {
                  temp1->right=temp->right;
              }
              else
                  temp1->left=temp->right;
              delete temp;
           }
           return root;
        }
            }
        else
            if(root->rent<rent_of_car)
           root->right= (delete_car(root->right,rent_of_car));
        else
            root->left=(delete_car(root->left,rent_of_car));

    }
}
                                                                    // owner login function
int login_owner(user *last)
{
  string username,password;
  string U="modi";
  string P="2080";
      cout<<endl<<endl;
   label:
       cout<<endl<<endl;
   cout<<setw(65)<<"Enter Username:";
   cin>>username;
   cout<<endl<<endl;
   cout<<setw(65)<<"Enter Password:";
   cin>>password;

    if(username==U)
       {
        if(password==P)
    {
         cout<<endl<<endl<<endl;
        cout<<setw(30)<<"Logged In Successfully............"<<"!!!!!!!!!!!"<<endl;
        sleep(1);
        system("cls");
        return 0;

     }
     else
     {
         cout<<endl<<endl;
    cout<<setw(66)<<"Invalid Password"<<endl<<endl;
    cout<<setw(79)<<"Try Again...................."<<endl<<endl;
    goto label;
     }
       }
    else
    {
        cout<<endl<<endl;
        cout<<setw(66)<<" Invalid Username"<<endl<<endl;
        cout<<setw(79)<<"Try Again...................."<<endl<<endl;
      goto label;
    }
}

// user login
string login_user(user *last)
{

    string username,password;
      cout<<endl<<endl<<endl<<endl;
    top:
    int choice;
     cout<<setw(65)<<" 1---->For New User"<<endl<<endl;
     cout<<setw(65)<<" 2---->For Old User"<<endl<<endl;
     cout<<setw(70)<<"Enter your choice here :";

     cin>>choice;
     cout<<endl<<endl;
    switch (choice)
    {
      case 1:
      cout<<setw(65)<<"Enter Username:";
      cin>>username;
      cout<<endl<<endl;
      cout<<setw(65)<<"Enter Password:";
      cin>>password;
      cout<<endl<<endl;
    last=create_user(last,username,password);
    goto label;
    case 2:
    label:
    user *temp;

      cout<<setw(65)<<"Enter Username:";
      cin>>username;
      cout<<endl<<endl;
      cout<<setw(65)<<"Enter Password:";
      cin>>password;
      cout<<endl<<endl;                                                           //Almost done;
   temp=last->right;
   do
   {
    if(temp->username==username)
        if(temp->password==password)
    {
        cout<<setw(35)<<"Logged In Successfully.............."<<""<<endl;
        return username;
    }
    else
      {
           cout<<endl<<endl;
    cout<<setw(66)<<"Invalid Password"<<endl<<endl;
    cout<<setw(79)<<"Try Again...................."<<endl<<endl;
        }
    temp=temp->right;
}
while(temp!=last->right);
        cout<<endl<<endl;
        cout<<setw(66)<<" Invalid Username"<<endl<<endl;
        cout<<setw(79)<<"Try Again...................."<<endl<<endl;
      goto label;

  default:
        cout<<setw(79)<<"Wrong choice.................!!!"<<endl<<endl;
      goto top;
}
}
// search by range
void closest(car *root,int element,int& diff,int &clo)
{
    if(root==NULL)
       return ;
         if (diff > abs(root->rent - element))
    {
        diff = abs(root->rent - element);
        clo= root->rent;
    }
     if (element < root->rent)
        closest(root->left, element,diff, clo);
    else
        closest(root->right,element, diff, clo);
}
int car_choice_byprice(car *root, int k)
{
    int diff = INT_MAX, clo = -1;
    closest(root, k,diff,clo);

    return clo;
}

void bye()

{



    for(int x=0;x<30;x++)
    {      system ("CLS");
     cout<<setw(60)<<"Car Rental Project     "<<endl;
    cout<<setw(60)<<"Made By:-              "<<endl;

    cout<<setw(60)<<"Madhura Jituri 21803004"<<endl;
    cout<<setw(60)<<"Yashvin Pant   21803009"<<endl;
    cout<<setw(60)<<"Anmol Verma    21803014"<<endl;
    cout<<setw(60)<<"Rohit Gupta    21803018"<<endl;
    cout<<endl<<endl<<endl;
int k=3*x;
           cout<<setw(22+k)<<"___________"<<endl;
          cout<<setw(24+k)<<"/           \\ "<<endl;
         cout<<setw(24+k)<<"/             \\"<<endl;
 cout<<setw(33+k)<<"______/               \\______ "<<endl;
 cout<<setw(33+k)<<"[   PAISE DE DO HAMARI LE LO    ]"<<endl;
 cout<<setw(33+k)<<"|             GADI              |"<<endl;
 cout<<setw(33+k)<<"|                               |"<<endl;
 cout<<setw(33+k)<<"|______     _________     ______|"<<endl;
cout<<setw(12+k)<<"* * "<<setw(15)<<" * *"<<endl;
cout<<setw(13+k)<<"* * * "<<setw(15)<<" * * *"<<endl;
cout<<setw(12+k)<<"* * "<<setw(15)<<" * *"<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
if(x==0)
sleep(1);
sleep(0.3);
}
system ("PAUSE");
system("CLS");

}



void welcome()
{

   for(int x=0;x<30;x++)
    {      system ("CLS");
      cout<<endl<<endl;
  cout<<"\t\t\t"<<"*   *   *   * * * *   *         * * * *   * * * *   * * * * *   * * * * "<<endl;
  cout<<"\t\t\t"<<"*   *   *   *         *         *         *     *   *   *   *   *       "<<endl;
  cout<<"\t\t\t"<<"*   *   *   * * * *   *         *         *     *   *   *   *   * * * * "<<endl;
  cout<<"\t\t\t"<<"*   *   *   *         *         *         *     *   *   *   *   *       "<<endl;
  cout<<"\t\t\t"<<"* * * * *   * * * *   * * * *   * * * *   * * * *   *   *   *   * * * * "<<endl;
  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl   ;
       int k=3*x;
           cout<<setw(22+k)<<"___________"<<endl;
          cout<<setw(24+k)<<"/           \\ "<<endl;
         cout<<setw(24+k)<<"/             \\"<<endl;
 cout<<setw(33+k)<<"______/               \\______ "<<endl;
 cout<<setw(33+k)<<"[   PAISE DE DO HAMARI LE LO    ]"<<endl;
 cout<<setw(33+k)<<"|             GADI              |"<<endl;
 cout<<setw(33+k)<<"|                               |"<<endl;
 cout<<setw(33+k)<<"|______     _________     ______|"<<endl;
cout<<setw(12+k)<<"* * "<<setw(15)<<" * *"<<endl;
cout<<setw(13+k)<<"* * * "<<setw(15)<<" * * *"<<endl;
cout<<setw(12+k)<<"* * "<<setw(15)<<" * *"<<endl;
cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
if(x==0)
sleep(1);
sleep(0.3);
}
system ("PAUSE");
system("CLS");

}
                           // checking the availablity of the car
int check_availabilty(car *root,int rent_of_car,int number)
{
    car *temp=root;
    while(temp->rent!=rent_of_car && temp!=NULL)
    {
        if(temp->rent<rent_of_car)
            temp=temp->right;
        else
            temp=temp->left;
    }
    if(temp==NULL)
    {
        cout<<"      You Have Enter The Wrong Car"<<endl;
        return 0;
    }
    else
    {
      if(temp->No_of_car<number)

            cout<<"      Sorry only "<<temp->No_of_car<<" are available"<<endl;

       else
           cout<<endl<<"      Your car has been available"<<endl;
      return temp->No_of_car;
    }
}

car *deletecar(car *root, Queue q)
{
    string name;
    int num;
    cout<<"Enter the Name of the car you want to delete: ";
    cin>>name;
    cout<<endl;
    cout<<"Enter the Number of cars you want to delete: ";
    cin>>num;
      int p=search_by_name(root,name);
      if(p!=0)
        {
     int k = check_availabilty(root,p,num);
     if(k!=0)
     {
         int j;

      j= q.no_ofcarrented(name);
       if(j==0 && k==num)
       {
        root=delete_car(root,p);
       }
       else
        if(k>=num)
       {
        reduce_availability(root,p,num);
       }
       else
        cout<<"Either the cars are rented or "<<num<<" cars are not available"<<endl;
        }
        }
       return root;
}
void car_choice_bytype(car *root,string type)
{
    if(type=="Luxary"||type=="luxary"||type=="LUXARY")
        details_of_car(root->right);
    else
        if(type=="Regular"||type=="regular"||type=="REGULAY")
        details_of_car(root->left);
    else
        cout<<"\t\t\t\Wrong Choice"<<endl;
}
//the functionality of user and owner
int verify_user(user* last,car* root)
{
     Queue q;
    int choice,check;
 do{
    back:
    cout<<endl<<endl;
    cout<<setw(90)<<"||-----------------------------------------------||"<<endl;
    cout<<setw(90)<<"||                HOME SCREEN                    ||"<<endl;
    cout<<setw(90)<<"||-----------------------------------------------||"<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<setw(65)<<"Press 1 For Owner"<<endl<<endl;
    cout<<setw(68)<<"Press 2 For Customer"<<endl<<endl;
    cout<<setw(63)<<"Press 3 to Exit"<<endl<<endl;
  int k=75;
           cout<<setw(22+k)<<"___________"<<endl;
          cout<<setw(24+k)<<"/           \\ "<<endl;
         cout<<setw(24+k)<<"/             \\"<<endl;
 cout<<setw(33+k)<<"______/               \\______ "<<endl;
 cout<<setw(33+k)<<"[   TAKE YOUR CAR AND GIVE      ]"<<endl;
 cout<<setw(33+k)<<"|             CASH              |"<<endl;
 cout<<setw(33+k)<<"|                               |"<<endl;
 cout<<setw(33+k)<<"|______     _________     ______|"<<endl;
cout<<setw(12+k)<<"* * "<<setw(15)<<" * *"<<endl;
cout<<setw(13+k)<<"* * * "<<setw(15)<<" * * *"<<endl;
cout<<setw(12+k)<<"* * "<<setw(15)<<" * *"<<endl;
  cin>>choice;
    system ("CLS");

    if(choice==1)
    {
       int k=login_owner(last);
      cout<<endl<<endl<<endl;
       here:


   cout<<setw(85)<<"************************************************"<<endl;
    cout<<setw(85)<<"*               WELCOME SIR                    *"<<endl;
    cout<<setw(85)<<"************************************************"<<endl;
    cout<<"\n\n"<<setw(40)<<"Choose From The Option Below ";
     abcd:
         cout<<endl<<endl;
     cout<<setw(44)<<"1---> Details of the Available"<<endl<<endl;
     cout<<setw(27)<<"2---> Add Car"<<endl<<endl;
     cout<<setw(34)<<"3---> Delete the Car"<<endl<<endl;
     cout<<setw(45)<<"4---> Details of the Car Rented"<<endl<<endl;
     cout<<setw(34)<<"5---> Total Revenue "<<endl<<endl;
     cout<<setw(45)<<"6---> Go Back to the Login Page"<<endl<<endl;
     cout<<setw(37)<<"Enter your choice here :";
    cin>>check;
    cout<<endl<<endl;
    switch(check)
    {
    case 1:
      details_of_car(root);
        system("Pause");
        system("cls");
        goto abcd;
    case 2:
       root= add_car(root);
        system("Pause");
        system("cls");
        goto abcd;
    case 3:
        root=deletecar(root,q);
        system("Pause");
        system("cls");
        goto abcd;
    case 4:
        q.show();
        system("Pause");
        system("cls");
        goto abcd;
    case 5:

        q.print_revenue();
        system("Pause");
        system("cls");
        goto abcd;
    case 6:
        goto back;
    default :
         cout<<setw(40)<<"Wrong Choice.............."<<endl<<endl<<setw(25)<<"Enter Again"<<endl<<endl;
        goto abcd;
     }

     }

    else if(choice==2)
    {
      string user_name=login_user(last);

         system("cls");
    cout<<setw(85)<<"************************************************"<<endl;
    cout<<setw(60)<<"               WELCOME "<<user_name<<"              "<<endl;
      cout<<setw(85)<<"************************************************"<<endl;
       label1:
           cout<<endl<<endl;
        cout<<"\n\n"<<setw(40)<<"Choose From The Option Below ";
         cout<<endl<<endl;
     cout<<setw(64)<<"1---> Search Car by Type(..Luxary..OR..Regular..)"<<endl<<endl;
     cout<<setw(64)<<"2---> Search Car by Budget                       "<<endl<<endl;
     cout<<setw(64)<<"3---> Search Car by Name                         "<<endl<<endl;
     cout<<setw(64)<<"4---> Availability of a Particular Car           "<<endl<<endl;
     cout<<setw(64)<<"5---> Rent the Car                               "<<endl<<endl;
     cout<<setw(64)<<"6---> Print the Invoice Message                  "<<endl<<endl;
     cout<<setw(64)<<"7---> Go Back to the Login Page                  "<<endl<<endl;
     cout<<setw(64)<<"Enter your choice here : ";
         int decision;
         cin>>decision;
         cout<<endl<<endl;
         if(decision==1)
             {
     cout<<setw(50)<<"Enter Car Type (Luxary OR Regular) :"<<endl;
             string type;
              cin>>type;
              cout<<endl<<endl;
              car_choice_bytype(root,type);
                cout<<endl<<endl;
               system("Pause");
               system("cls");
             goto label1;
             }
      else
      if (decision==2)
        {

             cout<<setw(40)<<"Enter Your Budget : ";
               int price;
               cin>>price;
             cout<<endl<<endl;
             int closest= car_choice_byprice(root,price);
             cout<<setw(50)<<"closest price available is --> "<<closest<<endl<<endl;
             details_of_particularcar(root,closest);
         cout<<endl<<endl;
              system("Pause");
               system("cls");
               goto label1;
      }
          else
            if(decision==4)
          {
           cout<<setw(60)<<"Enter the Name of the Car whose availability you want : ";
           string carname;
            cin>>carname;
            int k =search_by_name(root,carname);
            if(k==0)
            cout<<setw(25)<<carname<<" is not in our store"<<endl;
            else
            {
            cout<<endl<<endl<<setw(40)<<"NUMBER OF CARS YOU WANT TO RENT : ";
            int number;
            cin>>number;
            cout<<endl;
            check_availabilty(root,k,number);
            }
             cout<<endl<<endl;
            system("Pause");
               system("cls");
           goto label1;
}
else
if(decision==3)
    {
       cout<<setw(50 )<<"Name of Car you Want to Search : ";
      string carname;
      cin>>carname;
     int k =search_by_name(root,carname);
    if(k==0)
    cout<<endl<<endl<<setw(25)<<carname<<" is not in our store"<<endl;
 else
    cout<<endl<<endl<<setw(25)<<carname<<" is in our store    "<<endl;
      cout<<endl<<endl;
       system("Pause");
               system("cls");
           goto label1;
    }
 else
        if(decision==5)
 {
     string name_of_car;
     cout<<endl<<endl<<"Enter the name of the car you want to rent : ";
     cin>>name_of_car;
     cout<<endl<<endl<<"Enter the no of cars you want to rent : ";
      int no_of_car;
      cin>>no_of_car;
      int k =search_by_name(root,name_of_car);
      if(k==0)
    cout<<endl<<name_of_car<<" is not in our store"<<endl;
    else
    {
      int c=check_availabilty(root,k,no_of_car);
      if(c>=no_of_car)
        {
      reduce_availability(root,k,no_of_car);
      int noofdays;
     cout<<endl<<endl<<setw(21)<<"Enter the no of days : ";
      cin>>noofdays;
      cout<<endl;
       q.enQueue(user_name,name_of_car,k,noofdays,no_of_car);
       cout<<"          Car has been Successfully Rented"<<endl;

        }
        else
            cout<<endl<<endl<<setw(40)<<" Sorry car is not available"<<endl;
    }
     cout<<endl<<endl;
           system("Pause");
               system("cls");
              goto label1;
 }
 else
    if(decision==6)
 {
     q.showrent(user_name);

        cout<<endl<<endl;
        system("Pause");
               system("cls");
           goto label1;
 }
else
    if(decision==7)
{
    system("cls");
   goto back;
}
else
{
        cout<<setw(40)<<"Wrong Choice.............."<<endl<<endl<<setw(25)<<"Enter Again"<<endl<<endl;
         cout<<endl<<endl;
          system("Pause");
               system("cls");
           goto label1;
        }
}
} while(choice!=3);
bye();
}

int main()
{

    sleep(3.5);
    welcome();
    car *root=NULL;
    user *last=NULL;
    root=createcar(root);
    last=createuser(last);

verify_user(last,root);
return 0;
}
