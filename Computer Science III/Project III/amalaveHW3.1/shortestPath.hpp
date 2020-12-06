#ifndef SHORTESTPATH
#define SHORTESTPATH

#include<iostream>
#include<limits>
#include<stack>
#include "BinaryHeap.hpp"

using namespace std;

void dijkstra(const double* const* matrix,int numVertices,int source,double*& dist,int*& prev);

void dijkstra(const int* const* adj,const double* const* weights,const int* lengths,int numVertices,int source,double*& dist,int*& prev);

int getPath(int source,int dest,const int* prev,int*& path);

#endif