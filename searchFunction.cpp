//
//  searchFunction.cpp
//  ENGG1340_course_project
//
//  Created by Leung King To on 27/4/2019.
//  Copyright © 2019 Leung King To. All rights reserved.
//


#include "searchFunction.hpp"
#include "manipulateRec.hpp"
#include "getAge.hpp"
#include "printRec.hpp"

using namespace std;

// Function: display the menu of search, let user to choose what to search
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
//        int records_per_page: number of records can be displayed each time
// Output: NULL
void search_record(StaffRec * &old_database, int &number_of_records, int capacity, int records_per_page){
    
    char choice;
    string keyword;
    string keyword_2;
    string temp;
    
    cout << "Search/Delete Mode" << endl;
    cout << endl;
    cout << "1. Employee ID" << endl;
    cout << "2. Name" << endl;
    cout << "3. Age" << endl;
    cout << "4. Role" << endl;
    cout << "Q. Quit" << endl;
    
    cout << endl << "Please enter your choice: " ;
    cin >> choice;
    
    switch (choice){
        case '1':
            cout << endl << "Enter Employee ID: " ;
            cin >> keyword;
            search_match_string(old_database, number_of_records, capacity, choice, keyword, keyword_2, records_per_page);
            break;
            
        case '2':
            getline(cin, temp);                                                             //clear keyboard input buffer
            cout << endl << "Enter Employee First Name (Press Enter if not specified): " ;
            getline(cin, keyword);
            cout << endl << "Enter Employee Last Name (Press Enter if not specified): " ;
            getline(cin, keyword_2);
            cout << endl;
            search_match_string(old_database, number_of_records, capacity, choice, keyword, keyword_2, records_per_page);
            break;
            
        case '3':
            getline(cin, temp);                                                             //clear keyboard input buffer
            cout << endl << "Enter Employee Age Lower Bound: " ;
            getline(cin, keyword);
            cout << endl << "Enter Employee Age Upper Bound: " ;
            getline(cin, keyword_2);
            cout << endl;
            search_match_string(old_database, number_of_records, capacity, choice, keyword, keyword_2, records_per_page);
            break;
            
        case '4':
            cout << endl << "Enter Role: " ;
            cin >> keyword;
            search_match_string(old_database, number_of_records, capacity, choice, keyword, keyword_2, records_per_page);
            break;
        
        case 'q':
            break;
            
        case 'Q':
            break;
            
    }
}

// Function: add record to database
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
//        int &number_of_deletion: number of deletion after serching for the result
//        string * &id_of_deletion: point to the array of storing the id of which items are deleted
//        int &number_of_edit: number of editing after serching for the result
//        string * &id_of_edit: point to the array of storing the id of which items are edited
//        int records_per_page: number of records can be displayed each time
// Output: NULL
void show_search_database(StaffRec * &database, int &number_of_records, int capacity, int &number_of_deletion, string * &id_of_deletion, int &number_of_edit, string * &id_of_edit, int records_per_page){
    
    string choice;
    int n = 0;
    
    id_of_deletion = new string[capacity];
    id_of_edit = new string[capacity];
    
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
            
            id_of_edit[number_of_edit] = database[stoi(choice) - 1].staff_no;
            edit_record(database, n + stoi(choice) - 1);
            
            number_of_edit++;
        }
        
        if (user_input == 'd' || user_input == 'D'){
            cout << "Which item you want to delete (input 'a' for all): " ;
            cin >> choice;
            
            if(choice != "a"){
                id_of_deletion[number_of_deletion] = database[stoi(choice) - 1].staff_no;
                delete_record(database, number_of_records, n + stoi(choice) - 1, capacity);
                
                number_of_deletion++;
            }else{
                for (int i = 0; i < number_of_records; i++){
                    id_of_deletion[i] = database[i].staff_no;
                    number_of_deletion++;
                }
                for (int i = 0; i < number_of_deletion; i++)
                    delete_record(database, number_of_records, 0, capacity);
            }
            cout << endl;
        }
    }
    
    cout << endl;
}

// Function: search records according to the input of range of value by user
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
//        char choice: searching criteria
//        string keyword: the lower bound value of range
//        string keyword_2: the upper bound value of range
//        int records_per_page: number of records can be displayed each time
// Output: NULL
void search_match_string (StaffRec * &old_database, int &number_of_records, int capacity, char choice, string keyword, string keyword_2, int records_per_page){
    
    StaffRec * search_result = new StaffRec[capacity];
    
    int * index = new int[capacity];
    string * id_of_deletion;
    string * id_of_edit;
    
    int number_of_deletion = 0;
    int number_of_edit = 0;
    
    int number_of_result = 0;
    
    if (choice == '1'){
        for(int i = 0; i < number_of_records; i++){
            if (old_database[i].staff_no == keyword){
                search_result[number_of_result] = old_database[i];
                index[number_of_result] = i;
                number_of_result++;
            }
        }
    }
    
    if (choice == '2'){
        for(int i = 0; i < number_of_records; i++){
            if (keyword == ""){
                if (old_database[i].last_name == keyword_2){
                    search_result[number_of_result] = old_database[i];
                    index[number_of_result] = i;
                    number_of_result++;
                }
            } else if (keyword_2 == ""){
                if (old_database[i].first_name == keyword){
                    search_result[number_of_result] = old_database[i];
                    index[number_of_result] = i;
                    number_of_result++;
                }
            } else{
                if (old_database[i].first_name == keyword && old_database[i].last_name == keyword_2){
                    search_result[number_of_result] = old_database[i];
                    index[number_of_result] = i;
                    number_of_result++;
                }
            }
        }
    }
    
    if (choice == '3'){
        for(int i = 0; i < number_of_records; i++){
            if (getAge(stoi(old_database[i].birth_day), stoi(old_database[i].birth_month), stoi(old_database[i].birth_year)) >= stoi(keyword) && getAge(stoi(old_database[i].birth_day), stoi(old_database[i].birth_month), stoi(old_database[i].birth_year)) <= stoi(keyword_2)){
                search_result[number_of_result] = old_database[i];
                index[number_of_result] = i;
                number_of_result++;
            }
        }
    }
    
    if (choice == '4'){
        for(int i = 0; i < number_of_records; i++){
            if (old_database[i].job_title == keyword){
                search_result[number_of_result] = old_database[i];
                index[number_of_result] = i;
                number_of_result++;
            }
        }
    }
    
    show_search_database(search_result, number_of_result, capacity, number_of_deletion, id_of_deletion, number_of_edit, id_of_edit, records_per_page);
    
    if(number_of_edit != 0){
        for (int i = 0; i < number_of_edit; i++){                               //number of deletion e.g. 3 items to be edited
            for (int j = 0; j < number_of_records; j++){                        //loop the whole database
                if (old_database[j].staff_no == id_of_edit[i]){
                    int k;
                    for(k = 0; k < number_of_result; k++){
                        if (old_database[j].staff_no == search_result[k].staff_no)
                            break;
                    }
                    old_database[j] = search_result[k];
                    break;
                }
            }
        }
    }
    
    if (number_of_deletion != 0){
        for (int i = 0; i < number_of_deletion; i++){                           //number of deletion e.g. 3 items to be deleted
            for (int j = 0; j < number_of_records; j++){                        //loop the whole database
                if (old_database[j].staff_no == id_of_deletion[i]){
                    delete_record(old_database, number_of_records, j, capacity);
                    break;
                }
            }
        }
    }
}
