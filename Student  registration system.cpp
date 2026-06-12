
#include<iostream>
#include<cstring>
using namespace std;

struct student {
    int id;
    char name[10];
    char department[20];
};

void add(student students[], int n, int startindex) {
    for(int i = 0; i < n; i++) {
        cout << "Student " << startindex + i + 1 << endl;
        cout << "ID:"<<endl;
        cin >> students[startindex + i].id;
        cin.ignore();
        cout << "Name:"<<endl;
        cin.getline(students[startindex+i].name,10); 
        cout << "Department:"<<endl;
        cin.getline (students[startindex + i].department,20); 
    }
}
void display(student students[],int total){
for(int i=0;i<total;i++){
    cout<<"Student"<<i+1<<endl;
    cout<<"ID:"<<students[i].id<<endl;
    cout<<"Name:"<<students[i].name<<endl;
    cout<<"Department:"<<students[i].department<<endl;
}
}
void deleterecord(student students[],int &count,int id){
	int index;
	for(int i=0;i<count;i++){
		if(students[i].id==id){
			index=i;
			break;
		}
	}
		for(int i=index;i<count-1;i++){
			students[i]=students[i+1];
		}
		cout<<"Student deleted successfully"<<endl;
	count--;
}
void edit(student students[],int&count,int id){
	for(int i=0;i<count;i++){
		if(students[i].id==id){
			cout<<"Student previous record"<<endl;
			cout<<"ID:"<<students[i].id<<endl;
			
    cout<<"Name:"<<students[i].name<<endl;
    cout<<"Department:"<<students[i].department<<endl;
    cin.ignore();
    cout<<"Enter new name"<<endl;
     cin.getline(students[i].name,10);
     cout<<"Enter department"<<endl;
     cin.getline(students[i].department,20);
		}
	}
}
void access(student* students, int count, int id) {
    bool found = false;
    for (int i=0;i<count;i++) {
        if ((students+i)->id == id) {
            cout << "Student record found:\n";
            cout << "ID: " << (students+i)->id<<endl;
            cout << "Name: " <<(students+i)->name<<endl;
            cout << "Department: " << (students + i)->department << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No student found with ID " << id << endl;
    }
}

int main(){
   int choice;
    student students[10];
    int currentcount = 0;

    do {
        cout << "---------------------------------\n";
        cout << "       Student registration record            \n";
        cout << "---------------------------------\n";
        cout << "1.Add student record." << endl;
        cout<<"2.Display record"<<endl;
        cout << "3.Delete student record." << endl;
        cout<<"4.Edit record."<<endl;
        cout << "5.Access student record." << endl;
        cout << "6.Exit." << endl;
        cout << "----------------------------------\n";
        cin >> choice;
        switch(choice) {
            
            case 1: 
            int no;
                cout << "How many students you want to add." << endl;
                cin >> no;
                if(currentcount+no>10){
                    cout<<"More than 10 students are not allowed to be enterd. "<<endl;
                    break;
                }
            add(students,no,currentcount);
             currentcount+=no;
             break;
             case 2:
             	if(currentcount==0){
             		cout<<"No record to dispay"<<endl;
				 }else{
				 
             cout<<"\tNew record.\t"<<endl;
             display(students,currentcount);
         }
             break;
             case 3:
             int studentid;
             cout<<"Enter id"<<endl;
             cin>>studentid;
             if(currentcount==0){
                 cout<<"No record to delete"<<endl;
             }else{
                 deleterecord(students,currentcount,studentid);
             }
             break;
             case 4:
             int student_id;
             cout<<"Enter id to edit"<<endl;
             cin>>student_id;
             if(currentcount==0){
                 cout<<"No record to edit"<<endl;
             }else{
                 edit(students,currentcount,student_id);
             }
             break;
             case 5: 
            if(currentcount == 0) {
            cout << "No record to access" << endl;
            break;
            }
            int access_id;
            cout << "Enter ID to access: ";
            cin >> access_id;
            access(students, currentcount, access_id);
             break;

             case 6:
             cout<<"Exit."<<endl;
             break;
             default:
             cout<<"Invalid option.Please choose from above"<<endl;
             break;
        }
}while(choice!=6);
}

