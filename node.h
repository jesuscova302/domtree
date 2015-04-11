#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include "element.cpp"
//using namespace std;

template <class Element>
class Node
{
	/**ATRIBUTOS**/
	private:
		Element e;
		Node<Element> *firstChild,*nextSibling;	

	/**METODOS**/
	public:
		Node<Element>() : firstChild(NULL), nextSibling(NULL){};
		Node<Element>(Element elem) : e(elem),firstChild(NULL), nextSibling(NULL){};
		Node<Element>(Element elem,Node<Element> *hj_i,Node<Element> *hn_d) :e(elem), firstChild(hj_i), nextSibling(hn_d){};
	    Node<Element>(const Node<Element> &nod);
	
		//~ Element	get_element(){return(e.get_innerHTML());}
		Element		element(){return(e);}
		Node<Element> *getFirstChild(){return(firstChild);}
		Node<Element> *getNextSibling(){return(nextSibling);}
		
		void setElement(Element elem){e = elem;}
		void setFirstChild(Node<Element> *hj_i){firstChild = hj_i;}
		void setNextSibling(Node<Element> *hn_d){nextSibling = hn_d;}
		void operator=(const Node<Element> &nod);
	
};

template <class Element>
Node<Element>::Node(const Node<Element> &nod)
{
	e = nod.e ;
	//~ e.Element( nod.e );
	//~ e.tagname = nod.tagname();
	//~ e.innerHTML = nod.innerHTML();
	//~ e.attrList = nod.attrlist();
    firstChild  = nod.firstChild ;
    nextSibling = nod.nextSibling;
}

template <class Element>
void Node<Element>::operator=(const Node<Element> &nod)
{
	e = nod.e ;
	//~ e.tagname = nod.tagname();
	//~ e.innerHTML = nod.innerHTML();
	//~ e.attrList = nod.attrlist();
    firstChild  = nod.firstChild ;
    nextSibling = nod.nextSibling;
}
#endif

