/*Author
	whulinus 1034765650@qq.com
Program
	change numeric socres to letter grades.
History
	version 1.0
	2016.5.10
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<int> grades{1,61,66,79,82,90,100};
    const vector<string> scores{"F","D","C","B","A","A++"};
    string lettergrade;
    for(auto grade:grades) {
        if(grade<60)
            lettergrade=scores[0];
        else if(grade==100)
            lettergrade=scores[5];
        else {
            if(grade<70)
                lettergrade=scores[1];
            else if(grade<80)
                lettergrade=scores[2];
            else if(grade<90)
                lettergrade=scores[3];
            else
                lettergrade=scores[4];
            if(grade%10<3)
                lettergrade+='-';
            if(grade%10>7)
                lettergrade+='+';
        }
        cout<<lettergrade<<endl;
    }
    return 0;
}
