#pragma once

template<typename T>
class Sequence {
public:
    virtual T& get(int index) = 0;
    virtual const T& get(int index) const = 0;
    virtual int getSize() const = 0;
    virtual ~Sequence() = default;
};