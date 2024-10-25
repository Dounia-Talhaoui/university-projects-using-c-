#include "MyStack.hpp"

template <typename T>
void insert_into_stack(MyStack<T>& stack, T item) {
  if(!stack.is_empty()){
    MyStack<T> secondStack;
    int index = 0;
    int count = 0;

    while (index < stack.size() && stack[index] <= item) {
      secondStack.push(stack.pop());
      ++count;
    }

    stack.push(item);

    for (int i = 0; i < count; ++i) {
      stack.push(secondStack.pop());
    }
  }
}