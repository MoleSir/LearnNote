#ifndef __PRINTER_HH__
#define __PRINTER_HH__

class Printer
{
public:
    Printer() : _x(0.0f), _y(0.0f), _z(0.0f) {}
    Printer(float x, float y, float z) : _x(x), _y(y), _z(z) {}

    void moveUp(float distance)
    { this->_z += distance; }
    void moveDown(float distance)
    { this->_z -= distance; }

    void moveLeft(float distance)
    { this->_x += distance; }
    void moveRight(float distance)
    { this->_x -= distance; }

    void moveFront(float distance)
    { this->_y += distance; }
    void moveBack(float distance)
    { this->_y -= distance; }

    void clear()
    {
        this->_x = 0.0f;
        this->_y = 0.0f;
        this->_z = 0.0f;
    }

private:
    float _x, _y, _z;

public:
    float x() const { return this->_x; }
    float y() const { return this->_y; }
    float z() const { return this->_z; }
};

#endif