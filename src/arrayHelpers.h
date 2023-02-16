#pragma once

namespace ArrayHelpers
{
  // increase array size by 1
  template <typename T>
  T *increaseArraySize(T *array, int &size)
  {
    // Create an array with the current size + 1
    T *newArray = new T[size + 1];

    memcpy(newArray, array, size * sizeof(T));

    size++;

    delete[] array;

    return newArray;
  }

  // insert item on array (and automatically increase array size by 1)
  template <typename T>
  T *increaseAndInsertItem(T *array, int& size, T item)
  {
    T *newArray = increaseArraySize(array, size);

    newArray[size] = item;

    return newArray;
  }

  // get index of item, returns -1 if item doesn't exist
  template <typename T>
  int indexOf(T *array, int size, T item)
  {
    int index = -1;

    int i = 0;
    while (i < size && index != -1)
    {
      if (array[i] == item)
      {
        index = i;
      }
      i++;
    }

    return index;
  }

  // check if item exists in array
  template <typename T>
  bool exists(T *array, int size, T item)
  {
    return indexOf(array, size, item) != -1;
  }

}