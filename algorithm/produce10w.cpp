#define LENGTH 10000
#include <time.h>
#include<stdlib.h>
#include <vector>
//#include<iostream>
#include<fstream>
using namespace std;

// 原数组
vector<int> oldArray;
// 打乱后的数组
vector<int> newArray;

/**
 * 将数组随机打乱
 */
void RandomArray(vector<int>oldArray, vector<int> &newArray) {
    // 随机打乱
    for (int i=LENGTH; i>0; i--) {
        srand(unsigned(time(NULL)));
        // 选中的随机下标
        int index = rand()%i;
        // 根据选中的下标将原数组选中的元素push到新数组
        newArray.push_back(oldArray[index]);
        // 将原数组中选中的元素剔除
        oldArray.erase(oldArray.begin()+index);
    }
}

/**
 * 打印数组
 */
void Print() {
//    cout<<"原数组：";
//    for (vector<int>::iterator it = oldArray.begin() ; it!=oldArray.end() ; it++) {
//        cout<<*it<<" ";
//    }
	ofstream out("data.txt");
	if (out.is_open()){
		for (vector<int>::iterator it = newArray.begin() ; it!=newArray.end() ; it++) {
        out<<*it;
        out.close(); 
    }
	}
   // cout<<endl<<"打乱后的数组：";

}

int main() {
    // 初始化原数组
    for(int i=0; i<LENGTH ;i++)
        oldArray.push_back(i);
    // 打乱
    RandomArray(oldArray, newArray);
    // 打印结果
    Print();
    return 0;
}

