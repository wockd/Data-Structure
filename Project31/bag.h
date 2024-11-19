#include<cassert>
#include<cstdlib>
#include<iostream>
#include "dnode.h"
using namespace std;

class bag {
public:
	typedef size_t size_type;
	typedef dnode::value_type value_type;

	bag();
	bag(const bag& source);
	~bag();

	bool erase_one(const value_type& target);
	value_type grab() const;
	void insert(const value_type& entry);
	void operator +=(const bag& addend);
	void operator =(const bag& source);
	bool operator ==(const bag& source);
	bool operator != (const bag& source);
	size_type size() const { return many_dnodes; }

	size_type count(const value_type& target) const;

	void show_contents();
	void sort();
private:
	dnode* head_ptr;
	size_type many_dnodes; //노드의 수

};


bag::bag() {
	//생성자
	//
	head_ptr = NULL;
	many_dnodes = 0;
};

bag::bag(const bag& source) {
	//복사생성자

	dnode* tail_ptr; //로컬로 변수로 노드에 대한 포인터 

	list_copy(source.head_ptr, head_ptr, tail_ptr);

	many_dnodes = source.many_dnodes;
}

bag::~bag() {
	//소멸자
	list_clear(head_ptr);

	many_dnodes = 0;
};
bool bag::operator ==(const bag& source) {
	//같다면 ture를 리턴
	if (this == &source)
		return true;
	else
		return false;

}


bool bag::erase_one(const value_type& target) {
	//노드 하나 제거해주는 함수
	dnode* target_ptr;//제거하고자 하는 값의 주소 확보용

	target_ptr = list_search(head_ptr, target);//주소 확보
	if (target_ptr == NULL)// NULL이라면 찾지 못하여 리턴
		return false;

	target_ptr->set_data(head_ptr->data());//값을 삭제가 아니라 헤드포인터로 넘겨줌
	list_head_remove(head_ptr);
	--many_dnodes;//노드 개수 줄이기

	return true;
}

bag::size_type bag::count(const value_type& target)const {
	//target 값이 몇개 있는지 세어주는 함수
	size_type answer = 0;
	const dnode* cursor;
	cursor = list_search(head_ptr, target);//커서가 target을 가리키게 함
	while (cursor != NULL) {//target을 찾았다면 answer를 1증가시킴 
		++answer;
		cursor = cursor->next();
		cursor = list_search(cursor, target);
	}
	return answer;
}

bag::value_type bag::grab() const {
	//랜덤으로 노드를 하나 골라 노드의 데이터를 리턴해주는 함수
	size_type i;
	const dnode* cursor;
	assert(size() > 0);
	i = (rand() % size()) + 1;//난수 생성
	cursor = list_locate(head_ptr, i);//난수 i를 주고 i 번째 노드를 찾음
	return cursor->data();

}
//연산자들
void bag::insert(const value_type& entry) {
	//entry를 하나 추가 하는 함수
	list_head_insert(head_ptr, entry);//헤드 노드에 인서트

	++many_dnodes;//추가된 노드 수 반영

}


bag operator +(const bag& b1, const bag& b2) {
	// bag class 끼리 더해주는 함수
	bag answer;
	answer += b1;
	answer += b2;
	return answer;

}
bool bag::operator != (const bag& source) {
	//다르다면 true 리턴
	if (this == &source)
		return false;
	else
		return true;
}

void bag::operator =(const bag& source) {
	//bag class의 대입연산자
	dnode* tail_ptr; //로컬 변수

	if (this == &source)// self - assignment 똑같은 오브젝트면 그냥 리턴 
		return;

	list_clear(head_ptr);//자신을 클리어
	many_dnodes = 0;
	list_copy(source.head_ptr, head_ptr, tail_ptr);//카피해서 복사본의 헤드와 테일 가져옴
	many_dnodes = source.many_dnodes;

}


void bag::operator +=(const bag& addend) {
	dnode* copy_head_ptr;
	dnode* copy_tail_ptr;

	if (addend.many_dnodes > 0) { //empty 인지 확인

		list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		copy_tail_ptr->set_next(head_ptr);
		head_ptr = copy_head_ptr;
		many_dnodes += addend.many_dnodes;

	}

}

void bag::show_contents() {
	//bag class 안의 노드의 데이터를 프린트 해주는 함수
	const dnode* cursor;
	for (cursor = head_ptr;cursor != NULL;cursor = cursor->next())
		cout << cursor->data() << ' ';


}




void bag::sort() {
	//bag 클래스 안의 노드들을 오름차순으로 버블 정렬하는 함수
	int i = 0; //리스트의 개수를 리턴 받을 변수
	i = list_length(head_ptr);
	int a = 0;
	for (int k = i - 1;k > 0;k--) { //리스트의 길이를 리턴 받아 n-1번 루프

		for (a = 0;a < k;a++) { //n-2번 루프
			dnode* left;
			dnode* right;
			value_type temp;
			// dnode* lTemp;
			 //dnode* rTemp;
			left = list_locate(head_ptr, a + 1);//인접한 두 노드 리턴
			right = list_locate(head_ptr, a + 2);

			if (left->data() > right->data()) {
				temp = left->data();
				left->set_data(right->data());
				right->set_data(temp);
				//데이터 교체


				 /*if (a==0) {  //노드 자체를 sort 하는 형식
					 rTemp = right->next();
					 rTemp->set_prev(left);

					 left->set_next(rTemp);
					 left->set_prev(right);
					 right->set_next(left);
					 head_ptr->set_next(right);

				 }
				 else if()




				 else{ //head_ptr 오류 해결 필요

					 lTemp = left->prev();

					 rTemp = right->next();
					 lTemp->set_next(right);
					 left->set_next(right->next());
					 rTemp->set_prev(right->prev());

					 right->set_next(right->prev());
					 right->set_prev(left->prev());
					 left->set_prev(lTemp->next());
					 */
			}





		}
	}


}



