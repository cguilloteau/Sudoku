#include <iostream>
#include<string>

#ifndef SQUARE_H
#define SQUARE_H

using namespace std;

class Square
{
    public:
        Square();
        virtual ~Square();
        void setAcross(const int ac);
        void setDown(const int dow);
        void setRegion(const int reg);
        void setValue(const int val);
        void setIndex(const int ind);
        int getAcross()const;
        int getDown()const;
        int getRegion()const;
        int getValue()const;
        int getIndex()const;
        friend ostream& operator<< (ostream&, const Square&);

    protected:
    private:
        int across;
        int down;
        int region;
        int value;
        int index;
};

#endif // SQUARE_H
