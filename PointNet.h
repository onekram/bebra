//
// Created by onekram on 11/2/23.
//

#ifndef LABWORK3_ONEKRAM_POINTNET_H
#define LABWORK3_ONEKRAM_POINTNET_H

#endif //LABWORK3_ONEKRAM_POINTNET_H


#include <cstdint>
#include <cstring>

#pragma pack(push, 4)
struct Point {
    int16_t x, y;
    uint64_t value;
};
#pragma pack(pop)


class PointNet {
private:
    uint64_t size;
    Point* points;
public:
    explicit PointNet(uint64_t size);

    void putPoint(const Point& point, uint64_t index);

    Point getPoint(int64_t index) const;
};


