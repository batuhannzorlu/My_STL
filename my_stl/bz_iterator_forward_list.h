template<typename T1>
class bz_Iterator_forward_list
{
public:

	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T1;
	using pointer = T1*;
	using reference = T1&;
	pointer m_ptr;


	bz_Iterator_forward_list(pointer ptr = nullptr) : m_ptr(ptr) {}
	//	bz_Iterator_forward_list(pointer ptr = nullptr) : m_ptr(ptr) {}

	reference operator*() const { return *m_ptr; }
	pointer operator->() { return m_ptr; }
	bz_Iterator_forward_list& operator++() { this->m_ptr = this->m_ptr->Next; return *this; }
	bz_Iterator_forward_list operator++(int) { bz_Iterator_forward_list tmp = *this; this->m_ptr = this->m_ptr->Next; return tmp; }

	bz_Iterator_forward_list& operator +(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Next; i--; } return *this;
	}
	bz_Iterator_forward_list& operator -(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Prev; i--; } return *this;
	}

	/////???????
	////bz_Iterator_forward_list& operator =(const T1 other) { std::swap(*m_ptr, other); std::cout << "assignment op" << endl; return *this; }
	friend bool operator== (const bz_Iterator_forward_list& a, const bz_Iterator_forward_list& b) { return a.m_ptr == b.m_ptr; };
	friend bool operator!= (const bz_Iterator_forward_list& a, const bz_Iterator_forward_list& b) { return a.m_ptr != b.m_ptr; };


	bz_Iterator_forward_list& operator +=(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Next; i--; } return *this;
	}
	bz_Iterator_forward_list& operator -=(int i) {
		while (i >= 1) { this->m_ptr = this->m_ptr->Prev; i--; } return *this;
	}





};