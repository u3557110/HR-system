//
//  file.cpp
//  ENGG1340_course_project
//
//  Created by Leung King To on 27/4/2019.
//  Copyright © 2019 Leung King To. All rights reserved.
//

#include "file.hpp"

#include <iostream>
#include <fstream>

using namespace std;

// Function: export database to file
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int &capacity: the size of the current database
// Output: int: 0 = unsuccessful input. 1 = successful input.
int file_import(StaffRec * &database, int &number_of_records, int &capacity){
    
    //string filename = "test.txt";
    string filename;
    cout << "Please enter name of file to import: ";
    cin >> filename;
    
    ifstream input_file;
    input_file.open(filename.c_str());
    
    if (input_file.fail()){
        cout << "Error!" << endl;
        return 0;                   // return 0 for unsuccessful file input
    }
    
    string temp;
    getline(input_file, temp);      // read the first line of the file (field name)
    
    int i = 0;                      // (used for while loop below)
    int j = 0;                      // (used for while loop below)
    int number_of_attributes = 0;   // number of attributes the input file has
    
    while ( temp[i] != '\0'){       // find the number of attributes (field name) the input file has
        j = int(temp.find('\t', i));// attributes are seperated by '\t' in the input file
        i = ++j;                    // look for the next attribute
        number_of_attributes++;     // result is stored in 'number_of_attributes'
    }
    
    // initialize the first element of the database array
    database[0].number_of_user_defined_attributes = number_of_attributes - 10;                              // - find the number of user defined attributes
    database[0].user_defined_attributes = new string[database[0].number_of_user_defined_attributes];        // - create array to store the user defined attributes
                                                                                                            //   according the the number of user defined attributes
    database[0].user_defined_attributes_value = new string[database[0].number_of_user_defined_attributes];  // - create array to store the value of respective user defined attributes
                                                                                                            //   according the the number of user defined attributes
    
    for (int k = 0; k < database[0].number_of_user_defined_attributes; k++){                                // find the name of user user defined attributes
                                                                                                            // store the name into the array 'user_defined_attributes'
        int i = 0;
        int j = 0;
        
        number_of_attributes = 0;
        string user_defined_attributes;                                                                     // name of user defined attributes
        
        while ( temp[i] != '\0'){
            j = int(temp.find('\t', i));                                                                    // user defined attributes are seperated by '\t' in the input file
            if (number_of_attributes == k + 10){                                                            // - name of the user defined attributes are placed at the back,
                //cout << "temp.substr(i, j - i) = " << temp.substr(i, j - i) + " " << endl;                //   just befind the name of the default attributes
                user_defined_attributes = temp.substr(i, j - i);                                            // name of user defined attributes is found accordingly
            }
            i = ++j;                                                                                        // look for the name of the next user defined attribute
            number_of_attributes++;
        }
        
        database[0].user_defined_attributes[k] = user_defined_attributes;                                   // names of user defined attributes are stored into specific array
    }
    
    //cout << "database[0].user_defined_attributes[0] = " << database[0].user_defined_attributes[0] << endl;
    //cout << "database[0].user_defined_attributes[1] = " << database[0].user_defined_attributes[1] << endl;
    
    int k = number_of_records;
    
    while(getline(input_file, temp)){                                                                       // store the value of all attribues in respective place
        
        int i = 0;
        int j = 0;
        
        if (k >= capacity)                                                                                  // enlarge the database if necessary
            grow_array(database, capacity, 3);
        
        j = int(temp.find('\t', i));                                                                        // import the staff number
        database[k].staff_no = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the first name
        database[k].first_name = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the last name
        database[k].last_name = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // improt the gender
        database[k].gender = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the job title
        database[k].job_title = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the salary
        database[k].salary = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the employment form
        database[k].employment_form = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the job status
        database[k].job_status = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the phone number
        database[k].phone_no = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));                                                                        // import the date of birth
        string date_of_birth = temp.substr(i, j - i);
        database[k].birth_day = date_of_birth.substr(0,2);
        database[k].birth_month = date_of_birth.substr(3,2);
        database[k].birth_year = date_of_birth.substr(6,4);
        //cout << temp.substr(i, j - i) << endl;
        i = ++j;
        
        if (k == 0){                                                                                        // if there is no record in the database
            for (int n = 0; n < database[k].number_of_user_defined_attributes; n++){                        // just import the value of self defined attribues
                j = int(temp.find('\t', i));
                database[k].user_defined_attributes_value[n] = temp.substr(i, j - i);
                i = ++j;
            }
        }
        
        //cout << "database[0].user_defined_attributes[0] = " << database[0].user_defined_attributes[0] << endl;
        //cout << "database[0].user_defined_attributes[1] = " << database[0].user_defined_attributes[1] << endl;
        
        if (k != 0){                                                                                        // if there are some records in the database
                                                                                                            // initialize the element according to the first element in the databas
            database[k].number_of_user_defined_attributes = database[0].number_of_user_defined_attributes;  // set the number of user defined attributes
            database[k].user_defined_attributes = database[0].user_defined_attributes;                      // set the name of user defined attributes
            database[k].user_defined_attributes_value = new string[database[0].number_of_user_defined_attributes];
            
            for (int n = 0; n < database[k].number_of_user_defined_attributes; n++){                        // import the value of the self defined attribues
                j = int(temp.find('\t', i));
                database[k].user_defined_attributes_value[n] = temp.substr(i, j - i);
                i = ++j;
            }
        }
        
        k++;
        number_of_records++;                                                                                // update the numer of total records in the database
    }
    
    cout << "System Message: File test.txt is successfully imported!" << endl;
    cout << endl;
    
    input_file.close();
    
    return 1;                                                                                               // return 1 for successful file input
}

