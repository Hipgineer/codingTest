#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct point
{
    int64_t x;
    int64_t y;
    int64_t r;
    int64_t parentID;
};

inline bool areTheyConnected(const point &p1, const point &p2)
{
    int64_t dist = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    if (dist <= (p1.r + p2.r) * (p1.r + p2.r))
        return true;
    else
        return false;
}

int64_t getOriginParentID(const vector<point> &arr, const int64_t &idx)
{
    int64_t pID = arr[idx].parentID;
    int64_t res;
    if (pID != idx)
        res = getOriginParentID(arr, pID);
    else
        res = idx;

    return res;
}

int main()
{
    int64_t T, N;
    point tmp;
    vector<point> arr;
    bool firstCheck = true;
    int64_t oID;
    // vector<int64_t> res;

    scanf("%lld", &T);
    // res.reserve(T);
    for (int64_t tt = 0; tt < T; ++tt)
    {
        arr.resize(0);
        scanf("%lld", &N);
        arr.reserve(N);
        int64_t nOrigin = 0;
        for (int64_t nn = 0; nn < N; ++nn)
        {
            scanf("%lld %lld %lld", &(tmp.x), &(tmp.y), &(tmp.r));
            tmp.parentID = nn;
            arr.push_back(tmp);
        }

        for (int64_t nn = 0; nn < N - 1; ++nn)
        {
            for (int64_t vv = nn + 1; vv < N; ++vv)
            {
                if (areTheyConnected(arr[vv], arr[nn]))
                {
                    int64_t nOID = getOriginParentID(arr, nn);
                    int64_t vOID = getOriginParentID(arr, vv);
                    if (nOID < vOID)
                        arr[vOID].parentID = nOID;
                    else if (vOID < nOID)
                        arr[nOID].parentID = vOID;
                }
            }
        }

        for (int64_t nn = 0; nn < N; ++nn)
        {
            if (getOriginParentID(arr, nn) == nn)
                ++nOrigin;
        }
        printf("%lld\n", nOrigin);
    }
}