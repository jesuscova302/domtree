#ifndef NODO_H_
#define NODO_H_

#include<iostream>

template <class E>
class NODO
{
	private:
		E elemento;
		NODO<E> *prox;
		
	public:
		NODO<E>() : prox(NULL){};
		NODO<E>(E elem) : elemento(elem){};
		NODO<E>(E elem,NODO<E> *nod) : elemento(elem), prox(nod){};
		E get_elemento()  {return(elemento); }			
        NODO<E> *proximo(){return prox;} 
		void  set_elemento(E elem) { elemento = elem; }
		void set_proximo(NODO<E> *sig) {prox=sig;}			
};

	
#endif
