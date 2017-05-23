/*
Header file that asks user for path info for files or sets default
*/


#include <pwd.h>
#include <string>
#include <fstream>

int getpath(){
//Tell user path has to be set
cout << "The path to save files to must be set. The master folder will \n contain other folders, each for a different request" << endl;

//Devine vars
char answer;

//Get default user path on linux
mypasswd = getpwuid(myuid);
def_path = mypasswd->pw_dir;




return 0;
    
}
