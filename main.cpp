
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

// Global variables
int increment = 3;                                  // The size of each time of array enlargement. Default value is 3.
int records_per_page = 10;                          // The number of records can be shown each time. Default value is 10.

// Function prototype

// Function:    To show the setting page.
//              - User can modify the size of each time of array enlargement. Default value is 3.
//              - User can change the value of how many records can be shown each time. Default value is 10.
// Input: NULL
// Output: NULL
void showSetting();

int main(){
    
    StaffRec * database = new StaffRec[increment];  //Create a new array, act as a database, to store the staff records.
    
    int capacity = increment;                       // The maximum number of records can be stored currently in the database.
    int number_of_records = 0;                      // The number of records currently the database has.
    
    char user_input = show_menu();                  // Call the show_menu(). Choice input by the user will be returned.
    
    while(user_input != '0'){                       // Exit the system when user input '0'
        switch (user_input){
            case '1':
                file_import(database, number_of_records, capacity);                         // Import exisiting records from file
                break;
            
            case '2':
                show_database(database, number_of_records, capacity, records_per_page);     // Print out the records in the database
                break;
            
            case '3':
                if(number_of_records >= capacity)                                           // Enlarge the database if needded
                    grow_array(database, capacity, increment);                              // Enlarge according to the value of 'increment'
                    
                add_record(database, number_of_records);                                    // Add record into the database
                break;
                
            case '4':
                file_export(database, number_of_records);                                   // Export database to file
                break;
            
            case '5':
                search_record(database, number_of_records, capacity, records_per_page);     // Search records
                break;
                
            case '6':
                sort_record(database, number_of_records, capacity);                         // Sort records depends on fields
                break;
                
            case '7':
                showSetting();                                                              // Show setting page
                break;
            
            default:
            
                break;
        }
        user_input = show_menu();
    }
    
    cout << "bye bye!" << endl;
}


void showSetting (){
    
    cout << "current increment = " << increment << endl;
    cout << "current records_per_page = " << records_per_page << endl;
    
    cout << endl;
    
    char user_input = '\0';
    
    while(user_input != 'q' && user_input != 'Q'){                      // Quit when user input 'Q'
        
        cout << "I = Edit number of increment. R = Edit records_per_page. Q = Quit. Your choice = " ;
        
        cin >> user_input;
        
        if (user_input == 'i' || user_input == 'I'){                    // Modify the size of each time of array enlargement
            cout << endl << "Please enter new value: ";
            cin >> increment;
        }
        
        if (user_input == 'r' || user_input == 'R'){                    // Change the value of how many records can be shown each time.
            cout << endl << "Please enter new value: ";
            cin >> records_per_page;
        }
    }
}
