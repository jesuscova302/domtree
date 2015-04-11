#ifndef LISTA_H_ 
#define LISTA_H_ 

#include "nodo.h"
using namespace std;

template <class E>
class LISTA
{
	private:
		int cantidad;
	    NODO<E> *primero,*ultimo;
	
	public:	
		/**CONSTRUCTORES**/
		LISTA<E>(): cantidad(0), primero(NULL),ultimo(NULL){};
		//LISTA<E>(int cant):cantidad(cant){};
		//LISTA<E>(const LISTA<E> &l_copiar);
        LISTA(const LISTA<E> &list);
        LISTA<E> copiar(LISTA<E> list);	
        
		/**DESTRUCTOR**/
		~LISTA<E>();

		/**VERIFICADORES**/
		bool es_vacia()  const { return  primero == NULL; }
		int  longitud() const {return(cantidad);} 
		
		E consultar_por_pos(int pos) const;        //listo
		//E consultar_por_pos2(int pos) const;	  //probar en main
		bool esta(E elem); 						 //listoDEVUELVE UN VALOR LOGICO INDICANDO SI ESTA O NO EL ELEMENTO
		int localizar(E e);						//listoDEVUELVE LA POSICION DONDE SE ENCUENTRA  ELEMENTO SINO SE ENCUMNTRA DEVUELE -1 
		/*friend std::ostream& operator<<(std::ostream& os, const LISTA<E>& LIS);
	    friend std::istream& operator>>(std::istream& is, LISTA<E>& LIS);
		*/
		/**MODIFICADORES**/
	    void insertar_por_pos(E elem,int pos) ;      //listo
		void insertar_al_principio(E elem);		    //probar en main
		void insertar_al_final(E elem);			   //probar en main
	
		void eliminar_al_final();				  //probar en main
		void eliminar_por_pos(int pos);	         //probar en main
		void operator=(const LISTA<E> &l2) ;
		bool operator==(const LISTA<E> &l2) ;//const;
		void ordenar();
		void invertir();
		
		/**METODOS DE EJERCICIOS**/
	    void codificar();
	    void sublista(int i,int j,LISTA<E> &list);
};


template <class E>
ostream& operator<<(std::ostream& os, const LISTA<E>& LIS)
{
	int i;
	if( !LIS.es_vacia() )
	{
		for(i=1;i<=LIS.longitud();i++)
			os << "[" << LIS.consultar_por_pos(i)<<"]";
		return os;
	}
}

template <class E>
istream& operator>>(std::ostream& is, const LISTA<E>& LIS)
{
	int i;
	if( !LIS.es_vacia() )
	{
		for(i=1;i<=LIS.longitud();i++)
			is <<LIS.consultar_por_pos(i);
		return is;
	}
}


/*
 * PARA LEER E IMPRIMIR
ostream& operator<<(std::ostream& os, const Person& per)
{
	os << "Given name: " << per.given_name << '\n' << "Family name: " << per.family_name << '\n' << "ID number: "
	<< per.ID_number << '\n' << "Year of birth: " << per.birth_year << '\n';
	
	return os;
}

istream& operator>>(std::istream& is, Person& per)
{
	cout << "Nombre: ";
	//is >> per.given_name;
	getline(is, per.given_name, '\n');
	cout << "Apellido: ";
	//is >> per.family_name;
	getline(is, per.family_name, '\n');
	cout << "Cedula: ";
	//is >> per.ID_number;
	getline(is, per.ID_number, '\n');
	cout << "AÃ±o de Nacimiento: ";
	is >> per.birth_year;
	is.ignore(numeric_limits<int>::max(), '\n');
	
	return is;

}

*/


template <class E>
LISTA<E> LISTA<E>::copiar(LISTA<E> list)
{
    	LISTA<E> l_cop = list;
	    return (l_cop);
}


//COPIA LOS ELEMENTOS DE UNA LISTA A OTRA
/*template <class E>
LISTA<E>::LISTA(const LISTA<E> &l_copiar)
{
	NODO<E> *aux; 
	int i,longt;

	if(!l_copiar.es_vacia() )
	{
		longt =l_copiar.longitud() ;
		i=1;
		while( i <= longt )
		{
			this->insertar_por_pos(l_copiar.consultar_por_pos(i),i);
			i++;
		}
	}else this->primero = NULL; 
}*/


