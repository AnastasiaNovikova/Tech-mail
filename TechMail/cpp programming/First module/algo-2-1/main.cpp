//
//  main.cpp
//  Sort-2-1
//
//  Created by Анастасия on 15.11.14.
//  Copyright (c) 2014 AnastasiaNovikova. All rights reserved.
//

#include <iostream>

struct box {
    int length;
    int height;
    int width;
    int number;

    box() : length(0), height(0), width(0), number(0) {}
};

bool isLess (box a, box b) {
    if ((a.height > b.height) & ( a.length > b.length ) & (a.width > b.width)) return false;
    if ((a.height > b.length) & ( a.length > b.width ) & (a.width > b.height)) return false;
    if ((a.height > b.width) & ( a.length > b.height ) & (a.width > b.length)) return false;

    return true;
}

class CHeap {
public:
    CHeap(box *arr, size_t arrSize);
    ~CHeap();

    void heapify(size_t i);
    void buildHeap(void);
    void heap_sort(box**, size_t &);
    box extractMin();
    box readMin();

    size_t boxNumber;

private:
    box *pBoxArray;
    size_t pBoxArraySize;
};

CHeap::CHeap(box *arr, size_t arrSize) {
    pBoxArraySize = arrSize;
    boxNumber = arrSize;
    pBoxArray = new box[pBoxArraySize];

    for (size_t i = 0; i < arrSize; i++)
        pBoxArray[i] = arr[i];
    buildHeap();
}

CHeap::~CHeap() {
    delete[] pBoxArray;
}

void CHeap::heapify(size_t i) {
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;
    //Ищем маньшего сына
    size_t min = i;
    if (left < boxNumber && isLess(pBoxArray[left], pBoxArray[i]))
        min = left;
    if (right < boxNumber && isLess(pBoxArray[right], pBoxArray[min]))
        min = right;
    //Если есть меньший сын ...
    if (min != i) {
        std::swap(pBoxArray[min], pBoxArray[i]);
        CHeap::heapify(min);
    }
}

void CHeap::buildHeap(void) {
    for (int i = (int) (boxNumber / 2 - 1); i >= 0; --i)
        heapify((size_t) i);
}

box CHeap::readMin() {
    return pBoxArray[0];
}

box CHeap::extractMin() {
    if (boxNumber == 0) return box();

    box result = pBoxArray[0];
    pBoxArray[0] = pBoxArray[boxNumber - 1];
    boxNumber--;
    if (boxNumber > 1) heapify(0);
    return result;
}

void CHeap::heap_sort(box **data, size_t &n) {
    n = 0;
    *data = new box[boxNumber];

    while (boxNumber) {
        *data[n] = readMin();
        extractMin();
        n++;
    }
}

int main() {

    size_t arraySize;
    std::cin >> arraySize;
    box* array = new box[arraySize];

    for (int i = 0; i < arraySize; i++) {
        std::cin >> array[i].height ;
        std::cin >> array[i].length ;
        std::cin >> array[i].width ;
        array[i].number = i;
    }

    CHeap hBoxes(array, arraySize);
    std::cout << 5;
    box* sortedArray;
    size_t n;
    hBoxes.heap_sort(&sortedArray, n);
    std::cout << 7;
    for (int i = 0; i < arraySize; i++){
        std::cout << sortedArray[i].number << " ";
    }
    delete [] sortedArray;
    delete [] array;
    return  0;
}





