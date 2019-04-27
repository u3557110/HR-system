//
//  searchFunction.hpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#ifndef searchFunction_hpp
#define searchFunction_hpp

#include <stdio.h>

#include "structStaffRec.hpp"

void search_record(StaffRec * &database, int &number_of_records, int capacity, int records_per_page);

void search_match_string (StaffRec * &database, int &number_of_records, int capacity, char choice, string keyword, string keyword_2, int records_per_page);

void show_search_database(StaffRec * &database, int &number_of_records, int capacity, int &number_of_deletion, string * &id_of_deletion, int &number_of_edit, string * &id_of_edit, int records_per_page);

#endif /* searchFunction_hpp */
