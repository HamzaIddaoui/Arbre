#include <iostream>
#include <vector>
#include "Arbre.h"
#include <time.h>
#define COUNT 10
using namespace std;

template <class T>
Noeud<T>::Noeud(T info){
    this->info = info;
    this->fd = this->fg = NULL;
}

template <class T>
Noeud<T>::Noeud(T info, Noeud<T> *fg, Noeud<T> *fd){
    this->info = info;
    this->fg = fg;
    this->fd = fd;
}

template <class T>
Arbre<T>::Arbre(T info){
    this->racine = new Noeud<T>(info);
}

template <class T>
Arbre<T>::Arbre(Noeud<T> *nd){
    this->racine = nd;
};

template <class T>
Noeud<T>* Arbre<T>::InsererInfos(Noeud<T> *racine,T info){
    if(racine == NULL) {
        racine = new Noeud<T>(info);
        return racine;
    }
    if(info > racine->info)
        racine->fd = this->InsererInfos(racine->fd,info);
    else {
        racine->fg = this->InsererInfos(racine->fg,info);
    }
    return racine;
};


template <class T>
void Arbre<T>::InsererInfos(T info){
    this->InsererInfos(this->racine,info);
};


template <class T>
void Arbre<T>::print2DUtil(Noeud<T> *nd,int space){
    if (nd == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(nd->fd, space);
 
    // Print current node after space
    // count
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << nd->info << "\n";
 
    // Process left child
    print2DUtil(nd->fg, space);
};

template <class T>
void Arbre<T>::print2D(){
    this->print2DUtil(this->racine,0);
};

template <class T>
void Arbre<T>::ParcourirArbre(Noeud<T> * nd){
    if(nd == NULL) return;
    cout << nd->info << " ";
    this->ParcourirArbre(nd->fd);
    this->ParcourirArbre(nd->fg);
}

template <class T>
void Arbre<T>::ParcourirArbre(){
    time_t start,end;
    time(&start);
    this->ParcourirArbre(this->racine);
    time(&end);
    double time_taken = double(end - start);
    cout << "Temps d'execution = " << time_taken << endl;
}

int main() 
{ 
    Arbre<int> *arb = new Arbre<int>(5);
    time_t start,end;
    time(&start);
    for(int i=0;i < 100000 ; i++) arb->InsererInfos(rand());
    time(&end);
    double time_taken = double(end - start);
    cout << "Temps d'execution = " << time_taken << endl;
    //arb->print2D();
    cout << endl;
    arb->ParcourirArbre();
    return 0;
}