/*Author
	whulinus 1034765650@qq.com
Program
	change numeric socres to letter grades by using conditional operator.
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
        lettergrade=grade<60?scores[0]:scores[(grade-50)/10];
        lettergrade+=grade<60||grade==100?"":
                    grade%10<3?"-":
                    grade%10>7?"+":"";
        cout<<lettergrade<<endl;
    }
    return 0;
}
