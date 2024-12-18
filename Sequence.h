#pragma once

template<typename T>
class Sequence {
public:
    virtual T& get(int index) = 0;
    virtual const T& get(int index) const = 0;
    virtual void set(int index, const T& value) = 0;
    virtual int getSize() const = 0;
    virtual ~Sequence() = default;
    virtual void concat(std::shared_ptr<Sequence<T>> other) = 0;
};