template <class E>
LISTA<E>::LISTA(const LISTA<E> &list)
{
	NODO<E> *aux, *nuevo, *insertar;

    if(list.primero != NULL)
    {
		primero  = new NODO<E>(list.primero->get_elemento(), NULL);
		aux		 = list.primero->proximo();
		insertar = primero;
		while( aux != NULL )
		{
			nuevo = new NODO<E> (aux->get_elemento(), NULL);
			insertar->set_proximo(nuevo);
			insertar = insertar->proximo();
			aux = aux->proximo();
	    }
	}else { primero = NULL; }
}


//FUNCION QUE RETORNA EL ELEMENTO QUE ESTA EN LA POSICION (pos) DE LA LISTA DE LA SEGUNDA IMPLEMENTACION
template <class E>
E LISTA<E>::consultar_por_pos(int pos) const
{
	NODO<E> *ant,*act;
	int i;
  
    if(pos==1) 
    {
        return (this->primero->get_elemento());    
    }else
     {
		if(pos == this->cantidad )
		{
			return (this->ultimo->get_elemento());    
		}else
		{
			ant = this->primero;
			act = ant->proximo();
			i   = 2;
			while( i < pos  &&   act != NULL)
			{
				ant = act; 
				act = act->proximo();
				i++; 
			}
			 if(i==pos && act!=NULL)
			 {
				return (act->get_elemento());
			 }
		}
	}
		   
}

/**DEVUELVE LA POSICION DEL ELEMENTO e, SI ES QUE SE ENCUENTRA EN LA LISTA**/
template <class E>
int LISTA<E>::localizar(E e)
{
	NODO<E> *aux;
	bool encon;
	int cont; // inicializamos a cont con valor centinela 
	
	if( this->cantidad != 0)
    {
		if( e==this->primero->get_elemento() )  cont = 1;
		 else
		 {
			 if( e==this->ultimo->get_elemento() )  cont = this->cantidad ;
		      else
			  {  
				aux = this->primero->proximo();
				cont = 2;
				encon = true;
				while( encon && aux != this->ultimo )
				{
					if( e ==aux->get_elemento() ) encon=false;
					else 
					{
						 cont++;
						 aux = aux->proximo();
		            }
				}
			}
		}
      if( aux ==  this->ultimo ) cont = -1;
        
        return cont;
    }
}


/**INSERTA EL ELEMENTO elem EN LA POSICION pos DE LA LISTA**/
template <class E>
void LISTA<E>::insertar_por_pos(E elem,int pos) 
{
    NODO<E> *aux,*ant,*sig,*nuevo;
    int i;
   
	
    nuevo = new NODO<E>(elem,NULL);
	if( this->cantidad == 0 )
	{
		this->primero = this->ultimo = nuevo;
		this->cantidad++;
	}else
	{
		if( pos <= this->cantidad+1  )
		{
		   if(pos==1)
		   {
			  nuevo->set_proximo(this->primero);
			  this->primero = nuevo;
		   }else
		   {
				if( pos == this->longitud()+1)
				{
					this->ultimo->set_proximo(nuevo);
					this->ultimo = nuevo;
				}else
				{
					ant = this->primero; 
					sig = ant->proximo();
					i=2; 
					while( i<pos && sig != NULL)
					{
						ant = sig;
						sig = sig->proximo(); 
						i++;
					}
					ant->set_proximo(nuevo); 
					nuevo->set_proximo(sig);   
				}
			}
			this->cantidad++; 
		}
	}
   
}

/*VERIFICAR SI ESTA BIEN*/
template <class E>
void LISTA<E>::insertar_al_final(E elem)
{
	 NODO<E> *nuevo;
	 
	nuevo =new NODO<E>(elem,NULL);
	if(this->primero == NULL)
	{
		this->primero = this->ultimo = nuevo;
         
	}else
    {
		this->ultimo->set_proximo(nuevo);
		this->ultimo  = nuevo;
	}
	this->cantidad++; //nuevo
}


/*VERIFICAR SI ESTA BIEN*/
template <class E>
void LISTA<E>::insertar_al_principio(E elem)
{
	 NODO<E> *nuevo;
	 
	nuevo =new NODO<E>(elem,NULL);
	if(this->primero == NULL)
	{
		this->primero = this->ultimo = nuevo;		
	}else
    {
		nuevo->set_proximo(this->primero);
		this->primero = nuevo;
	}
	this->cantidad++; //nuevo
}


