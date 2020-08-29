#include <iostream>
#include <string>
using namespace std;
struct Sales_data {
    string bookNo;
    int quantity_sold;
    double revenue;
};
int main() {
    Sales_data temp;
    while(cin>>temp.bookNo>>temp.quantity_sold>>temp.revenue) {
        cout <<temp.bookNo<<" "<<temp.quantity_sold<<" "<<temp.revenue<<endl;
    }
    return 0;
}

