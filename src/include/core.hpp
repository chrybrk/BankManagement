#pragma once

// - opening an account [done]
// - show account details [done]
// - deposit [done]
// - withdraw [done]
// - search
// - exit

#include <iostream>

#define MAX_ACCOUNT     1024
#define MAX_DEPOSIT     1000000
#define MAX_WITHDRAW    50000

typedef struct BANK_DETAIL_STRUCT
{
    const char* name;
    const char* address;
    unsigned int uid;
    bool employed;
    long long int amount;
} bank_detail_T;

class Bank
{
    public:
        // Create Bank
        Bank();

        /*
         * name: user name
         * address: user permanent address
         * uid: any type of valid id, like pan card or aadhar card number
        */
        void CreateAccount(const char* name, const char* address, unsigned int uid, bool employed);

        // uid: any type of valid id, like pan card or aadhar card number
        void ShowDetails(unsigned int uid);

        /*
         * uid: any type of valid id, like pan card or aadhar card number
         * amount: amount you want to deposit <= MAX_DEPOSIT
        */
        void Deposit(unsigned int uid, unsigned long long int amount);

        /*
         * uid: any type of valid id, like pan card or aadhar card number
         * amount: amount you want to withdraw <= MAX_WITHDRAW
        */
        void Withdraw(unsigned int uid, unsigned long long int amount);

        // search by names
        void SearchByName(const char* keyword);

        // search by uid
        void SearchByUID(unsigned int uid);
    private:
        unsigned int m_index = 0;
        bank_detail_T *m_details[MAX_ACCOUNT];

    private:
        bank_detail_T* get_account(unsigned int uid);
};
