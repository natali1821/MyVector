#include "MyVector.h"

MyVector::MyVector(size_t size) {
	_size = size;
	_data = nullptr;
	if (_size) {
		_data = new ValueType[_size];
		for (size_t i = 0; i < _size; ++i) {
			_data[i] = 0;
		}
	}
}

MyVector::MyVector(const MyVector& other) {
	_size = other.size();
	_data = nullptr;
	if (size()) {
		_data = new ValueType[size()];
		for (size_t i = 0; i < size(); ++i) {
			_data[i] = other._data[i];
		}
	}
}

MyVector::MyVector(MyVector&& other) noexcept{
	_size = other.size();
	_data = other._data;
	other._size = 0;
	other._data = nullptr;
}

MyVector& MyVector::operator=(const MyVector& other) {
	if (this != &other) {
		if (!other.size()) {
			_size = 0;
			_data = nullptr;
		}
		else {
			delete[] _data;
			_size = other.size();
			_data = new ValueType[size()];
			for (size_t i = 0; i < size(); ++i) {
				_data[i] = other._data[i];
			}
		}
	}
	return *this;
}

MyVector& MyVector::operator=(MyVector&& other) noexcept{
	if (this != &other) {
		_size = other.size();
		delete[] _data;
		_data = other._data;
		other._size = 0;
		other._data = nullptr;
	}
	return *this;
}

MyVector::~MyVector() {
	delete[] _data;
	_data = nullptr;
}

ValueType& MyVector::at(size_t idx) {
	if (idx >= size()) {
		throw std::out_of_range("Called at() : idx >= size of vector");
	}
	return _data[idx];
}

const ValueType& MyVector::at(size_t idx) const {
	if (idx >= size()) {
		throw std::out_of_range("Called at() : idx >= size of vector");
	}
	return _data[idx];
}

ValueType& MyVector::operator[](const size_t i) {
	return at(i);
}

const ValueType& MyVector::operator[](const size_t i) const {
	return at(i);
}

void MyVector::pushBack(const ValueType& value) {
	insert(value, size());
}

void MyVector::pushFront(const ValueType& value) {
	insert(value, 0);
}

void MyVector::insert(const ValueType& value, size_t idx) {
	if (idx > size()) {
		throw std::out_of_range("Called at insert() : idx > size of vector");
	}
	size_t tmpSize = size() + 1;
	ValueType* tmp = new ValueType[tmpSize];
	for (size_t i = 0; i < idx; ++i) {
		tmp[i] = _data[i];
	}
	tmp[idx] = value;
	for (size_t i = idx + 1; i < tmpSize; ++i) {
		tmp[i] = _data[i - 1];
	}
	delete[] _data;
	_data = tmp;
	_size = tmpSize;
}

void MyVector::clear() {
	//erase(0, size());
	delete[] _data;
	_data = nullptr;
}

void MyVector::erase(size_t idx) {
	if (idx >= size()) {
		throw std::out_of_range("Called at erase() : idx >= size of vector");
	}
	erase(idx, 1);
}

void MyVector::erase(size_t idx, size_t len) {
	if (idx >= size()) {
		throw std::out_of_range("Called at erase() : idx >= size of vector");
	}
	if (len > size() - idx) {
		len = size() - idx;
	}
	size_t tmpSize = size() - len;
	ValueType* tmp = new ValueType[tmpSize];
	for (size_t i = 0; i < idx; ++i) {
		tmp[i] = _data[i];
	}
	for(size_t i = idx; i < tmpSize; ++i) {
		tmp[i] = _data[i + len];
	}
	delete[] _data;
	_data = tmp;
	_size = tmpSize;
}

void MyVector::popBack() {
	if (size()) {
		erase(size() - 1, 1);
	}
}

size_t MyVector::size() const {
	return _size;
}

size_t MyVector::find(const ValueType& value) const {
	size_t idx = 0;
	for(idx; idx < size(); ++idx) {
		if (_data[idx] == value) {
			return idx;
		}
	}
	return -1;
}
