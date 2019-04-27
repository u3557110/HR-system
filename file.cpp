//
//  file.cpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#include "file.hpp"

#include <iostream>
#include <fstream>

using namespace std;

int file_import(StaffRec * &database, int &number_of_records, int &capacity){
    
    string filename = "test.txt";
    
    ifstream input_file;
    input_file.open(filename.c_str());
    
    if (input_file.fail()){
        cout << "Error!" << endl;
        return 0;
    }
    
    string temp;
    getline(input_file, temp); //read the first line (field name)
    
    int i = 0;
    int j = 0;
    int number_of_attributes = 0;
    
    // this while loop is used to find the number of attributes (field name) a file has
    // result is stored in 'int number_of_attributes'
    while ( temp[i] != '\0'){
        j = int(temp.find('\t', i));
        i = ++j;
        number_of_attributes++;
    }
    
    //initialize the first element in the database array
    database[0].number_of_user_defined_attributes = number_of_attributes - 10;
    database[0].user_defined_attributes = new string[database[0].number_of_user_defined_attributes];
    database[0].user_defined_attributes_value = new string[database[0].number_of_user_defined_attributes];
    
    for (int k = 0; k < database[0].number_of_user_defined_attributes; k++){
        
        int i = 0;
        int j = 0;
        
        number_of_attributes = 0;
        string user_defined_attributes_value;
        
        while ( temp[i] != '\0'){
            j = int(temp.find('\t', i));
            if (number_of_attributes == k + 10){
                //cout << "temp.substr(i, j - i) = " << temp.substr(i, j - i) + " " << endl;
                user_defined_attributes_value = temp.substr(i, j - i);
            }
            i = ++j;
            number_of_attributes++;
        }
        
        database[0].user_defined_attributes[k] = user_defined_attributes_value;
    }
    
    //cout << "database[0].user_defined_attributes[0] = " << database[0].user_defined_attributes[0] << endl;
    //cout << "database[0].user_defined_attributes[1] = " << database[0].user_defined_attributes[1] << endl;
    
    int k = number_of_records;
    
    while(getline(input_file, temp)){
        
        int i = 0;
        int j = 0;
        
        if (k >= capacity)
            grow_array(database, capacity, 3);
        
        j = int(temp.find('\t', i));
        database[k].staff_no = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].first_name = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].last_name = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].gender = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].job_title = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].salary = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].employment_form = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].job_status = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        database[k].phone_no = temp.substr(i, j - i);
        i = ++j;
        
        j = int(temp.find('\t', i));
        string date_of_birth = temp.substr(i, j - i);
        database[k].birth_day = date_of_birth.substr(0,2);
        database[k].birth_month = date_of_birth.substr(3,2);
        database[k].birth_year = date_of_birth.substr(6,4);
        //cout << temp.substr(i, j - i) << endl;
        i = ++j;
        
        if (k == 0){
            for (int n = 0; n < database[k].number_of_user_defined_attributes; n++){
                j = int(temp.find('\t', i));
                database[k].user_defined_attributes_value[n] = temp.substr(i, j - i);
                i = ++j;
            }
        }
        
        //cout << "database[0].user_defined_attributes[0] = " << database[0].user_defined_attributes[0] << endl;
        //cout << "database[0].user_defined_attributes[1] = " << database[0].user_defined_attributes[1] << endl;
        
        if (k != 0){
            
            database[k].number_of_user_defined_attributes = database[0].number_of_user_defined_attributes;
            database[k].user_defined_attributes = database[0].user_defined_attributes;
            database[k].user_defined_attributes_value = new string[database[0].number_of_user_defined_attributes];
            
            for (int n = 0; n < database[k].number_of_user_defined_attributes; n++){
                j = int(temp.find('\t', i));
                database[k].user_defined_attributes_value[n] = temp.substr(i, j - i);
                i = ++j;
            }
        }
        
        k++;
        number_of_records++;
    }
    
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
    output_file << "Phone No.\t";
    output_file << "Date of Birth\t";
    
    for (int j = 0; j < database[0].number_of_user_defined_attributes; j++)
        output_file << database[0].user_defined_attributes[j] + "\t";
    
    output_file << "\n";
    
    for (int i = 0; i < number_of_records; i++){
        
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
        
        for (int j = 0; j < database[i].number_of_user_defined_attributes; j++)
            output_file << database[i].user_defined_attributes_value[j] + "\t";
        
        output_file << "\n";
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
    
}
