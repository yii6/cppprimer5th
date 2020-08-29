/*Author
	whulinus 1034765650@qq.com
Program
	the copy of vector and array.
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr[10],j=0,arr1[10];
    for(auto &i:arr) {
        i=j;
        j++;
    }
    for(int i=0; i<10; i++)
        arr1[i]=arr[i];
    vector<int> arrv,arrv1;
    for(int i=0; i<10; i++)
        arrv.push_back(i);
    arrv1=arrv;
    return 0;
}
