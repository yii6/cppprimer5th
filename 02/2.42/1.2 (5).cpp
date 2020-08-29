#include <iostream>
using namespace std;
#include "Sales_data.h"
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
                if(total.quantity_sold)
                    cout <<total.bookNo<<" "<<total.quantity_sold<<" "<<total.revenue/total.quantity_sold<<endl;
                else
                    cout <<total.bookNo<<" "<<total.quantity_sold<<" "<<"No sales!"<<endl;
                total.bookNo=temp.bookNo;
                total.quantity_sold=temp.quantity_sold;
                total.revenue=temp.quantity_sold*price;
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
