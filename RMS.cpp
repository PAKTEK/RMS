#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
class dish{
public:
float price;
string name;
int serial_no;
class dish* next;
void setdata()
{
cout<<"\t\t\t\t\tEnter the Serial No. of the dish: ";
cin>>serial_no;
cout<<"\t\t\t\t\tEnter the Name of the dish: ";
cin>>name;
cout<<"\t\t\t\t\tEnter the Price of the dish: ";
cin>>price;
}
void setdata(int s, string n, float p)
{
serial_no = s;
name = n;
price = p;
}
void getdata()
{
cout<<"\t\t\t\t\t"<<serial_no<<"."<<name<<" "<<price<<endl;
}
};
class order{
public:
 string naam;
 int quantity, s_no;
 float amount;
 class order* nextptr;

 void setorder(int s, int q, string n, float a)
 {
 naam = n;
 quantity = q;
 amount = a;
 s_no = s;
}
};
class order* createorder(int s, int q, string n, float a)
{
class order* neworder = new (class order);
neworder->setorder(s, q, n, a);
neworder->nextptr = NULL;
return neworder;
}
class order* orderhead = createorder(0, 0, "none", 0);
class dish* createdish(int s, string n, float p)
{
class dish* newdish = new (class dish);
newdish->setdata(s, n, p);
newdish->next = NULL;
return newdish;
}
void add_order(class order* orderptr, int n, int q, class dish* item)
{
class order* naya = createorder(n, q, item->name,item->price);
while(orderptr->nextptr!=NULL)
{
orderptr = orderptr->nextptr;
}
orderptr->nextptr = naya;
naya->nextptr = NULL;
}
void view_menu(class dish* head)
{
cout<<endl<<endl;
cout<<"\t\t\t\t\tFOOD MENU-"<<endl<<endl;
for(int i=1; head!=NULL; i++)
{
head->getdata();
head = head->next;
}
}
void add_item(class dish* head)
{
system("clear");
cout<<endl<<endl;
int serial;
string irim;
float pri;
cout<<"\t\t\t\t\tEnter the serial no: ";
cin>>serial;
cout<<"\t\t\t\t\tEnter the dish name: ";
cin>>irim;
cout<<"\t\t\t\t\tEnter the dish price: ";
cin>>pri;
class dish* n = createdish(serial, irim, pri);
class dish* temp = head;
while(temp->next!=NULL)
{
if(irim == temp->name || serial == temp->serial_no)
{
if(irim == temp->name)
{
cout<<endl<<"\t\t\t\t\tYou cannot add this dish..."<<endl;
cout<<"\t\t\t\t\tDish with this Name is already present in the menu!!"<<endl;
break;
}
if(serial == temp->serial_no)
{
cout<<endl<<"\t\t\t\t\tYou cannot add this dish..."<<endl;
cout<<"\t\t\t\t\tDish with this Serial_No. is already present in the menu!!"<<endl;
break;
}
}
temp = temp->next;
}
if(temp->next==NULL && irim!=temp->name)
{
temp->next = n;
n->next = NULL;
cout<<endl<<"\t\t\t\t\tDish has been successfully added in the menu!!";
cout<<endl<<endl<<"\t\t\t\t\tUPDATEDLIST-"<<endl<<endl;
view_menu(head);
}
}
void remove_item(class dish* head)
{
system("clear");
view_menu(head);
cout<<endl<<endl;
int sno;
cout<<"\t\t\t\t\tEnter the Serial No. of the dish you want to remove: ";
cin>>sno;
class dish* ptr = head;
class dish* temp = head->next;
while(temp->serial_no != sno)
{
if(temp==NULL)
{
cout<<endl<<"\t\t\t\t\tThis dish does not exist in the menu!!";
break;
}
ptr = ptr->next;
temp = temp->next;
}
if(temp->serial_no == sno)
{ptr->next = temp->next;
free(temp);
cout<<endl<<"\t\t\t\t\tDish has been removed from the menu!!";
cout<<endl<<endl<<"\t\t\t\t\tUPDATEDLIST-"<<endl<<endl;
view_menu(head);
}
}
void place_order(class dish* head, class order*orderptr)
{
system("clear");
cout<<endl<<endl;
cout<<"\t\t\t\t\tFOOD MENU-"<<endl<<endl;
class dish* temp = head;
class dish* ptr = head->next;
int i;
temp->getdata();
for(i=1; ptr!=NULL; i++)
{
ptr->getdata();
ptr = ptr->next;
temp = temp->next;
}
int last = temp->serial_no+1;
cout<<"\t\t\t\t\t"<<last<<". DONE WITHORDER"<<endl;
cout<<endl<<"\t\t\t\t\tORDER-"<<endl;
int choice, quan;
int num=1;
while(true){
cout<<endl;
cout<<"\t\t\t\t\tEnter the Serial No. of the dish: ";
cin>>choice;
if(choice==last)
{
break;
}
else{
class dish* temp2 = head;
cout<<"\t\t\t\t\tEnter quantity: ";
cin>>quan;
while(temp2!=NULL)
{
if(choice == temp2->serial_no)
{
add_order(orderptr, num, quan,temp2);
num++;
break;
}
temp2 = temp2->next;
}
if(temp2==NULL)
{
cout<<endl<<"\t\t\t\t\tThis dish is not present in the menu!!";
}
}
}
cout<<endl<<"\t\t\t\t\tYour order has been successfully placed!!";
}
void view_placed_order(class order* orderptr)
{
cout<<endl<<endl;
class order* temp = orderptr->nextptr;
cout<<"\t\t\t\t\tYOUR ORDER-"<<endl<<endl;
cout<<"\t\t\t\t\t"<<"S_No."<<endl;
while(temp!=NULL){
cout<<"\t\t\t\t\t"<<" "<<temp->s_no<<""<<temp->naam<<" * "<<temp->quantity<<endl;
temp = temp->nextptr;
}
}
void view_bill(class order* orderptr)
{
system("clear");
cout<<endl<<endl;
class order* temp = orderptr->nextptr;
if(temp==NULL){
cout<<endl<<"\t\t\t\t\tYou cannot view bill..."<<endl<<"\t\t\t\t\tPlease order some dishesfirst!!"<<endl;
}
else
{
float total;
cout<<"\t\t\t\t\tTOTAL BILL-"<<endl;
for(int i=1; temp!=NULL; i++)
{
cout<<"\t\t\t\t\t"<<i<<". "<<temp->naam<<" * "<<temp->quantity<<" = "<<temp->quantity*temp->amount<<endl;
total += temp->quantity*temp->amount;
temp = temp->nextptr;
}
cout<<endl;
cout<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t TOTAL\t\t"<<total;
}
}
void calculate_bill(class order* orderptr)
{
system("clear");
cout<<endl<<endl;
class order* temp = orderptr->nextptr;
if(temp==NULL)
{
cout<<endl<<"\t\t\t\t\tYou cannot calculate bill..."<<endl<<"\t\t\t\t\tPlease order some dishes first!!"<<endl;
}
else
{
float total;
cout<<"\t\t\t\t\tCALCULATING BILL-"<<endl;
for(int i=1; temp!=NULL; i++)
{
cout<<"\t\t\t\t\t"<<i<<". "<<temp->naam<<": "<<temp->amount<<" * "<<temp->amount<<" = "<<temp->quantity*temp->amount<<endl;
total += temp->quantity*temp->amount;
temp = temp->nextptr;
}
cout<<endl;
cout<<"\t\t\t\t\t---------------------------------------------------------------------"<<endl;
cout<<"\t\t\t\t\t TOTAL\t\t\t"<<total;
}
}
void cancel_items(class order* orderptr)
{
system("clear");
class order* temp2 = orderptr;
class order* temp = orderptr->nextptr;
view_placed_order(orderptr);
cout<<endl<<endl;
int remove;
cout<<"\t\t\t\t\tEnter the Serial No. of the dish you want to remove from the list: ";
cin>>remove;
while(temp->s_no != remove)
{
if(temp==NULL)
{
cout<<endl<<"\t\t\t\t\tThis dish is not present in the list you ordered!!";
break;
}
temp = temp->nextptr;
temp2 = temp2->nextptr;
}
if(temp->s_no==remove)
{
temp2->nextptr = temp->nextptr;
free(temp);
cout<<endl<<"\t\t\t\t\tDish has been deleted from the list you ordered!!";
cout<<endl<<endl<<"\t\t\t\t\tUPDATEDLIST-"<<endl<<endl;
view_placed_order(orderptr);
}
}
void customer(class dish* head)
{
system("clear");
int choice;
cout<<endl<<endl<<"\t\t\t<<<<<------------------CUSTOMER MENU------------------>>>>>"<<endl;
cout<<endl<<"\t\t\t\t\t1. View Menu--->>";
cout<<endl<<"\t\t\t\t\t2. Place order--->>";
cout<<endl<<"\t\t\t\t\t3. View placed order--->>";
cout<<endl<<"\t\t\t\t\t4. Cancel items from placed order--->>";
cout<<endl<<"\t\t\t\t\t5. View total Bill--->>";
cout<<endl<<"\t\t\t\t\t6. Exit--->>";
cout<<endl<<endl<<"\t\t\t\t\tPlease enter your choice- ";
cin>>choice;
switch (choice)
{
case 1: view_menu(head);
break;
case 2: place_order(head, orderhead);
break;
case 3: view_placed_order(orderhead);
break;
case 4: cancel_items(orderhead);
break;
case 5: view_bill(orderhead);
break;
case 6: exit(2);
break;
default: cout<<endl<<"\t\t\t\t\tPlease enter a valid choice!!"<<endl;
}
}
void admin(class dish* head)
{
system("clear");
int choice;
cout<<endl<<endl<<"\t\t\t<<<<<------------------ADMIN MENU------------------>>>>>"<<endl;
cout<<endl<<"\t\t\t\t\t1. View Menu--->>";
cout<<endl<<"\t\t\t\t\t2. Add item to menu list--->>";
cout<<endl<<"\t\t\t\t\t3. Remove item from menu list--->>";
cout<<endl<<"\t\t\t\t\t4. Calculate Bill--->>";
cout<<endl<<"\t\t\t\t\t5. Exit--->>";
cout<<endl<<endl<<"\t\t\t\t\tPlease enter your choice- ";
cin>>choice;
switch (choice)
{
case 1: view_menu(head);
break;
case 2: add_item(head);
break;
case 3: remove_item(head);
break;
case 4: calculate_bill(orderhead);
break;
case 5: exit(2);
break;
default: cout<<endl<<"\t\t\t\t\tPlease enter a valid choice!!"<<endl;
}
}
void mainmenu(class dish* head){
while(true){
system("clear");
cout<<endl<<endl;
cout<<"\t***************************************************************************************"<<endl;
cout<<"\t\t\t\t\tRESTAURANTMANAGEMENT SYSTEM"<<endl;
cout<<"\t***************************************************************************************"<<endl;
int choice;
cout<<endl<<endl<<"\t\t\t<<<<<------------------MAIN MENU------------------>>>>>"<<endl;
cout<<endl<<"\t\t\t\t\t1. ADMIN--->>\n\t\t\t\t\t2. CUSTOMER--->>\n\t\t\t\t\t3. EXIT--->>"<<endl<<endl;
cout<<"\t\t\t\t\tPlease enter your choice- ";
cin>>choice;
switch (choice){
case 1: admin(head);
break;
case 2: customer(head);
break;
case 3: exit(1);
break;
default: cout<<endl<<"\t\t\t\t\tPlease enter a valid choice!!"<<endl;
}
}
}
int main()
{
class dish* head = createdish(1, "Fried Chiken",150);
class dish* d1 = createdish(2, "Veg Birayani", 125);
class dish* d2 = createdish(3, "Shahi Paneer", 100);
class dish* d3 = createdish(4, "Manchurian", 90);
class dish* d4 = createdish(5, "Manchow Soup",200);
head->next = d1;
d1->next = d2;
d2->next = d3;
d3->next = d4;
d4->next = NULL;
mainmenu(head);
return 0;
}
