#pragma once

#include "iostream"
using namespace std;

class Rac {
    private:
        int chis;
        int znam;
    public:
        void algAct(Rac s1, Rac s2, string act);
        // umn(Rac m1, Rac m2);
        // del(Rac d1; Rac d2);

        void get(int c, int z) {
            chis = c;
            znam = z;
        }
};