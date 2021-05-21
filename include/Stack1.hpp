#ifndef INCLUDE_FSTACK_HPP_
#define INCLUDE_FSTACK_HPP_

#include <StructElem.hpp>
#include <iostream>
#include <utility>

template <typename T>
class Stack1 {
 public:
  Stack1 ();
  Stack1 (Stack1  & elem);
  Stack1 (Stack1 && elem);
  ~Stack1 ();
  Stack1 <T>& operator =(Stack1 <T> &Elem);
  Stack1 <T>& operator =(Stack1 <T> &&Elem);
  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
  [[nodiscard]] size_t size() const;
  [[nodiscard]] bool empty() const;
 private:
  StructElem<T>* headElem = nullptr;
};

template <typename T>
Stack1 <T>& Stack1 <T>::operator=(Stack1 <T>&& elem)  {
  headElem = std::forward<StructElem<T>>(elem.headElem);
  return *this;
}

template <typename T>
Stack1 <T>& Stack1 <T>::operator =(Stack1 <T> & Elem) {
  headElem = Elem.headElem;
  Elem.headElem = nullptr;
  return *this;
}

template <typename T>
Stack1 <T>::Stack1 () {}

template <typename T>
Stack1 <T>::Stack1 (Stack1 <T>&& elem) {
  headElem = new StructElem<T>{std::forward<T>(elem.head()), elem};
  elem.headElem = nullptr;
}

template <typename T>
Stack1 <T>::Stack1 (Stack1 <T>& elem) {
  headElem = std::move(elem.headElem);
  elem.headElem = nullptr;
}

template <typename T>
Stack1 <T>::~Stack1 <T>() {
  while (headElem != nullptr)
    pop();
}

template <typename T>
void Stack1 <T>::push(T&& value) {
  StructElem<T>* link = headElem;
  headElem = new StructElem<T>{std::forward<T>(value), link};
}

template <typename T>
void Stack1 <T>::push(const T& value) {
  StructElem<T>* link = headElem;
  headElem = new StructElem<T>{value, link};
}

template <typename T>
void Stack1 <T>::pop(){
  if (headElem == nullptr)
    throw std::out_of_range("N = 0!");
  StructElem<T>* link = headElem;
  headElem = headElem->early_Elem;
  delete link;
}

template <typename T>
const T& Stack1 <T>::head() const {
  if (empty()){
    throw std::out_of_range("Stack is empty!");
  } else {
    return headElem->elem;
  }
}

template <typename T>
bool Stack1 <T>::empty() const{
  return headElem == nullptr;
}

template <typename T>
size_t Stack1 <T>::size() const {
  size_t n = 0;
  StructElem<T> *link = headElem;
  while (link != nullptr){
    ++n;
    link = link->early_Elem;
  }
  return n;
}

#endif  // INCLUDE_FSTACK_HPP_"
