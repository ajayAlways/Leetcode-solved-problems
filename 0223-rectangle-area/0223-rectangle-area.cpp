class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area=0;
            if (C<=E || A>=G || B>=H || D<=F )
            return (C-A)*(D-B)+(G-E)*(H-F);
        else
        {
            vector <int> h;
            h.push_back(A);
            h.push_back(C);
            h.push_back(E);
            h.push_back(G);

            vector <int> v;
            v.push_back(B);
            v.push_back(D);
            v.push_back(F);
            v.push_back(H);

            sort(h.begin(), h.end());
            sort(v.begin(), v.end());

            area = -(h[2] - h [1]) * (v[2] - v[1]);
            area=(C-A)*(D-B)+area+(G-E)*(H-F);
            return area;
    }
        return 0;
    }
};