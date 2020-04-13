#include <iostream>

using namespace std;
template<typename T>
class List
{

private:

	template<typename T>
	struct Node {
		T data; //íàøè äàííûå
		Node* p_next; //óêàçàòåëü íà ñëåä. ýëåìåíò
	};

	Node<T>* p_first; // óêàçàòåëü íà ïåðâûé ýëåìåíò
	Node<T>* p_last; // óêàçàòåëü íà ïîñëåäíèé ýëåìåíò
	int size_list;		//ðàçìåð ñïèñêà

	void show(Node<T>* current_element) {
		std::cout << current_element->data << endl;
	}
public:
	List();
	~List();
	void push_back(T data);		//äîáàâèòü ýëåìåíò â êîíåö
	void push_front(T data);		//âñòàâèòü â íà÷àëî ýëåìåò
	void print_all();	//ðàñïå÷àòàòü âñå ýëåìåíòû
	void pop_back();	//óäàëèòü ïîñëåäíèé ýëåìåò
	void pop_front();	//óäàëåíèå ïåðâîãî ýëåìåíòà
	void insert(const T data, int index);	//âñòàâèòü ýëåìåíò ïî èíäåêñó
	void remove(int index); //óäàëèòü ýëåìåíò ïî èíäêñó
	void clear(); //î÷èñòêà ñïèñêà
	bool check_empty() { if (p_first == NULL) return true; else return false; }//ïðîâåðêà ,åñòü ëè ýëåìåíòû â ñïèñêå
	bool find_item(T data);		//íàéòè ýëåìåò â ñïèñêå
	int get_length() { return size_list; }		//ïîëó÷èòü äëèíó ñïèñêà
	T front()const  { return p_first->data; }
	T back()const  { return p_last->data; }

	T& operator[](const int);		//ïåðåãðóçêà îïåðàòîðà 
	void operator=(const List<T>& original);
	List<T>& get_poinet_head() { return p_first; }	//ïîëó÷èòü ïåðâûé óêàçàòåëü

};

template<typename T>
List<T>::List()		//êîíñòðóêòîð
{
	p_first = NULL;
	p_last = NULL;
	size_list = 0;
}

template<typename T>
void List<T>::push_back(T data) {

	Node<T>* current_element = new Node<T>;		//ñîçäàåì íîâóþ ñòðóêòóðó
	current_element->data = data;			//ïîìåùàåì íàøè äàííûå
	size_list++;								//ñ÷åò÷èê êîë-âî ýëåìåíòîâ
	if (p_first == NULL) {					//ïðîâåðÿåì åñòü ëè ýëåìåíòû â ñïèñêå
		p_first = current_element;			//óêàçàòåëþ íà ïåðâûé ýëåìåíò - òåêóùèé
		p_last = current_element;			//óêàçàòåëþ íà ïîñëåäíèé ýëåìåíò - òåêóùèé
		p_last->p_next = NULL;				//óêàçàòåëü ïîñëåäíåãî ýåëåìåíòà íà ñëåäóùèé óêàçûâàåò â ïóñòîòó

	}
	else {									//åñëè åñòü ýëåìåíòû
		p_last->p_next = current_element;	//óêàçàòåëþ ïðåäûäóùåãî ýëåìåíòà íà ñëåäóùèé = òåêóùåìó ýëåìåíòó
		p_last = current_element;			//ïîñëåäíèé ýëåìåò ðàâåí òåêóùåìó
		p_last->p_next = NULL;				//óêàçàòåëü ïîñëåäíåãî íà ñëåäóùèé = ïóñòîòà
	}
}

template<typename T>
void List<T>::push_front(T data) {		//äîáàâèòü ýëåìåíò â íà÷àëî ñïèñêà

	Node<T>* current_element = new Node<T>;		//ñîçäàåì ñòðóêòóðó
	current_element->data = data;		//òåêóùåé ýëåìåíò = íàøåìó çíà÷åíèþ
	size_list++;		//ñ÷åò÷èê óâåëè÷èâàåì
	if (p_first == NULL) {		//åñëè ýëåìåíòîâ íåò ,òî ñîçäàåì ñíà÷àëà
		p_first = current_element;
		p_last = current_element;
		p_last->p_next = NULL;
	}
	else {		//åñëè ýëåìåíòû åñòü
		current_element->p_next = p_first;		//óêàçàòåëü íà ñëåä.ýëåìåò òåêóùåãî ýëåìåíòà = ïåðâîìó ýëåìåíòó
		p_first = current_element;		//ïåðâûé ýëåìåò ðàâåí òåêóùåìó
	}
}

