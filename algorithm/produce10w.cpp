#define LENGTH 10000
#include <time.h>
#include<stdlib.h>
#include <vector>
//#include<iostream>
#include<fstream>
using namespace std;

// ԭ����
vector<int> oldArray;
// ���Һ������
vector<int> newArray;

/**
 * �������������
 */
void RandomArray(vector<int>oldArray, vector<int> &newArray) {
    // �������
    for (int i=LENGTH; i>0; i--) {
        srand(unsigned(time(NULL)));
        // ѡ�е�����±�
        int index = rand()%i;
        // ����ѡ�е��±꽫ԭ����ѡ�е�Ԫ��push��������
        newArray.push_back(oldArray[index]);
        // ��ԭ������ѡ�е�Ԫ���޳�
        oldArray.erase(oldArray.begin()+index);
    }
}

/**
 * ��ӡ����
 */
void Print() {
//    cout<<"ԭ���飺";
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
   // cout<<endl<<"���Һ�����飺";

}

int main() {
    // ��ʼ��ԭ����
    for(int i=0; i<LENGTH ;i++)
        oldArray.push_back(i);
    // ����
    RandomArray(oldArray, newArray);
    // ��ӡ���
    Print();
    return 0;
}

