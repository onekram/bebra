//
// Created by onekram on 11/2/23.
//

#ifndef LABWORK3_ONEKRAM_POINTNET_H
#define LABWORK3_ONEKRAM_POINTNET_H

#endif //LABWORK3_ONEKRAM_POINTNET_H


#include <cstdint>
#include <cstring>
#include <limits>

#pragma pack(push, 4)

struct Point {
    int16_t x{}, y{};
    uint64_t value{};
};
#pragma pack(pop)


class PointNet {
private:
    uint64_t size; // real size of array
    uint64_t amount; // quantity of points
    uint64_t** net{};
    Point* points;

    int16_t maxCoordX = std::numeric_limits<int16_t>::min();
    int16_t maxCoordY = std::numeric_limits<int16_t>::min();
    int16_t minCoordX = std::numeric_limits<int16_t>::max();
    int16_t minCoordY = std::numeric_limits<int16_t>::max();

    void createNet();


public:
    explicit PointNet(uint64_t size);
    void putPoint(const Point& point, bool add = false);
    Point getPoint(uint64_t index) const;
    void updateBoundCoords(int16_t x, int16_t y);
    uint64_t getSize() const;
    void fillNet();
    uint64_t** getNet() const;
    int getWidth() const;
    int getLength() const;
    bool iteration();

    bool checkExists(const Point &point, bool add) const;
};


