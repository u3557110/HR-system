//
//  structStaffRec.hpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#ifndef structStaffRec_hpp
#define structStaffRec_hpp

#include <stdio.h>

#include <iostream>
#include <fstream>

using namespace std;

struct StaffRec {
    string staff_no;        //staff_number
    string first_name;      //First Name
    string last_name;       //Last Name
    string gender;          //Gender
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
    
};

#endif /* structStaffRec_hpp */
