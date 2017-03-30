#ifndef SQUARE_H
#define SQUARE_H


class Square
{
    public:
        Square();
        virtual ~Square();
        void setAcross(int ac);
        void setDown(int dow);
        void setRegion(int reg);
        void setValue(int val);
        void setIndex(int ind);
        int getAcross();
        int getDown();
        int getRegion();
        int getValue();
        int getIndex();
    protected:
    private:
        int across;
        int down;
        int region;
        int value;
        int index;
};

#endif // SQUARE_H
