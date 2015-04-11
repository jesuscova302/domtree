# domtree
Proyecto de arboles periodo 2014 /2015

Universidad de Carabobo
Facultad Experimental de Ciencias y Tecnología
Departamento de Computación
Unidad Académica de Algoritmos, Programación y LenguajesProgramación II
                                Proyecto: DOM Tree

Introducción
Al cargar una página web, los exploradores utilizan el DOM (Document Object Model), para representar su
estructura como un árbol n-ario llamado DOM tree. El DOM tree está formado por elementos llamados nodos,
y siempre tiene como nodo raíz un nodo llamado document a partir del cual se derivan el resto de los
elementos que estructuran la página web. Por ejemplo, la siguiente página web,

01 <!doctype html>
02      <html>
03          <head>
04               <title>Ejemplo de Página Web</title>
05          </head>
06          <body>
07               <h1>Una Página Web</h1>
08               <p id="contenido">Hola Mundo!!!</p>
09               <p>Bye!!!</p>
10               </body>
11        </html>

Está representada por el árbol:

JavaScript es un lenguaje de programación generalmente utilizado por los exploradores web para
implementar scripts que permiten hacer la página más dinámica, ya que mediante JavaScript se puede
modificar el contenido del documento mostrado por la página, sin necesidad de que esta se recargue.
document
html
head body
title h1 p p
Objetivos
1. Hacer una clase DOM_Tree, que represente el árbol de un documento HTML.
Esta clase debe permitir hacer operaciones al estilo JavaScript sobre un documento HTML dado. Para ello, es
necesario que implemente las clases Element, la cual debe poseer la información de cada elemento dentro de
un documento HTML, y Node, la cual es un nodo del DOM_Tree.
Cada Element debe tener su tagName (nombre del tag que le corresponde, por ejemplo: html, p o h1), una
lista de atributos, attrList (los atributos siempre se encontrarán en el tag de inicio, luego del tagName, y
tendrán la forma “nombre='valor'”, por ejemplo id='contenido'), y un innerHTML (HTML interno), en caso de
que el elemento permita mostrar texto.

La interfaz mínima de Element debe ser:
· Element: Crea un elemento. Debe permitir colocar un string para el tagName (obligatorio), una lista de
atributos (vacía por defecto) de tipo std::list de string, y un string para el innerHTML (vacío por defecto).
· tagName: Devuelve el nombre del elemento como string.
· attributeList: Devuelve la lista de atributos del elemento en un objeto de la clase std::list. Cada atributo
será un string de la forma “nombre='valor'”.
· innerHTML: Devuelve el texto guardado en el nodo como string.
· setTagName: Cambia el nombre del elemento. Para ello recibe un string con el nuevo tagName.
· setAttributeList: Cambia la lista de atributos del elemento. Para ello, se pasará un parámetro de tipo
std::list, donde cada atributo será un string de la forma “nombre='valor'”.
· setInnerHTML: Cambia el texto guardado en el elemento. Recibirá un string.

Un Node tendrá como atributos un campo que contiene un objeto de tipo Element, e, y los apuntadores al
primer hijo, firstChild, y al hermano derecho, nextSibling. Como mínimo, la clase Node debe tener la interfaz:
· Node: Crea un nodo. Es imprescindible pasarle un Element. Debe permitir igualmente asignar los
apuntadores al firstChild y al nextSibling, si estos no se pasan, se coloca por defecto NULL.
· element: Devuelve el elemento almacenado en el nodo, de tipo Element.
· firstChild: Devuelve el apuntador a su primer hijo.
· nextSibling: Devuelve el apuntador a su hermano derecho.
· setElement: Modifica el elemento almacenado en el nodo. Para ello, recibe un objeto de tipo Element.
· setFirstChild: Modifica el apuntador a su primer hijo.
· setNextSibling: Modifica el apuntador a su hermano derecho.

El DOM_Tree debe tener como mínimo la siguiente interfaz:
· DOM_Tree: Crea un nuevo árbol.
· DOM_Tree: Con un parámetro obligatorio de tipo Element, y un parámetro std::list de DOM_Tree (por
defecto vacía), para sus hijos.
· childNode: Devuelve el hijo correspondiente a la posición p del árbol.
· appendChild: Agrega un nuevo hijo en la posición p del árbol. Si no se especifica la posición, se agrega
como último hijo.
· removeChild: Elimina el hijo de la posición p del árbol.
· replaceChild: Cambia el subarbol de la posición p por otro subárbol dado.
· getElementByID: Devuelve el subarbol cuya raíz es el element que tenga el ID dado. Si no existe dicho
elemento, devuelve el árbol vacío.
· ~DOM_Tree: Destruye el árbol.

Las operaciones appendChild y replaceChild deben ser sobrecargadas para recibir un DOM_Tree o un string
que contenga HTML, por ejemplo “<p>Este es un <b>string</b></p>”.

Importante: Todas las clases deben tener además su constructor copia, y la sobrecarga del operador =.
Además, la clase DOM_Tree debe tener sobrecargado el operador <<, de manera tal que imprima el HTML
correspondiente a un DOM_Tree, debidamente indentado.

2. Hacer un makefile que permita compilar un programa principal cualquiera, brindado por el usuario
(profesor).
Este programa principal incluirá la librería “DOM_Tree.h” unicamente. Asegúrese de colocar al principio del
makefile una variable llamada “PRINCIPAL”, en la cual el usuario colocara el nombre del principal dado, y una
variable llamada “EXE”, en la cual el usuario colocará el nombre del ejecutable.
