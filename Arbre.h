#include <vector>

template <class T>
class Noeud {
    public : 
    T info;
    Noeud<T> *fg;
    Noeud<T> *fd;
    public :
    Noeud(T info);
    Noeud(T info, Noeud<T> *fg, Noeud<T> *fd);
};


template <class T>
class Arbre{
    private :  
    Noeud<T> *racine;

    public : 
    Arbre(){};
    Arbre(T);
    Arbre(Noeud<T> *nd);
    void AfficherArbre();
    void InsererNoeud(Noeud<T> *);

    private : 
    Noeud<T>* InsererInfos(Noeud<T> *,T);   

    public :
    void InsererInfos(T);
    void print2DUtil(Noeud<T> *,int);
    void print2D();

    private :
    void ParcourirArbre(Noeud<T>*);

    public : 
    void ParcourirArbre();

};