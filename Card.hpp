/*
PIC 10B Homework 4, bank_account_demo
Author: Matthew Napoli
UID: 005690610
Discussion Section: 1A
Date: 02/06/2023
*/

#ifndef Card_hpp
#define Card_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>



using namespace std;

void startUp();

class Card
{
private:
    string instit;
    string name;
    string exp_date;
public:
    Card();
    Card(string instit_inp, string name_inp, string exp_date_inp);
    string get_instit() const;
    string get_name() const;
    string get_exp_date() const;
    void set_instit(string instit_new);
    void set_name(string name_new);
    void set_exp_date(string exp_date_new);
    virtual void printCard(Card& card_inp) const;
    Card getInput();
    };

class IDCard : public Card
{
private:
    int id_num;
    string d_o_b;
public:
    virtual void printCard(IDCard& card_inp) const;
    IDCard(Card card_deriv, int id_num_inp, string d_o_b_inp);
};

class BankCard : public Card
{
private:
    int acc_num;
    int security_pin;
public:
    BankCard(Card card_deriv, int acc_num_inp, int security_pin_inp);
    virtual void printCard(BankCard& card_inp) const;
};


#endif
