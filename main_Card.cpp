/*
PIC 10B Homework 4, bank_account_demo
Author: Matthew Napoli
UID: 005690610
Discussion Section: 1A
Date: 02/06/2023
*/

#include "Card.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

int main()
{
    startUp();
    vector<Card*> wallet;
    int cardChoice = -1;
    while(cardChoice != 0)
    {
        cout << "Card type : ";
        cin >> cardChoice;
        cin.ignore();
        cout << endl;
        if(cardChoice == 1)
        {
            string instit_for_input;
            string name_for_input;
            string exp_date_for_input;
            cout << "Intstitution name : ";
            getline(cin,instit_for_input);
            cout << "Card holder name : ";
            getline(cin,name_for_input);
            cout << "Expiration date mmddyyyy (0 if none) : ";
            cin >> exp_date_for_input;
            cin.ignore();
            cout << endl << endl;
            wallet.push_back(new Card(instit_for_input,name_for_input, exp_date_for_input));
        } else if (cardChoice == 2)
        {
            string instit_for_input;
            string name_for_input;
            string exp_date_for_input;
            int id_number;
            string d_o_birth;
            cout << "Intstitution name : ";
            getline(cin,instit_for_input);
            cout << "Card holder name : ";
            getline(cin,name_for_input);
            cout << "Expiration date mmddyyyy (0 if none) : ";
            cin >> exp_date_for_input;
            cin.ignore();
            cout << "ID Number : ";
            cin >> id_number;
            cin.ignore();
            cout << "DOB mmddyyyy (0 if not listed) : ";
            cin >> d_o_birth;
            cin.ignore();
            cout << endl << endl;
            wallet.push_back(new IDCard(Card(instit_for_input,name_for_input, exp_date_for_input),id_number,d_o_birth));
        } else if(cardChoice == 3)
        {
            string instit_for_input;
            string name_for_input;
            string exp_date_for_input;
            int acc_number;
            int security_pin_number;
            cout << "Intstitution name : ";
            getline(cin,instit_for_input);
            cout << "Card holder name : ";
            getline(cin,name_for_input);
            cout << "Expiration date mmddyyyy (0 if none) : ";
            cin >> exp_date_for_input;
            cin.ignore();
            cout << "Account number : ";
            cin >> acc_number;
            cin.ignore();
            cout << "Card Security Code : ";
            cin >> security_pin_number;
            cin.ignore();
            cout << endl << endl;
            wallet.push_back(new BankCard(Card(instit_for_input,name_for_input, exp_date_for_input),acc_number,security_pin_number));
        }else if(cardChoice != 0)
        {
            cout << "ERROR: WRONG INPUT!" << endl << endl;
        }
    }
    
    struct
    {
        bool operator()(Card* a, Card* b) const {
            string betterdate_a = a->get_exp_date().substr(4,4) + a->get_exp_date().substr(0,4);
            string betterdate_b = b->get_exp_date().substr(4,4) + b->get_exp_date().substr(0,4);
            return (stoi(betterdate_a) < stoi(betterdate_b));
        }
    }
    customLess;
    
    std::sort(wallet.begin(), wallet.end(), customLess);
    for(int i = wallet.size()-1; i >= 0; i--)
    {
        wallet[i]->printCard(*(wallet[i]));
    }
    return 0;
}
