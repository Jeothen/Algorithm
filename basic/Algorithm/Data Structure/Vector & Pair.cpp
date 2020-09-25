template <typename T>
class _vector {
private:
	int _capacity = 0;
	int _size = 0;
	T *vc;

public:
	_vector(int size = 1) {
		_capacity = size;
		vc = new T[size];
	}
	~_vector() {
		delete[] vc;
	}
	int size() { return _size; }
	bool empty() { return !_size; }
	void resize(int size) {
		_capacity = size;
		T *tVc = new T[size];
		for (int i = 0; i < _size; i++)
			tVc[i] = vc[i];
		delete[] vc;

		vc = tVc;
	}
	void clear() {
		delete[] vc;
		_capacity = 1;
		_size = 0;

		vc = new T[1];
	}
	void push_back(T val) {
		if (_size == _capacity) {
			_capacity *= 2;
			resize(_capacity);
		}

		vc[_size++] = val;
	}

	void pop_back() {
		if (_size == 0)
			return;

		vc[--_size] = 0;
	}

	void reverse() {
		for (int i = 0; i < _size / 2; i++)
		{
			T tmp = vc[i];
			vc[i] = vc[(_size - 1) - i];
			vc[(_size - 1) - i] = tmp;
		}
	}

	T& operator[](int i) { return vc[i]; }
	T operator [] (int i) const {
		return vc[i];
	}
	/*
	T &operator[](const int &i) const{ return vc[i]; }
	void operator=(const _vector<T> &tVc) {
		_capacity = tVc._capacity;
		_size = tVc._size;
		delete[] vc;
		vc = new T[_capacity];
		for (int i = 0; i < _size; i++)
			vc[i] = tVc[i];
	}*/
};

template <typename T1, typename T2>
class _pair {
public:
	T1 first;
	T2 second;

	bool operator <(const _pair<T1, T2> &a) {
		if (first == a.first)
			return second < a.second;
		return first < a.first;
	}
};