#include "train.h"
#include <iostream>
#include <iomanip>

int main() {
    std::cout << "[cars]" << ' ' << "[false]" << ' ' << "[true]" << ' ' << "[true&false]" << std::endl;
    for (int i = 10; i < 101; i += 10) {
        Train train1, train2, train3;
        for (int j = 0; j < i; j++) {
            train1.addCar(false);
            train2.addCar(true);
            train3.addCar((j % 2 == 0));
        }
        train1.getLength();
        train2.getLength();
        train3.getLength();
        
        std::cout << i << ' ' << train1.getOpCount() << ' ' << train2.getOpCount() << ' ' << train3.getOpCount() << std::endl;
    }
}