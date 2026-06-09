#include <iostream>
#include <string>
using namespace std;
struct Employee
{
    int id;
    string name;
    string position;
    float salary;
    float bonus;
    float totalSalary;
    Employee *next;
    Employee()
    {
        id=0;
        name="";
        position="";
        salary=0;
        bonus=0;
        totalSalary=0;
        next=NULL;
    }
};
struct Employer
{
    string companyName;
    string managerName;
    string department;
    Employer()
    {
        companyName="";
        managerName="";
        department="";
    }
};
Employee*employee=NULL;
Employer*employer=NULL;
void addEmployer()
{
    employer=new Employer();
    cout<<"Enter Company Name: ";
    cin.ignore();
    getline(cin,employer->companyName);
    cout<<"Enter Manager Name: ";
    getline(cin,employer->managerName);
    cout<<"Enter Department: ";
    getline(cin,employer->department);
}
void getEmployeeDetails(Employee *p)
{
    cout<<"Enter ID: ";
    cin>>p->id;
    cin.ignore();
    cout<<"Enter Name: ";
    getline(cin,p->name);
    cout<<"Enter Position: ";
    getline(cin,p->position);
    cout<<"Enter Salary: ";
    cin >> p->salary;
    cout<<"Enter Bonus: ";
    cin>>p->bonus;
    p->totalSalary=p->salary+p->bonus;
}
void addEmployee()
{
    Employee *newEmployee = new Employee();
    getEmployeeDetails(newEmployee);
    if(employee==NULL)
    {
        employee=newEmployee;
    }
    else
    {
        Employee *temp=employee;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newEmployee;
    }
}
void displayEmployee(Employee *p)
{
    cout<<"ID           : " <<p->id<< endl;
    cout<<"Name         : " <<p->name<< endl;
    cout<<"Position     : " <<p->position<< endl;
    cout<<"Salary       : " <<p->salary<< endl;
    cout<<"Bonus        : " <<p->bonus<< endl;
    cout<<"Total Salary : " <<p->totalSalary<< endl;
}
void displayAllEmployees()
{
    Employee*temp=employee;
    int count = 1;
    cout<<"EMPLOYEE DETAILS"<< endl;
    while (temp!=NULL)
    {
        cout<<"Employee "<< count<< endl;
        displayEmployee(temp);
        temp=temp->next;
        count++;
    }
}
void displayEmployer()
{
    if(employer==NULL){
    cout<<"\nEMPLOYER DETAILS" << endl;
    return;
    }
        cout<<"EMPLOYER DETAILS"<<endl;
        cout<<"Company Name : "<<employer->companyName<< endl;
        cout<<"Manager Name : "<<employer->managerName<< endl;
        cout<<"Department   : "<<employer->department<< endl;
}
void showPositions()
{
    Employee *temp=employee;
    cout<<"\nPOSITION DETAILS"<< endl;
    while(temp!=NULL)
    {
        cout<<temp->name <<" is working as "<< temp->position << endl;
        temp=temp->next;
    }
}
void findHighestSalary()
{
    if(employee == NULL)
    {
        cout<<"No employee details found."<< endl;
        return;
    }
    Employee*highest=employee;
    Employee*temp=employee->next;
    while(temp!=NULL)
    {
        if(temp->totalSalary > highest->totalSalary)
        {
            highest=temp;
        }
        temp=temp->next;
    }
    cout<<"\nHIGHEST SALARY EMPLOYEE" << endl;
    displayEmployee(highest);
}
void deleteAll()
{
    Employee*eTemp;
    while(employee!=NULL)
    {
        eTemp=employee;
        employee=employee->next;
        delete eTemp;
    }
    if(employer!=NULL)
    {
        delete employer;
        employer=NULL;
    }
    cout<<"\nMemory deleted successfully."<< endl;
}
int main()
{
    int n;
    cout<<"Enter Employer Details"<< endl;
    addEmployer();
    cout<<"Enter number of employees: "<<endl;
    cin>> n;
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter Employee "<< i + 1<< " Details"<< endl;
        addEmployee();
    }
    displayEmployer();
    displayAllEmployees();
    showPositions();
    findHighestSalary();
    deleteAll();
    return 0;
}