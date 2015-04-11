
#ifndef DOM_TREE_H_
#define DOM_TREE_H_

//~ #include "lista.h"
#include "node.h"

//~ using std::ostream;
//~ using std::cout; 
using namespace std;

template <class Element>
class DOM_Tree
{
	/**ATRIBUTOS**/
	private:
		Node<Element>  *document;	

	private:
		 static Node<Element> *copiar_nodos(Node<Element> *ptr);
		 static void destruir( Node<Element> *&ptrRaiz);
		 static Node<Element>* buscar(Node<Element> *ptr, Element elem, bool &entrar );	
		 void recorrido_preorden( Node<Element> *ptrRaiz,LISTA<Element> &lis );
		 void preorden(DOM_Tree<Element> A,LISTA<Element> &lis);
	/**METODOS**/
	public:
		/**constructores**/
		DOM_Tree<Element>():document(NULL){};                                    				
		DOM_Tree<Element>( Element elem );                									 
		DOM_Tree<Element>( Element elem,LISTA< DOM_Tree<Element> > lst_arb );              	  
		DOM_Tree<Element>( const DOM_Tree<Element> &dom );              	  
		
		/**verificadores**/
		bool esNulo() { document == NULL; }
		//~ void preorden(DOM_Tree<Element> A,LISTA<Element> &lis);
		
		Node<Element>* get_document() const { return (document); } 
		DOM_Tree<Element> childNode(int pos);  
		DOM_Tree<Element> getElementByID(Element elem);	
		//~ friend std::ostream& operator<<(std::ostream& os, const DOM_Tree<Element> &dom);	
		//~ ostream& operator<<(std::ostream& os, const DOM_Tree<Element> &dom);	
		void operator=(const DOM_Tree<Element> &dom);
		
		
		/**modificadores**/
	    void appendChild(DOM_Tree<Element> dom,int pos);
	    void appendChild(DOM_Tree<Element> dom);
	    void replaceChild(DOM_Tree<Element> dom,int pos);  
	    void removeChild(int pos);
	    ~DOM_Tree();
};

/***IMPLEMENTACION***/

template <class Element>
void DOM_Tree<Element>::preorden(DOM_Tree<Element> A,LISTA<Element> &lis)
{
	LISTA<Element> list();
	recorrido_preorden(A.document, list);
}

template <class Element>
void DOM_Tree<Element>::recorrido_preorden(Node<Element> *ptrRaiz,LISTA<Element> &lis)
{
	Node<Element> *aux;
	if(ptrRaiz != NULL)
	{	
		lis.insertar_al_final( ptrRaiz->element() );
		aux = ptrRaiz->getFirstChild();
		while(aux != NULL)
		{
			recorrido_preorden(aux);
			aux = aux->getNextSibling();	
		}
	}
}
/*
template <class Element>
ostream& operator<<(std::ostream& os, const DOM_Tree<Element>& dom)
{
	LISTA<Element> list();
    int i;
    
	preorden(dom,list);

	for(i=1;i<=list.longitud();i++)
		os << "<"<< list.consultar_por_pos(i).get_tagName()<< " " <<list.consultar_por_pos(i).get_attrList() <<  " " <<list.consultar_por_pos(i).get_innerHTML()<< ">"<<endl;
	
	return os;
		
}*/

template <class Element>
DOM_Tree<Element>::DOM_Tree( const DOM_Tree<Element> &dom )
{
	document = copiar_nodos( dom.document );
}

template <class Element>
void DOM_Tree<Element>::operator=(const DOM_Tree<Element> &dom)
{
	document = copiar_nodos( dom.document );

}

template <class Element>
DOM_Tree<Element>::DOM_Tree( Element elem ) 
{
	document = new Node<Element>(elem);
	
}

template <class Element>
Node<Element>* DOM_Tree<Element>::copiar_nodos(Node < Element > *ptr)
 {
	Node<Element> *nuevo_nodo;
	
	if(ptr == NULL)
	{
		return(NULL);
	}else
	{
		nuevo_nodo = new Node<Element>();
	    nuevo_nodo = new Node<Element>(ptr->element(),copiar_nodos( ptr->getFirstChild() ),copiar_nodos( ptr->getNextSibling()) );
		return(nuevo_nodo);
	} 
}
		
template <class Element>
DOM_Tree<Element>::DOM_Tree( Element elem,LISTA< DOM_Tree<Element> > lst_arb )
{
	int i=1;
	Node<Element> *aux;
	DOM_Tree<Element> arb_aux,arb_aux2;
		
	this->document = new Node<Element>();
	this->document->setElement(elem);
	
	if( !lst_arb.es_vacia() )
	{	
		this->document->setFirstChild(   copiar_nodos( lst_arb.consultar_por_pos(1).document ) );
		lst_arb.eliminar_por_pos(1);	
		aux = this->document->getFirstChild();
		while(!lst_arb.es_vacia() )
		{	
			aux->setNextSibling( copiar_nodos( lst_arb.consultar_por_pos(1).document) );
			lst_arb.eliminar_por_pos(1);
		    aux = aux->getNextSibling();
		}
	}	
}

