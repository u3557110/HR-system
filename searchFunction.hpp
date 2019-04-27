//
//  searchFunction.hpp
//  ENGG1340_course_project
//
//  Created by Leung King To on 27/4/2019.
//  Copyright © 2019 Leung King To. All rights reserved.
//

#ifndef searchFunction_hpp
#define searchFunction_hpp

#include <stdio.h>

#include "structStaffRec.hpp"

// Function: display the menu of search, let user to choose what to search
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
//        int records_per_page: number of records can be displayed each time
// Output: NULL
void search_record(StaffRec * &database, int &number_of_records, int capacity, int records_per_page);

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
void show_search_database(StaffRec * &database, int &number_of_records, int capacity, int &number_of_deletion, string * &id_of_deletion, int &number_of_edit, string * &id_of_edit, int records_per_page);

// Function: search records according to the input of range of value by user
// Input: StaffRec * &database: the address pointing to the database
//        int &number_of_records: number of records the database has
//        int capacity: size of the current database
//        char choice: searching criteria
//        string keyword: the lower bound value of range
//        string keyword_2: the upper bound value of range
//        int records_per_page: number of records can be displayed each time
// Output: NULL
void search_match_string (StaffRec * &database, int &number_of_records, int capacity, char choice, string keyword, string keyword_2, int records_per_page);

#endif /* searchFunction_hpp */
