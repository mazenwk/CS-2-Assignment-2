#pragma once
template <typename T> class generic_queue {
private:
	T* m_ptr_{};
	int m_size_{};
	int m_front_index_{};
	int m_rear_index_{};

public:
	explicit generic_queue(int size);
	~generic_queue();

	void push(T element);
	void pop();
	T front();
	bool is_empty() const;
	bool is_full() const;
	int count() const;
};

template <typename T>
generic_queue<T>::generic_queue(const int size) {
	m_size_ = size;
	m_ptr_ = new T[m_size_ = size];
}

template <typename T>
generic_queue<T>::~generic_queue() {
	delete[] m_ptr_;
	m_ptr_ = nullptr;
}

template <typename T>
void generic_queue<T>::push(T element) {
	if (!is_full()) {
		m_rear_index_ = m_rear_index_ + 1 > m_size_ ? 0 : ++m_rear_index_;
		m_ptr_[m_rear_index_ == 0 ? m_rear_index_ : m_rear_index_-1] = element;
	}
}

template <typename T>
void generic_queue<T>::pop() {
	if (!is_empty()) {
		m_front_index_ = m_front_index_ + 1 > m_size_ ? 0 : ++m_front_index_;
		//m_rear_index_ = m_rear_index_ == m_size_ ? 0 : ++m_rear_index_;
	}
}

template <typename T>
T generic_queue<T>::front() { 
	return m_ptr_[m_front_index_ == m_size_ ? 0 : m_front_index_];
}

template <typename T>
bool generic_queue<T>::is_empty() const {
	return m_rear_index_ == m_front_index_;
}

template <typename T>
bool generic_queue<T>::is_full() const {
	return m_rear_index_ - m_front_index_ == m_size_ || m_rear_index_ - m_front_index_ == -1;
}

template <typename T>
int generic_queue<T>::count() const {
	return m_rear_index_ - m_front_index_;
}


