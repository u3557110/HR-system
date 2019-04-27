//
//  manipulateRec.cpp
//  ENGG1340_course_project
//
//  Created by Leung King To on 27/4/2019.
//  Copyright © 2019 Leung King To. All rights reserved.
//

#include <iostream>

#include "manipulateRec.hpp"

using namespace std;

// Function: add record to database
// Input: StaffRec database[]: the address pointing to the database
//        int &number_of_records: number of records the database has
// Output: int: 0 = unsuccessful adding. 1 = successful adding.
int add_record(StaffRec database[], int &number_of_records){
    
    string temp;
    getline(cin, temp);                                                                 //Clear Keyboard Buffer
    
    cout << "Please enter Employee ID: ";
    getline(cin, database[number_of_records].staff_no);
    cout << "Please enter First Name: ";
    getline(cin, database[number_of_records].first_name);
    cout << "Please enter Last Name: ";
    getline(cin, database[number_of_records].last_name);
    cout << "Please enter Gender: ";
    getline(cin, database[number_of_records].gender);
    cout << "Please enter Job Title: ";
    getline(cin, database[number_of_records].job_title);
    cout << "Please enter Salary: ";
    getline(cin, database[number_of_records].salary);
    cout << "Please enter Form of Employment: ";
    getline(cin, database[number_of_records].employment_form);
    cout << "Please enter Job Status: ";
    getline(cin, database[number_of_records].job_status);
    cout << "Please enter Phone Number: ";
    getline(cin, database[number_of_records].phone_no);
    cout << "Please enter Date of Birth (dd-mm-yyyy): ";
    getline(cin, temp);
    database[number_of_records].birth_day = temp.substr(0,2);
    database[number_of_records].birth_month = temp.substr(3,2);
    database[number_of_records].birth_year = temp.substr(6,4);
    
    if (number_of_records != 0){                                                                            // if this is not the first record
        if(database[number_of_records - 1].number_of_user_defined_attributes != 0){                         // and if there are user defined attributes in previous record
            
            database[number_of_records].number_of_user_defined_attributes = database[number_of_records - 1].number_of_user_defined_attributes;
            database[number_of_records].user_defined_attributes = database[number_of_records - 1].user_defined_attributes;
            database[number_of_records].user_defined_attributes_value = new string[database[number_of_records].number_of_user_defined_attributes];
            
            for (int i = 0; i < database[number_of_records].number_of_user_defined_attributes; i++){        // ask the user to input the value of user defined attributes accordindly
                cout << "Please enter " << database[number_of_records].user_defined_attributes[i] << ": ";
                getline (cin, database[number_of_records].user_defined_attributes_value[i]);
            }
        }
    }
    
    cout << "Add user defined attributes (Y/N)?" << endl;                                                   // ask whether if the user would like to add new user defined attributes
    getline(cin, temp);
    if (temp == "Y" || temp == "y"){
        cout << "Number of new user defined attributes?" << endl;                                           // get the number of desired new user defined attributes
        getline(cin, temp);
        
        int number_of_new_attributes = stoi(temp);
        
        if(database[number_of_records].number_of_user_defined_attributes == 0){                             // if there is no user defined attribute currently
            database[number_of_records].user_defined_attributes = new string[number_of_new_attributes];     // create corresponding arrays directly
            database[number_of_records].user_defined_attributes_value = new string[number_of_new_attributes];
        }else{                                                                                              // if there are some user defined attributes currently
            string * backup_user_defined_attributes = database[number_of_records].user_defined_attributes;  // update corresponding arrays
            string * backup_user_defined_attributes_value = database[number_of_records].user_defined_attributes_value;
            
            database[number_of_records].user_defined_attributes = new string[database[number_of_records].number_of_user_defined_attributes + number_of_new_attributes];
            database[number_of_records].user_defined_attributes_value = new string[database[number_of_records].number_of_user_defined_attributes + number_of_new_attributes];
            
            for (int k = 0; k < database[number_of_records].number_of_user_defined_attributes; k++){
                
                database[number_of_records].user_defined_attributes[k] = backup_user_defined_attributes[k];                //copy elements from old array to new array
                database[number_of_records].user_defined_attributes_value[k] = backup_user_defined_attributes_value[k];
                
            }
            
        }
        
        int j = 0;
        for (int i = database[number_of_records].number_of_user_defined_attributes; i < database[number_of_records].number_of_user_defined_attributes + number_of_new_attributes; i++){
            
            cout << "New attribute " << ++j << ": ";                                                        // get the name of the desired new user defined attributes
            getline(cin, database[number_of_records].user_defined_attributes[i]);
            cout << "Value of "<< database[number_of_records].user_defined_attributes[i] << ": ";           // get the value of the desired new user defined attributes
            getline(cin, database[number_of_records].user_defined_attributes_value[i]);
            
        }
        
        database[number_of_records].number_of_user_defined_attributes += number_of_new_attributes;          // update the number of user defined attributes
        
        for (int k = 0; k < number_of_records; k++){                                                        // update the value of new attributes of the existing employee be empty
            
            int old_number_of_user_defined_attributes = database[k].number_of_user_defined_attributes;      // store the old number of user-defined attributes
            
            database[k].number_of_user_defined_attributes = database[number_of_records].number_of_user_defined_attributes;
            database[k].user_defined_attributes = database[number_of_records].user_defined_attributes;      // update the number of user-defined attributes
            
            string * backup_user_defined_attributes_value = database[k].user_defined_attributes_value;
            database[k].user_defined_attributes_value = new string[database[number_of_records].number_of_user_defined_attributes];
            
            for (int n = 0; n < old_number_of_user_defined_attributes; n++){
                database[k].user_defined_attributes_value[n] = backup_user_defined_attributes_value[n];     // copy old element from old array to new array
            }
            
            for (int m = old_number_of_user_defined_attributes; m < database[number_of_records].number_of_user_defined_attributes; m++){
                database[k].user_defined_attributes_value[m] = "----";                                      // update the value of new attributes of the existing employee be empty
            }
        }
    }
    //cout << "Please enter Address:" << endl;
    //cout << "Please enter ID:" << endl;
    //cout << "Please enter Bank Account Number:" << endl;
    
    number_of_records++;                                                                                    // update the total number of records in the database
    
    return 1;
}

