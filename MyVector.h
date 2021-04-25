#pragma once
#include "IVector.h"
#include <iostream>
#include <exception>

class MyVector : public IVector {
public:
	MyVector(size_t size = 0);

	explicit MyVector(const MyVector& other);
	MyVector(MyVector&& other) noexcept;

	MyVector& operator=(const MyVector& other);
	MyVector& operator=(MyVector&& other) noexcept;

	~MyVector();

	ValueType& at(size_t idx) override;
	const ValueType& at(size_t idx) const override;
	ValueType& operator[](const size_t i) override;
	const ValueType& operator[](const size_t i) const override;

	void pushBack(const ValueType& value) override;
	void pushFront(const ValueType& value) override;
	void insert(const ValueType& value, size_t idx) override;

	void clear() override;
	void erase(size_t idx) override;
	void erase(size_t idx, size_t len) override;
	void popBack() override;

	size_t size() const override;

	size_t find(const ValueType& value) const override;

private:
	size_t _size;
	ValueType* _data;

};
