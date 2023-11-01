//
// Created by onekram on 11/2/23.
//

#include "PointNet.h"

PointNet::PointNet(const uint64_t size) {
    this->size = size;
    points = new Point[size];
}

void PointNet::putPoint(const Point& point, const uint64_t index) {
    if (index + 1 > size) {
        uint64_t newSize = size *  2;
        auto* pointNetExt = new Point[size];
        std::memcpy(pointNetExt, points, newSize);
        points = pointNetExt;
    }
    points[index] = point;
}

Point PointNet::getPoint(const int64_t index) const {
    return points[index];
}

