#include<iostream>
#include<string>
using namespace std;
struct Student{
    string name;
    int marks[5];
    int subjects;
    int total;
    float average;
    char grade;
    Student*next;
    Student(){
        name="";
        total=0;
        average=0;
        grade=' ';
        next=NULL;
        for(int i=0;i<5;i++)
        {
            marks[i]=0;
        }
        }
        void getdetails()
        {
            total=0;
            cout<<"Enter student name :";
            getline(cin, name);
            cout<<"Enter 5 subjects marks: "<<endl;
            for(int i=0;i<5;i++){
            cout<<"Subjects "<<i+1<<" mark: ";
            cin>>marks[i];
            total=total+marks[i];
        }
        cin.ignore();
        average=(float)total/5;
        if(average>=90){
            grade='A';
        }
        else if(average>=75){
            grade='B';
        }
        else if(average>=55){
            grade='C';
        }
        else if(average>=35){
            grade='D';
        }
        else{
            grade='F';
        }
    }
    void display(){
        cout<<"Student Grade Report"<<endl;
        cout<<"Name: "<<name<<endl;
        for(int i=0;i<5;i++){
            cout<<"Subjects "<<i+1 <<" :"<<marks[i]<<endl;  
             }
             cout<<"Total Marks: "<<total<<endl;
             cout<<"Average: "<<average<<endl;
             cout<<"Grade: "<<grade<<endl;
    }
    };
    Student*head=NULL;
    void addstudent(){
        Student*newstudent=new Student();
        newstudent->getdetails();
        if(head==NULL){
            head=newstudent;
        }
        else{
            Student*temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newstudent;
        }
        cout<<"Student added successfully."<<endl;
    }
    void displayAllstudents(){
        if(head==NULL){
            cout<<"No student details found."<<endl;
            return;
        }
        Student*temp=head;
        int count=1;
        while(temp!=NULL){
            cout<<"Students "<<count<<endl;
            temp->display();
            temp=temp->next;
            count++;
        }
    }
    void deleteAllstudents(){
        Student*temp;
        while(head!=NULL){
            temp=head;
            head=head->next;
            delete temp;
        }
        cout<<"All students memory deleted. "<<endl;
    }
int main(){
    int n;
    cout<<"Enter num of Students: ";
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        cout<<"Enter details for student "<<i+1<<": "<<endl;
        addstudent();
    }
    displayAllstudents();
    deleteAllstudents();
    return 0;
}
