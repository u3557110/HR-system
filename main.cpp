//
//  main.cpp
//  1340_project
//
//  Created by Toto Leung on 17/4/2019 and Kin on 23/4/2019.
//  Copyright © 2019 Toto Leung & Kin. All rights reserved.
//

#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

struct StaffRec {
    string staff_no;        //staff_number
    string first_name;      //First Name
    string last_name;       //Last Name
    string gender;          //Gender
    //string age;           //Age
    string job_title;       //Job Title
    string salary;          //Salary
    string employment_form; //Full time or part time
    string job_status;      //on leave or suspension from work
    string phone_no;        //Phone Number
    //string address;       //Address
    //string id_no;         //Id Card Number
    //string bank_no;       //Bank Account Number
    
    string birth_day;
    string birth_month;
    string birth_year;
    
    int number_of_user_defined_attributes = 0;
    
    string *user_defined_attributes;
    string *user_defined_attributes_value;
    
    //= new string[number_of_user_defined_attributes];
    
    
};

//-------------------------------------------------------------------------------------------------------------------

char show_menu();

int add_record(StaffRec database[], int &number_of_records);

void show_database(StaffRec * &database, int &number_of_records, int capacity);

void show_search_database(StaffRec * &database, int &number_of_records, int capacity, int &number_of_deletion, string * &id_of_deletion, int &number_of_edit, string * &id_of_edit);

char print_table(StaffRec database[], int number_of_records, int records_per_page, int n);

int file_import(StaffRec * &database, int &number_of_records, int &capacity);

int file_export(StaffRec database[], int number_of_records);

void grow_array(StaffRec * &database, int &capacity, int increment);

int getAge(int birth_date, int birth_month, int birth_year);

void edit_record(StaffRec database[], int index);

void delete_record(StaffRec * &database, int &number_of_records, int index, int capacity);

void search_record(StaffRec * &database, int &number_of_records, int capacity);

void search_match_string (StaffRec * &database, int &number_of_records, int capacity, char choice, string keyword);

void search_in_range (StaffRec * &database, int &number_of_records, int capacity);


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
                file_export(database, number_of_records);                       //export to file
                break;
            
            case '5':
                search_record(database, number_of_records, capacity);
                break;
            
            default:
            
                break;
        }
        user_input = show_menu();
    }
    
    cout << "bye bye!" << endl;
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
                cout << "temp.substr(i, j - i) = " << temp.substr(i, j - i) + " " << endl;
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
        
        cout << "database[0].user_defined_attributes[0] = " << database[0].user_defined_attributes[0] << endl;
        cout << "database[0].user_defined_attributes[1] = " << database[0].user_defined_attributes[1] << endl;
        
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

char show_menu(){
    
    char input;
    
    cout << "Welcome to Staff Management System." << endl;
    cout << "Please select:" << endl;
    cout << "1. Import Record" << endl;
    cout << "2. Show Record" << endl;
    cout << "3. Add Record" << endl;
    cout << "4. Export Record" << endl;
    cout << "5. Search Record" << endl;
    cout << "6. Sort Record" << endl;
    cout << "7. Setting" << endl;
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

void show_database(StaffRec * &database, int &number_of_records, int capacity){
    
    int choice;
    int records_per_page = 10;
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
    }
    
    //cout << endl;
}

void show_search_database(StaffRec * &database, int &number_of_records, int capacity, int &number_of_deletion, string * &id_of_deletion, int &number_of_edit, string * &id_of_edit){
    
    string choice;
    int records_per_page = 10;
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
    
    //cout << << endl;
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
    
    cout << endl << "Q = Quit. E = Edit. N = Next. P = Previous. D = Delete. Your Choce: ";
    cin >> user_input;
    
    return user_input;
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

int getAge(int birth_date, int birth_month, int birth_year){
    
    time_t current_time = time(0);
    tm* now = localtime(&current_time);
    
    int current_date = now -> tm_mday;
    int current_month = now -> tm_mon + 1;
    int current_year = now -> tm_year + 1900;
    
    // days of every month
    int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    
    if (birth_date > current_date) {
        current_date = current_date + month[birth_month - 1];
        current_month = current_month - 1;
    }
    
    if (birth_month > current_month) {
        current_year = current_year - 1;
        current_month = current_month + 12;
    }
    
    // calculate date, month, year
    // int calculated_date = current_date - birth_date;
    // int calculated_month = current_month - birth_month;
    int calculated_year = current_year - birth_year;
    
    return calculated_year;
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

void search_record(StaffRec * &old_database, int &number_of_records, int capacity){
    
    char choice;
    string keyword;
    
    cout << "Search/Delete Mode" << endl;
    cout << "1. Employee ID" << endl;
    cout << "2. Name" << endl;
    cout << "3. Age" << endl;
    cout << "4. Role" << endl;
    
    cout << endl << "Your Choice: " ;
    cin >> choice;
    
    switch (choice){
        case '1':
            cout << endl << "Enter Employee ID: " ;
            cin >> keyword;
            search_match_string(old_database, number_of_records, capacity, choice, keyword);
            break;
            
        case '4':
            cout << endl << "Enter Role: " ;
            cin >> keyword;
            search_match_string(old_database, number_of_records, capacity, choice, keyword);
            break;
    
    }
}

void search_match_string (StaffRec * &old_database, int &number_of_records, int capacity, char choice, string keyboard){
    
    StaffRec * search_result = new StaffRec[capacity];

    int * index = new int[capacity];
    string * id_of_deletion;
    string * id_of_edit;
    
    int number_of_deletion = 0;
    int number_of_edit = 0;
    
    int number_of_result = 0;
    
    if (choice == '1'){
        for(int i = 0; i < number_of_records; i++){
            if (old_database[i].staff_no == keyboard){
                search_result[number_of_result] = old_database[i];
                index[number_of_result] = i;
                number_of_result++;
            }
        }
    }
    
    if (choice == '4'){
        for(int i = 0; i < number_of_records; i++){
            if (old_database[i].job_title == keyboard){
                search_result[number_of_result] = old_database[i];
                index[number_of_result] = i;
                number_of_result++;
            }
        }
    }
    
    show_search_database(search_result, number_of_result, capacity, number_of_deletion, id_of_deletion, number_of_edit, id_of_edit);

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

void search_in_range (StaffRec * &database, int &number_of_records, int capacity){
}
