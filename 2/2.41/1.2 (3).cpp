#include <iostream>
#include <string>
using namespace std;
struct Sales_data {
    string bookNo;
    int quantity_sold;
    double revenue;
};
int main() {
    Sales_data total,temp;
    double price;
    if(cin>>total.bookNo>>total.quantity_sold>>price) {
        total.revenue=total.quantity_sold*price;
        while(cin>>temp.bookNo>>temp.quantity_sold>>price) {
            if(temp.bookNo==total.bookNo) {
                total.quantity_sold+=temp.quantity_sold;
                temp.revenue=temp.quantity_sold*price;
                total.revenue+=temp.revenue;
            }
            else {
                cerr <<"Data must refer to same ISBN!"<<endl;
                return -1;
            }
        }
        if(total.quantity_sold)
            cout <<total.bookNo<<" "<<total.quantity_sold<<" "<<total.revenue/total.quantity_sold<<endl;
        else
            cout <<total.bookNo<<" "<<total.quantity_sold<<" "<<"No sales!"<<endl;
        return 0;
    }
    else {
        cerr <<"No data!"<<endl;
        return -1;
    }
}

