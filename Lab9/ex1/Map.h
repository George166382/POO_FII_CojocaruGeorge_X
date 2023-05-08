#pragma once

template<typename T, typename T1>
class Map {
	struct Element {
		T key;
		T1 value;
		int index;
	};

	Element* data;
	int size;

public:
	Map() {
		data = new Element[100];
		size = 0;
	}

	void add(T key, T1 value) {
		data[size].index = size;
		data[size].key = key;
		data[size].value = value;
		size++;
	}

	T1& operator[](T key) {
		for (int i = 0; i < size; i++) {
			if (data[i].key == key) {
				return data[i].value;
			}
		}
		data[size].index = size;
		data[size].key = key;
		size++;
		return data[size - 1].value;
	}

	~Map() {
		delete[] data;
	}

	struct iterator {
		Element* pos;

		iterator(Element* pos) : pos(pos) {
		}

		bool operator!=(iterator i) {
			return pos != i.pos;
		}

		void operator++() {
			pos++;
		}

		Element& operator*() {
			return *pos;
		}
	};

	iterator begin() {
		return iterator(&data[0]);
	}

	iterator end() {
		return iterator(&data[size]);
	}
};
