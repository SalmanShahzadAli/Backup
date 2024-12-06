// this module will handle emails sent to users 
#include <iostream>
#include <cstdlib>

void sendEmail(const std::string& email) {
    std::string command = "echo 'This is a test email.' | mail -s 'Test Email' " + email; 
    system(command.c_str());
}

int main() {
    std::string userEmail;
    std::cout << "Enter your email address: ";
    std::cin >> userEmail;

    sendEmail(userEmail); // Send the email

    return 0;
}