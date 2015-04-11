#ifndef ELEMENT_H_ 
#define ELEMENT_H_ 

#include <string>
#include "lista.h"
using namespace std;
 
class Element
{
	/**** ATRIBUTOS ****/
	private:
		string tagName,innerHTML;
		LISTA<string> attrList;
	
	
	/**** METODOS ****/
	public:
		/**CONSTRUCTORES**/
		Element():tagName(" "),innerHTML(" "),attrList(){};
		Element(string nombre):tagName(nombre),innerHTML(" "),attrList(){};
		Element(string nombre,string conteni):tagName(nombre),innerHTML(conteni),attrList(){};
		Element(string nombre,string conteni,LISTA<string> listAtrib);
		Element(const Element &Elem);
		//~ Element(string nombre,string  valor,LISTA<string> listAtrib):tagName(nombre),innerHTML(valor),attrList(listAtrib){};


		/**VERIFICADORES**/ 
		//~ string get_tagName() const {return (tagName);}
		//~ string get_innerHTML() const{return (innerHTML);}
		//~ LISTA<string> get_attrList() const{ return (attrList);}
		//~ 
		string get_tagName() {return (tagName);}
		string get_innerHTML() {return (innerHTML);}
		LISTA<string> get_attrList() { return (attrList);}
		
		/**MODIFICADORES**/
		//~ friend std::ostream& operator<<(std::ostream& os,Element &Elem);
		void operator=(const Element &Elem) ;
		bool operator==(const Element &Elem) ;
		void set_tagName(string nombre){tagName = nombre;}
		void set_innerHTML(string contenido){innerHTML = contenido;}
		void set_attrList( LISTA<string> listAtrib){attrList = listAtrib;}
	
};


#endif
