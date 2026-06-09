#include <bits/stdc++.h>
using namespace std;
class Patient
{
public:
    int patientId;
    string name;
    int age;
    long long phNo;
    string disease;
    string doctorName;
    int priority;
    Patient* next;
    Patient()
    {
        patientId=0;
        name="";
        age=0;
        phNo=0;
        disease="";
        doctorName="";
        priority=0;
        next=NULL;
    }
};
class TreatmentHistory
{
public:
    int patientId;
    string name;
    int age;
    long long phNo;
    string disease;
    string doctorName;
    int priority;
    TreatmentHistory*next;
    TreatmentHistory()
    {
        patientId=0;
        name="";
        age=0;
        phNo=0;
        disease="";
        doctorName="";
        priority=0;
        next=NULL;
    }
};
class Priority
{
private:
    Patient*front;
    TreatmentHistory*top;
public:
    Priority()
    {
        front=NULL;
        top=NULL;
    }
    void addhistory(Patient* p)
    {
        TreatmentHistory* newHistory = new TreatmentHistory();
        newHistory->patientId = p->patientId;
        newHistory->name = p->name;
        newHistory->age = p->age;
        newHistory->phNo = p->phNo;
        newHistory->disease = p->disease;
        newHistory->doctorName = p->doctorName;
        newHistory->priority = p->priority;
        newHistory->next = top;
        top = newHistory;
    }
    void printPatient(Patient* temp)
    {
        cout << "Patient ID: " << temp->patientId<<endl;
        cout << "Name: " << temp->name<<endl;
        cout << "Age: " << temp->age<<endl;
        cout << "Patient Number: "<<temp->phNo<<endl;
        cout << "Disease: " << temp->disease<<endl;
        cout << "Doctor Name: " << temp->doctorName<<endl;
        cout << "Priority: " << temp->priority<<endl;
    }
    void printHistory(TreatmentHistory* temp)
    {
        cout << "Patient ID: " << temp->patientId<<endl;
        cout << "Name: " << temp->name<<endl;
        cout << "Age: " << temp->age<<endl;
        cout << "Patient Number: "<<temp->phNo<<endl;
        cout << "Disease: " << temp->disease<<endl;
        cout << "Doctor Name: " << temp->doctorName<<endl;
        cout << "Priority: " << temp->priority<<endl;
    }
    void addbypriority(Patient* newPatient)
    {
        if (front==NULL||newPatient->priority<front->priority)
        {
            newPatient->next=front;
            front=newPatient;
        }
        else
        {
            Patient*temp=front;
            while (temp->next!=NULL&&temp->next->priority<=newPatient->priority)
            {
                temp=temp->next;
            }
            newPatient->next=temp->next;
            temp->next=newPatient;
        }
    }
    void addPatient()
    {
        Patient*newPatient=new Patient();
        cout << "Enter Patient ID: ";
        cin >> newPatient->patientId;
        cout << "Enter Patient Name: ";
        cin.ignore();
        getline(cin, newPatient->name);
        cout << "Enter Age: ";
        cin >> newPatient->age;
        cout<<"Enter Patient Phone Number: ";
        cin>>newPatient->phNo;
        while(newPatient->phNo<1000000000||newPatient->phNo>9999999999)
        {
            cout<<"Invalid phone number. Please enter a 10-digit phone number: ";
            cin>>newPatient->phNo;
        }
        cout << "Enter Disease: ";
        cin.ignore();
        getline(cin, newPatient->disease);
        cout<<"Enter Doctor Name: ";
        getline(cin, newPatient->doctorName);
        cout<<"Enter Priority 1.High/Emergency 2.Medium 3.Low: ";
        cin>>newPatient->priority;
        if (newPatient->priority<1||newPatient->priority>3)
        {
            cout<<"Invalid priority. Patient not added."<<endl;
            delete newPatient;
            return;
        }
        addbypriority(newPatient);
        cout << "Patient added successfully." << endl;
    }
    void giveTreatment()
    {
        if (front==NULL)
        {
            cout<<"No patients waiting for treatment."<<endl;
        }
        else
        {
            Patient*temp=front;
            cout << "Patient moved for treatment:"<<endl;
            printPatient(temp);
            addhistory(temp);
            front = front->next;
            delete temp;
            cout << "Treatment completed and added to history stack."<<endl;
        }
    }
    void displayAllPatients()
    {
        if (front==NULL)
        {
            cout<<"Priority Queue is empty."<<endl;
        }
        else
        {
            Patient* temp = front;
            cout << " Waiting Patient List "<<endl;
            while (temp != NULL)
            {
                printPatient(temp);
                temp=temp->next;
            }
        }
    }
    void searchPatient()
    {
        if (front==NULL)
        {
            cout<<"Priority Queue is empty."<<endl;
            return;
        }
        int id;
        cout<<"Enter Patient ID to search: ";
        cin>>id;
        Patient* temp=front;
        while (temp!=NULL)
        {
            if (temp->patientId==id)
            {
                cout<<"Patient Found:"<<endl;
                printPatient(temp);
                return;
            }

            temp=temp->next;
        }
        cout << "Patient not found."<<endl;
    }
    void countPatients()
    {
        int count = 0;
        Patient* temp = front;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        cout<<"Total waiting patients: "<<count<<endl;
    }
    void displayByPriority()
    {
        if(front==NULL)
        {
            cout<<"Priority Queue is empty."<<endl;
            return;
        }
        int p;
        bool found = false;
        cout<<"Enter priority to display 1.High 2.Medium 3.Low: ";
        cin>>p;
        Patient*temp=front;
        while(temp!=NULL)
        {
            if(temp->priority==p)
            {
                printPatient(temp);
                found=true;
            }
            temp=temp->next;
        }
        if (found==false)
        {
            cout<<"No patients found with this priority."<<endl;
        }
    }
    void displaytreatmenthistory()
    {
        if(top==NULL)
        {
            cout<<"Treatment history is empty."<<endl;
        }
        else
        {
            TreatmentHistory* temp = top;
            cout<<"Treatment History Stack "<<endl;
            cout<<"Last treated patient will display first."<<endl;
            while(temp!=NULL)
            {
                printHistory(temp);
                temp=temp->next;
            }
        }
    }
    void displayLastTreatedpatient()
    {
        if (top==NULL)
        {
            cout<<"No patient treated yet."<<endl;
        }
        else
        {
            cout<<"Last Treated Patient Details: "<<endl;
            printHistory(top);
        }
    }
};
int main()
{
    Priority p;
    int choice;
    do
    {
        cout << "1. Add Patient"<<endl;
        cout << "2. Give Treatment to Highest Priority Patient"<<endl;
        cout << "3. Display Waiting Patients"<<endl;
        cout << "4. Search Patient"<<endl;
        cout << "5. Count Waiting Patients"<<endl;
        cout << "6. Display Patients by Priority"<<endl;
        cout << "7. View Treatment History"<<endl;
        cout << "8. View Last Treated Patient"<<endl;
        cout << "9. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.addPatient();
            break;
        case 2:
            p.giveTreatment();
            break;
        case 3:
            p.displayAllPatients();
            break;
        case 4:
            p.searchPatient();
            break;
        case 5:
            p.countPatients();
            break;
        case 6:
            p.displayByPriority();
            break;
        case 7:
            p.displaytreatmenthistory();
            break;
        case 8:
            p.displayLastTreatedpatient();
            break;
        case 9:
            cout << "Program ended."<<endl;
            break;
        default:
            cout << "Invalid choice."<<endl;
        }
    } while (choice != 9);
    return 0;
}