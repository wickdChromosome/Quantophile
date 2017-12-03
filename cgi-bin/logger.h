/*
--------------------------------------------------------------------------------
See LICENSE.txt for intellectual propery claims
See REFERENCE.txt for function input/output variable & other reference
--------------------------------------------------------------------------------
FUNCTION:
Logging function, formats, then dumps specified log strings to a log file
===============================================================================
*/

//IMPORT LIBS
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//SUCCESS LOGGING
///////////////////////////////////////////////////////////////////////////////
int success_log(string message) {
    
    ofstream logfile;
    logfile.open("journal.log");
    logfile << "[+] " + message;
    logfile.close();

    return 0;

}

//ERROR LOGGING
///////////////////////////////////////////////////////////////////////////////
int fail_log(string message) {
    
    ofstream logfile;
    logfile.open("journal.log");
    logfile << "[-] " + message;
    logfile.close();

    return 0;

}


