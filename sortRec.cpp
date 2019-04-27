//
//  sortRec.cpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#include <iostream>

#include "sortRec.hpp"
#include "structStaffRec.hpp"
#include "getAge.hpp"

using namespace std;

// Function: sort the records in the database
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
// Output: NULL
void sort_record(StaffRec * &old_database, int &number_of_records, int capacity){
    
    int choice;
    int i;
    int j;
    int index;
    string min;
    
    cout << "Select attributes to sort:" << endl;
    cout << endl;
    cout << "1. Employee ID" << endl;
    cout << "2. First Name" << endl;
    cout << "3. Surname" << endl;
    cout << "4. Gender" << endl;
    cout << "5. Job Title" << endl;
    cout << "6. Salary" << endl;
    cout << "7. Form" << endl;
    cout << "8. Status" << endl;
    cout << "9. Phone No." << endl;
    cout << "10. Date of Birth" << endl;
    cout << "11. Age" << endl;
    
    for (int i = 0; i < old_database[0].number_of_user_defined_attributes; i++)
        cout << i + 12 << ". " << old_database[0].user_defined_attributes[i] << endl;
    
    cout << endl << "Please enter your choice: " ;
    cin >> choice;
    
    for (i = 0; i < number_of_records - 1; i++){                    // sort records by using selection sort
        index = i;
        
        switch (choice){
                
            case 1:
                min = old_database[i].staff_no;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].staff_no < min){
                        min = old_database[j].staff_no;
                        index = j;
                    }
                }
                break;
                
            case 2:
                min = old_database[i].first_name;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].first_name < min){
                        min = old_database[j].first_name;
                        index = j;
                    }
                }
                break;
                
            case 3:
                min = old_database[i].last_name;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].last_name < min){
                        min = old_database[j].last_name;
                        index = j;
                    }
                }
                break;
                
            case 4:
                min = old_database[i].gender;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].gender < min){
                        min = old_database[j].gender;
                        index = j;
                    }
                }
                break;
                
            case 5:
                min = old_database[i].job_title;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].job_title < min){
                        min = old_database[j].job_title;
                        index = j;
                    }
                }
                break;
                
            case 6:
                min = old_database[i].salary;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].salary < min){
                        min = old_database[j].salary;
                        index = j;
                    }
                }
                break;
                
            case 7:
                min = old_database[i].employment_form;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].employment_form < min){
                        min = old_database[j].employment_form;
                        index = j;
                    }
                }
                break;
                
            case 8:
                min = old_database[i].job_status;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].job_status < min){
                        min = old_database[j].job_status;
                        index = j;
                    }
                }
                break;
                
            case 9:
                min = old_database[i].phone_no;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].phone_no < min){
                        min = old_database[j].phone_no;
                        index = j;
                    }
                }
                break;
                
            case 10:
                min = old_database[i].birth_day;
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].birth_day < min){
                        min = old_database[j].birth_day;
                        index = j;
                    }
                }
                break;
                
            case 11:
                min = to_string(getAge(stoi(old_database[i].birth_day), stoi(old_database[i].birth_month), stoi(old_database[i].birth_year)));
                
                for (j = i + 1; j < number_of_records; j++){
                    if (to_string(getAge(stoi(old_database[j].birth_day), stoi(old_database[j].birth_month), stoi(old_database[j].birth_year))) < min){
                        min = to_string(getAge(stoi(old_database[j].birth_day), stoi(old_database[j].birth_month), stoi(old_database[j].birth_year)));
                        index = j;
                    }
                }
                break;
                
            default:
                int k = choice - 12;
                
                min = old_database[i].user_defined_attributes_value[k];
                
                for (j = i + 1; j < number_of_records; j++){
                    if (old_database[j].user_defined_attributes_value[k] < min){
                        min = old_database[j].user_defined_attributes_value[k];
                        index = j;
                    }
                }
                
                break;
        }
        
        if (index != i){
            StaffRec temp;
            temp = old_database[i];
            old_database[i] = old_database[index];
            old_database[index] = temp;
        }
        
    }
    cout <<"Finish Sorting!"<< endl;
    
    cout << endl;
}
