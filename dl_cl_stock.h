/*
downloads and cleans up yahoo stock input
*/

#include <iostream>
#include <fstream>
#include dl_stock.h
#include cl_stock.h

using namespace std;


//Define function
int dl_cl_stock(stock, logfile){
    
    //download data from yahoo
    try{
        d_data = dl_stock(stock);
        logfile << "Downloading " << stockname << " successful" << endl;
        
    }catch(...){
        logfile << "Downloading " << stockname << " failed, skipping.. \n";
        cout <<  "Downloading " << stockname << " failed, skipping.. " << endl;
        return 0;
        
    };
    
    
    //feed data into cleaning function
    try{
    c_data = cl_stock(d_data);
    
        
    }catch(...){
        logfile << "Cleaning " << stockname << " failed \n";
        cout <<  "Cleaning " << stockname << " failed " << endl;
        return 0;
        
    };
    
    //spit cleaned data out
    return(c_data);
    
    
    
    ofstream myfile;
 logfile.open ("example.txt");
  logfile << "Writing this to a file.\n";
  logfile.close();
  return 0;
    
    
    
}
