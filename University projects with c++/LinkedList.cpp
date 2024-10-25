#include <cstdio>

template <typename U>
class Node {
 public:
  Node(U const& x) : cont_{x} {}
  U cont_;  // speichert das Datenelement
  Node* next_ = nullptr;
};

template <typename T>
class LinkedList {
 public:
  LinkedList() : head_{nullptr} {}

  bool is_empty() const { return head_ == nullptr; }

  void push_front(T const& x) {
    Node<T>* new_node = new Node<T>(x);  // erzeuge neue Knoten mit Inhalt x
    new_node->next_ = head_;  // der neue Knoten zeigt auf den bisher ersten...
    head_ = new_node;         // ... und ist der neue erste Knoten
  }

  // loescht das erste Element aus der LinkedList:
  T pop_front() {
    if (!is_empty()) {
      Node<T>* tmp = head_->next_;     // temporäre Kopie des Zeigers
      T first_element = head_->cont_;  // erzeugt eine Kopie
      delete head_;  // loescht das Knotenobjekt (das irgendwann mal im
                     // Konstruktor angelegt wurde)

      head_ = tmp;
      return first_element;  // erzeugt Kopie, da keine Referenz zurückgegeben
    }
    return T();  // damit irgendwas zurückgegeben wird
  }

  // Index-Operator als Referenz:
  T& operator[](int i) const {
    Node<T>* current = head_;  // kopiere Zeiger auf head_
    for (int j = 0; j < i; ++j) current = current->next_;  // folge i-mal next_
    return current->cont_;
  }

  ~LinkedList() {
    while (!is_empty()) pop_front();  // loescht alle Knotenobjekte aus der LL
  }

  // ===========================================================================
  // Implementieren Sie hier die Funktion insert_after
  void insert_after(T const &where, T const &s){
    Node<T>* current = this->getHead();
    while (current != nullptr){
      if (current->cont_ == where){
        Node<T>* new_node = new Node<T>(s);
          new_node->next_ = current->next_;
          current->next_ = new_node;
      }
      current = current->next_;
    }
  }
  // ===========================================================================

 private:
  // ===========================================================================
  Node<T>* getHead() const {
    return head_;
  }
  // ===========================================================================

  Node<T>* head_;  // Beginn der Liste
};

// Nur für 0-terminierte Listen
void print(LinkedList<int> const& ll) {
  for (int i = 0; ll[i] != 0; ++i) printf("%i, ", ll[i]);
  printf("0\n");
}

int main() {
  LinkedList<int> list;
  list.push_front(0);
  print(list);
  list.push_front(5);
  print(list);
  list.insert_after(5, 3);
  print(list);
  list.insert_after(5, 2);
  print(list);
  list.insert_after(3, 5);
  print(list);
  list.insert_after(1, 17);
  print(list);
  list.insert_after(3, 13);
  print(list);
  list.insert_after(13, 2);
  print(list);
  list.insert_after(2, 4);
  print(list);
  list.insert_after(17, 12);
  print(list);
}

/* Ausgabe:

0
5, 0
5, 3, 0
5, 2, 3, 0
5, 2, 3, 5, 0
5, 2, 3, 5, 0
5, 2, 3, 13, 5, 0
5, 2, 3, 13, 2, 5, 0
5, 2, 4, 3, 13, 2, 5, 0
5, 2, 4, 3, 13, 2, 5, 0

*/