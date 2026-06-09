#include<iostream>
#include<string>
using namespace std;
struct buyer{
    string name;
    string mobileNo;
    string address;
    buyer*next;
    buyer(){
        name="";
        mobileNo="";
        address="";
        next=NULL;
    }
};
struct membership
{
    string membershipId;
    string name;
    string mobileNo;
    string type;
    string startDate;
    string endDate;
    membership*next;
    membership(){
        membershipId="";
        name="";
        mobileNo="";
        type="";
        startDate="";
        endDate="";
        next=NULL;
    }
};
struct book
{
    string bookId;
    string bookName;
    string authorName;
    float price;
    book*next;
    book(){
        bookId="";
        bookName="";
        authorName="";
        price= 0;
        next=NULL;
    }
};
struct issue
{
   string bookNo;
   string buyerName;
   string mobileNo;
   string issueDate;
   string returnDate;
   issue*next;
    issue(){
        bookNo="";
        buyerName="";
        mobileNo="";
        issueDate="";
        returnDate="";
        next=NULL;
    }
};
buyer*Buyer=NULL;
membership*Membership=NULL;
book*Book=NULL;
issue*Issue=NULL;
void addbuyer(){
    buyer*newbuyer= new buyer();
    cout<<"Enter Buyer name: "<<endl;
    cin.ignore();
    getline(cin,newbuyer->name);
    cout<<"Enter Buyer MobileNo: "<<endl;
    cin>>newbuyer->mobileNo;
    cout<<"Enter Buyer Address: "<<endl;
    cin.ignore();
    getline(cin,newbuyer->address);
    if(Buyer==NULL){
        Buyer=newbuyer;
    }
    else{
        buyer*temp=Buyer;
     while(temp->next!=NULL)
        {
            temp=temp->next;
        }

        temp->next=newbuyer;
    }
    cout<<"Buyer added successfully."<<endl;
}
void displayBuyers()
{
    if(Buyer==NULL)
    {
        cout<<"No buyer details found."<<endl;
        return;
    }
    buyer*temp=Buyer;
    while(temp!=NULL)
    {
        cout<<"Name          : " << temp->name<<endl;;
        cout<<"Mobile Number : " << temp->mobileNo<<endl;;
        cout<<"Address       : " << temp->address<<endl;;
        temp=temp->next;
    }
}
void addMembership()
{
    membership*newMember=new membership();
    cout<<"Enter Membership ID: "<<endl;
    cin>>newMember->membershipId;
    cout<<"Enter Member Name: ";
    cin.ignore();
    getline(cin,newMember->name);
    cout<<"Enter Mobile No: ";
    cin>>newMember->mobileNo;
    cout<<"Enter Membership Type: "<<endl;
    cin>>newMember->type;
    cout<<"Enter Start Date: "<<endl;
    cin>>newMember->startDate;
    cout<<"Enter End Date: "<<endl;
    cin>>newMember->endDate;
    if(Membership==NULL)
    {
        Membership=newMember;
    }
    else
    {
        membership*temp=Membership;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newMember;
    }
    cout<<"Membership added successfully."<<endl;
}
void displayMembership()
{
    if(Membership==NULL)
    {
        cout<<"No membership details found."<<endl;
        return;
    }
    membership*temp=Membership;
    while(temp!=NULL)
    {
        cout<<"Membership ID   : "<< temp->membershipId<<endl;
        cout<<"Membership Name : "<< temp->name<<endl;
        cout<<"Membership Mobile No"<< temp->mobileNo<<endl;
        cout<<"Membership Type : "<< temp->type<<endl;
        cout<<"Start Date      : "<< temp->startDate<<endl;
        cout<<"End Date        : "<< temp->endDate<<endl;
        temp=temp->next;
    }
}
void addBook()
{
    book*newbook =new book();
    cout<<"Enter Book Id: "<<endl;
    cin>>newbook->bookId;
    cout<<"Enter Book Name: "<<endl;
    cin.ignore();
    getline(cin, newbook->bookName);
    cout<<"Enter Author Name: "<<endl;
    getline(cin, newbook->authorName);
    cout<<"Enter Book Price: "<<endl;
    cin>>newbook->price;
    if(Book==NULL)
    {
        Book=newbook;
    }
    else
    {
        book*temp=Book;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newbook;
    }
    cout<<"Book added successfully."<<endl;
}
void displayBooks()
{
    if(Book==NULL)
    {
        cout<<"No book details found.";
        return;
    }
    book*temp=Book;
    while(temp!=NULL)
    {
        cout<<"\nBook Number   : " << temp->bookId;
        cout<<"\nBook Name     : " << temp->bookName;
        cout<<"\nAuthor Name   : " << temp->authorName;
        cout<<"\nPrice         : " << temp->price<<endl;
        temp=temp->next;
    }
}
void addIssue()
{
    issue*newIssue=new issue();
    cout<<"\nEnter Book ID to Issue: ";
    cin>>newIssue->bookNo;
    cout<<"Enter Buyer Name: ";
    cin.ignore();
    getline(cin, newIssue->buyerName);
    cout<<"Enter Buyer Mobile No: ";
    cin>>newIssue->mobileNo;
    cout<<"Enter Issue Date: ";
    cin>>newIssue->issueDate;
    cout<<"Enter Return Date: ";
    cin>>newIssue->returnDate;
    if (Issue==NULL)
    {
        Issue=newIssue;
    }
    else
    {
        issue*temp=Issue;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newIssue;
    }
    cout<<"Book issued successfully."<<endl;
}
void displayIssues()
{
    if(Issue==NULL)
    {
        cout<<"No issue details found."<<endl;
        return;
    }
    issue*temp=Issue;
    while(temp != NULL)
    {
        cout<< "\nBook ID      : " << temp->bookNo;
        cout<< "\nBuyer Name   : " << temp->buyerName;
        cout<< "\nMobile Number: " << temp->mobileNo;
        cout<< "\nIssue Date   : " << temp->issueDate;
        cout<< "\nReturn Date  : " << temp->returnDate<<endl;
        temp=temp->next;
    }
}
void searchBook()
{
    if(Book==NULL)
    {
        cout<<"No book details found."<<endl;
        return;
    }
    string searchNo;
    int found = 0;
    cout << "Enter Book Number to Search: "<<endl;
    cin >> searchNo;
    book*temp=Book;
    while(temp!=NULL)
    {
        if(temp->bookId == searchNo)
        {
            cout<<"\nBook Found.";
            cout<<"\nBook Id   : " <<temp->bookId;
            cout<<"\nBook Name     : " <<temp->bookName;
            cout<<"\nAuthor Name   : " <<temp->authorName;
            cout<<"\nPrice         : " <<temp->price<<endl;
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==0)
    {
        cout<<"Book not found."<<endl;
    }
}
void searchBuyer()
{
    if(Buyer==NULL)
    {
        cout<<"No buyer details found."<<endl;
        return;
    }
    string searchMobile;
    int found=0;
    cout<<"Enter Buyer Mobile Number to Search: ";
    cin>>searchMobile;
    buyer *temp=Buyer;
    while(temp!=NULL)
    {
        if(temp->mobileNo == searchMobile)
        {
            cout<<"Buyer Found."<<endl;
            cout<<"Name          : "<< temp->name<<endl;
            cout<<"Mobile Number : "<< temp->mobileNo<<endl;
            cout<<"Address       : "<< temp->address<<endl;
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found == 0)
    {
        cout<<"Buyer not found."<<endl;
    }
}
void searchIssue()
{
    if(Issue==NULL)
    {
        cout<<"No issue details found."<<endl;
        return;
    }
    string searchBookNo;
    int found = 0;
    cout<<"Enter Book ID to Search Issue Details: "<<endl;
    cin>>searchBookNo;
    issue *temp = Issue;
    while(temp != NULL)
    {
        if(temp->bookNo == searchBookNo)
        {
            cout<<"\nIssue Details Found."<<endl;
            cout<<"\nBook ID      : "<<temp->bookNo;
            cout<<"\nBuyer Name   : "<<temp->buyerName;
            cout<<"\nMobile Number: "<<temp->mobileNo;
            cout<<"\nIssue Date   : "<<temp->issueDate;
            cout<<"\nReturn Date  : "<<temp->returnDate<<endl;
            found = 1;
        }
        temp=temp->next;
    }
    if (found==0)
    {
        cout<<"Issue details not found."<<endl;
    }
}
void deleteAll()
{
    buyer *bTemp;
    while(Buyer!=NULL)
    {
        bTemp=Buyer;
        Buyer=Buyer->next;
        delete bTemp;
    }
    membership *mTemp;
    while(Membership!=NULL)
    {
        mTemp=Membership;
        Membership=Membership->next;
        delete mTemp;
    }
    book *BookTemp;
    while(Book!=NULL)
    {
        BookTemp=Book;
        Book=Book->next;
        delete BookTemp;
    }
    issue *iTemp;
    while(Issue!=NULL)
{
    iTemp=Issue;
    Issue=Issue->next;
    delete iTemp;
}
    cout<<"All memory deleted successfully."<<endl;
}
int main()
{
    int choice;
    do
    {
        cout<<"\n1. Add Book";
        cout<<"\n2. Display Books";
        cout<<"\n3. Add Membership";
        cout<<"\n4. Display Membership";
        cout<<"\n5. Add Buyers";
        cout<<"\n6. Display Buyers";
        cout<<"\n7. Issue Books";
        cout<<"\n8. Display Issue Detials";
        cout<<"\n9. Search Book";
        cout<<"\n10. Search Buyer";
        cout<<"\n11. Search Issue";
        cout<<"\n12. Exit";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            addMembership();
            break;
        case 4:
            displayMembership();
            break;
            case 5:
            addbuyer();
            break;
            case 6:
            displayBuyers();
            break;
            case 7:
            addIssue();
            break;
            case 8:
            displayIssues();
            break;
            case 9:
            searchBook();
            break;
            case 10:
            searchBuyer();
            break;
            case 11:
            searchIssue();
            break;
            case 12:
            deleteAll();
            cout<<"Program exited successfully"<<endl;
            break;
        default:
            cout<<"Invalid choice"<<endl;
            break;
        }
    } while(choice!=12);
    return 0;
}