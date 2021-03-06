#ifndef RTREE_H
#define RTREE_H
#include "node.h"
#include <stack>


class Rtree
{
    public:
        unsigned int m;
        Rtree();
        Rtree(unsigned int max_children);
        void rtinsert (point d);
        float distance_points(point A, point B);
        float distance_rec_point(point d,point cmin, point cmax);
        void bigger_Rec(point Amin,point Amax,point Bmin, point Bmax, point& Cmin, point& Cmax);
        void adjusttree (node**& p,stack<node**>& path);
        void splitnode (node**& p,stack<node**>& path);
        void pickseeds (int& ii, int& jj, node** p);
        bool findpointleaf (node**& p,point d);
        bool overlap(point p, point gmin, point gmax);
        void picknext (int& ii, node** p,vector<node*>&temp,node* l, node* r,float& d1f,float& d2f);
        float area (point cmin, point cmax);
        node* root;
        void chooseleaf (point d, node**& p,stack<node**>& path);
        ~Rtree();
};

#endif // RTREE_H
