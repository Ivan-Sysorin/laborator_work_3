#include <iostream>
#include <vector>
#include <string>
#include <map>

template<class T>
class Stack {
private:
	std::vector<T> pMem; 
public:
	Stack() {} 
    
	bool IsEmpty() const {
		return pMem.empty();
	}
    
	void Push(const T& val) {
		pMem.push_back(val);
	}	
    
	void Pop() {
		if(!IsEmpty()) {
			pMem.pop_back();
		}
	}
    
	T Top() const {
		if (IsEmpty()) {
			throw -1; 
		}
		return pMem.back(); 
	}
    
	void Print() const {
        for (const auto& item : pMem) {
            std::cout << item << "\t";
        }
        std::cout << "\n";
    }
};


class TArithmeticExpression {
	std::string infix;
	std::string postfix;
	std::vector<char> lexem;
	std::map<char, int> priority;
	std::map<char, double> operands;	
public:
	TArithmeticExpression(std::string str_infix) {
		infix = str_infix;
		priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
		ToPostfix();
	}
    void Parse() {
    for (char c : infix) {
        if (c != ' ') { 
            lexem.push_back(c);
        }
    }
	}	
	void ToPostfix() {
            Parse();	
			Stack<char> st;
			char stackItem;
			for (char Item : lexem) {
				switch (Item) {
					case '(':
						st.Push(Item);
						break;
					case ')':
						stackItem = st.Top(); st.Pop();
						while (stackItem != '(') {
							postfix += stackItem;
							stackItem = st.Top();
							st.Pop();
						}
						break;
					case '+' : case '-' : case '*' : case '/':
						while (!st.IsEmpty()) {
							stackItem = st.Top(); st.Pop();
							if (priority[Item] <= priority[stackItem]) {
								postfix += stackItem;
							}
							else {
								st.Push(stackItem);
								break;
							}
						}
						st.Push(Item);
						break;
					default:
						operands.insert({Item, 0.0});
						postfix += Item;
				}
			}
			while (!st.IsEmpty())
			{
				stackItem = st.Top(); st.Pop();
				postfix += stackItem;
			}
	}
    std::vector<char> GetOperands() const {
		std::vector<char> op;
		for (const auto& item : operands) {
			op.push_back(item.first);
		}
		return op;
	}
	std::string GetPostfix() {
		return postfix;	
	}
	double Calculate(const std::map<char, double>& value) {
		for (auto& val : value) {
			operands.at(val.first) = val.second;
		}
		Stack<double> st;
		double left, right;
		for (char lexem : postfix) {
			switch(lexem) {
				case '+':
					right = st.Top(); st.Pop();
					left = st.Top(); st.Pop();
                    st.Push(left+right);
                    break;
                case '-':
                    right = st.Top(); st.Pop();
                    left = st.Top(); st.Pop();
                    st.Push(left - right);
                    break;
                case '*':
                    right = st.Top(); st.Pop();
                    left = st.Top(); st.Pop();
                    st.Push(left * right);
                    break;
                case '/':
                    right = st.Top(); st.Pop();
                    left = st.Top(); st.Pop();
                    st.Push(left / right);
                    break;
                default:
                    st.Push(operands[lexem]);
			}	
		}
        return st.Top();
	}
};