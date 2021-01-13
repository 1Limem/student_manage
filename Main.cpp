#include<iostream>

#include<cstdlib>
#include<string>
#include<fstream>
#include <cstring>
char *fileName = "dataBase.txt" ;
using namespace std ;

struct student 
{

    char name [20];
    char reg[15];
    char course[15];
    float cgpa ;

};
fstream file; 
student obj ;
void add()
{
    cout << "Enter Name:";
    cin>>obj.name ;
    cout << "Enter Registration Number:";
    cin >>obj.reg ;
    cout << "Enter Course:";
    cin>> obj.course;
    cout << "Enter CGPA:";
    cin >> obj.cgpa ;
    file.open(fileName , ios::app); // app ==> append 
    file.write((char*)&obj, sizeof(obj));
    file.close();

}
void show_all()
{
    file.open(fileName , ios::in);
    file.read((char*)&obj , sizeof(obj));
    while (file.eof()==0)
    {
        cout << "Name"<<obj.name<<endl;
        cout << "Registration Number: "<<obj.reg<<endl ; 
        cout << "Course: "<<obj.course<< endl ; 
        cout << "CGPA:  "<<obj.cgpa<<endl;
        file.read((char*)&obj,sizeof(obj));
    }
    file.close();

    
}

void search()
{
    float user ;
    cout << "Enter CGPA: ";
    cin>>user ;
    file.open(fileName , ios::in);
    file.read((char*)&obj,sizeof(obj));

    while (file.eof()==0)
    {
       if(obj.cgpa==user)
       {
            cout<<"Name: "<<obj.name<<endl;
            cout<<"Registration Number: "<<obj.reg<<endl;
            cout<<"Course: "<<obj.course<<endl;
            cout<<"CGPA: "<<obj.cgpa<<endl<<endl;
       } 
       file.read((char*)&obj,sizeof(obj));

    }
    file.close();
    
}
void edit()
{
    char user[15];
    cout <<"Enter registration Number:";
    cin >> user ;
    file.open(fileName, ios::in | ios::out);
    file.read((char*)&obj, sizeof(obj));

    while (file.eof()==0)
    
    {
        if(strcmp(obj.reg , user) ==0)
        {
            cout<<"Name: "<<obj.name<<endl;
            cout<<"Registration Number: "<<obj.reg<<endl;
            cout<<"Course: "<<obj.course<<endl;
            cout<<"CGPA: "<<obj.cgpa<<endl<<endl;

            cout << "\nEnter New course: " ;
            cin>>obj.course;

            file.seekp(file.tellg()-sizeof(obj));
            file.write((char*)&obj , sizeof(obj));
            cout <<"\n\nFile Updated";
            break ;
        }
        file.read((char*)&obj,sizeof(obj));

    }
    file.close();
    


}
void main()
{
    int option ;
    while (1)
    {
      cout << "Enter 1 to Enter Record\n";
      cout << "Enter 2 to Enter All Record\n";
      cout << "Enter 3 to Search Record\n";
      cout << "Enter 4 to Exit\n";
      cout <<"\n\nEnter Option: ";
      cin>>option ;
      switch(option)
      {
        case '1':
          add();
          cout <<"\n\nRecord Entered\n";
          break ;
          case '2':
          show_all();

          break ;
        case '3':
          search();
           break ;
        case '4' :
           exit(0);
        default:
        cout<<"Invalid Option...";
        


      }
    }
    
}
