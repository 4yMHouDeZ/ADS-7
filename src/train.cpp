// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* tempCar = new Car;
    tempCar->light = light;
    if (first == nullptr) {
        first = tempCar;
        tempCar->next = tempCar;
        tempCar->prev = tempCar;
    } else {
        Car* lastCar = first->prev;
        tempCar->prev = lastCar;
        lastCar->next = tempCar;
        tempCar->next = first;
        first->prev = tempCar;
    }
}

int Train::getLength() {
    first->light = true;
    Car* current = first->next;
    countOp++;
    while (true) {
        int len = 1;
        while (!current->light) {
            current = current->next;
            countOp++;
            len++;
        }
        current->light = false;
        for (int i = 0; i < len; i++) {
            current = current->prev;
            countOp++;
        }
        if (!current->light) {
            return len;
        } else {
            current = current->next;
            countOp++;
        }
    }
}

int Train::getOpCount() {
    return countOp;
}

Train::~Train() {
    if (first == nullptr) return;
    Car* current = first, * nextCar;
    do {
        nextCar = current->next;
        delete current;
        current = nextCar;
    } while (current != first);
}