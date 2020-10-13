#include "clase_destinos.h"
using namespace std;
typedef nodo_destinos *pnodo_destinos;


class listaDC {
   public:
    listaDC() { primero = NULL; }
    ~listaDC();
    
    void InsertarInicio(int v);
    void InsertarFinal(string codpais, string nombrepais);
    void InsertarFinalciudad(string codpais, string codciudad, string nombreciudad);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Borrar(int v);
    void Mostrar();
    void BorrarFinal();
    void BorrarInicio();
    void BorrarPosicion(int pos);
    int largoLista();
    
    pnodo_destinos primero;
    
    friend class lista;
    
    
   
};

listaDC::~listaDC()
{
   pnodo_destinos aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      primero->anterior=aux->anterior;
      aux->anterior->siguiente=primero;
      delete aux;
   }
   
}

int listaDC::largoLista()
{
    int cont=0;

    pnodo_destinos aux = primero;
    if(ListaVacia())
    {
        return cont;
    }
    else
    {
        while(aux!=primero)
        {
          aux=aux->siguiente;
          cont++;
        }
    return cont;
    }
    
}
/*
void listaDC::InsertarInicio(int v)
{
  
   if (ListaVacia())
   {
     primero = new nodo_destinos(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   }  
   else
   {
     pnodo_destinos nuevo=new nodo_destinos (v);
     nuevo->siguiente=primero;
     nuevo->anterior= primero->anterior;
     primero->anterior->siguiente=nuevo;
     nuevo->siguiente->anterior=nuevo;
     primero= nuevo;
   }
}
 */
void listaDC::InsertarFinal(string codigo_pais, string nombre_pais)
{
   if (ListaVacia())
     {
     primero = new nodo_destinos(codigo_pais, nombre_pais);
     primero->anterior=primero;
     primero->siguiente=primero;
   	}  
   else
   { 
     pnodo_destinos nuevo = new nodo_destinos(codigo_pais, nombre_pais);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}

void listaDC::InsertarFinalciudad(string codigo_pais, string codigo_ciudad, string nombre_ciudad)
{
   if (ListaVacia())
     {
     primero = new nodo_destinos(codigo_pais, codigo_ciudad, nombre_ciudad);
     primero->anterior=primero;
     primero->siguiente=primero;
   	}  
   else
   { 
     pnodo_destinos nuevo = new nodo_destinos(codigo_pais, codigo_ciudad, nombre_ciudad);
     nuevo->anterior = primero->anterior;
     nuevo->siguiente=primero->anterior->siguiente;
     primero->anterior->siguiente=nuevo;
     primero->anterior=nuevo;
    }    
}

/*
void listaDC::InsertarPos(int v,int pos)
{
   if (ListaVacia())
   {
     primero = new nodo_destinos(v);
     primero->anterior=primero;
     primero->siguiente=primero;
   } 
   else
   {
      if(pos <=1)
        InsertarInicio(v);    
       else
       {
        if (pos==largoLista())
          InsertarFinal(v);
        else
        {     
             pnodo_destinos aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= primero))
             {
                   i++;
                   aux=aux->siguiente;
             }
             pnodo_destinos nuevo= new nodo_destinos(v);
             nuevo->siguiente=aux->siguiente;
             aux->siguiente=nuevo;
             aux->siguiente->anterior=aux;
             nuevo->siguiente->anterior=nuevo;                           
        }
       }
   }
}   

void listaDC::BorrarFinal()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
      if (primero->siguiente == primero)
      {
        pnodo_destinos temp= primero;
        primero= NULL;
        delete temp;
      }
      else 
      {
         pnodo_destinos aux = primero;
         while (aux->siguiente->siguiente != primero)
              aux = aux->siguiente;
         pnodo_destinos temp = aux->siguiente;
         aux->siguiente= primero;
         primero->anterior=aux;
         delete temp;
      }
    }
}

void listaDC::BorrarInicio()
{
    if (ListaVacia())
      cout << "No hay elementos en la lista:" << endl;
    else
    {
     if (primero->siguiente == primero)
     {
        pnodo_destinos temp= primero;
        primero= NULL;
        delete temp;
     }
     else
     {
        pnodo_destinos aux = primero->anterior;
        pnodo_destinos temp= primero;
        aux->siguiente=primero->siguiente;
        primero=primero->siguiente; 
        primero->anterior=aux;
        delete temp;
      }
    }
}

void listaDC:: BorrarPosicion(int pos)
{
    
  if(ListaVacia())
    cout << "Lista vacia" <<endl;
  else
  {
   if((pos>largoLista())||(pos<0))
        cout << "Error en posicion" << endl;
   else
   {
      if(pos==1)
        BorrarInicio();
      else
      {
       int cont=2;
       pnodo_destinos aux=  primero;
       while(cont<pos)
       {
         aux=aux->siguiente;
         cont++;
       }
       pnodo_destinos temp = aux->siguiente;
       aux->siguiente=aux->siguiente->siguiente;
       delete temp;
     }
    }
  }
}

void listaDC::Mostrar()
{
   pnodo_destinos aux=primero;
   while(aux->siguiente!=primero)
     {
                                
      cout << aux->valor << "-> ";
      aux = aux->siguiente;
     }
     cout<<aux->valor<<"->";
     cout<<endl;
}   
*/


