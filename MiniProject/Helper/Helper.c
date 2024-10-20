#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../Structs/AllStructures.h"

#define EMPPATH "../DataBase/employees.txt"
#define CUSPATH "../DataBase/customers.txt"
#define LOANPATH "../DataBase/loanDetails.txt"
#define COUNTERPATH "../DataBase/loanCounter.txt"
#define HISTORYPATH "../DataBase/TransHistory.txt"
#define FEEDBACKPATH "../DataBase/feedback.txt"

int main()
{
    FILE *f1 = fopen(CUSPATH, "rb+");
    FILE *f2 = fopen(EMPPATH, "rb+");
    FILE *f3 = fopen(LOANPATH, "rb+");
    FILE *f4 = fopen(COUNTERPATH, "rb");
    FILE *f5 = fopen(HISTORYPATH, "rb");
    FILE *f6 = fopen(FEEDBACKPATH, "rb");
    
    struct Customer customer;
    struct Employee employee;
    struct LoanDetails loanDetails;
    struct Counter ct;
    struct TransHistory th;
    struct FeedBack fb;

    fclose(f4);    
    
    printf("================ Customer ==================\n");
    rewind(f1);
    while(fread(&customer, sizeof(customer), 1, f1) > 0)
    {
        printf("Name: %s\n", customer.customerName);
        printf("Account Number: %d\n", customer.accountNumber);
        printf("Balance: %.2f\n", customer.balance);
        printf("Status: %d\n", customer.activeStatus);
        printf("password: %s\n", customer.password);
    }
    fclose(f1);


    printf("================ Employee ==================\n");
    rewind(f2);
    while(fread(&employee, sizeof(employee), 1, f2) > 0)
    {
        printf("Emp ID: %d\n", employee.empID);
        printf("FirstName: %s\n", employee.firstName);
        printf("LastName: %s\n", employee.lastName);
        printf("Role: %d\n", employee.role);
        printf("Password: %s\n", employee.password);
    }
    fclose(f2);


    printf("================ Loan Details ==================\n");
    rewind(f3);
    while(fread(&loanDetails, sizeof(loanDetails), 1, f3) > 0)
    {
        printf("Emp ID: %d\n", loanDetails.empID);
        printf("Acc No: %d\n", loanDetails.accountNumber);
        printf("Loan Amount: %d\n", loanDetails.loanAmount);
        printf("Status: %d\n", loanDetails.status);
        printf("Loan ID: %d\n", loanDetails.loanID);
        printf("=======================\n");
    }
    fclose(f3);

    printf("================ Transaction History ==================\n");
    rewind(f5);
    while(fread(&th, sizeof(th), 1, f5) > 0)
    {
        printf("%d\n", th.acc_no);
        printf("%s\n", th.hist);
        printf("=======================\n");        
    }
    fclose(f5);

    printf("\n================ Feedback ==============\n");
    rewind(f6);
    while(fread(&fb, sizeof(fb), 1, f6) > 0)
    {
        printf("%s\n", fb.feedback);
    } 
    fclose(f6);

    return 0;
}