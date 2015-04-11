#include "element.h"
using namespace std;

Element::Element(string nombre,string conteni,LISTA<string> listAtrib)
{ 
	tagName 	= nombre;
	innerHTML	= conteni;
	attrList	= listAtrib;
}


Element::Element(const Element &Elem)
{
	tagName 	= Elem.tagName;
	innerHTML   = Elem.innerHTML;
	attrList    = Elem.attrList;	
}

void Element::operator=(const Element &Elem)
{
	tagName 	= Elem.tagName;
	innerHTML   = Elem.innerHTML;
	attrList    = Elem.attrList;	
}

bool Element::operator==(const Element &Elem)
{
	bool son =  false;
	
	if( (tagName == Elem.tagName) && (innerHTML  == Elem.innerHTML) && (attrList  == Elem.attrList) ) son = true;
    return (son);
}

/*
ostream& operator<<(std::ostream& os, Element &Elem)
{
	int i;
	
	os << "<"<< Elem.get_tagName()<< " " <<Elem.get_attrList() <<  " " <<Elem.get_innerHTML()<< ">"<<endl;
		//~ for(i=1;i<=LIS.longitud();i++)
			//~ os << "[" << LIS.consultar_por_pos(i)<<"]";
	return os;	
}*/

