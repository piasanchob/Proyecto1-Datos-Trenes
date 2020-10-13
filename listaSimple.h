#include <iostream>
using namespace std;
//TDA Tipo abstractos de Datos, no pertenece al lenguaje, sin embargo, cuando el programador lo define se puede empezar a utilizar

class nodo { //clase NODO
	
   public:
    nodo(int v) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
       valor = v;//20
       siguiente = NULL;
    }

 
    nodo(int v, nodo * signodo) // 2 dirprimero direccion de memoria
    {
       valor = v;//2
       siguiente = signodo;//primero
    }


   private: // atributos
    int valor; // tipo entero. Ej clase estudiante nombre,dir,tel,siguente
    nodo *siguiente; // tipo de la clase, clase autoreferencia. Direccion 
    
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodo *pnodo; //alias redefinir los punteros

class lista {
   public:
    lista()
	{
      primero=NULL;   	
    	
	}
    ~lista();
    void InsertarInicio(int v);
    void InsertarFinal(int v);
    void InsertarPos (int v, int pos);
    bool ListaVacia() { return primero == NULL; } 
    void Imprimir();
    void Mostrar();
    void Primero();
	void BorrarFinal();
    void BorrarInicio();
    void borrarPosicion(int pos);
    int largoLista();
      
   private:
    pnodo primero; // nodo *primero; tipo nodo tiene derechoi direccionar un nodo
   
};
  
lista::~lista() //Destructor
{
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
  
}

int lista::largoLista(){ //largo
    int cont=0;

    pnodo aux; //nodo *aux;
    aux = primero;
    if(ListaVacia()){
        return cont;
    }else{
        while(aux!=NULL){
        aux=aux->siguiente;
        cont++;
    }
    return cont;
    }
    
}

void lista::InsertarInicio(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     primero=new nodo (v,primero);
}
 
void lista::InsertarFinal(int v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}

void lista::InsertarPos(int v, int pos) 
{
   if (ListaVacia())
     primero = new nodo(v);
   else{
        if(pos <=1){                     //InsertarInicio(v);
          pnodo nuevo = new nodo(v);
          nuevo->siguiente= primero;
          primero= nuevo;     
        }      
        else
		{
        	if (pos>=largoLista())
			   InsertarFinal(v);
			else
			{
			
             pnodo aux= primero;
             int i =2;
             while((i != pos )&&(aux->siguiente!= NULL)){
                   i++;
                   aux=aux->siguiente;
             }
             pnodo nuevo= new nodo(v); //1 NODO
             nuevo->siguiente=aux->siguiente; // 2 Nuevo con el valor siguiente 20
             aux->siguiente=nuevo;// 3 aux con nuevo
            }
             
        }
        }
}
      
void lista::BorrarFinal()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else{
        if (primero->siguiente == NULL) {
                primero= NULL;
            } else {

                pnodo aux = primero;
                while (aux->siguiente->siguiente != NULL) {
                    aux = aux->siguiente;

                }
                
              pnodo temp = aux->siguiente;
              aux->siguiente= NULL;

                
                delete temp;
            }
        }
}

void lista::BorrarInicio()
{
    if (ListaVacia()){
     cout << "No hay elementos en la lista:" << endl;
    
   }else
   {
        if (primero->siguiente == NULL)
		{
        	    pnodo temp=primero;
                primero= NULL;
                delete temp;
        }
		else
		{

                pnodo aux = primero;
                primero=primero->siguiente;                
                delete aux;
        }
   }
}



void lista:: borrarPosicion(int pos){
     if(ListaVacia()){
              cout << "Lista vacia" <<endl;
    }else{
         if((pos>largoLista())||(pos<0)){
        cout << "Error en posicion" << endl;
        }else{
        if(pos==1){
        primero=primero->siguiente;
        }else{
          int cont=2;
            pnodo aux=  primero;
            while(cont<pos){
             aux=aux->siguiente;
             cont++;
            }
            aux->siguiente=aux->siguiente->siguiente;
            }
        }
     }

}
 

void lista::Mostrar()
{
   nodo *aux;
   if (primero== NULL)
       cout << "No hay elementos";  
   else
   {
   
       
   		aux = primero;
		while(aux) 
		{
		    cout << aux->valor << "-> ";
		    aux = aux->siguiente;
		}
		cout << endl;
   }
}



int main()
{
   lista L1;// lista es la clase y Lista instancia
   
   
    
   
   L1.InsertarInicio(20);
   L1.InsertarInicio(2);
   L1.InsertarFinal(10);
   L1.InsertarFinal(11);
   L1.InsertarPos(5, 3);
   L1.InsertarPos(106, 45);
   L1.InsertarInicio(30);
   L1.InsertarInicio(1);   
   L1.InsertarFinal(5);
   L1.InsertarPos(1, 3);
   L1.Mostrar();
   L1.BorrarInicio();
      L1.Mostrar();
   L1.BorrarFinal();
      L1.Mostrar();
   L1.borrarPosicion(3);
   L1.Mostrar();

   cout << "Lista de elementos:" << endl;

   L1.BorrarFinal();
  
   
   L1.Mostrar();
   L1.~lista();
   L1.Mostrar();

   cin.get();
   return 0;
}
