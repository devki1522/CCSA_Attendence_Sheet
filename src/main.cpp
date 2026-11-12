#include "crow_include/crow.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace crow;


//helper functions
void sendFile(response& res, const string& filename, const string& contentType)
{
	ifstream in(filename);
	if (in) {
		ostringstream contents;
		contents << in.rdbuf();
		in.close();
		res.set_header("Content-Type", contentType);
		res.write(contents.str());
	} else {
		res.code = 500;
		res.write("Not Found.");
	}
	res.end();
}


int main(){

    crow::SimpleApp app;
    // load the welcome page and have links for attendees and admins
    CROW_ROUTE(app, "/")([]( response& res){
        sendFile(res, "public/index.html", "text/html");
    });

    // load the form and use the POST method to get the atttendee data.
    CROW_ROUTE(app, "/check-in").methods(HTTPMethod::GET, HTTPMethod::POST)
    ([]( request & req, response& res){
        if(req.method == HTTPMethod::GET){
            sendFile(res, "public/check-in.html", "text/html");
            return;
        }

        const auto form = req.get_body_params();
        const char* name = form.get("name");
        const char* studentNumber = form.get("studentNumber");
        const char* email = form.get("email");

        if (name == nullptr || studentNumber == nullptr || email == nullptr ||
        name[0] == '\0' || studentNumber[0] == '\0' || email[0] == '\0') {
        res.code = 400;
        res.write("Name, Student Number and Email are required.");
        } else {
        res.write("Check-in received. Thank you for attending.");
        }

    res.end();
        
    });

    CROW_ROUTE(app, "/health")([]{
        crow::json::wvalue response;
        response["status"] = "ok";
        return response;

    });


    app.port(27000).multithreaded().run();
    return 0;
    
}