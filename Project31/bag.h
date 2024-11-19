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
	size_type many_dnodes; //����� ��

};


bag::bag() {
	//������
	//
	head_ptr = NULL;
	many_dnodes = 0;
};

bag::bag(const bag& source) {
	//���������

	dnode* tail_ptr; //���÷� ������ ��忡 ���� ������ 

	list_copy(source.head_ptr, head_ptr, tail_ptr);

	many_dnodes = source.many_dnodes;
}

bag::~bag() {
	//�Ҹ���
	list_clear(head_ptr);

	many_dnodes = 0;
};
bool bag::operator ==(const bag& source) {
	//���ٸ� ture�� ����
	if (this == &source)
		return true;
	else
		return false;

}


bool bag::erase_one(const value_type& target) {
	//��� �ϳ� �������ִ� �Լ�
	dnode* target_ptr;//�����ϰ��� �ϴ� ���� �ּ� Ȯ����

	target_ptr = list_search(head_ptr, target);//�ּ� Ȯ��
	if (target_ptr == NULL)// NULL�̶�� ã�� ���Ͽ� ����
		return false;

	target_ptr->set_data(head_ptr->data());//���� ������ �ƴ϶� ��������ͷ� �Ѱ���
	list_head_remove(head_ptr);
	--many_dnodes;//��� ���� ���̱�

	return true;
}

bag::size_type bag::count(const value_type& target)const {
	//target ���� � �ִ��� �����ִ� �Լ�
	size_type answer = 0;
	const dnode* cursor;
	cursor = list_search(head_ptr, target);//Ŀ���� target�� ����Ű�� ��
	while (cursor != NULL) {//target�� ã�Ҵٸ� answer�� 1������Ŵ 
		++answer;
		cursor = cursor->next();
		cursor = list_search(cursor, target);
	}
	return answer;
}

bag::value_type bag::grab() const {
	//�������� ��带 �ϳ� ��� ����� �����͸� �������ִ� �Լ�
	size_type i;
	const dnode* cursor;
	assert(size() > 0);
	i = (rand() % size()) + 1;//���� ����
	cursor = list_locate(head_ptr, i);//���� i�� �ְ� i ��° ��带 ã��
	return cursor->data();

}
//�����ڵ�
void bag::insert(const value_type& entry) {
	//entry�� �ϳ� �߰� �ϴ� �Լ�
	list_head_insert(head_ptr, entry);//��� ��忡 �μ�Ʈ

	++many_dnodes;//�߰��� ��� �� �ݿ�

}


bag operator +(const bag& b1, const bag& b2) {
	// bag class ���� �����ִ� �Լ�
	bag answer;
	answer += b1;
	answer += b2;
	return answer;

}
bool bag::operator != (const bag& source) {
	//�ٸ��ٸ� true ����
	if (this == &source)
		return false;
	else
		return true;
}

void bag::operator =(const bag& source) {
	//bag class�� ���Կ�����
	dnode* tail_ptr; //���� ����

	if (this == &source)// self - assignment �Ȱ��� ������Ʈ�� �׳� ���� 
		return;

	list_clear(head_ptr);//�ڽ��� Ŭ����
	many_dnodes = 0;
	list_copy(source.head_ptr, head_ptr, tail_ptr);//ī���ؼ� ���纻�� ���� ���� ������
	many_dnodes = source.many_dnodes;

}


void bag::operator +=(const bag& addend) {
	dnode* copy_head_ptr;
	dnode* copy_tail_ptr;

	if (addend.many_dnodes > 0) { //empty ���� Ȯ��

		list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		copy_tail_ptr->set_next(head_ptr);
		head_ptr = copy_head_ptr;
		many_dnodes += addend.many_dnodes;

	}

}

void bag::show_contents() {
	//bag class ���� ����� �����͸� ����Ʈ ���ִ� �Լ�
	const dnode* cursor;
	for (cursor = head_ptr;cursor != NULL;cursor = cursor->next())
		cout << cursor->data() << ' ';


}




void bag::sort() {
	//bag Ŭ���� ���� ������ ������������ ���� �����ϴ� �Լ�
	int i = 0; //����Ʈ�� ������ ���� ���� ����
	i = list_length(head_ptr);
	int a = 0;
	for (int k = i - 1;k > 0;k--) { //����Ʈ�� ���̸� ���� �޾� n-1�� ����

		for (a = 0;a < k;a++) { //n-2�� ����
			dnode* left;
			dnode* right;
			value_type temp;
			// dnode* lTemp;
			 //dnode* rTemp;
			left = list_locate(head_ptr, a + 1);//������ �� ��� ����
			right = list_locate(head_ptr, a + 2);

			if (left->data() > right->data()) {
				temp = left->data();
				left->set_data(right->data());
				right->set_data(temp);
				//������ ��ü


				 /*if (a==0) {  //��� ��ü�� sort �ϴ� ����
					 rTemp = right->next();
					 rTemp->set_prev(left);

					 left->set_next(rTemp);
					 left->set_prev(right);
					 right->set_next(left);
					 head_ptr->set_next(right);

				 }
				 else if()




				 else{ //head_ptr ���� �ذ� �ʿ�

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



