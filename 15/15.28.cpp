/*
Author
    whulinus 1034765650@qq.com
Program
    exercise 15.20
History
    version 1.0
    2016.8.4
*/
#include <iostream>
#include <vector>
#include <memory>
#include "Quote.h"
#include "Bulk_quote.h" 
using namespace std;
int main(int argc,char *argv[]) {
    vector<shared_ptr<Quote>> vsq;
    vector<Quote> vq;
    vq.push_back(Bulk_quote("isbn",50.4,19,0.2));
    vsq.push_back(make_shared<Bulk_quote>("isbn",50.4,19,0.2));
    double psum=0,sum=0;
    for(auto c:vq)
    	psum+=c.net_price(20);
    cout<<psum<<endl;
    for(auto c:vsq)
    	sum+=c->net_price(20);
    cout<<sum<<endl;
    return 0;
}
