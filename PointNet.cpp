//
// Created by onekram on 11/2/23.
//
#include <iostream>
#include "PointNet.h"

PointNet::PointNet(const uint64_t size) {
    this->size = size;
    amount = 0;
    points = new Point[size];
}
bool PointNet::checkExists(const Point& point, bool add) const {
    for (uint64_t i = 0; i < amount; i++) {
        if (points[i].x == point.x && points[i].y == point.y) {
            if (add)
                points[i].value += point.value;
            else
                points[i].value = point.value;
            return true;
        }
    }
    return false;
}

void PointNet::putPoint(const Point& point, bool add) {
    updateBoundCoords(point.x, point.y);
    if (amount == 0 || !checkExists(point, add)) {
        if (amount + 1 > size) {
            uint64_t newSize = size * 2;
            auto *pointNetExt = new Point[size];
            std::memcpy(pointNetExt, points, newSize);  // work invalid
            points = pointNetExt;
            delete[] pointNetExt;
        }
        points[amount] = point;
        amount++;
    }
}

Point PointNet::getPoint(const uint64_t index) const {
    return points[index];
}

void PointNet::updateBoundCoords(int16_t x, int16_t y) {
    if (x > maxCoordX) maxCoordX = x;
    if (y > maxCoordY) maxCoordY = y;
    if (x < minCoordX) minCoordX = x;
    if (y < minCoordY) minCoordY = y;
}

uint64_t PointNet::getSize() const {
    return amount;
}
int PointNet::getLength() const {
    return maxCoordY - minCoordY + 1;
}

int PointNet::getWidth() const {
    return maxCoordX - minCoordX + 1;
}

void PointNet::createNet() {
    int length = getLength();
    int width = getWidth();
    std::cout << length << " - length" << std::endl;
    std::cout << width << " - width" << std::endl;

    net = new uint64_t*[width];  // work invalid

    for (int i = 0; i < width; ++i) {
        net[i] = new uint64_t[length];
        for (int j = 0; j < length; ++j) {
            net[i][j] = 0;
        }
    }
}

void PointNet::fillNet() {
    createNet();

    for (int i = 0; i < amount; ++i) {
        Point point = getPoint(i);
        net[point.x - minCoordX][point.y - minCoordY] = point.value;
    }
}

uint64_t** PointNet::getNet() const {
    return net;
}
bool PointNet::iteration() {
    fillNet();
    bool res = false;
    int len = getLength();
    int wid = getWidth();
    int mx = minCoordX;
    int my = minCoordY;
    for (int i = 0; i < wid; ++i) {
        for (int j = 0; j < len; ++j) {
            if (net[i][j] >= 4) {
                uint64_t val = net[i][j] % 4;
                putPoint(Point{static_cast<int16_t>(i + mx), static_cast<int16_t>(j + my), val});
                uint64_t newVal = net[i][j] / 4;
                putPoint(Point{static_cast<int16_t>(i - 1 + mx), static_cast<int16_t>(j + 1 + my), newVal}, true);
                putPoint(Point{static_cast<int16_t>(i - 1 + mx), static_cast<int16_t>(j - 1 + my), newVal}, true);
                putPoint(Point{static_cast<int16_t>(i + 1 + mx), static_cast<int16_t>(j + 1 + my), newVal}, true);
                putPoint(Point{static_cast<int16_t>(i + 1 + mx), static_cast<int16_t>(j - 1 + my), newVal}, true);
                res = true;
            }
        }
    }
    delete[] net;
    fillNet();
    return res;
}




