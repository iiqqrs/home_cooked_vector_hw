#include <iostream>
#include <string>
#include "MyVec.h"
#include "MyVec_malloc.h"

using namespace std;

void WithNewAndDelete(){
    cout <<"The following is with new and delete:" <<endl;
    MyVec<int> int_array(1);
    cout <<"Array Size :" <<int_array.size()<<endl;
    cout << "Pushing back with an integer 472" <<endl;
    int_array.add_to_end(472);
    cout <<"New array Size :" <<int_array.size()<<endl;
    cout << "Last element: " << int_array[int_array.size()-1] <<endl;
}

void WithMallocAndFree(){
    cout <<"The following is with Malloc and free:" <<endl;
    MyVec_2<int> int_array(1);
    cout <<"Array Size :" <<int_array.size()<<endl;
    cout << "Pushing back with an integer 472" <<endl;
    int_array.add_to_end(472);
    cout <<"New array Size :" <<int_array.size()<<endl;
    cout << "Last element: " << int_array[int_array.size()-1] <<endl;
}

int main(){
    WithNewAndDelete();
    WithMallocAndFree();
}