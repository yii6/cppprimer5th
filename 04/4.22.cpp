/*Author 
	whulinus 1034765650@qq.com
Program
	print the final grade according to the scores.
History
	version 1.0
	2016.5.6
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> score{1,61,76,92};
    for(auto grade:score) {
        string finalgrade=(grade>90)?"high pass":
                          (grade>75)?"pass":
                          (grade>60)?"low pass":"fail";
        cout<<finalgrade<<endl;
    }
    for(auto grade:score) {
        string finalgrade;
        if(grade>90)
            finalgrade="high pass";
        else if(grade>75)
            finalgrade="pass";
        else if(grade>60)
            finalgrade="low pass";
        else
            finalgrade="fail";
        cout<<finalgrade<<endl;
    }
    return 0;
}