template <class Element>
DOM_Tree<Element> DOM_Tree<Element>::childNode(int pos)
{
    Node<Element> *aux;
    DOM_Tree<Element> subarbol;
    int i;
    
    if(pos == 1)
    {
		subarbol.document = copiar_nodos( document->get_firstChild() );
    }else
    {
        aux = document->get_firstChild( );
        for(i=2;i<pos;i++)
        {
		    aux = aux->get_nextSibling();  
        }
        subarbol.document = copiar_nodos( aux->get_nextSibling() );
    }
	return ( subarbol );
}

/**Elimina el hijo de la posición pos del árbol.**/
template <class Element>
void DOM_Tree<Element>::removeChild(int pos)
{
    Node<Element> *aux,*elim;
    DOM_Tree<Element> subarbol;
    int i;
    
    if(pos == 1)
    {
		subarbol.document = document->get_firstChild();
		document->set_firstChild(  document->get_firstChild( )->get_nextSibling( ) );
    }else
    {
        aux = document->get_firstChild();
        for(i=2;i<pos;i++)
        {
		    aux = aux->get_nextSibling();  
        }
		subarbol.document = aux->get_nextSibling();  
		aux->set_nextSibling( aux->get_nextSibling()->get_nextSibling() );

    }
	//destruir(subarbol.nodoRaiz);
	subarbol.~DOM_Tree() ; //DESTRUIR EL SUBARBOL "PENDIENTE RESOLVER"
}
/*
template <class Element>
void DOM_Tree<Element>::removeChild(int pos)
{
    Node<Element> *aux,*elim;
    int i;
    
    if(pos == 1)
    {
		destruir(  document->get_firstChild()->get_firstChild());
    }else
    {
        aux = document->get_firstChild();
        for(i=2;i<pos;i++)
        {
		    aux = aux->get_nextSibling();  
        }
        destruir(  aux->get_nextSibling()->get_firstChild() );		
    }
	
}
*/


template <class Element>
void DOM_Tree<Element>::appendChild(DOM_Tree<Element> dom,int pos)
{

	Node<Element>  *aux,*ant,*nuevo;
	int i;
   
    
	if( pos == 1)
	{	
		aux = document->get_firstChild();
		document->set_firstChild( copiar_nodos( dom.document) );
		document->get_firstChild()->set_nextSibling(aux);
	}else
	{
		nuevo = new Node<Element>( copiar_nodos(dom.document) );
		aux = document->get_firstChild();
		ant = NULL;	  
		for(i=2;i<pos;i++)
		{	
			aux = aux->get_nextSibling();
		}
		nuevo->set_nextSibling(aux);
		if( ant == NULL)
		{
			document->get_firstChild()->set_nextSibling(nuevo);
		}else
		{
			ant->set_nextSibling( nuevo  );
		}		
	}
}


template <class Element>
void DOM_Tree<Element>::replaceChild(DOM_Tree<Element> dom,int pos)
{ 
	Node<Element> *aux,*elim,*nuevo;
    DOM_Tree<Element> subarbol;
    int i;
    
    nuevo = copiar_nodos( dom.document );
    
    if(pos == 1)
    {
		subarbol.document = document->get_firstChild();
		nuevo->set_nextSibling(  document->get_firstChild( )->get_nextSibling( ) );
		document->set_firstChild( nuevo  );
    }else
    {
        aux = document->get_firstChild();
        for(i=2;i<pos;i++)
        {
		    aux = aux->get_nextSibling();  
        }
		subarbol.document = aux->get_nextSibling();  
		nuevo->set_nextSibling(  aux->get_nextSibling()->get_nextSibling() );
		aux->set_nextSibling( nuevo );

    }
	//destruir(subarbol.nodoRaiz);
	subarbol.~DOM_Tree() ; //DESTRUIR EL SUBARBOL "PENDIENTE RESOLVER"

} 

template <class Element>
void DOM_Tree<Element>::destruir( Node<Element> *&ptrRaiz)
{
	 Node<Element> *aux;

	if(ptrRaiz != NULL)
	{	
		aux = ptrRaiz->getFirstChild( );
		destruir(aux);
			
		while(aux != NULL)
		{	
			aux = aux->getNextSibling();
			destruir(aux);
		}	
		delete (aux);
		ptrRaiz = NULL;
	}	
}

template <class Element>
Node<Element>* DOM_Tree<Element>::buscar(Node<Element> *ptr, Element elem,bool &entrar)
{	
	if (ptr != NULL )
	{
		if ( entrar )
		{
			if( ptr->element() == elem  ) return ( copiar_nodos( ptr ) );
			else
			{
				buscar(ptr->getFirstChild(), elem);
				buscar(ptr->getNextSibling(), elem);
			}
		}
	}
}

template <class Element>
DOM_Tree<Element> DOM_Tree<Element>::getElementByID(Element ID )
{
	bool entrar;
	DOM_Tree<Element> DOM_ID;
	
	if ( document != NULL )	
	{
		entrar = true;
		DOM_ID.document =  buscar(document,ID,entrar) ; 
	}
	return ( DOM_ID );
}

template <class Element>
DOM_Tree<Element>::~DOM_Tree() 
{
	destruir( document );		
}


#endif
