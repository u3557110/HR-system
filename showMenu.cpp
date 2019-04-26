//
//  showMenu.cpp
//  1340_project
//
//  Created by Toto Leung on 27/4/2019.
//  Copyright © 2019 Toto Leung. All rights reserved.
//

#include <iostream>

#include "showMenu.hpp"

using namespace std;

char show_menu(){
    
    char input;
    
    cout << "  _, ___  _, __, __,   _, _  _, _, _  _,  _, __, _, _ __, _, _ ___    _, , _  _, ___ __, _, _" << endl;
    cout << " (_   |  /_\\ |_  |_    |\\/| /_\\ |\\ | /_\\ / _ |_  |\\/| |_  |\\ |  |    (_  \\ | (_   |  |_  |\\/|" << endl;
    cout << " , )  |  | | |   |     |  | | | | \\| | | \\ / |   |  | |   | \\|  |    , )  \\| , )  |  |   |  |" << endl;
    cout << "  ~   ~  ~ ~ ~   ~     ~  ~ ~ ~ ~  ~ ~ ~  ~  ~~~ ~  ~ ~~~ ~  ~  ~     ~    )  ~   ~  ~~~ ~  ~" << endl;
    cout << "                                                                          ~'                 " << endl;
    
    for (int i = 0; i < 98; i++)
        cout << "=";
    
    cout << endl << endl;
    
    for (int i = 0; i < 98; i++)
        cout << "¯";
    
    cout << endl;
    
    cout << "||\t\t\t1. Import Record                                                                    ||" << endl;
    cout << "||\t\t\t2. Show Record                                                                      ||" << endl;
    cout << "||\t\t\t3. Add Record                                                                       ||" << endl;
    cout << "||\t\t\t4. Export Record                                                                    ||" << endl;
    cout << "||\t\t\t5. Search Record                                                                    ||" << endl;
    cout << "||\t\t\t6. Sort Record                                                                      ||" << endl;
    cout << "||\t\t\t7. Setting                                                                          ||" << endl;
    cout << "||\t\t\t0. Exit                                                                             ||" << endl;
    
    for (int i = 0; i < 98; i++)
        cout << "_";
    
    cout << endl << endl << "\t\t\tEnter Choice: ";
    
    cin >> input;
    
    cout << endl;
    
    return input;
    
}
