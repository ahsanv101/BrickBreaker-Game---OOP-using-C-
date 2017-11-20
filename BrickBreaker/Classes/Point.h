#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        virtual ~Point();
        void Setx(int x);
        void Sety(int y);
        int Getx();
        int Gety();

    protected:

    private:
        int x;
        int y;
};

#endif // POINT_H
