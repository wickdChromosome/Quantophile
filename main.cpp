/*
Yahoo text data downloader, cleaner with ncurses interface
*/

//Include needed libs&headers
#include <iostream>
#include dl_cl_stock.h
#include getpath.h
#include mainmenu_init.h
#include m_stock_input.h
#include f_stock_input.h
#include all_stock_input.h
#include archive_stock.h


int main(){

//declare namespace, variables
using namespace std;
int lvl1_choice;
bool back = false;


//Print version, etc
cout << "Quantophile V0.1" << endl;

//set basic path by asking prompt if first startup
getpath();

//print main menu screen

lvl1_choice = mainmenu_init();

do {
if (lvl1_choice == 1){
    m_stock_input(); //download & clean data for inputted list of stock names

}else if (lvl1_choice == 2){
    f_stock_input(); //download & clean data for input file of stock names

}else if (lvl1_choice == 3){
    all_stock_input(); //download & clean all yahoo data for the longest period of time possible(lots of stuff)

}else if (lvl1_choice == 4){
    archive_stock(); //keep library of stock data for some type of stock
    
}else if (lvl1_choice == 5){
    back = true;
    
}else{
    cout << 'Please enter a valid choice' << endl;
}

}while(back == false);
}
        
