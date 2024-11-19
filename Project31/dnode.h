#include<cstdlib>
#include<cassert>

class dnode {

public:
	typedef double value_type;
	dnode(
		const value_type& init_data = value_type(),
		dnode* init_next = NULL,//link �� ���� �ȵǸ� null
		dnode* init_prev = NULL) {

		data_field = init_data;
		link_next = init_next;//���� ����� ������
		link_prev = init_prev;//���� ����� ������
	}

	value_type data() const { return data_field; }
	const dnode* next() const { return link_next; }
	dnode* next() { return link_next; }
	const dnode* prev() const { return link_prev; }
	dnode* prev() { return link_prev; }

	void set_data(const value_type& new_data) { data_field = new_data; }

	void set_next(dnode* new_next) { link_next = new_next; }
	void set_prev(dnode* new_prev) { link_prev = new_prev; }

private:
	//��� ���� 
	value_type data_field;
	dnode* link_next;//���� �ּ�
	dnode* link_prev;//���� �ּ�
};

size_t list_length(const dnode* head_ptr) {
	//����Ʈ�� ���̸� ��������

	const dnode* cursor; //��������ͺ��� �̵� ��Ŵ
	size_t answer;

	answer = 0;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())//Ŀ�� ������Ʈ �߿�
		++answer;//������ ���� �� �� �ִٸ� ����Ʈ�� ���� ī��Ʈ�� ������Ŵ

	return answer;
}





void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry) {
	//����Ʈ�� ���ο� ��带 ����, ������ ���� ��ĭ �з���
	head_ptr = new dnode(entry, head_ptr, NULL);



}



void list_insert(dnode* previous_ptr, const dnode::value_type& entry) {

	dnode* insert_ptr; //�����͸� ���� �� ��� ����

	insert_ptr = new dnode(entry, previous_ptr->next(), previous_ptr);

	if (previous_ptr->next() != NULL) {
		previous_ptr->next()->set_prev(insert_ptr);//���� �ƴ� ��� ���� ����� prev��ũ ����
	}
	previous_ptr->set_next(insert_ptr);

}



dnode* list_search(dnode* head_ptr, const dnode::value_type& target) {
	//����Ʈ���� Ư���� ���� ã����
	//cursor��� ��忡 ���� ������ �̿�
	dnode* cursor;
	//�Ӹ����� �˻��ذ����ϴ� ����������� ���� ī���ؿ� 
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())
		if (target == cursor->data())
			return cursor;

	return NULL;

}



const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target) {
	//target ���� �ִ� ��ġ�� �������ִ� �Լ�
	const dnode* cursor;



	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())
		if (target == cursor->data())
			return cursor;

	return NULL;

}



dnode* list_locate(dnode* head_ptr, size_t position) {
	//��ġ�� �˷��ָ� �ش� ��ġ�� ����� �����͸� �����ϴ� �Լ�
	dnode* cursor;
	size_t i;

	assert(0 < position);

	cursor = head_ptr;

	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->next();

	return cursor;

}



const dnode* list_locate(const dnode* head_ptr, size_t position) {
	//����Ʈ�� �ε����� �Է��ϸ� �ش� �ε����� ��ġ�� ��� �������ִ� �Լ�
	const dnode* cursor;

	size_t i;

	assert(0 < position);

	cursor = head_ptr;

	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->next();

	return cursor;//��� ���� 

}



void list_head_remove(dnode*& head_ptr) {
	//����Ʈ�� ��������Ͱ� ����Ű�� ��带 ���� �ϴ� �Լ�
	dnode* remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->next();//���ŵ� ��� �� ����Ŵ

	if (head_ptr != NULL)
		head_ptr->set_prev(NULL);

	delete remove_ptr;

}



void list_remove(dnode* previous_ptr) {
	//������ ��� �����ؼ� ����
	dnode* remove_ptr;
	remove_ptr = previous_ptr->next();

	previous_ptr->set_next(remove_ptr->next());

	if (remove_ptr->next() != NULL)
		remove_ptr->next()->set_prev(previous_ptr);
	//������ ����
	delete remove_ptr;

}



void list_clear(dnode*& head_ptr) {
	//list_head_remove�� �ݺ��Ͽ� ����Ʈ�� ��� ��� ����
	while (head_ptr != NULL)
		list_head_remove(head_ptr);

}



void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr) {
	//����Ʈ�� �����ϴ� �Լ�
	head_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL)//�����Ұ� ������ �ٷ� ����

		return;

	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	source_ptr = source_ptr->next();
	while (source_ptr != NULL) {//����

		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->next();
		source_ptr = source_ptr->next();//���� ��� �����Ϸ���

	}


}
