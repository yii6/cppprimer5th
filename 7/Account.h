/*Author
	whulinus 1034765650@qq.com
Program
	Account class.
History
	version 1.0
	2016.6.12
*/
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
struct Account {
        void calculate() {amount +=amount *interestRate ;}
        static double rate() {return interestRate;}
        static void rate(double);
    private:
        std::string owner;
        double amount;
        static constexpr double todayRate=3.13; 
        static double interestRate;
        static double initRate();
};
void Account::rate(double newRate) {
    interestRate=newRate;
}
double Account::initRate() {
    return todayRate;
}
double Account::interestRate=initRate(); 
#endif

