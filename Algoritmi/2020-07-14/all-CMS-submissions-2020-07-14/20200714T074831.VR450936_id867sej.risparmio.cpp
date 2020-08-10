/**
* user:  VR450936_id867sej
* fname: FRANCESCO
* lname: MARTINI
* task:  risparmio
* score: 100.0
* date:  2020-07-14 07:48:31.496206
*/
#include<iostream>
#include<string>
#include<fstream>
#include<list>
#include<vector>
#include<time.h>

using namespace std;

struct nodo {
    int v;
    bool dx;
    bool sx;
    bool f;
};

int N, M;
nodo node0 = { 0, false, false, false }, node1 = { 1, true, true, true };
vector<nodo> vec(262145, node0);

bool update(int a, int lsx, int ldx, int pos) {

    int temp = 0;
    nodo tmp = vec[a];
    if (ldx == lsx) {
        if (vec[a].f)
            vec[a] = node0;
        else
            vec[a] = node1;
    }
    else {
        int tm = (ldx + lsx) / 2;
        if (pos <= tm)
        {
            if (!update(a * 2, lsx, tm, pos)) return false;
        }
        else
        {
            if (!update(a * 2 + 1, tm + 1, ldx, pos)) return false;
        }

        vec[a].sx = vec[a * 2].sx;
        vec[a].dx = vec[a * 2 + 1].dx;

        if (vec[a * 2].f && vec[a * 2 + 1].f) {
            vec[a].f = true;
            vec[a].v = 1;
            if (tmp.dx == vec[a].dx && tmp.f == vec[a].f && tmp.sx == vec[a].sx && tmp.v == vec[a].v) return false;
            else return true;
        }

        vec[a].f = false;

        if (vec[a * 2].f) {
            vec[a].v = vec[a*2 + 1].v;
            if (!vec[a * 2 + 1].sx) vec[a].v+=1;
            if (tmp.dx == vec[a].dx && tmp.f == vec[a].f && tmp.sx == vec[a].sx && tmp.v == vec[a].v) return false;
            else return true;
        }

        if (vec[a * 2 + 1].f) {
            vec[a].v = vec[a * 2].v;
            if (!vec[a * 2].dx) vec[a].v+=1;
            if (tmp.dx == vec[a].dx && tmp.f == vec[a].f && tmp.sx == vec[a].sx && tmp.v == vec[a].v) return false;
            else return true;
        }

        vec[a].v = vec[a * 2].v + vec[a * 2 + 1].v;
        if (vec[a * 2].dx && vec[a * 2 + 1].sx) vec[a].v -=1;
        
        if (tmp.dx == vec[a].dx && tmp.f == vec[a].f && tmp.sx == vec[a].sx && tmp.v == vec[a].v) return false;
    }

    return true;
}


nodo get_val(int a, int lsx, int ldx, int sx, int dx) {

    if (sx > dx)
        return node0;

    if (sx == lsx && dx == ldx)
        return vec[a];

    int tm = (ldx + lsx) / 2;
    nodo tmpsx, tmpdx, tmp;

    if (tm < dx) tmpsx = get_val(a * 2, lsx, tm, sx, tm);
    else tmpsx = get_val(a * 2, lsx, tm, sx, dx);

    if (tm < sx) tmpdx = get_val(a * 2 + 1, tm + 1, ldx, sx, dx);
    else tmpdx = get_val(a * 2 + 1, tm + 1, ldx, tm + 1, dx);

    tmp.sx = tmpsx.sx;
    tmp.dx = tmpdx.dx;

    if (tmpsx.f && tmpdx.f) {
        tmp.f = true;
        tmp.v = 1;
        return tmp;
    }

    tmp.f = false;

    if (tmpsx.f) {
        tmp.v = tmpdx.v;
        if (!tmpdx.sx) tmp.v += 1;
        return tmp;
    }

    if (tmpdx.f) {
        tmp.v = tmpsx.v;
        if (!tmpsx.dx) tmp.v += 1;
        return tmp;
    }

    tmp.v = tmpsx.v + tmpdx.v;
    if (tmpsx.dx && tmpdx.sx) tmp.v -= 1;

    return tmp;
}


int main() {

    ifstream ifile;
    ofstream ofile;
    int val, a = 0, b;


    ofile.open("./output.txt");
    if (ofile.is_open()) {

        ifile.open("./input.txt");
        if (ifile.is_open()) {

            ifile >> N;

            for (b = 1; b < N; b *= 2);

            N = b;

            ifile >> M;

            for (int i = 0; i < M; i++) {
                
                ifile >> val ;

                if (val == 1) {
                    ifile >> a;
                    update(1, 1, N, a+1);
                }
                else {
                    ifile >> a >> b;
                    ofile << get_val(1, 1, N, a+1, b+1).v << endl;
                }
                
            }

            ifile.close();

        }
        else {
            cout << "fail";
        }

        ofile.close();

    }
    else {
        cout << "fail";
    }

    return 0;

}