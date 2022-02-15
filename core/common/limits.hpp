#ifndef __LIMITS_HPP__
#define __LIMITS_HPP__

struct Limits {
    float max;
    float min;

    bool inRange(float value) { return max >= value && value >= min; };
};


#endif /* __LIMITS_HPP__ */
