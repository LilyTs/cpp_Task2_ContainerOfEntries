#pragma once
#include "stdafx.h"

template<class T>
class Container
{
public:

	Container() {
		c = std::deque<T>();
	}

	~Container(){}

	bool add(const T &el) {
		if (std::find(c.begin(), c.end(), el) == c.end()) {
			c.push_back(el);
			return true;
		}
		return false;
	}

	template<class Collector>
	std::deque<T> linearSearch(Collector coll) const {
		std::for_each(c.begin(), c.end(), coll);
		return coll.getCollection();
	}
	
	template<class Cmp, class Collector>
	std::deque<T> binarySearch(Cmp &cmp, Collector coll, T &el) {
		std::sort(c.begin(), c.end(), cmp);
		std::deque<T>::iterator it = std::lower_bound(c.begin(), c.end(), el, cmp);
		std::for_each(it, c.end(), coll);
		return coll.getCollection();
	}
	
	void remove(T el) {
		std::deque<T>::iterator it = find(c.begin(), c.end(), el);
		c.erase(it);
	}

	void output(std::ostream &os) const {
		copy(c.begin(), c.end(), std::ostream_iterator<T>(os, "\n"));
	}

	bool saveToFile(std::fstream &f) const {
		if (f.is_open()) {
			copy(c.begin(), c.end(), std::ostream_iterator<T>(f, "\n"));
			f.close();
			return true;
		}
		return false;
	}

	bool loadFromFile(std::fstream &f) {
		if (f.is_open()) {
			std::istream_iterator<T> is(f);
			c.clear();
			is++;
			is++;
			while (!f.fail() && !f.eof()) {
				try {
					is++;
					T el = *is;
					add(el);
				}
				catch (std::exception) {};
			}
			f.close();
			return true;
		}
		return false;
	}

	T operator[](int i) {
		return c[i];
	}

	int size() {
		return c.size();
	}

	bool empty() {
		return c.empty();
	}
	
protected:
	std::deque<T> c;
};