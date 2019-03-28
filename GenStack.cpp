#include <iostream>
#include <string>

using namespace std;

template <class T, int stackSize>
class GenStack{
	public:
		GenStack();
		~GenStack();
		int getSize();
		void push(T c);
		T pop();
		T top();
		bool empty();
		bool full();


		int t;
		T data[stackSize];
		int emptyStack;
};

template<class T, int stackSize>
GenStack<T, stackSize>::GenStack()
{
	emptyStack = -1;
	t = emptyStack;
}

template<class T, int stackSize>
void GenStack<T, stackSize>::push(T c)
{
	data[++t] = c;
}

template<class T, int stackSize>
GenStack<T, stackSize>::~GenStack()
{
	cout<< "deleting";
	delete[] data;
}

template<class T, int stackSize>
int GenStack<T, stackSize>::getSize()
{
	return t + 1;
}

template<class T, int stackSize>
T GenStack<T, stackSize>::pop()
{
	return data[t--];
}

template<class T, int stackSize>
bool GenStack<T, stackSize>::full()
{
	return t+1 == stackSize;
}

template<class T, int stackSize>
bool GenStack<T, stackSize>::empty()
{
	return (t < 0);
}

template<class T, int stackSize>
T GenStack<T, stackSize>::top()
{
	return data[t];
}
