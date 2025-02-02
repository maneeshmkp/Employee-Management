#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include<windows.h>
#include<string.h>

using namespace std;

class employee{
    private:
        
        char name[10];
        char id[5];
        char designation[20];
        int age;
        int ctc;
        int experience;

       
        void waitForEnter(void){
            cout<<"\n\n\n Press enter to go back \n\n";
            cin.get();
            cin.get();
        }

       
        void listEmployees(void){ 
            //struct employee
            system("cls");
            FILE *file;
            char d1[20]="sde";
            char d2[20]="assistant";
            char  d3[20]="manager";
            
            cout<<"\n\t      List of Employees\n";
             cout<<"\n-------------------------------------------";
            cout<<"\n NAME        |     ID  |   DESIGNATION   \n";
            cout<<"---------------------------------------------";
        
			file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF){
			
            if(strcmp(designation,d1)==0){
			 cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            }
            }
             fclose(file);
             	file= fopen("data.txt", "r");
             
             while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF){
             	
	         if (strcmp(designation,d2)==0){
			 cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            }
           }
           fclose(file);
           	file= fopen("data.txt", "r");
         while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!= EOF){
			
           if(strcmp(designation,d3)==0){
		   cout<<"\n"<<name<<"\t\t"<<id<<"\t\t"<<designation;
            }
           }
           fclose(file);
         
           
            waitForEnter();
        }

        void showDetails(void){
            system("cls");
            FILE *file;
            char checkId[5];
            cout<<"\n\nEnter Employee ID: ";
            cin>>checkId;
            file= fopen("data.txt", "r");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                if(strcmp(checkId,id)==0){
                	cout<<"\n---------------------";
                    cout<<"\nName: "<<name;
                    cout<<"\n---------------------";
                    cout<<"\nId: "<<id;
                    cout<<"\n---------------------";
                    cout<<"\nDesignation: "<<designation;
                    cout<<"\n---------------------";
                    cout<<"\nAge: "<<age;
                    cout<<"\n---------------------";
                    cout<<"\nCTC: "<<ctc;
                    cout<<"\n---------------------";
                    cout<<"\nExperience: "<<experience;
                    cout<<"\n---------------------";
                }
            fclose(file);
            waitForEnter();
        }

        void editExisting(void){ 
            system("cls");
            char checkId[5];
            cout<<"\nEnter employee id: ";
            cin>>checkId;
            char newDesignation[20];
            cout<<"\n-----------------------------";
            cout<<"\nEnter new designation: ";
            cin>>newDesignation;
            int newCtc;
            cout<<"------------------------------";
            cout<<"\nEnter new CTC: ";
            cin>>newCtc;
            FILE *file, *tempfile;
            file= fopen("data.txt", "r");
            tempfile= fopen("temp.txt", "w");
            while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF){
                if(strcmp(checkId, id)==0)
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, newDesignation, age, newCtc, experience );
                else
                    fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
            }
            fclose(file);
            fclose(tempfile);
            int isRemoved= remove("data.txt");
            int isRenamed= rename("temp.txt", "data.txt");
            waitForEnter();
        }

        void addNewEmployee(void){ 
            system("cls");
            cout<<"\n----------------------------------------";
            cout<<"\n Enter  Name of Employee: ";
            cin>>name;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee ID [max 4 digits]: ";
            cin>>id;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Designation: ";
            cin>>designation;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Age: ";
            cin>>age;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee CTC: ";
            cin>>ctc;
            cout<<"\n----------------------------------------";
            cout<<"\n Enter Employee Experience: ";
            cin>>experience;
            cout<<"\n----------------------------------------";

            char ch;
            cout<<"\nEnter 's' to save above information\n";
            cin>>ch;
            if(ch=='s'){
                FILE  *file;
                file= fopen("data.txt","a");
                fprintf(file, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                cout<<"\nNew Employee has been added to database\n";
            }
            else
                addNewEmployee();
            waitForEnter();
        }

        void deleteEmployeeDetails(void){ 
            system("cls");
            char checkId[5];
            cout<<"\n----------------------------------";
            cout<<"\nEnter Employee Id To Remove: ";
            cin>>checkId;
            char ch;
            cout<<"----------------------------------";
            cout<<"\n\n\n\n\nCONFIRMATION\nEnter 'd' To Confirm Deletion \n";
            cin>>ch;
            if(ch=='d'){
                FILE *file, *tempfile;
                file= fopen("data.txt", "r");
                tempfile= fopen("temp.txt", "w");
                while(fscanf(file, "%s %s %s %d %d %d", &name[0], &id[0] , &designation[0], &age, &ctc, &experience)!=EOF)
                    if(strcmp(checkId, id)!=0)
                        fprintf(tempfile, "%s %s %s %d %d %d \n", name, id, designation, age, ctc, experience );
                fclose(file);
                fclose(tempfile);
                int isRemoved= remove("data.txt");
                int isRenamed= rename("temp.txt", "data.txt");
                cout<<"\nRemoved Successfully\n";
                waitForEnter();
            }
            else
                deleteEmployeeDetails();
        }


    public:
        
        void options(void){ 
        int login(); 
                login();
            while(true){
                system("cls");
                
                
                cout<<"\n\t\t\t>>>>>>>>>  EMPLOYEE MANAGEMENT SYSTEM BY MANEESH PRAJAPATI <<<<<<<<<";
                cout<<"\n";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   1:   To View List of Employees";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   2:   To View Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   3:   To Modify Existing Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   4:   To Add New Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   5:   To Remove an Employee Details";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\t\t\tENTER   0:   To Exit     ";
                cout<<"\n\t\t\t------------------------------------------------";
                cout<<"\n\n\t\t\t   Please Enter Your Choice: ";

                
                int choice;
                cin>>choice;
               
                switch (choice) {
                    case 0:
                    	system("CLS");
                        cout<<"\n\nEMPLOYEE MANAGEMENT SYSTEM BY MANEESH PRAJAPTI \n ";
                        Sleep(10);
                        return;
                    case 1:
                        listEmployees();
                        break;
                    case 2:
                        showDetails();
                        break;
                    case 3:
                        editExisting();
                        break;
                    case 4:
                        addNewEmployee();
                        break;
                    case 5:
                        deleteEmployeeDetails();
                        break;
                    default:
                        cout<<"\n Invalid Input\n";
                getch();
                break;
                        
                }

            }
        }

};

int main(){
    
    employee e;
    e.options();
    return 0;
}

int login(){ 
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\t\t\t\t\tEMPLOYEE MANAGEMENT SYSTEM BY MANEESH PRAJAPATI ";
   cout <<"\n\n\n\n\n\t\t\t\t\tEnter Your Password :";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "maneeshmkp@1234"){
   	cout<<"\n\n\n\t\t\t\t\tLOADING \n\t\t\t\t\t";
   	for(int a=1;a<5;a++) 
	{
		Sleep(500);
		cout << "___";
	}

      cout << "\n\n\n\t\t\t\t\tAccess Granted!! \n\n\n";
      
  
      
      system("PAUSE");
      system("CLS");
   }else{
      cout << "\n\t\t\t\t\tInvalid Password. Please enter the correct password\n";
      login();
   }
}