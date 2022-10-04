#pragma once

/**
 * \brief A Generic (Circular) Queue.
 * Front Index points to the Front Object.
 * Rear Index points to the next free cell (if any).
 * \tparam T Type of object in the Queue.
 */
template <typename T> class generic_queue {
public:
	/**
	 * \brief Default Constructor.
	 * \param size Size of the queue.
	 */
	explicit generic_queue(int size);

	/**
	 * \brief Destructor
	 */
	~generic_queue();

	/**
	 * \brief Pushes an element to the end of the Queue.
	 * \param element Element to push into the Queue.
	 */
	void push(T element);

	/**
	 * \brief Pops the first element in the Queue.
	 */
	void pop();

	/**
	 * \brief Gets the address of the front (first element) of the Queue.
	 * \return Address of the first element in the Queue.
	 */
	T* front();

	/**
	 * \brief Checks whether or not the Queue is empty.
	 * \return True if Queue is empty.
	 */
	[[nodiscard]] bool is_empty() const;

	/**
	 * \brief Checks whether or not the Queue is full.
	 * \return True if Queue is full.
	 */
	[[nodiscard]] bool is_full() const;

	/**
	 * \brief Gets the number of populated elements in the Queue.
	 * \return Number of populated elements in the Queue.
	 */
	[[nodiscard]] int count() const;

private:
	/**
	 * \brief Dynamic array to hold queue elements.
	 */
	T* m_ptr_;

	/**
	 * \brief Size of the dynamic array.
	 */
	int m_size_{};

	/**
	 * \brief The Index of the Queue's Front
	 */
	int m_front_index_{};

	/**
	 * \brief The Index of the Queue's Rear
	 */
	int m_rear_index_{};

	/**
	 * \brief The number of populated elements in the Queue.
	 */
	int m_count_{};
};

template <typename T>
generic_queue<T>::generic_queue(const int size) {
	m_size_ = size;
	m_ptr_ = new T[m_size_];
}

template <typename T>
generic_queue<T>::~generic_queue() {
	try {
		if (m_ptr_ != nullptr)
		{
			delete[] m_ptr_;
		}
			
	}
	catch (...) {
		delete m_ptr_;
	}
	m_ptr_ = nullptr;
}

template <typename T>
void generic_queue<T>::push(T element) {
	if (!is_full()) {
		int element_index = m_rear_index_ + 1 > m_size_ ? 0 : m_rear_index_++;
		if (m_rear_index_ == m_size_) {
			m_rear_index_ = element_index + 1;
		}
		m_ptr_[element_index] = element;
		m_count_++;
	}
}

template <typename T>
void generic_queue<T>::pop() {
	if (!is_empty()) {
		int element_index = m_front_index_ + 1 > m_size_ ? 0 : m_front_index_++;
		if (m_front_index_ == m_size_) {
			m_front_index_ = element_index + 1;
		}

		m_ptr_[element_index] = T();
		m_count_--;
	}
}

template <typename T>
T* generic_queue<T>::front() { 
	return &m_ptr_[m_front_index_ == m_size_ ? 0 : m_front_index_];
}

template <typename T>
bool generic_queue<T>::is_empty() const {
	return m_count_ == 0;
}

template <typename T>
bool generic_queue<T>::is_full() const {
	return m_count_ == m_size_;
}

template <typename T>
int generic_queue<T>::count() const {
	return m_count_;
}


