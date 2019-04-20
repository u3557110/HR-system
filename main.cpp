//
//  main.cpp
//  1340_project
//
//  Created by Toto Leung on 17/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct StaffRec {
    string staff_no;        //staff_number
    string first_name;      //First Name
    string last_name;       //Last Name
    string gender;          //Gender
    //string age;             //Age
    string job_title;       //Job Title
    string salary;          //Salary
    string employment_form; //Full time or part time
    string job_status;      //on leave or suspension from work
    string phone_no;        //Phone Number
    //string address;         //Address
    //string id_no;           //Id Card Number
    //string bank_no;         //Bank Account Number
};

//-------------------------------------------------------------------------------------------------------------------

char show_menu();

int add_record(StaffRec database[], int &number_of_records);

void show_database(StaffRec database[], int number_of_records);

void test_mode(StaffRec database[], int &number_of_records);

int file_import(StaffRec * &database, int &number_of_records, int &capacity);

//int file_import(StaffRec database[], int &number_of_records, int &capacity);

int file_export(StaffRec database[], int number_of_records);

void grow_array(StaffRec * &database, int &capacity, int increment);

//void grow_array(StaffRec database[], int &capacity, int increment);


//-------------------------------------------------------------------------------------------------------------------

int main(){
    
    int increment = 3;
    StaffRec * database = new StaffRec[increment];
    
    int capacity = increment;               //maximum number of records can be stored currently
    int number_of_records = 0;              //number of records currently have
    
    char user_input = show_menu();
    
    while(user_input != '0'){
        switch (user_input){
            case '1':
                file_import(database, number_of_records, capacity);
                break;
            
            case '2':
                show_database(database, number_of_records);
                break;
            
            case '3':
                if(number_of_records >= capacity)
                    grow_array(database, capacity, increment); //grow
                    
                add_record(database, number_of_records);
                break;
                
            case '4':
                file_export(database, number_of_records);
                break;
            
            case '9':
                test_mode(database, number_of_records);
                break;
            
            default:
            
                break;
        }
        user_input = show_menu();
    }
    
    cout << "bye bye!" << endl;
}

char show_menu(){
    
    char input;
    
    cout << "Welcome to Staff Management System." << endl;
    cout << "Please select:" << endl;
    cout << "1. Import Record" << endl;
    cout << "2. Show Record" << endl;
    cout << "3. Add Record" << endl;
    cout << "4. Export Record" << endl;
    cout << "5. Edit Record" << endl;
    cout << "6. Search Record" << endl;
    cout << "7. Sort Record" << endl;
    cout << "9. Test Mode" << endl;
    cout << "0. Exit" << endl;
    cout << endl << "Your Choice: ";
    
    cin >> input;
    
    cout << endl;
    
    return input;
    
}

int add_record(StaffRec database[], int &number_of_records){
    
    string temp;
    getline(cin, temp); //Clear Keyboard Buffer
    
    cout << "Please enter Staff Number:" << endl;
    getline(cin, database[number_of_records].staff_no);
    cout << "Please enter First Name:" << endl;
    getline(cin, database[number_of_records].first_name);
    cout << "Please enter Last Name:" << endl;
    getline(cin, database[number_of_records].last_name);
    cout << "Please enter Gender:" << endl;
    getline(cin, database[number_of_records].gender);
    //cout << "Please enter Age:" << endl;
    cout << "Please enter Job Title:" << endl;
    getline(cin, database[number_of_records].job_title);
    cout << "Please enter Salary:" << endl;
    getline(cin, database[number_of_records].salary);
    cout << "Please enter Form of Employment:" << endl;
    getline(cin, database[number_of_records].employment_form);
    cout << "Please enter Job Status:" << endl;
    getline(cin, database[number_of_records].job_status);
    cout << "Please enter Phone Number:" << endl;
    getline(cin, database[number_of_records].phone_no);

    //cout << "Please enter Address:" << endl;
    //cout << "Please enter ID:" << endl;
    //cout << "Please enter Bank Account Number:" << endl;
    
    number_of_records++;
    
    return 1;

}

void show_database(StaffRec database[], int number_of_records){
    
    cout << "Staff No.\t\t";
    cout << "First Name\t\t";
    cout << "Last Name\t";
    cout << "Gender\t";
    cout << "Job Title\t";
    cout << "Salary\t";
    cout << "Form\t";
    cout << "Status\t";
    cout << "Phone Number" << endl;
    
    for (int i = 0; i < number_of_records; i++){
        cout << database[i].staff_no << "\t\t";
        cout << database[i].first_name << "\t\t";
        cout << database[i].last_name << "\t\t";
        cout << database[i].gender << "\t\t";
        cout << database[i].job_title << "\t";
        cout << database[i].salary << "\t";
        cout << database[i].employment_form << "\t\t";
        cout << database[i].job_status << "\t";
        cout << database[i].phone_no << endl;
    }
    
    cout << endl;
}

