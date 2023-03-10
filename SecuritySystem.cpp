#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    int a, i = 0;
    string text, old, psswd1, psswd2, pass, name, psswd0, age, user, word, word1;
    string creds[2], cp[2];

    cout << "\n\nSecurity System"
         << endl;
    cout << "----------------------------------------------------------" << endl;
    cout << "\n1.) Register" << endl;
    cout << "\n2.) Login" << endl;
    cout << "\n3.) Change Password" << endl;
    cout << "\n4.) End" << endl;
    do
    {
        cout << endl;
        cout << "Choose One: " << endl;
        cin >> a;
        switch (a)
        {
        case 1:
        {
            cout << "\nRegister" << endl;
            cout << "---------------------------------------------" << endl;
            cout << "Please Enter username: " << endl;
            cin >> name;
            cout << "Please enter the password: " << endl;
            cin >> psswd0;
            cout << "Please Enter your age: " << endl;
            cin >> age;

            ofstream of1; // used to create a text file
            of1.open("file.txt");
            if (of1.is_open())
            {
                of1 << name << "\n"
                    << psswd0 << "\n"
                    << age << endl;
                cout << "Registration Successful" << endl;
            }
            break;
        }
        case 2:
        {
            i = 0;
            cout << "\nLogin" << endl;
            cout << "---------------------------------------------------" << endl;

            ifstream of2; // used to read the text file
            of2.open("file.txt");
            cout << "Please enter the username: " << endl;
            cin >> user;
            cout << "Please enter the password:" << endl;
            cin >> pass;

            if (of2.is_open())
            {
                while (of2.eof())
                {
                    while (getline(of2, text)) // used to read the file line by line
                    {
                        istringstream iss(text); // used to stream the string
                        iss >> word;
                        creds[i] = word;
                        i++;
                    }
                    if (creds[0] == user && pass == creds[1])
                    {
                        cout << "Login Successful" << endl;

                        cout << "Details: " << endl;

                        cout << "Username: " + name << endl;
                        cout << "Password: " + pass << endl;
                        cout << "Age: " + age << endl;
                    }
                    else
                    {
                        cout << endl;
                        cout << "Incorrect Credentials" << endl;
                        cout << "\n1.) Press 2 to login" << endl;
                        cout << "\n2.) Press 3 to Change Password" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 3:
        {
            i = 0;
            cout << "\nChange Password" << endl;

            ifstream of0;
            of0.open("file.txt");
            cout << "Enter the old password" << endl;
            cin >> old;
            if (of0.is_open())
            {
                while (of0.eof())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word;
                        cp[i] = word;
                        i++;
                    }
                    if (cp[1] == old)
                    {
                        of0.close();
                        ofstream of1;
                        if (of1.is_open())
                        {
                            cout << "Enter your new password:-" << endl;
                            cin >> psswd1;
                            cout << "Confirm your password:-" << endl;
                            cin >> psswd2;

                            if (psswd1 == psswd2)
                            {
                                of1 << cp[0] << endl;
                                of1 << psswd1 << endl;
                                cout << "Password Changed Successfully" << endl;
                            }
                            else
                            {
                                of1 << cp[0] << endl;
                                of1 << old;
                                cout << "Password not changed" << endl;
                            }
                        }
                    }
                    else
                    {
                        cout << "Please enter a valid password" << endl;
                        break;
                    }
                }
            }
            break;
        }
        case 4:
        {
            cout << "\nThank You for using the Security System" << endl;
            break;
        }
        default:
            cout << "\nPlease enter a valid option" << endl;
        }
    }
    while (a!=4);
    return 0;
    
}