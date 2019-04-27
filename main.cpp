
#include <iomanip>
#include <iostream>
#include <string>

#include "file.hpp"
#include "getAge.hpp"
#include "manipulateRec.hpp"
#include "showMenu.hpp"
#include "sortRec.hpp"
#include "searchFunction.hpp"
#include "printRec.hpp"

using namespace std;

//global variable
int increment = 3;
int records_per_page = 10;

//function prototype

void show_database(StaffRec * &database, int &number_of_records, int capacity);

void setting();

int main(){
    
    StaffRec * database = new StaffRec[increment];
    
    int capacity = increment;               //maximum number of records can be stored currently
    int number_of_records = 0;              //number of records currently have
    
    char user_input = show_menu();
    
    while(user_input != '0'){
        switch (user_input){
            case '1':
                file_import(database, number_of_records, capacity);                 //import from files
                break;
            
            case '2':
                show_database(database, number_of_records, capacity);               //print records
                break;
            
            case '3':                                                               //add record
                if(number_of_records >= capacity)                                   //expand database if needded
                    grow_array(database, capacity, increment);
                    
                add_record(database, number_of_records);
                break;
                
            case '4':
                file_export(database, number_of_records);                           //export to file
                break;
            
            case '5':
                search_record(database, number_of_records, capacity, records_per_page);
                break;
                
            case '6':
                sort_record(database, number_of_records, capacity);
                break;
                
            case '7':
                setting();
                break;
            
            default:
            
                break;
        }
        user_input = show_menu();
    }
    
    cout << "bye bye!" << endl;
}

void show_database(StaffRec * &database, int &number_of_records, int capacity){
    
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
    }
    
    //cout << endl;
}

void setting (){
    
    cout << "current increment = " << increment << endl;
    cout << "current records_per_page = " << records_per_page << endl;
    
    cout << endl;
    
    char user_input = '\0';
    
    while(user_input != 'q' && user_input != 'Q'){
        
        cout << "I = Edit number of increment. R = Edit records_per_page. Q = Quit. Your choice = " ;
        
        cin >> user_input;
        
        cout << endl;
        
        if (user_input == 'i' || user_input == 'I'){
            cout << "Please enter new value: ";
            cin >> increment;
        }
        
        if (user_input == 'r' || user_input == 'R'){
            cout << "Please enter new value: ";
            cin >> records_per_page;
        }
    }
}