void test_mode(StaffRec database[], int &number_of_records){
    
    int i = number_of_records;
    
    database[i].staff_no = "00000001";
    database[i].first_name = "Shun Wing";
    database[i].last_name = "Wong";
    database[i].gender = "M" ;
    database[i].job_title = "Engineer";
    database[i].salary = "20000";
    database[i].employment_form = "FT";
    database[i].job_status = "Normal";
    database[i].phone_no = "22333322";
    
    cout << "Database is initialized." << endl << endl;;
    
    number_of_records++;
}

int file_import(StaffRec * &database, int &number_of_records, int &capacity){
    
    string filename = "test.txt";
    
    ifstream input_file;
    input_file.open(filename.c_str());
    
    if (input_file.fail()){
        cout << "Error!" << endl;
        return 0;
    }
    
    string temp;
    getline(input_file, temp); //skip the first line (field name)
    //getline(input_file, temp);
    //cout << temp << endl;
    
    int k = 0;
    
    while(getline(input_file, temp)){
        
        int i = 0;
        int j = 0;
        
        //cout << endl << temp << endl;
        
        if (k >= capacity){
            grow_array(database, capacity, 3);
            //cout <<endl <<"------------------------------------------------------------------------"<<endl;
            //show_database(database, number_of_records);
        }
        
        j = temp.find('\t', i);
        database[k].staff_no = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        //cout << " i = " << i << endl;
        //cout << " j = " << j << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].first_name = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        //cout << " i = " << i << endl;
        //cout << " j = " << j << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].last_name = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        //cout << " i = " << i << endl;
        //cout << " j = " << j << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].gender = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        //cout << " i = " << i << endl;
        //cout << " j = " << j << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].job_title = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].salary = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].employment_form = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].job_status = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        i = ++j;
        
        j = temp.find('\t', i);
        database[k].phone_no = temp.substr(i, j - i);
        //cout << temp.substr(i, j - i) << endl;
        i = ++j;
        
        //cout << "File Successfully Imported!" << endl;
        //cout << endl;
        
        k++;
        number_of_records++;
    }
    
    //cout <<endl <<"------------------------------------------------------------------------"<<endl;
    //show_database(database, number_of_records);
    
    cout << "System Message: File test.txt is successfully imported!" << endl;
    cout << endl;
    
    input_file.close();
    
    return 1;
}

int file_export(StaffRec database[], int number_of_records){
    
    string filename = "test.txt";
    
    ofstream output_file;
    output_file.open(filename.c_str());
    
    if (output_file.fail()){
        cout << "Error." << endl;
        return 0;
    }
    
    output_file << "Staff No.\t";
    output_file << "First Name\t";
    output_file << "Surname\t";
    output_file << "Gender\t";
    output_file << "Job Title\t";
    output_file << "Salary\t";
    output_file << "Form\t";
    output_file << "Status\t";
    output_file << "Phone No." << endl;
    
    
    for (int i = 0; i < number_of_records; i++){
        
        output_file << database[i].staff_no << "\t";
        output_file << database[i].first_name << "\t";
        output_file << database[i].last_name << "\t";
        output_file << database[i].gender << "\t";
        output_file << database[i].job_title << "\t";
        output_file << database[i].salary << "\t";
        output_file << database[i].employment_form << "\t";
        output_file << database[i].job_status << "\t";
        output_file << database[i].phone_no << "\t" << endl;
    }
    
    cout << "File Successfully Exported!" << endl;
    cout << endl;
    
    output_file.close();
    
    return 1;
}

void grow_array(StaffRec * &old_database, int &capacity, int increment){
    
    StaffRec * new_database = new StaffRec[capacity + increment];
    
    for (int i = 0; i < capacity; i++)
        new_database[i] = old_database[i];
    
    delete [] old_database;
    old_database = new_database;
    
    capacity += increment;
    
    cout << "System Message: Capacity of database has been enlarged to " << capacity << "!" << endl;
    cout << endl;

    //cout <<endl <<"------------------------------------------------------------------------"<<endl;
    //show_database(old_database, 3);
    
}
