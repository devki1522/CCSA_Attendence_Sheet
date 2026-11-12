#include "crow_include/crow.h"
#include <iostream>

int main(){

    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "ATTENDENCE SERVICE IS ONLINE";
    });


    app.port(27000).multithreaded().run();
    return 0;
    
}