#include <iostream>
#include <vector>

template<class T>
class Stack {
private:
	int top;
	size_t sz;
	std::vector<T> pMem;
public:
	Stack(int n = 1): sz(n), pMem(n), top(-1) {}
	bool IsEmpty() {
		return top < 0;
	}
	void Push(const T& val) {
		++top;
		pMem.push_back(val);
	}	
	void Pop() {
		if(!IsEmpty()) {
			pMem.pop_back();
		}
	}
	T Top() {
		if (IsEmpty()) {
			throw -1;
		}
		T tmp = pMem[top];
		return tmp;
	}
};	

int main() {
	return 0;
}