//ELIMINA EL ELEMENTO QUE ESTA EN LA POSICION pos DE LA LISTA DE LA SEGUNDA IMPLEMENTACION
template <class E>
void LISTA<E>::eliminar_por_pos(int pos)
{
	NODO<E> *ant,*act,*sig;
	int i;

    if(pos==1)
    {
		if( this->primero == this->ultimo )
         {
		    act = this->primero;
            this->primero = this->ultimo = NULL;   
            delete act;
          }else
	      {
		      act = this->primero;
              this->primero = act->proximo();   
              delete act;
          }
    }else
	{
	   ant = this->primero;
	   act = ant->proximo();
	   sig = act->proximo();
	   i   = 2;
       while( i<pos && sig!=NULL)
	   {
			ant = act;
			act = sig;
			//act = act->proximo();
			//sig = act->proximo()->proximo();
			sig = sig->proximo();
			i++;	
        }
        if( i==pos )
		{
			if( sig == NULL)
			{
				ant->set_proximo(sig);  
				this->ultimo = ant;
				delete act;
			}else
			{
				ant->set_proximo(sig);  
				delete act;
			}
		}
	}
	this->cantidad--;
}

//elimina el nodo que esta al final de una lista
template <class E>
void LISTA<E>::eliminar_al_final()
{
	NODO<E> *ant;
	int i;

	if(this->cantidad == 1)
    {	
		delete this->primero ;
		delete this->ultimo;
        this->primero = this->ultimo = NULL;
        this->cantidad = 0; //nuevo
	}else
	{
		if(this->cantidad == 2)
		{	
			delete this->ultimo;
			this->ultimo = this->primero;
			this->cantidad = 1;//nuevo
		}else
		{
			//ant = this->primero->proximo();
			ant = this->primero;
			for(i=2;i<this->cantidad;i++)	ant = ant->proximo();
			delete this->ultimo;
			this->ultimo = ant;
			this->cantidad--;	//nuevo	
		}
	}
}


//DESTRUYE LA LISTA, "LA VACÍA"
template <class E>
LISTA<E>::~LISTA()
{
	NODO<E> *act;

	while(this->primero != NULL)
	{
		act=this->primero;
		this->primero = this->primero->proximo();
		delete(act);
	}	
	this->cantidad = 0;
}


//(cuando en elemento elem esta en la lista funciona , en caso contrario da violacion de segmento)
//VERIFÍCA SI EL EEMENTO elem ESTÁ Ó NO EL LISTA
template <class E>
bool LISTA<E>::esta(E elem)
{
	NODO<E> *aux;
	bool opc=false;
	
	
	if( elem == this->primero->get_elemento() )
    {
		opc = true;
	}else
	{
		if( elem ==  this->ultimo->get_elemento() )
		{
			opc = true;
		}else
		{			
			aux = this->primero->proximo();
			while ( (aux != this->ultimo)&&(opc==false) )
			{
				if (elem == aux->get_elemento())
					opc = true;
				 else
					 aux = aux->proximo();
			}
		}
	}
	return opc;
}


//VERIFÍCA SI DOS LISTAS SON IGUALES
template <class E>
bool LISTA<E>::operator==(const LISTA<E> &l2) 
{
    NODO<E> *aux1,*aux2,*rpd;
    bool son;
	int i;
	
	//~ if(this->longitud() != l2.longitud()) return (false);
	
	if( cantidad != l2.cantidad ) return (false);
  	else
	{
		//
		if(  ultimo->get_elemento() != l2.ultimo->get_elemento() ) return (false);
		else
		{
			aux1 = this->primero;
			aux2 = l2.primero;   //cambiÈ aux2 = l2->primero; por aux2 = l2.primero;
			son = true;
		
			while( (aux1!= this->ultimo) && (son) )
			{
				//if(this->consultar_por_pos(i) == l2.consultar_por_pos(i))
				if(aux1->get_elemento() == aux2->get_elemento())
				{
					aux1 = aux1->proximo();
					aux2 = aux2->proximo();
				}else
					son=false;
			}
			return (son);
		 
		 }
		
	}				
}