template<typename T>
void List<T>::print_all() {
	Node<T>* temp = new Node<T>;		//ñîçäàåì íîâóþ ñòðóêòóðó èòåðàòîð
	temp = p_first;			//ïðèðàâíèâàåì óêàçàòåëü íà ïåðâûé ýëåìåíò ñïèñêà
	while (temp != NULL) {		//ïîêà ýòîò ýëåìåíò íå óêàçûâàåò íà ïóñòîòó
		show(temp);		//âûçûâàåì ìåòîä ïîêàçàòü äàííûé ýëåìåíò
		temp = temp->p_next;		//ïðèðàâíèâàåì óêàçàòåëü íà ñëåäóùèé ýëåìåíò

	}
}

template<typename T>
void List<T>::pop_back() {
	Node<T>* current_element = p_first;		//ñîçäàåì íîâóþ ñòðóêòóðó
	Node<T>* p_previous = NULL;		//óêàçàòåëü íà ïðåäûäóùèé ýëåìíåò = ïóñòîòà
	size_list--;

	while (current_element != NULL) {		//ïîêà òåêóùèé ýëåìåò íå ïóñòîòà
		if (current_element->p_next == NULL) {		//åñëè ñëåäóùèé óêàçàòåëü = ïóñòîòà
			p_last = p_previous;		//ïîñëåäíåìó óêàçàòåëþ = ïðåäûäóùèé óêàçàòåëü
			delete current_element;
			p_last->p_next = NULL;		//ïîñëåäíèé óêàçàòåëü íà ñëåäóùèé ýëåìåíò = ïóñòîòà
			break;
		}
		p_previous = current_element;	//ïðåäûäóùèé ýëåìåíò = òåêóùèé
		current_element = current_element->p_next;	//òåêóùèé = ñëåäóþùèé
	}
}

template<typename T>
void List<T>::pop_front() {	//óäàëèòü â íà÷àëå

	Node<T>* current_element = p_first;
	p_first = current_element->p_next;//ïåðâûé ýëåìåíò ðàâåí ñëåäóþùåìó

	delete current_element;//óäàëÿåì òåêóùèé	
	size_list--;//ñ÷åò÷èê ìèíóñ 1

}

template<typename T>
void List<T>::insert(const T data, int index) {
	Node<T>* current_element = new Node<T>;
	current_element->data = data;
	if (p_first == NULL) {
		push_front(data);
	}
	else {
		Node<T>* previous = p_first;
		for (int i = 1; i < index - 1 && previous->p_next != NULL; ++i) {
			previous = previous->p_next;
		}
		if (index == 0) {
			push_front(data);
		}
		else if (previous->p_next == NULL) {
			push_back(data);
		}
		else {
			current_element->p_next = previous->p_next;
			previous->p_next = current_element;

		}
	}

}

template<typename T>
void List<T>::clear() {//î÷èñòêà ñïèñêà ïîëíîñòüþ
	while (size_list) {
		pop_front();
	}
}

template<typename T>
List<T>::~List()//äåñòðóêòîð
{
	clear();
}

template<typename T>
T& List<T>::operator[](const int index) { //ïåðåãðóçêà îïåðàòîðà èíäåêñàöèè

	Node<T>* current_element = p_first;//óêàçàòåëü íà ïåðâûé ýëåìåíò
	int count = 0;
	while (current_element != NULL)
	{
		if (count == index) {
			return current_element->data;	//íàõîäèì íàø èíäåêñ è âîçâðàùàåì ññûëêó íà íåãî
		}
		current_element = current_element->p_next;
		count++;
	}
}

template<typename T>
void List<T>::operator=(const List<T>& original)
{
	Node<T>* current = original.p_first;
	while (current != NULL) {
		this->push_back(current->data);
		current = current->p_next;
	}

	// TODO: âñòàâüòå çäåñü îïåðàòîð return
}

template<typename T>
void List<T>::remove(int index) {		//óäàëèòü ýëåìåíò ïî èíäåêñó
	Node<T>* current_element = p_first;
	Node<T>* previous = p_first;
	size_list--;
	for (int i = 0; i < index && current_element->p_next != NULL; ++i) {
		current_element = current_element->p_next;
	}
	if (index == 0) {
		pop_front();
	}
	else if (current_element == NULL) {
		pop_back();
	}
	else {
		while (previous->p_next != current_element) {
			previous = previous->p_next;
		}
		previous->p_next = current_element->p_next;
		delete current_element;
		current_element = previous;
	}
}

template<typename T>
bool List<T>::find_item(const T data) {//ïîèñê ýëåìåòà 

	Node<T>* current_element = p_first;
	while (current_element != NULL) {
		if (current_element->data == data) {
			return true;
		}
		current_element = current_element->p_next;
	}
	return false;
}