// Function: import database from file
// Input: StaffRec database[]: the address pointing to the database
//        int &number_of_records: number of records the database has
// Output: int: 0 = unsuccessful output. 1 = successful output.
int file_export(StaffRec database[], int number_of_records){
    
    //string filename = "test.txt";
    
    string filename;
    cout << "Please enter name of file to export: ";
    cin >> filename;
    
    ofstream output_file;
    output_file.open(filename.c_str());
    
    if (output_file.fail()){
        cout << "Error." << endl;
        return 0;                                                                                           // return 0 for unsuccessful file output
    }
                                                                                                            // export the first line of the file
    output_file << "Staff No.\t";                                                                           // export the name of default attributes
    output_file << "First Name\t";
    output_file << "Surname\t";
    output_file << "Gender\t";
    output_file << "Job Title\t";
    output_file << "Salary\t";
    output_file << "Form\t";
    output_file << "Status\t";
    output_file << "Phone No.\t";
    output_file << "Date of Birth\t";
    
    for (int j = 0; j < database[0].number_of_user_defined_attributes; j++)                                 // export the name of user defined attributes
        output_file << database[0].user_defined_attributes[j] + "\t";
    
    output_file << "\n";
    
    for (int i = 0; i < number_of_records; i++){                                                            // export the value of default attributes
        
        output_file << database[i].staff_no << "\t";
        output_file << database[i].first_name << "\t";
        output_file << database[i].last_name << "\t";
        output_file << database[i].gender << "\t";
        output_file << database[i].job_title << "\t";
        output_file << database[i].salary << "\t";
        output_file << database[i].employment_form << "\t";
        output_file << database[i].job_status << "\t";
        output_file << database[i].phone_no << "\t";
        output_file << database[i].birth_day + "-" + database[i].birth_month + "-" + database[i].birth_year<< "\t";
        
        for (int j = 0; j < database[i].number_of_user_defined_attributes; j++)                             // export the value of user defined attributes
            output_file << database[i].user_defined_attributes_value[j] + "\t";
        
        output_file << "\n";
    }
    
    cout << "File is Successfully Exported!" << endl;
    cout << endl;
    
    output_file.close();
    
    return 1;                                                                                               // return 1 for successful file output
}

// Function: enlarge the database if it is too small to add new record
// Input: StaffRec * &database: the address pointing to the database
//        int &capacity: the size of the current database, before incrementation
//        int increment: size of the incrementation
// Output: NULL
void grow_array(StaffRec * &old_database, int &capacity, int increment){
    
    StaffRec * new_database = new StaffRec[capacity + increment];                                           // create a new array with new size
    
    for (int i = 0; i < capacity; i++)                                                                      // copy element from old database to new database
        new_database[i] = old_database[i];
    
    delete [] old_database;                                                                                 // free memory space
    old_database = new_database;                                                                            // update the memory location of old database to new database
    
    capacity += increment;                                                                                  // update the size of capacity
    
    cout << "System Message: Capacity of database has been enlarged to " << capacity << "!" << endl;
    
}
