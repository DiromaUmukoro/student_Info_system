#include <iostream>
#include <cstring>
using namespace std;

class student{
    public ://this allowd the variables to be available everywhere in the program
        long int id;//student id
        string name;//student name
        student(int id, string name);
        student();
        void get_data();
        void display_data();
};

int main(){
    cout<<"=======================STUDENT DATABASE SYSTEM==================="<<endl;
    int choice;
    long int size;//enter any input size for the number of students
    cout<<"Enter the size of the student to be saved in the database:";
    cin>>size;
    student s[size];
    for(int i=0;i<size;i++){//get data for each student
        s[i].get_data(); 
    }
    cout<<endl;
    
    while(choice !=5 ){//check the choice is not 5
        cout<<endl;
        cout<<endl<<"Enter 1 to Display database";
        cout<<endl<<"Enter 2 to Display requested student record";
        cout<<endl<<"Enter 3 to Delete a student record";
        cout<<endl<<"Enter 4 to Modify a student record";
        cout<<endl<<"Enter 5 to quit program";

        cout<<endl<<"Enter your choice :";
        cin>>choice;

        switch (choice){

            case 1://Display database for all student
                {
                    cout<<endl<<"Student Info:"<<endl;
                    for(int i=0;i<size;i++){
                        s[i].display_data(); 
                    }
                    break;
                }
            case 2://Display requested student record
                {
                    int id;
                    cout<<endl<<"Enter student id to find student:";
                    cin>>id;
                    for(int i=0;i<size;i++){ 
                        if(s[i].id==id){
                            cout<<"student name:"<<s[i].name<<endl;
                            cout<<"student id:"<<s[i].id;                
                        }
                    }
                    break;
                }
            case 3://Delete a student record
                {
                    long int id;
                    cout<<"Enter student id you want to delete:";
                    cin>>id;

                    int checkStudent=0;//check if a given student is in our data base
                    for(int i=0;i<size;i++){ 
                        if(s[i].id==id){    
                            break;      
                        }

                        if(i<size){
                            size=size-1;
                            for(int i=0;i<size;i++){
                                s[i].id=s[i+1].id;
                                s[i].name=s[i+1].name;   

                            }
                            checkStudent=1;
                        }
                        if(checkStudent==0){
                            cout<<" This student is not in our database.";
                        }
                        else{
                            cout<<"Student record have been successfully deleted";
                        }
                    }
                    break;
                }

            case 4://modify a student record
                {
                    long int id;
                    cout<<"Enter student id you want to modify:";
                    cin>>id;
                    int checkStudent=0;
                    for(int i=0;i<size;i++){ 
                        if(s[i].id==id){
                            cout<<"Student record is available for modification.\n";
                            checkStudent=1;
                            int newId;
                            string newName;
                            cout<<" student new name:";
                            cin>>newName;
                            cout<<endl<<" student new id:";
                            cin>>newId;

                            s[i].id=newId;
                            s[i].name=newName;      

                            cout<<"Student Info has been successfully modified.\n";
                            cout<<"Modified data:\n";
                            s[i].display_data();      
                        }
                        else{
                            cout<<"Student is not in our database.";
                        }
                        
                    }
                    break;
                }
            case 5://quit the program
                {
                    cout<<"exiting..."<<endl<<"exited. Thank you";
                    break;
            }
            default:cout<<"not a valid choice";//when a wrong input choice is selected
                break;
        }

    }

    
    return 0;
};

student::student(int id, string name){//initialize the student variable using pointer
    this->id=id;
    this->name=name;
}

student::student(){//initialize all var to 0 if left empty
    id=0;
    name=" ";
}

void student::get_data(){//get the data of the student
    cout<<"Enter your name:";
    cin>>name;
    cout<<"Enter your student id(numbers only):";
    cin>>id;
}

void student::display_data(){//display the data of the student
    cout<<"student name is:"<<name<<endl;
    cout<<"student id is:"<<id<<endl;
}