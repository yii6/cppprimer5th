#include <iostream>
using namespace std;
#include "Sales_data.h"
int main() {
    Sales_data total,temp;
    double price;
    if(cin>>total.bookNo>>total.quantity_sold>>price) {
        int count_quantity=1;
        while(cin>>temp.bookNo>>temp.quantity_sold>>price) {
            if(temp.bookNo==total.bookNo)
                count_quantity++;
            else {
                cout <<total.bookNo<<" "<<count_quantity<<endl;
                total.bookNo=temp.bookNo;
                count_quantity=1;
            }
        }
        cout <<total.bookNo<<" "<<count_quantity<<endl;
        return 0;
    }
    else {
        cerr <<"No data!"<<endl;
        return -1;
    }
}

