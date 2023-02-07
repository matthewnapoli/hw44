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

void startUp() //compartmentalizing the startup console out
{
    cout << "********************" << endl;
    cout << "*  Wallet Printer! *" << endl;
    cout << "********************" << endl << endl;
    cout << "Print Cards by selecting the type (0 when done) :" << endl << endl;
    cout << "1. Basic Card" << endl;
    cout << "2. ID Card" << endl;
    cout << "3. Bank Card" << endl << endl;
}

Card::Card() //default constructor
{
    instit = "";
    name = "";
    exp_date = -1;
}

Card::Card(string instit_inp, string name_inp, string exp_date_inp) //initializer constructor
{
    instit = instit_inp;
    name = name_inp;
    if(exp_date_inp != "0")
    {
        exp_date = exp_date_inp;
    }
    else
    {
        exp_date = "00000000";
    }
}

void Card::printCard(Card& card_inp) const
{
    cout << " " << setfill('-') << setw(47) << "-" <<  endl << setw(0) << setfill(' ');
    cout << "|" << endl;
    cout << "| " << instit << endl;
    cout << "|" << right << setw(13) << "name : " << setw(0) << name << endl;
    if(exp_date != "00000000")
    {
        cout << "|" << setw(13) << "exp : " << setw(0) << exp_date.substr(0,2) << "/" << exp_date.substr(2,2) << "/" << exp_date.substr(4,4) << endl;
    } else
    {
        cout << "|" << setw(13) << "exp  : " << setw(0) << "N/A." << endl;
    }
    cout << "|" << endl;
}


string Card::get_instit() const{
    return instit;
}

string Card::get_name() const{
    return name;
}

string Card::get_exp_date() const{
    return exp_date;
}

void Card::set_instit(string instit_new){
    instit = instit_new;
}

void Card::set_name(string name_new){
    name = name_new;
}
void Card::set_exp_date(string exp_date_new){
    exp_date = exp_date_new;
}

IDCard::IDCard(Card card_deriv, int id_num_inp, string d_o_b_inp)
{
    set_instit(card_deriv.get_instit());
    set_name(card_deriv.get_name());
    set_exp_date(card_deriv.get_exp_date());
    id_num = id_num_inp;
    d_o_b = d_o_b_inp;
}

void IDCard::printCard(IDCard& card_inp) const
{
    Card::printCard(card_inp);
    cout << "|" << right << setw(13) << "ID# : " << setw(0) << id_num << endl;
    if(d_o_b != "0")
    {
        cout << "|" << setw(13) << "DOB : " << setw(0) << d_o_b.substr(0,2) << "/" << d_o_b.substr(2,2) << "/" << d_o_b.substr(4,4) << endl;
    } else
    {
        cout << "|" << setw(13) << "DOB  : " << setw(0) << "N/A." << endl;
    }
    cout << "|" << endl;
}


BankCard::BankCard(Card card_deriv, int acc_num_inp, int security_pin_inp)
{
    set_instit(card_deriv.get_instit());
    set_name(card_deriv.get_name());
    set_exp_date(card_deriv.get_exp_date());
    acc_num = acc_num_inp;
    security_pin = security_pin_inp;
}


void BankCard::printCard(BankCard& card_inp) const
{
    Card::printCard(card_inp);
    cout << "|" << right << setw(13) << "Account# : " << setw(0) << acc_num;
    cout << "|" << right << setw(13) << "CSC : " << setw(0) << security_pin;
    cout << "|" << endl;
}