//ASIGNA TODOS LOS ELENTOS DE UNA LISTA A OTRA(de l2  a la lista por defecto)
template <class E>
void LISTA<E>::operator=(const LISTA<E> &l2) 
{
   // this(l2);//nuevo
	//~ int i;
    NODO<E> *aux;
  
	if(!l2.es_vacia() )
	{	
		aux = l2.primero;
		//~ i=1;
		while(aux  != NULL)
		{
			this->insertar_al_final(aux->get_elemento() );//ULTIMA MODIFICACION
			//~ this->insertar_por_pos(aux->get_elemento(), i );//ULTIMA MODIFICACION
			//this->insertar_por_pos(l2.consultar_por_pos(i), i );
			aux = aux->proximo();
			//~ i++;		
		}
	}else                                         //ESTAS
	{                                            //LINEAS 
		this->primero = this->ultimo = NULL;
		cantidad = 0;    //SON 
	}                                          // NECESARIAS ?
}


//ORDENA ACCENDENTEMENTE LOS ELEMENTOS DE UNA LISTA 
template <class E>
void LISTA<E>::ordenar()
{
	NODO<E> *aux,*aux1;
	E x;
	 
	aux = this->primero;
    while(aux!= NULL)
    {
		aux1=aux->proximo();
	    while(aux1!=NULL)
	    {
	       if(aux->get_elemento() > aux1->get_elemento())
	       {
		      x=aux->get_elemento();
		      aux->set_elemento(aux1->get_elemento());
		      aux1->set_elemento(x);     
		   }
		   aux1=aux1->proximo();
	    }
	    aux=aux->proximo();
    }	
}

//INVIERTE LOS VALORES DE UNA LISTA
template <class E>
void LISTA<E>::invertir()
{
    NODO<E> *aux1,*aux2,*aux3;
    aux1 = aux2 = aux3 = this->primero;

    if(this->primero != NULL)
    {
        aux1 = aux2->proximo();
        aux3= aux1;
        aux2->set_proximo(NULL);
        while(aux3 != NULL)
        {
                aux3 = aux3->proximo();
                aux1->set_proximo(aux2);
                aux2=aux1;
                aux1=aux3;
        }
        this->primero = aux2;
    }
}

/*/
template <class E>		
void LISTA<E>::compactar()
{
		int cont=0;
		E elem;
		NODO<E> *act;
		LISTA<int> L;
		
		cin<< k;
		if(0<k<=100)
		{
			cin<< n;
			if(0<n<=10000)
			{	
				for(i=1;i<=n;i++)
				{
					
					if(0< this->longitud() <=10000)
					{
						act = this->primero;
						elem = act->get_elemento();
						while(act != NULL)
						{
								if(act->get_elemento() == elem)
								{
									cont++;
									act= act->proximo();
								}else
								{
									cout>>elem>>cont>>endl;
									act= act->proximo();
									elem = act->get_elemento();
									cont=0;	
								}
						}
					} 
				}
			}
		}
}
	
	/*/
template <class E>
//~ void LISTA<E>::codificar(LISTA<E> &L)
void LISTA<E>::codificar()
{
	int i,j;
	E aux,aux2;
	
	j = longitud();
	 cout<<"hdhdhdhhhhh:::::"<<j<<endl;
	if( j > 3 )
	{
		if( (j % 2) != 0 )
	    {
			cout<<"entrò:::::"<<endl;
	         j = j-1;
        } 
	     i=2;
	     
	     while( i < j )
	     {
			 aux2  = consultar_por_pos(j);
		     aux  = consultar_por_pos(i);
		     eliminar_por_pos(j);
		     eliminar_por_pos(i);
		     insertar_por_pos(aux2,i);
		     insertar_por_pos(aux,j);
		     i = i+2;
		     j = j-2;
		 }			 
    }
}	

template <class E>
void  LISTA<E>::sublista(int i,int j,LISTA<E> &list)
{
	int k,l;
	NODO<E> *apt = this->primero;
	
    for(k=1;k<i;k++)
    {
	    apt=apt->proximo();	
	}
	l=1;
    while( i<= j  )
	{ 
        list.insertar_por_pos(apt->get_elemento(),l);
        apt= apt->proximo();
        l++;
        i++;
    }
	
}
#endif

