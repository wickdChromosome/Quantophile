/*
--------------------------------------------------------------------------------
See LICENSE.txt for intellectual propery claims

See REFERENCE.txt for function input/output variable & other reference
--------------------------------------------------------------------------------

FUNCTION:
Manually enter stocks, then feed into dlcl function.
================================================================================
*/


//IMPORT LIBS
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include dl_cl_stock.h
using namespace std;

int m_stock_input(){
    
    //DECLARE VARS
    ////////////////////////////////////////////////////////////////////////////
    string index; //stock index string
    string line; //used to store line info from file
    string confirm; //resued to store confirmation question answers
    bool checker; //reused to exit loops
    checker = false;
    int interval; //stores data interval for stock
    int period; //stores number of days of data to dl
    
    //BEGIN MENU FOR CHOOSING STOCKS
    ////////////////////////////////////////////////////////////////////////////
    do {
        cout << "Please enter exact stock or option index" << endl;
        cin >> index;
        //open yahoo indexes file for reading
        index_file.open("yahoo_indexes.txt");
        
        //CHECK FOR INDEX IN LIST TO MAKE SURE ENTRY VALID
        ////////////////////////////////////////////////////////////////////////
        while (getline(infile, line)){
            istringstream iss(line);
            int a, b;
            
            if (line.find(index) != std::string::npos) { //find index in list
                cout << "Index found in list" << '\n';
                checker = true;
            }
            
            if (!(iss >> a >> b)) { break; } // error
        }
        
        //IF INDEX PASSES CHECK
        ////////////////////////////////////////////////////////////////////////
        if (checker == true){ //if index was found in list, get request info
            checker = false; //reuse checker
            
            do{
                cout << "What data interval(s) would you like to download (in seconds)?" << endl;
                cin >> interval;
                
                do{
                    cout << "You had entered " << interval << " seconds as data interval. Correct?(y/n)"
                    cin >> confirm;
                    
                    if (confirm == "n") {
                        cout << "Please try entering the interval again" << endl;
                    
                    }else if (confirm == "y"){ //interval accepted
                        
                        do{
                            cout << "How long of a period should the data span?"
                            cin >> period;
                            cout << "You had entered " << period << " seconds as data interval. Correct?(y/n)"
                            cin >> confirm;
                            
                            if (confirm == "n") {
                                cout << "Please try entering the interval again" << endl;
                                
                            else if (confirm == "y"){ //period accepted
                                dl_cl_stock(); //download and clean stock data
                                checker = true; //exit loops
                            }
                        }while(checker=false);
                    }
                }while(checker == false);
                
            }while(confirm != "y" || confirm != "n"); //only accept y or n as answer
        }while(checker == false);
            
            
            
        }else if (checker == false){ //if index input fails test
            cout << "Index seemingly not available on Yahoo" << endl;
        
        }
    }while (checker == false); // retry until user terminates inputs
}
