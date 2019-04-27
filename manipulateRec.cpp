//
//  manipulateRec.cpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#include <iostream>

#include "manipulateRec.hpp"

using namespace std;

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
    cout << "Please enter Date of Birth (dd-mm-yyyy):" << endl;
    getline(cin, temp);
    database[number_of_records].birth_day = temp.substr(0,2);
    database[number_of_records].birth_month = temp.substr(3,2);
    database[number_of_records].birth_year = temp.substr(6,4);
    
    if (number_of_records != 0){
        if(database[number_of_records - 1].number_of_user_defined_attributes != 0){
            
            database[number_of_records].number_of_user_defined_attributes = database[number_of_records - 1].number_of_user_defined_attributes;
            database[number_of_records].user_defined_attributes = database[number_of_records - 1].user_defined_attributes;
            database[number_of_records].user_defined_attributes_value = new string[database[number_of_records].number_of_user_defined_attributes];
            
            for (int i = 0; i < database[number_of_records].number_of_user_defined_attributes; i++){
                cout << "Please enter " << database[number_of_records].user_defined_attributes[i] << ": ";
                getline (cin, database[number_of_records].user_defined_attributes_value[i]);
            }
        }
    }
    
    cout << "Add user defined attributes (Y/N)?" << endl;
    getline(cin, temp);
    if (temp == "Y" || temp == "y"){
        cout << "Number of new user defined attributes?" << endl;
        getline(cin, temp);
        
        int number_of_new_attributes = stoi(temp);
        
        if(database[number_of_records].number_of_user_defined_attributes == 0){
            database[number_of_records].user_defined_attributes = new string[number_of_new_attributes];
            database[number_of_records].user_defined_attributes_value = new string[number_of_new_attributes];
        }else{
            string * backup_user_defined_attributes = database[number_of_records].user_defined_attributes;
            string * backup_user_defined_attributes_value = database[number_of_records].user_defined_attributes_value;
            
            database[number_of_records].user_defined_attributes = new string[database[number_of_records].number_of_user_defined_attributes + number_of_new_attributes];
            database[number_of_records].user_defined_attributes_value = new string[database[number_of_records].number_of_user_defined_attributes + number_of_new_attributes];
            
            for (int k = 0; k < database[number_of_records].number_of_user_defined_attributes; k++){
                
                database[number_of_records].user_defined_attributes[k] = backup_user_defined_attributes[k];
                database[number_of_records].user_defined_attributes_value[k] = backup_user_defined_attributes_value[k];
                
            }
            
        }
        
        int j = 0;
        for (int i = database[number_of_records].number_of_user_defined_attributes; i < database[number_of_records].number_of_user_defined_attributes + number_of_new_attributes; i++){
            
            cout << "New attribute " << ++j << ": ";
            getline(cin, database[number_of_records].user_defined_attributes[i]);
            cout << "Value of "<< database[number_of_records].user_defined_attributes[i] << ": ";
            getline(cin, database[number_of_records].user_defined_attributes_value[i]);
            
        }
        
        database[number_of_records].number_of_user_defined_attributes += number_of_new_attributes;
        
        for (int k = 0; k < number_of_records; k++){
            
            int old_number_of_user_defined_attributes = database[k].number_of_user_defined_attributes;
            
            database[k].number_of_user_defined_attributes = database[number_of_records].number_of_user_defined_attributes;
            database[k].user_defined_attributes = database[number_of_records].user_defined_attributes;
            
            string * backup_user_defined_attributes_value = database[k].user_defined_attributes_value;
            database[k].user_defined_attributes_value = new string[database[number_of_records].number_of_user_defined_attributes];
            
            for (int n = 0; n < old_number_of_user_defined_attributes; n++){
                database[k].user_defined_attributes_value[n] = backup_user_defined_attributes_value[n]; //copy old value element
            }
            
            for (int m = old_number_of_user_defined_attributes; m < database[number_of_records].number_of_user_defined_attributes; m++){
                database[k].user_defined_attributes_value[m] = "----";
            }
        }
    }
    //cout << "Please enter Address:" << endl;
    //cout << "Please enter ID:" << endl;
    //cout << "Please enter Bank Account Number:" << endl;
    
    number_of_records++;
    
    return 1;
}

void edit_record(StaffRec database[], int index){
    
    string temp;
    getline(cin, temp); //Clear Keyboard Buffer
    
    cout << "Current Employee ID = " << database[index].staff_no << ", New Employee ID (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].staff_no = temp;
    
    cout << "Current First Name = " << database[index].first_name << ", New First Name (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].first_name = temp;
    
    cout << "Current Surname = " << database[index].last_name << ", New Surname (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].last_name = temp;
    
    cout << "Current Gender = " << database[index].gender << ", New Gender (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].gender = temp;
    
    cout << "Current Job Title = " << database[index].job_title << ", New Job Title (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].job_title = temp;
    
    cout << "Current Salary = " << database[index].salary << ", New Salary (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].salary = temp;
    
    cout << "Current Employment Form = " << database[index].employment_form << ", New Employment Form (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].employment_form = temp;
    
    cout << "Current Status = " << database[index].job_status << ", New Status (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].job_status = temp;
    
    cout << "Current Phone No. = " << database[index].phone_no << ", New Phone No. (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != "")
        database[index].phone_no = temp;
    
    cout << "Current Date of Birth = " << database[index].birth_day + "-" + database[index].birth_month + "-" + database[index].birth_year << ", New Date of Birth, dd-mm-yyyy (Press Enter if No Change): ";
    getline(cin, temp);
    if( temp != ""){
        database[index].birth_day = temp.substr(0,2);
        database[index].birth_month = temp.substr(3,2);
        database[index].birth_year = temp.substr(6,4);
    }
    
    cout << endl;
}

void delete_record(StaffRec * &old_database, int &number_of_records, int del_index, int capacity){
    
    StaffRec * new_database = new StaffRec[capacity];
    
    for (int i = 0; i < del_index; i++)
        new_database[i] = old_database[i];
    
    for (int i = del_index + 1; i < number_of_records; i++)
        new_database[i - 1] = old_database[i];
    
    cout << "System Message: Item with ID = "<< old_database[del_index].staff_no << " is deleted!" << endl;
    
    delete [] old_database;
    old_database = new_database;
    
    number_of_records--;
}

