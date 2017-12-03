/*
--------------------------------------------------------------------------------
See LICENSE.txt for intellectual propery claims
See REFERENCE.txt for function input/output variable & other reference
--------------------------------------------------------------------------------
FUNCTION:
Pulls down data for a stock for an array of intervals.
===============================================================================
*/

//IMPORT LIBS
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <logger.h>

//IMPORT MYSQL LIBS
///////////////////////////////////////////////////////////////////////////////
#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

using namespace std


class dbase 
{
  
    //IDENTIFIERS FOR ITEM DATA
    ///////////////////////////////////////////////////////////////////////////////
    string dbCall;
    string item; 
    string dataType;
    string api;
    int startingYear = 0;
    int startingMonth = 0;
    int startingWeek = 0;
    int startingDay = 0;
    int startingHour = 0;
    int startingMinute = 0;
    int startingSecond = 0;

    public:

        //INITIALIZE MYSQL SOCKET
        ///////////////////////////////////////////////////////////////////////////////
        int exec (dbCall) 
        {
            
            cout << endl;
            cout << "Executing " << dbCall << endl;

            try {
                
                sql::Driver *driver;
                sql::Connection *con;
                sql::Statement *stmt;
                sql::ResultSet *res;

                /* Create a connection */
                driver = get_driver_instance();
                con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
                /* Connect to the MySQL test database */
                con->setSchema("Quantophile");

                stmt = con->createStatement();
                res = stmt->executeQuery(dbCall);
                
                return res;
                /* 
                while (res->next()) {
           
                    cout << "\t... MySQL replies: ";
                    /* Access column data by alias or column name */
                    cout << res->getString("_message") << endl;
                    cout << "\t... MySQL says it again: ";
                    /* Access column data by numeric offset, 1 is the first column */
                    cout << res->getString(1) << endl;

                }
                */  
                
                delete res;
                delete stmt;
                delete con;

            } catch (sql::SQLException &e) {
                cout << "# ERR: SQLException in " << __FILE__;
                cout << "(" << __FUNCTION__ << ") on line " »
                    << __LINE__ << endl;
                cout << "# ERR: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            }

            cout << endl;

            return EXIT_SUCCESS;
    
        };

        //DOWNLOAD ITEM THROUGH API
        ///////////////////////////////////////////////////////////////////////////////
        int dl(api, item, startingYear, startingMonth, startingWeek, startingDay, startingHour, startingSecond){
        
            //INIT API
            ///////////////////////////////////////////////////////////////////////////////
            

            //MAKE API CALL FOR DATA FOR ITEMI
            ///////////////////////////////////////////////////////////////////////////////
             

            //RETURN ITEM DATA
            ///////////////////////////////////////////////////////////////////////////////
             



        
        };

        int getEpoch( startingYear, startingMonth, startingWeek, startingDay, startingHour, startingSecond ){
       
 
            //CONVERT STARTING YEAR TO EPOCHT
            ///////////////////////////////////////////////////////////////////////////////
            struct tm t = {0};  
            t.tm_year = startingYear;  
            t.tm_mon = startingMonth;
            t.tm_mday = startingDay;
            t.tm_hour = startingHour;
            t.tm_min = startingMinute;
            t.tm_sec = startingSecond;
            time_t timeSinceEpoch = mktime(&t);

            return timeSinceEpoch;

        }


        int useItem(api, item, startingYear, startingMonth, startingWeek, startingDay, startingHour, startingSecond)
        {

            //CONVERT STARTING YEAR TO EPOCHT
            ///////////////////////////////////////////////////////////////////////////////
            time = getEpoch( startingYear, startingMonth, startingWeek, startingDay, startingHour, startingSecond )

            //CHECK IF ITEM IN DATABASE
            ///////////////////////////////////////////////////////////////////////////////
            isPresent = exec("SELECT 1 FROM " << item << " LIMIT 1;");
            
            if (sPresent == 0) {
                
            }

            //QUERY MYSQL TO GET APITYPE FOR ITEM
            ///////////////////////////////////////////////////////////////////////////////
            api = exec("SELECT api FROM " << userid << ";" ); //query for api type for user

            //USE API TO PULL DOWN AVAILABLE DATA FOR ITEM
            /////////////////////////////////////////////////////////////////////////////// 
            dl(item, time); 
            logger_success("Refreshed stock data for " << item);
 
            return 0;

        };

        int getData(item, dataType, startingYear)
        {
            
            int time = getEpoch(startingYear);

            //DEFINE CALL TO MYSQL FOR DATA
            ///////////////////////////////////////////////////////////////////////////////
            string queryCall =  "SELECT " << dataType << " FROM  "<< item << " WHERE " 
                << " time <= " << time << ";";
       
            //MAKE CALL FOR DATA
            ///////////////////////////////////////////////////////////////////////////////
            int data = exec(queryCall);
            logger_success("Got data for " << item);

            return data;
        
        };


       


};
    


