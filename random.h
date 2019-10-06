#ifndef RANDOM_H
#define RANDOM_H


class random
{
public:
    random();
    void seed();
    int next(int lo, int hi);
};

#endif // RANDOM_H
