#include<cassert>
#include<cstdlib>
#include<iostream>
#include "bag.h"


int main(){
    cout << "�̸� : ����â   �й� : 2016508055" << endl;
    bag bag1;
    cout << "========================�Լ� ���� ��� ���========================" << endl;
    cout << "\nbag class ��ü bag1 ������ insert �Լ��� 1~10���� insert, show_contents�Լ��� ���"<< endl<<"bag1 : ";
    

    for (int i = 1;i < 11;i++) {
        bag1.insert(i);
    }
    bag1.show_contents();

    cout << "\n\nbag2 ��ü ���� �� 11~20���� insert " << endl;
    bag bag2;
    for (int i = 11;i < 21;i++) {
        bag2.insert(i);
    }
    
    cout<< "bag2 : ";

    bag2.show_contents();
    

    cout << "\n\noperator ����" << endl;
    
    cout << "bag1!=bag2? : ";
    if (bag1 != bag2) 
        cout << "�� ��ü�� �ٸ��ϴ�." << endl;
    
    else
        cout << "�� ��ü�� �����մϴ�." << endl;
    
    cout << "\nbag1== bag1? :";
    if (bag1 == bag1)
        cout << "�� ��ü�� �����մϴ�." << endl;
    else
        cout << "�� ��ü�� �ٸ��ϴ�." << endl;



    cout << "\nbag1+bag2 =";
    bag1 = bag1 + bag2;
    bag1.show_contents();
    cout << "\nbag2=bag \n bag2 :  ";
    bag2 = bag1;

 
 
    bag2.show_contents();
    cout << endl;

    cout << "bag1 += bag1 :";
    bag1 += bag1;
    bag1.show_contents();

    cout << "\n\ncount �Լ��� �� 20 ���� ���� " << endl;
    int count=bag1.count(20);

    cout << "20�� ���� : " << count;
    


    cout << "\n\nerase_one()�Լ��� �� 20 ����" << endl;
    bag1.erase_one(20);
    cout << "erase_one(20) = ";


    bag1.show_contents();
    int c = 0;
    c=bag1.count(20);

    cout << "\n20���� �� 20�� ���� : ";
    cout << c;
    cout << "\n�ѹ� �� ���� �� 20�� ���� : ";
    bag1.erase_one(20);
    c = bag1.count(20);

    cout << c;

    cout << "\n\ngrab���� �ϳ� ����" << endl;
    c = bag1.grab();
    cout << "bag1.grab() : " ;
    cout << c;
  
    cout << "\n\n\nsort()�Լ��� �̿��Ͽ� bag1�� ��������" << endl;
    bag1.sort();
    cout << "\n\nsort()�� ������ bag1 class ��� : "<<endl;
    bag1.show_contents();
    
    cout << "\n\n\nbag3�� 1~100���� insert �� sort()�� ����\n" << endl;
    bag bag3;
    for (int i = 1;i < 101;i++) {
        bag3.insert(i);
    }
    cout << "bag3 : ";
    bag3.show_contents();
    cout << "\n\nsort �� bag3 : ";
    bag3.sort();
    bag3.show_contents();
    cout << "\n\n\n=================����===============\n\n\n";
    
    
    getchar();
    getchar();

    return 0;

}

