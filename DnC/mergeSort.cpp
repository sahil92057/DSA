#include<iostream>
// #include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&v, vector<int>&temp, int s, int e, int m){
    int i=s, j=m+1, k=s;
    while(i<=m && j<=e){
        if(v[i]>v[j]) temp[k++]=v[j++];
        else temp[k++]=v[i++];
    }
    while(i<=m){ temp[k++]=v[i++];}
    while(j<=e){ temp[k++]=v[j++];}
    for(int l=s; l<=e; l++){
        v[l]=temp[l];
    }

}

void mergesort(vector<int>&v, vector<int>&temp, int s, int e){
   if(s>=e)return;
   int m = s+(e-s)/2;
   mergesort(v, temp, s, m);
   mergesort(v, temp, m+1, e);
   merge(v, temp, s, e, m);
}

int main (){
    vector<int>v={5,2,3,1};
   vector<int>temp(v.size());
    mergesort(v, temp, 0, v.size()-1);
    for(auto it:v){
        cout<<it<<" ";
    }
    return 0;
}