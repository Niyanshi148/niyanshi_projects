#include<fstream>  

#include<conio.h>  

#include<string.h>  

#include<iomanip> 

#include<iostream>  

#include<time.h>  

using namespace std; 

int s; 

char patient[30]; 

class personal 

        {int number; char name[40], ad[100], bd[30], con[100], age[30], sex[30]; 

        public: 

void add() //input personal info 

{       
        
		cout<<"\nPATIENT NUMBER: "; cin>>number; 

        cout<<"\nNAME: "; cin.ignore(); cin.get(name,40); 

        cout<<"\nADDRESS: "; cin.ignore(); cin.get(ad,100); 

        cout<<"\nBIRTHDATE: "; cin.ignore(); cin.get(bd,30); 

        cout<<"\nAGE: "; cin.ignore(); cin.get(age,30); 

        cout<<"\nSEX: "; cin.ignore(); cin.get(sex,30); 

        cout<<"\nCONTACT NUMBER: "; cin.ignore(); cin.get(con,100); 

        cout<<"\t\t\t\n Information saved!\n"<<endl; 

        system("pause"); 

        } 

  

void show() //print info 

    { 

         cout<<"\nPATIENT: "<<number; 

           cout<<"\nNAME: "<<name; 

         cout<<"\nADDRESS: "<<ad; 

         cout<<"\nBIRTHDATE: "<<bd; 

         cout<<"\nAGE: "<<age; 

         cout<<"\nSEX: "<<sex; 

         cout<<"\nCONTACT NUMBER: "<<con;} 

             

  

int getNumber() 

    {return number;} 

char* getName() 

    {return name;} 

char* getAddress() 

    {return ad;} 

char* getPhone() 

    {return con;} 

char* getbirthdate() 

    {return bd;} 

char* getage() 

    {return age;} 

char* getsex() 

    {return sex;} 

void report() 

    {cout<<"\t\t"<<number<<setw(40)<<name<<endl;} 

};   

  

fstream medical; 

personal info; 

  

void save() 

{ 

    system("cls"); 

     int option; 

      medical.open("patient.dat",ios::out|ios::app); 

        info.add(); 

         medical.write((char*)&info,sizeof(personal)); 

     medical.close(); 

} 

void locate(int number) 

{ 

          system("cls"); 

          cout<<"\n[ P E R S O N A L  I N F O R M A T I O N ]\n"; 

          int check=0; 

          medical.open("patient.dat",ios::in); 

          while(medical.read((char*)&info,sizeof(personal))) 

          { 

                    if(info.getNumber()==number) 

                    { 

                               info.show(); 

                              check=1; 

                    } 

          } 

          medical.close(); 

          if(check==0) 

              cout<<"\n\n[PATIENT'S RECORD DOES NOT EXIST]"; 

        getch(); 

} 

void update() 

   { 

          system("cls"); 

          int number; 

          int found=0; 

          cout<<"\n\n\tPATIENT NUMBER: "; 

          cin>>number; 

          medical.open("patient.dat",ios::in|ios::out); 

          while(medical.read((char*)&info,sizeof(personal)) && found==0) 

          { 

            if(info.getNumber()==number) 

                { 

                    info.show(); 

                     cout<<"\n\nUPDATE PERSONAL INFORMATION"<<endl; 

                      info.add(); 
                      
                      double pos=(-1)*(sizeof(info)); //-1 delete first file to overwrite updates 

                      medical.seekp(pos,ios::cur); 

                      medical.write((char*)&info,sizeof(personal)); 

                      cout<<"\n\n\t[SUCCESSFULLY UPDATED]"; 

                      found=1;                    

                } 

          } 

                              
          medical.close(); 

          if(found==0) 

          cout<<"\n\n [PATIENTS'S RECORD DOES NOT EXIST]"; 

          getch(); 

   } 

  

void list() 

{ 

          system("cls"); 

          medical.open("patient.dat",ios::in); 

          cout<<"===================================================================\n"; 

          cout<<"\tPATIENT NUMBER"<<setw(20)<<"NAME"<<endl; 

          cout<<"\n==================================================================\n"; 

          while(medical.read((char*)&info,sizeof(personal))) 

          { 

                    info.report(); 

          } 

          medical.close(); 

          getch(); 

} 

void main_menu() 

{ 

    int s; 

select:  

cout<< "\n\nHELLO!\n"; 

cout<< "\nWHAT DO YOU WANT TO DO?\n\n"; 

cout<<"1 RECORD NEW PATIENT\n"; 

cout<<"2 LOCATE EXISTING MEDICAL RECORD\n"; 

cout<<"3 UPDATE PATIENT'S PERSONAL INFROMATION\n"; 

cout<<"4 VIEW LIST OF PATIENTS\n"; 

cout<<"5 EXIT"; 

cout<<"\nSelect: "; 

cin>>s; 


    if(s==1) 

    {save(); 

    system("cls"); 

    goto select;} 

    if(s==2) 

    {int number; 

     system("cls"); 

     cout<<"\n\n\tPATIENT NUMBER: "; 

     cin>>number; 

     locate(number); 

     system("cls"); 

     goto select;} 

    if(s==3) 

    {update(); 

     system("cls"); 

     goto select;} 

    if(s==4) 

        {list(); 

    system("cls"); 

    goto select;} 

    if(s==5) 

    {exit(0);} 
} 
  
enter() //code password//  

{ string pass=""; 
char ch;
     cout<<"================================HOSPITAL MANAGEMENT SYSTEM=======================================";
   cout<<"\n\nENTER PASSWORD:\n"; 
   ch=_getch();
    while(ch!=13)
    {
   	 pass.push_back(ch);
   	 cout<<"*";
   	 ch=_getch();
    }  

   if(pass == "12345"){ 
  

      system("cls"); 

   }else{ 

      cout<< "\n\n[ACCESS DENIED]\n\n"; 

      system("pause"); 

      system("cls"); 

      enter(); 

   }} 


int main(int argc, char *argv[]) 

{ 

    enter(); 

    main_menu(); 

    return 0; 

} 