// Function: edit record in database
// Input: StaffRec database[]: the address pointing to the database
//        int index: the index, used in array, of the element going to be edited
// Output: NULL
void edit_record(StaffRec database[], int index){
    
    string temp;
    getline(cin, temp);                                                                                     //Clear Keyboard Buffer
    
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
    
    for (int k = 0; k < database[index].number_of_user_defined_attributes; k++){
        cout << "Current " << database[index].user_defined_attributes[k] << " = " << database[index].user_defined_attributes_value[k] << ", New " << database[index].user_defined_attributes[k] << ". (Press Enter if No Change): ";
        getline(cin, temp);
        if( temp != ""){
            database[index].user_defined_attributes_value[k] = temp;
        }
    }
    
    cout << endl;
}

// Function: delete record from databse
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int index: the index, used in array, of the element going to be deleted
//        int capacity: the capacity of the current database
// Output: NULL
void delete_record(StaffRec * &old_database, int &number_of_records, int del_index, int capacity){
    
    StaffRec * new_database = new StaffRec[capacity];           // create new array
    
    for (int i = 0; i < del_index; i++)
        new_database[i] = old_database[i];                      // copy elements from old database to new database
    
    for (int i = del_index + 1; i < number_of_records; i++)     // copy elements from old database to new database
        new_database[i - 1] = old_database[i];
    
    cout << "System Message: Item with ID = "<< old_database[del_index].staff_no << " is deleted!" << endl;
    
    delete [] old_database;                                     // free memory
    old_database = new_database;                                // point to the new database
    
    number_of_records--;                                        // update the total number of records in the database
}

