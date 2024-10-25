#include "P10-2-Helpers.hpp"

void sort_stacks(MyStack<Present>& stack1, MyStack<Present>& stack2,
                 MyStack<Present>& stack3) {
int n1 = get_stack_height(stack1);
int n2 = get_stack_height(stack2);
int n3 = get_stack_height(stack3);
int count = 0;
if(n1 == 0 && n2 == 0 && n3 == 0){ // Fall mit 3 leeren stacks  
  printf("Hier gibt es nichts mehr zum sortieren\n");
}
else if(n1 == n2 && n1 == n3){ // Fall mit 3 gleich großen stacks
  for(int i = 0; i < n2; ++i){ 
    stack1.push(stack2.top());
    stack2.pop();
  }
  for(int i = 0; i < n3; ++i){
    stack1.push(stack3.top());
    stack3.pop();
  }
  int newN1 = get_stack_height(stack1);
    for(int i = 0; i < newN1; ++i){
    if(stack1.top().get_initial() == 'B'){
      stack3.push(stack1.top());
      stack1.pop();
    }
    else if(stack1.top().get_initial() == 'G'){
      stack2.push(stack1.top());
      stack1.pop();
    }
    else if(stack1.top().get_initial() == 'R'){
      stack1.pop();
      count++;
    }
  }
  for(int i = 0; i < count; ++i){
    stack1.push(Present("Robert", 6));
  }
}
else if(n1 >= n2 && n1 >= n3){ // stack1 ist der größte Stapel, deswegen werden alle Elemente auf diesen verlegt und von dort aus richtig einsortiert
  for(int i = 0; i < n2; ++i){ 
    stack1.push(stack2.top());
    stack2.pop();
  }
  for(int i = 0; i < n3; ++i){
    stack1.push(stack3.top());
    stack3.pop();
  }
  int newN1 = get_stack_height(stack1);
    for(int i = 0; i < newN1; ++i){
    if(stack1.top().get_initial() == 'B'){
      stack3.push(stack1.top());
      stack1.pop();
    }
    else if(stack1.top().get_initial() == 'G'){
      stack2.push(stack1.top());
      stack1.pop();
    }
    else if(stack1.top().get_initial() == 'R'){
      stack1.pop();
      count++;
    }
  }
  for(int i = 0; i < count; ++i){
    stack1.push(Present("Robert", 6));
  }
}
else if(n2 >= n1 && n2 >= n1){ // stack2 ist der größte Stapel, deswegen werden alle Elemente auf diesen verlegt und von dort aus richtig einsortiert
  for(int i = 0; i < n1; ++i){
    stack2.push(stack1.top());
    stack1.pop();
  }
  for(int i = 0; i < n3; ++i){
    stack2.push(stack3.top());
    stack3.pop();
  }
  int newN2 = get_stack_height(stack2);
  for(int i = 0; i < newN2; ++i){
    if(stack2.top().get_initial() == 'B'){
      stack3.push(stack2.top());
      stack2.pop();
    }
    else if(stack2.top().get_initial() == 'R'){
      stack1.push(stack2.top());
      stack2.pop();
    }
    else if(stack2.top().get_initial() == 'G'){
      stack2.pop();
      count++;
    }
  }
  for(int i = 0; i < count; ++i){
    stack2.push(Present("Gabi", 4));
  }
}
else if(n3 >= n2 && n3 >= n1){ // stack3 ist der größte Stapel, deswegen werden alle Elemente auf diesen verlegt und von dort aus richtig einsortiert
  for(int i = 0; i < n1; ++i){
    stack3.push(stack1.top());
    stack1.pop();
  }
  for(int i = 0; i < n2; ++i){
    stack3.push(stack2.top());
    stack2.pop();
  }
  int newN3 = get_stack_height(stack3);
  for(int i = 0; i < newN3; ++i){
    if(stack3.top().get_initial() == 'G'){
      stack2.push(stack3.top());
      stack3.pop();
    }
    else if(stack3.top().get_initial() == 'R'){
      stack1.push(stack3.top());
      stack3.pop();
    }
    else if(stack3.top().get_initial() == 'B'){
      stack3.pop();
      count++;
    }
  }
  for(int i = 0; i < count; ++i){
    stack3.push(Present("Bert", 4));
  }
}

}

int main() {
  MyStack<Present> stack1;
  MyStack<Present> stack2;
  MyStack<Present> stack3;

  // Hier können sie zwischen den Testfällen 0, 1, 2 oder 3 wählen.
  // Sie können auch die nächsten beiden Zeilen auskommentieren und einen
  // eigenen Testfall erstellen.
  int test_case_number = 0;
  fill_stack_with_test_case(test_case_number, stack1, stack2, stack3);

  printf("======== Initialer Zustand ========");
  print_present_stacks(stack1, stack2, stack3);

   sort_stacks(stack1, stack2, stack3);

  printf("======== Nach dem Aufraeumen ========");
  print_present_stacks(stack1, stack2, stack3);
}