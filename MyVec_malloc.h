#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class MyVec_2{
  public:
    MyVec_2(int size);
    ~MyVec_2();
    int size(); // Returns size
    //Overload [] operator
    T& operator[](int i);
    void add_to_end(T e);
    
  private:
    T* pointer;
    int vec_length;
    int nextIndex;
};


template<typename T>
MyVec_2<T>::MyVec_2(int size){
  pointer = (T*) malloc((size)*sizeof(T));
  //pointer = new T[size];
  vec_length = size;
  nextIndex = size +1;
}

template <typename T>
MyVec_2<T>::~MyVec_2() {
 free(pointer);
 //delete [] pointer;
} 

template<typename T>
int MyVec_2<T>::size(){
  return vec_length;
}

template <typename T>
T& MyVec_2<T>::operator[](int index){
    T *p2araynew;
    if (index >= vec_length) {
      p2araynew = (T *) malloc(vec_length+1*sizeof(T));
        //p2araynew = new T[index + 10];
        for (int i = 0; i < nextIndex; i++){
            p2araynew[i] = pointer[i];
        }
        for (int j = nextIndex; j < index + 10; j++){
            p2araynew[j] = 0;
        }
        vec_length = index + 10;
        free(p2araynew);
        //delete [] pointer;
        pointer = p2araynew;
    }
    if (index > nextIndex){
    nextIndex = index + 1;
    }
 return *(pointer + index);
} 


template<typename T>
void MyVec_2<T>::add_to_end(T e){
  T* placeholder = (T*)malloc((vec_length+1)*sizeof(T));;
  //T* placeholder = new T[vec_length + 1];
  for(int i = 0; i < vec_length; i++){
    placeholder[i] = pointer[i];
  }
  vec_length += 1;
  //free(placeholder);
  //delete[] pointer;
  pointer = placeholder;
  pointer[vec_length - 1] = e;
}