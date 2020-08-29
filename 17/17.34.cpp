/*Author
 * 	whulinus 1034765650@qq.com
 *Program
 * 	show how to use operators
 *History
 *	ver 1.0 2016.10.1
 */
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main(int argc,char *argv[]) {
    cout<<boolalpha<<true<<" "<<false<<" "
        <<noboolalpha<<true<<" "<<false<<endl;
    cout<<showbase<<oct<<1024<<" "<<hex<<uppercase<<1024<<" "<<nouppercase<<1024<<" "<<flush
        <<noshowbase<<oct<<1024<<" "<<hex<<1024<<dec<<ends;
    cout<<setprecision(8)<<showpoint<<showpos<<100.0<<" "<<unitbuf
        <<noshowpoint<<noshowpos<<100.0<<setbase(8)<<" "<<63<<dec<<ends;
    double d=-314.159265433;
    cout.precision(8);
    cout<<nounitbuf<<left<<setw(23)<<setfill('#')<<"precision:"<<cout.precision()
        <<"\n"<<d<<"\n"
        <<right<<setw(22)<<scientific<<d<<"\n"
        <<internal<<setw(21)<<fixed<<d<<"\n";
    cout<<setw(20)<<hexfloat<<d<<setfill(' ')<<defaultfloat<<endl;
    ifstream cin("17.20.txt"),in("17.34.txt");
    char c;
    while(cin>>c)
        cout<<c;
    cout<<endl;
    in>>noskipws;
    while(in>>c)
        cout<<c;
    cout<<endl;
}
