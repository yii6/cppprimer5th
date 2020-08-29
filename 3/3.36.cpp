/*Author
	whulinus 1034765650@qq.com
Program
	compare two arrays whether they are equal, compare two vectors. 
History
	version 1.0
	2016.5.19
*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int arr1[]= {1,2},arr2[]= {1,2};
    int *b1=arr1,*e1=end(arr1);
    int *b2=arr2,*e2=end(arr2);
    auto n=e1-b1;
    if(n==(e2-b2)) {
        while(n--)
            if(arr1[n]!=arr2[n]) {
                cout<<"array not equal!"<<endl;
                break;
            }
        if(arr1[0]==arr2[0]&&n==-1)
            cout<<"array equal!"<<endl;
    }
    else
        cout<<"array length not equal!"<<endl;
    vector<int> vec1{1,2,3},vec2{1,2,4};
    if(vec2==vec1)
        cout<<"vector  equal!"<<endl;
    else
        cout<<"vector  not equal!"<<endl;
    return 0;
}
