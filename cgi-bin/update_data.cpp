/*
--------------------------------------------------------------------------------
See LICENSE.txt for intellectual propery claims
See REFERENCE.txt for function input/output variable & other reference
--------------------------------------------------------------------------------
FUNCTION:
Called by Quantophile cron. Pulls down new data into mysql database from  yahoo
finance, then cleans it up.
===============================================================================
*/


//IMPORT LIBS
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <clean_stocks.h>
#include <pull_stocks.h>
#include <read_stocks.h>
#include <logger.h>

using namespace std;


int main () {

    //WRITE TO LOGS
    ///////////////////////////////////////////////////////////////////////////////
    success_log("Started stock info update");

    //PULL IN ARRAY OF STOCKS TO BE UPDATED FROM DATABASE
    ///////////////////////////////////////////////////////////////////////////////
    string stock_list = read_stocks();
    int stock_list_len = stock_list.size();
    
    //PULL THEN CLEAN NEW STOCK INFO
    ///////////////////////////////////////////////////////////////////////////////
    for ( int stocknum = 0; stocknum <= stock_list_len; stocknum++ ) {
        
        //LOAD STOCK
        ////////////////////////////////////////////////////////////////////////
        string stock = stock_list_len[stocknum];

        //DETERMINE TRACKED INTERVALS FOR STOCK
        ////////////////////////////////////////////////////////////////////////
        int intervals = read_stock_intervals(stock);

        //DETERMINE LAST UPDATE DATE
        ///////////////////////////////////////////////////////////////////////
        int last_update = get_last_upgrade(stock);
        
        //DETERMINE IF UPDATE POSSIBLE
        ///////////////////////////////////////////////////////////////////////
        bool is_updatable = eval_update(stock, last_update, intervals);

        //IF DATA CAN'T BE ACQUIRED DUE TO YAHOO'S RESTRICTIONS
        ///////////////////////////////////////////////////////////////////
        if (is_updatable == False) {
           
            no_update_notify(stock, last_upgrade);
            logger.fail("Can't update data for " + stock);

        }

        //CLEAN NEW DATA, ADD INTO DB, UPDATE DATES 
        ///////////////////////////////////////////////////////////////////
        clean_stock(stock); 
        success_log("Cleaned data for " + stock);

    };

    success_log("Update finished.")
    return 0;

}
