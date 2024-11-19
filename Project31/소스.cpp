#include<cassert>
#include<cstdlib>
#include<iostream>
#include "bag.h"


int main(){
    cout << "이름 : 정재창   학번 : 2016508055" << endl;
    bag bag1;
    cout << "========================함수 실행 결과 출력========================" << endl;
    cout << "\nbag class 객체 bag1 생성후 insert 함수로 1~10까지 insert, show_contents함수로 출력"<< endl<<"bag1 : ";
    

    for (int i = 1;i < 11;i++) {
        bag1.insert(i);
    }
    bag1.show_contents();

    cout << "\n\nbag2 객체 생성 후 11~20까지 insert " << endl;
    bag bag2;
    for (int i = 11;i < 21;i++) {
        bag2.insert(i);
    }
    
    cout<< "bag2 : ";

    bag2.show_contents();
    

    cout << "\n\noperator 연산" << endl;
    
    cout << "bag1!=bag2? : ";
    if (bag1 != bag2) 
        cout << "두 객체는 다릅니다." << endl;
    
    else
        cout << "두 객체는 동일합니다." << endl;
    
    cout << "\nbag1== bag1? :";
    if (bag1 == bag1)
        cout << "두 객체는 동일합니다." << endl;
    else
        cout << "두 객체는 다릅니다." << endl;



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

    cout << "\n\ncount 함수로 값 20 갯수 리턴 " << endl;
    int count=bag1.count(20);

    cout << "20의 갯수 : " << count;
    


    cout << "\n\nerase_one()함수로 값 20 제거" << endl;
    bag1.erase_one(20);
    cout << "erase_one(20) = ";


    bag1.show_contents();
    int c = 0;
    c=bag1.count(20);

    cout << "\n20제거 후 20의 갯수 : ";
    cout << c;
    cout << "\n한번 더 제거 후 20의 갯수 : ";
    bag1.erase_one(20);
    c = bag1.count(20);

    cout << c;

    cout << "\n\ngrab으로 하나 리턴" << endl;
    c = bag1.grab();
    cout << "bag1.grab() : " ;
    cout << c;
  
    cout << "\n\n\nsort()함수를 이용하여 bag1을 버블정렬" << endl;
    bag1.sort();
    cout << "\n\nsort()로 정렬후 bag1 class 출력 : "<<endl;
    bag1.show_contents();
    
    cout << "\n\n\nbag3에 1~100까지 insert 후 sort()로 정렬\n" << endl;
    bag bag3;
    for (int i = 1;i < 101;i++) {
        bag3.insert(i);
    }
    cout << "bag3 : ";
    bag3.show_contents();
    cout << "\n\nsort 후 bag3 : ";
    bag3.sort();
    bag3.show_contents();
    cout << "\n\n\n=================종료===============\n\n\n";
    
    
    getchar();
    getchar();

    return 0;

}

