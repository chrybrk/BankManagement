#include "include/core.hpp"

Bank::Bank()
{
};

void Bank::CreateAccount(const char* name, const char* address, unsigned int uid, bool employed)
{
    bank_detail_T* new_account = (bank_detail_T*)calloc(1, sizeof(struct BANK_DETAIL_STRUCT));

    new_account->name = name;
    new_account->address = address;
    new_account->employed = employed;
    new_account->uid = uid;
    new_account->amount = 0;

    m_details[m_index] = (bank_detail_T*)calloc(1, sizeof(struct BANK_DETAIL_STRUCT));
    m_index++;
}

void Bank::ShowDetails(unsigned int uid)
{
    bank_detail_T* element = get_account(uid);
    if (element)
    {
        const char* temp = "------ Account ------\n"
                           "-- Name: %s --\n"
                           "-- Address: %s --\n"
                           "-- Amount: %d --\n";
        printf(temp, element->name, element->address, element->amount);
    }
    else
    {
        printf("Account not found.");
        exit(139);
    }
}

void Bank::Deposit(unsigned int uid, unsigned long long int amount)
{
    if (amount <= MAX_DEPOSIT)
    {
        bank_detail_T* element = get_account(uid);
        if (element)
            element->amount += amount;
    }
}

void Bank::Withdraw(unsigned int uid, unsigned long long int amount)
{
    if (amount <= MAX_WITHDRAW)
    {
        bank_detail_T* element = get_account(uid);
        if (element)
            element->amount -= amount;
    }
}

void Bank::SearchByName(const char* keyword)
{

}

void Bank::SearchByUID(unsigned int uid)
{

}

bank_detail_T* Bank::get_account(unsigned int uid)
{
    for (int i = 0; i < m_index; i++)
    {
        bank_detail_T* element = (bank_detail_T*)m_details[i];
        if (element->uid == uid)
            return element;
    }

    return nullptr;
}

int main()
{
    Bank* test = (Bank*)calloc(1, sizeof(class Bank));
    test->CreateAccount("test", "test", 12, false);
}
