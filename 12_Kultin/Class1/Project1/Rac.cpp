#include "Rac.h";
#include "cmath";

void Rac::algAct(Rac s1, Rac s2, string act) {
    int chl1 = s1.chis;
    int chl2 = s2.chis;
    int znm1 = s1.znam;
    int znm2 = s2.znam;
    int chl3, znm3;
    if (act == "+" || act == "-") {
        if (znm1 != znm2) {
            int mx = (znm1 > znm2) ? znm1 : znm2;
            int mn = (znm1 < znm2) ? znm1 : znm2;

            if ((mx % mn) == 0) {
                if (mx == znm1) chl2 = chl2 * (mx / mn);
                else chl1 = chl1 * (mx / mn);
                chl3 = chl1 + chl2;
                znm3 = mx;

            }
            else {
                chl1 = chl1 * znm2;
                chl2 = chl2 * znm1;
                if (act == "+")
                    chl3 = chl1 + chl2;
                else
                    chl3 = chl1 - chl2;
                znm3 = znm1 * znm2;
            }
        }
        else {
            if (act == "+")
                chl3 = chl1 + chl2;
            else
                chl3 = chl1 - chl2;

            znm3 = znm1;
        }
    }
    else {
        if (act == "*") {
            chl3 = chl1 * chl2;
            znm3 = znm1 * znm2;
        }
        if (act == "/") {
            chl3 = chl1 * znm2;
            znm3 = chl2 * znm1;
        }
        else
            cout << "Wrong apperation!";
    }

    if (chl3 % znm3 != 0 && znm3 % chl3 != 0 ) {
        int vver = (chl3 > znm3) ? int(floor((chl3 / 2))) : int(floor((znm3 / 2)));
        int n = 2;
        while (n != vver) {
            while (chl3 % n == 0 && znm3 % n == 0)
            {
                chl3 /= n;
                znm3 /= n;            
            }
            n++;
        }
        cout << chl3 << "\n--\n" << znm3;
    }
    else {
        if (chl3 % znm3 == 0)
            cout << chl3 / znm3;
        else
            cout << 1 << "\n--\n" << znm3 / chl3;
    }
    

}


