
// Copyright 2021 ivan <ikhonyak@gmail.com>
#ifndef INCLUDE_ELEM_HPP_
#define INCLUDE_ELEM_HPP_

template <typename T>
struct StructElem {
  T elem;
  StructElem* early_Elem = nullptr;
};

#endif  // INCLUDE_ELEM_HPP_
