#include<cstdlib>
#include<cassert>

class dnode {

public:
	typedef double value_type;
	dnode(
		const value_type& init_data = value_type(),
		dnode* init_next = NULL,//link 값 제공 안되면 null
		dnode* init_prev = NULL) {

		data_field = init_data;
		link_next = init_next;//다음 노드의 포인터
		link_prev = init_prev;//이전 노드의 포인터
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
	//노드 구조 
	value_type data_field;
	dnode* link_next;//다음 주소
	dnode* link_prev;//이전 주소
};

size_t list_length(const dnode* head_ptr) {
	//리스트의 길이를 리턴해줌

	const dnode* cursor; //헤드포인터부터 이동 시킴
	size_t answer;

	answer = 0;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())//커서 업데이트 중요
		++answer;//다음번 노드로 갈 수 있다면 리스트의 길이 카운트를 증가시킴

	return answer;
}





void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry) {
	//리스트에 새로운 헤드를 삽입, 기존의 노드는 한칸 밀려남
	head_ptr = new dnode(entry, head_ptr, NULL);



}



void list_insert(dnode* previous_ptr, const dnode::value_type& entry) {

	dnode* insert_ptr; //데이터를 받을 새 노드 생성

	insert_ptr = new dnode(entry, previous_ptr->next(), previous_ptr);

	if (previous_ptr->next() != NULL) {
		previous_ptr->next()->set_prev(insert_ptr);//끝이 아닐 경우 다음 노드의 prev링크 설정
	}
	previous_ptr->set_next(insert_ptr);

}



dnode* list_search(dnode* head_ptr, const dnode::value_type& target) {
	//리스트에서 특정한 값을 찾아줌
	//cursor라는 노드에 대한 포인터 이용
	dnode* cursor;
	//머리부터 검색해가야하니 헤드포인터의 값을 카피해옴 
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())
		if (target == cursor->data())
			return cursor;

	return NULL;

}



const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target) {
	//target 값이 있는 위치를 리턴해주는 함수
	const dnode* cursor;



	for (cursor = head_ptr; cursor != NULL; cursor = cursor->next())
		if (target == cursor->data())
			return cursor;

	return NULL;

}



dnode* list_locate(dnode* head_ptr, size_t position) {
	//위치를 알려주면 해당 위치의 노드의 포인터를 리턴하는 함수
	dnode* cursor;
	size_t i;

	assert(0 < position);

	cursor = head_ptr;

	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->next();

	return cursor;

}



const dnode* list_locate(const dnode* head_ptr, size_t position) {
	//리스트의 인덱스를 입력하면 해당 인덱스에 위치한 노드 리턴해주는 함수
	const dnode* cursor;

	size_t i;

	assert(0 < position);

	cursor = head_ptr;

	for (i = 1; (i < position) && (cursor != NULL); i++)
		cursor = cursor->next();

	return cursor;//노드 리턴 

}



void list_head_remove(dnode*& head_ptr) {
	//리스트의 헤드포인터가 가리키는 노드를 제거 하는 함수
	dnode* remove_ptr;

	remove_ptr = head_ptr;
	head_ptr = head_ptr->next();//제거된 노드 뒤 가리킴

	if (head_ptr != NULL)
		head_ptr->set_prev(NULL);

	delete remove_ptr;

}



void list_remove(dnode* previous_ptr) {
	//제거할 노드 선택해서 제거
	dnode* remove_ptr;
	remove_ptr = previous_ptr->next();

	previous_ptr->set_next(remove_ptr->next());

	if (remove_ptr->next() != NULL)
		remove_ptr->next()->set_prev(previous_ptr);
	//포인터 정리
	delete remove_ptr;

}



void list_clear(dnode*& head_ptr) {
	//list_head_remove를 반복하여 리스트의 모든 노드 삭제
	while (head_ptr != NULL)
		list_head_remove(head_ptr);

}



void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr) {
	//리스트를 복사하는 함수
	head_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL)//복사할거 없으면 바로 리턴

		return;

	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	source_ptr = source_ptr->next();
	while (source_ptr != NULL) {//연결

		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->next();
		source_ptr = source_ptr->next();//다음 노드 복사하러감

	}


}
