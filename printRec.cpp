//
//  printRec.cpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#include <iostream>
#include <iomanip>

#include "printRec.hpp"
#include "structStaffRec.hpp"
#include "getAge.hpp"
#include "manipulateRec.hpp"
#include "sortRec.hpp"

using namespace std;

// Function: print the content of the database
// Input: StaffRec database[]: the address pointing to the database
//        int number_of_records: number of records the database has
//        int records_per_page: number of records can be displayed each time
//        int n: page number
// Output: NULL
char print_table(StaffRec database[], int number_of_records, int records_per_page, int n){
    
    char user_input = '\0';
    
    cout << "Page: " << (n/10 + 1) << '/' ;
    
    if (number_of_records%records_per_page != 0)
        cout << (number_of_records/records_per_page + 1) << endl;
    else{
        cout << (number_of_records/records_per_page == 0 ? 1 : number_of_records/records_per_page) << endl;
    }
    
    cout << setw(2)  << "#";
    cout << setw(12) << "Employee ID";
    cout << setw(12) << "First Name";
    cout << setw(9)  << "Surname";
    cout << setw(8)  << "Gender";
    cout << setw(11) << "Job Title";
    cout << setw(9)  << "Salary";
    cout << setw(6)  << "Form";
    cout << setw(9)  << "Status";
    cout << setw(11) << "Phone No.";
    cout << setw(15) << "Date of Birth";
    cout << setw(5)  << "Age";
    
    int extra_hyphen = 0;
    if (database[0].number_of_user_defined_attributes != 0){
        for (int j = 0; j < database[0].number_of_user_defined_attributes; j++){
            cout << setw(int(database[0].user_defined_attributes[j].length() + 2)) << database[0].user_defined_attributes[j];
            extra_hyphen += int(database[0].user_defined_attributes[j].length() + 2);
        }
    }
    
    cout << endl << "-------------------------------------------------------------------------------------------------------------";
    
    for (int i = 0; i < extra_hyphen; i++)
        cout << "-" ;
    
    cout << endl;
    
    for (int i = 0; i < records_per_page; i++){
        if (n+i < number_of_records){
            cout << setw(2)  << i + 1;
            cout << setw(12) << database[n+i].staff_no;
            cout << setw(12) << database[n+i].first_name;
            cout << setw(9)  << database[n+i].last_name;
            cout << setw(8)  << database[n+i].gender;
            cout << setw(11) << database[n+i].job_title;
            cout << setw(9)  << database[n+i].salary;
            cout << setw(6)  << database[n+i].employment_form;
            cout << setw(9)  << database[n+i].job_status;
            cout << setw(6)  << database[n+i].phone_no.substr(0, 4);
            cout << setw(1)  << "-" ;
            cout << setw(4)  << database[n+i].phone_no.substr(4, 4);
            cout << setw(15) << database[n+i].birth_day + "-" + database[n+i].birth_month + "-" + database[n+i].birth_year;
            cout << setw(5)  << getAge(stoi(database[n+i].birth_day), stoi(database[n+i].birth_month), stoi(database[n+i].birth_year));
            
            if (database[n+i].number_of_user_defined_attributes != 0){
                for (int j = 0; j < database[n+i].number_of_user_defined_attributes; j++){
                    cout << setw(int(database[n+i].user_defined_attributes_value[j].length() + 2))<< database[n+i].user_defined_attributes_value[j];
                }
            }
            
            cout << endl;
        }
    }
    
    cout << endl << "Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. S = Sort. F = Fire. Your Choce: ";
    cin >> user_input;
    
    return user_input;
}

// Function: sort the records in the database
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
//        int records_per_page: number of records can be displayed each time
// Output: NULL
void show_database(StaffRec * &database, int &number_of_records, int capacity, int records_per_page){
    
    int choice;
    int n = 0;
    
    char user_input = '\0';
    
    while(user_input != 'q' && user_input != 'Q'){
        
        user_input = print_table(database, number_of_records, records_per_page, n);
        
        cout << endl;
        
        if (user_input == 'n' || user_input == 'N'){
            n += records_per_page;
        }
        
        if (user_input == 'p' || user_input == 'P'){
            n -= records_per_page;
        }
        
        if (user_input == 'e' || user_input == 'E'){
            cout << "Which item you want to edit: " ;
            cin >> choice;
            edit_record(database, n + choice - 1);
        }
        
        if (user_input == 'd' || user_input == 'D'){
            cout << "Which item you want to delete: " ;
            cin >> choice;
            delete_record(database, number_of_records, n + choice - 1, capacity);
        }
        
        if (user_input == 's' || user_input == 'S'){
            sort_record(database, number_of_records, capacity);
        }
        
        if (user_input == 'f' || user_input == 'F'){
            cout << "Whom you want to fire: " ;
            cin >> choice;
            database[n + choice - 1].job_status = "Fired";
        }
    }
}
