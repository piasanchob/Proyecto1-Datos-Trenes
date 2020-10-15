#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
using namespace std;


//*************************************************************************USUARIOS*****************************************************************
class nodoUsuarios { //clase NODO Trenes
	
   public:
    nodoUsuarios(string codpais, string codciudad, string codnombre, string codpasaporte, string codestado_migratorio) 
    {
       cod_pais = codpais;
       cod_ciudad = codciudad;
       nombre = codnombre;
       pasaporte = codpasaporte;
       estado_migratorio = codestado_migratorio;
       
       siguiente = NULL;
    }

 
    nodoUsuarios(string codpais, string codciudad, string codnombre, string codpasaporte, string codestado_migratorio, nodoUsuarios * signodo) // 2 dirprimero direccion de memoria
    {
       cod_pais = codpais;
       cod_ciudad = codciudad;
       nombre = codnombre;
       pasaporte = codpasaporte;
       estado_migratorio = codestado_migratorio;
       siguiente = signodo;
    }


    // atributos
    string cod_pais;
	string cod_ciudad;
	string nombre;
	string pasaporte;
	string estado_migratorio;
    nodoUsuarios * siguiente; 
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoUsuarios *pnodoUsuarios; //alias redefinir los punteros


//**********************************************************ADMIN******************************************************************************************
class nodoAdministradores { //clase NODO
	
   public:
    nodoAdministradores(string codadministrador, string nombre) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
       cod_administrador = codadministrador;
       nombre_administrador = nombre;
       siguiente = NULL;

    }

 
    nodoAdministradores(string codadministrador, string nombre, nodoAdministradores *signodo) 
    {
       cod_administrador = codadministrador;
       nombre_administrador = nombre;
       siguiente = signodo;
    }


    // atributos
    string cod_administrador;
	string nombre_administrador; 
    nodoAdministradores * siguiente; 
 
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoAdministradores *pnodoAdministradores; //alias redefinir los punteros
//*********************************************************************RUTAS**********************************************************************************
class nodoRutas { 
	
   public:
    nodoRutas(string codtipotren, string codtren, string codruta, string codpais1, string codciudad1, string codpais2, string codciudad2, string codprecio) 
    {
       cod_tipo_tren = codtipotren;
       cod_tren = codtren;
       cod_ruta = codruta;
       cod_pais = codpais1;
       cod_ciudad = codciudad1;
       cod_pais2 = codpais2;
       cod_ciudad2 = codciudad2;
       precio = codprecio;
       siguiente = NULL;
 
    }

 
    nodoRutas(string codtipotren, string codtren, string codruta, string codpais1, string codciudad1, string codpais2, string codciudad2, string codprecio, nodoRutas * signodo) // 2 dirprimero direccion de memoria
    {
       cod_tipo_tren = codtipotren;
       cod_tren = codtren;
       cod_ruta = codruta;
       cod_pais = codpais1;
       cod_ciudad = codciudad1;
       cod_pais2 = codpais2;
       cod_ciudad2 = codciudad2;
       precio = codprecio;
       siguiente = signodo;
    }


   // atributos
    string cod_tipo_tren;
    string cod_tren;
	string cod_ruta;
	string cod_pais;
	string cod_ciudad;
	string cod_pais2;
	string cod_ciudad2;
	string precio;
    nodoRutas * siguiente; 

   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoRutas *pnodoRutas; //alias redefinir los punteros


//***********************************************************CODIGO RUTAS Y PRECIO********************************************************************************

class nodoRutasprecio { 
	
   public:
    nodoRutasprecio(string codruta, string codprecio) 
    {
       cod_ruta = codruta;
       precio = codprecio;
       siguiente = NULL;
    }

 
    nodoRutasprecio(string codruta, string codprecio, nodoRutasprecio * signodo) // 2 dirprimero direccion de memoria
    {
	   cod_ruta = codruta;
       precio = codprecio;
       siguiente = signodo;
    }


    // atributos
    string cod_ruta;
    string precio;
    nodoRutasprecio * siguiente; 

        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoRutasprecio *pnodoRutasprecio; //alias redefinir los punteros



//*******************************************************TRENES**********************************************************************

class nodoTrenes { //clase NODO Trenes
	
   public:
    nodoTrenes(string codtipotren, string codtren, string nombre, string cantidadasientos, string codigorutas) 
    {
       cod_tipo_tren = codtipotren;
       cod_tren = codtren;
       nombre_tipo_tren = nombre;
       cantidad_asientos = cantidadasientos;
       codigo_rutas = codigorutas;
       siguiente = NULL;
       abajo = NULL;
    }

 
    nodoTrenes(string codtipotren, string codtren, string nombre, string cantidadasientos, string codigorutas, nodoTrenes * signodo) // 2 dirprimero direccion de memoria
    {
       cod_tipo_tren = codtipotren;
       cod_tren = codtren;
       nombre_tipo_tren = nombre;
       cantidad_asientos = cantidadasientos;
       codigo_rutas = codigorutas;
       siguiente = signodo;
    }


   // atributos
    string cod_tipo_tren;
    string cod_tren;
	string nombre_tipo_tren;
	string cantidad_asientos;
	string codigo_rutas;
    nodoTrenes * siguiente; 
    nodoRutasprecio *abajo;
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoTrenes *pnodoTrenes; //alias redefinir los punteros


//*****************************************************TIPO_TRENES**************************************************************

class nodoTipotrenes { //clase NODO Tipo Trenes
	
   public:
    nodoTipotrenes(string codtipotren, string nombre) 
    {
       cod_tipo_tren = codtipotren;
       nombre_tipo_tren = nombre;
       siguiente = NULL;
       abajo = NULL;
    }

 
    nodoTipotrenes(string codtipotren, string nombre, nodoTipotrenes * signodo) // 2 dirprimero direccion de memoria
    {
       cod_tipo_tren = codtipotren;
       nombre_tipo_tren = nombre;
       siguiente = signodo;
    }


    // atributos
    string cod_tipo_tren;
	string nombre_tipo_tren;
    nodoTipotrenes * siguiente; 
    nodoTrenes * abajo;
    
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoTipotrenes *pnodoTipotrenes; //alias redefinir los punteros


//*****************************************************CONEXIONES*************************************************************************************************************
class nodoConexiones { //clase NODO
	
   public:
    nodoConexiones(string codpais1,string codciudad1, string conexion, string codpais2, string codciudad2,string tiempo12) 
    {
       cod_pais1 = codpais1;
       cod_ciudad1 = codciudad1;
       cod_conexion = conexion;
       cod_pais2 = codpais2;
       cod_ciudad2 = codciudad2;
       tiempo = tiempo12;
       siguiente = NULL;
       
    }

 
    nodoConexiones(string codpais1,string codciudad1, string conexion, string codpais2, string codciudad2,string tiempo12, nodoConexiones * signodo)
    {
       cod_pais1 = codpais1;
       cod_ciudad1 = codciudad1;
       cod_conexion = conexion;
       cod_pais2 = codpais2;
       cod_ciudad2 = codciudad2;
       tiempo = tiempo12;
       siguiente = signodo;
    }


    // atributos
    string cod_pais1;
    string cod_pais2;
    string cod_conexion;
    string cod_ciudad1;
	string cod_ciudad2;
	string tiempo;
    nodoConexiones * siguiente; 
    
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoConexiones *pnodoConexiones; //alias redefinir los punteros



//***********************************************CIUDADES*************************************************************************************************
class nodoCiudades { //clase NODO
	
   public:
    nodoCiudades(string codpais,string codciudad, string nombre) 
    {
       cod_pais = codpais;
       nombre_ciudad = nombre;
       cod_ciudad = codciudad;
       siguiente = NULL;
       abajo = NULL;
    }

 
    nodoCiudades(string codpais, string nombre, nodoCiudades * signodo) // 2 dirprimero direccion de memoria
    {
       cod_pais = codpais;
       nombre_ciudad = nombre;
       siguiente = signodo;
    }


   // atributos
    string cod_pais;
    string cod_ciudad;
	string nombre_ciudad;
    nodoCiudades * siguiente; 
    nodoConexiones * abajo;
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoCiudades *pnodoCiudades; //alias redefinir los punteros



//+++++++++++++++++++++++++++++++++++++++++++++++++++PAISES++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class nodoPaises { //clase NODO
	
   public:
    nodoPaises(string codpais, string nombre) // 20 Tiene diferente cantidad de parametros, diferente tipos. Mismo nombre de la clase
    {
       cod_pais = codpais;
       nombre_pais = nombre;
       siguiente = NULL;
       abajo = NULL;
    }

 
    nodoPaises(string codpais, string nombre, nodoPaises * signodo) // 2 dirprimero direccion de memoria
    {
       cod_pais = codpais;
       nombre_pais = nombre;
       siguiente = signodo;
    }


    // atributos
    string cod_pais;
	string nombre_pais; 
    nodoPaises * siguiente; 
    nodoCiudades * abajo;
        
   friend class lista; // telefono, son amigas lista con la clase. Solo los metodos, constructores

};
typedef nodoPaises *pnodoPaises; //alias redefinir los punteros

class lista {
   public:
    lista()
	{
      primeroPaises = NULL; 
	  primeroCiudades = NULL;
	  primeroConexiones = NULL;  
	  primeroTipotrenes = NULL;
	  primeroTrenes = NULL;
	  primeroRutasprecio = NULL;
	  primeroRutas = NULL;
	  primeroUsuarios = NULL;
	  primeroAdministradores = NULL;
	  
	}

    void InsertarFinalPaises(string codpais, string nombre);
  	void InsertarFinalCiudades(string codpais,string codciudad, string nombre);
    void InsertarFinalConexiones(string codpais1,string codciudad1, string conexion, string codpais2, string codciudad2,string tiempo12);
    void InsertarFinalTipoTrenes(string codtipotren, string nombre);
    void InsertarFinalTrenes(string codtipotren, string codtren, string nombre);
    void InsertarFinalRutasPrecio(string codruta, string codprecio);
    
    
    bool ListaVaciaPaises() { return primeroPaises == NULL; }
    bool ListaVaciaCiudades() { return primeroCiudades == NULL; }
    bool ListaVaciaConexiones() { return primeroConexiones == NULL; }
    bool ListaVaciaTipoTrenes() { return primeroTipotrenes == NULL; }
    bool ListaVaciaTrenes() { return primeroTrenes == NULL; }
    bool ListaVaciaRutasprecio() { return primeroRutasprecio == NULL;}
    bool ListaVaciaRutas() { return primeroRutas == NULL; }
    bool ListaVaciaUsuarios() { return primeroUsuarios == NULL; }
    bool ListaVaciaAdministradores() { return primeroAdministradores == NULL; }
    
    
    
    void mostrarPaises();
    void mostrarCiudades();
    void mostrarConexiones();
    void mostrarTipoTrenes();
    void mostrarTrenes();
    
    void Imprimir();
    void Mostrar();
    void Primero();
	void BorrarFinal();
    
    
    
      

    pnodoPaises primeroPaises;
	pnodoCiudades primeroCiudades;
	pnodoConexiones primeroConexiones; // nodo *primero; tipo nodo tiene derechoi direccionar un nodo
    pnodoTipotrenes primeroTipotrenes;
	pnodoTrenes primeroTrenes;
	pnodoRutasprecio primeroRutasprecio;
	pnodoRutas primeroRutas;
	pnodoUsuarios primeroUsuarios;
	pnodoAdministradores primeroAdministradores;
	
};

/*int lista::largoLista(){ //largo
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
    
}*/
 
/*void lista::InsertarFinal(string v)
{
   if (ListaVacia())
     primero = new nodo(v);
   else
     { pnodo aux = primero;
        while ( aux->siguiente != NULL)
          aux= aux->siguiente;
        aux->siguiente=new nodo(v);
      }    
}*/

      
/*void lista::BorrarFinal()
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

 
*/
	
//*****************************MÉTODOS DE INSERCIÓN*********************************************************

void lista::InsertarFinalPaises(string CodPaises, string Nombre)
{
	bool flag = true;
	if(ListaVaciaPaises())
	{
	    primeroPaises = new nodoPaises(CodPaises, Nombre);
	  
	}
	else 
	{
	  pnodoPaises aux = primeroPaises;
		while(aux)
		{ if(CodPaises == aux->cod_pais)
			{   flag = false;
				break;
			}
		  else
		  	{
		  		if(aux->siguiente == NULL)
		  		{
		  			break;
				}
		  		aux = aux->siguiente;
		  	}
		}
		if(flag == true)
		{
			aux->siguiente = new nodoPaises(CodPaises, Nombre);
		}
	}
	
}

void lista::InsertarFinalCiudades(string codpais,string codciudad, string nombre)
{ 
	bool flag = true;
	
    pnodoPaises aux = primeroPaises;
	pnodoCiudades aux2;
	while(aux)
	{
		if(codpais == aux->cod_pais)
		{ 	
			if(aux->abajo == NULL)
			{
				aux->abajo = new nodoCiudades(codpais, codciudad, nombre);
				flag == false;
				break;
			}
			else
			{
				aux2 = aux->abajo;
				
				while(aux2)
				{	
					if(codciudad == aux2->cod_ciudad)
					{
						flag = false;
						break;
					}
					else
					{
						if(aux2->siguiente == NULL)
						{
							break;
						}
						
						aux2 = aux2->siguiente;
					}
					
				}
				break;
			}			
		}
		else
		{	if(aux->siguiente == NULL)
			{
				flag = false;
				break;
			}
			aux = aux->siguiente;
		}
	}
		if(flag == true)
		{
			aux2->siguiente = new nodoCiudades(codpais, codciudad, nombre);
		}
		primeroTipotrenes = NULL;
}

void lista::InsertarFinalConexiones(string codpais1,string codciudad1, string conexion, string codpais2, string codciudad2,string tiempo12)
{
	bool flag = true;
	pnodoPaises aux = primeroPaises;
	pnodoCiudades aux2;
	pnodoConexiones aux3;
	
	while(aux)
	{
		if(codpais1 == aux->cod_pais)
		{	
			aux2 = aux->abajo;
					
			while (aux2)
			{
				if(codciudad1 == aux2->cod_ciudad)
				{
					aux3 = aux2->abajo;
					
					if(aux3 == NULL)
					{
						aux2->abajo = new nodoConexiones(codpais1, codciudad1, conexion, codpais2, codciudad2, tiempo12);
						
						flag = false;
						break;
					}
					
					while(aux3)
					{
						if(conexion == aux3->cod_conexion)
						{
							flag = false;
							break;
						}
							aux3 = aux3->siguiente;
					}
					break;
				}
				else
				{
					aux2 = aux2->siguiente;
				}
			}
			break;
		}
		else
		{
			if(aux->siguiente == NULL)
			{
				flag = false;
				break;
			}
			aux = aux->siguiente;
		}	
	}
	
	if(flag == true)
	{
		aux3->siguiente = new nodoConexiones(codpais1, codciudad1, conexion, codpais2, codciudad2, tiempo12);

	}
}

void lista::InsertarFinalTipoTrenes(string codtipotren, string nombre)
{

	bool flag = true;

	if(ListaVaciaTipoTrenes())
	{ 
	    primeroTipotrenes = new nodoTipotrenes(codtipotren, nombre);

	}
	else 
	{
	  pnodoTipotrenes aux = primeroTipotrenes;
		while(aux)
		{ if(codtipotren == aux->cod_tipo_tren)
			{   flag = false;
				break;
			}
		  else
		  	{
		  		if(aux->siguiente == NULL)
		  		{
		  			break;
				}
		  		aux = aux->siguiente;
		  	}
		}
		if(flag == true)
		{
			aux->siguiente = new nodoTipotrenes(codtipotren, nombre);
		}
	}	
}
/*
void lista::InsertarFinalTrenes(string codtipotren, string codtren, string nombre, string cantidadasientos, string codigorutas) 
{
	bool flag = true;
	
    pnodoTipotrenes aux = primeroTipotrenes;
	pnodoTrenes aux2;
	while(aux)
	{
		if(codtipotren == aux->cod_tipo_tren)
		{ 	
			if(aux->abajo == NULL)
			{
				aux->abajo = new nodoTrenes(string codtipotren, string codtren, string nombre, string cantidadasientos, string codigorutas);
				flag == false;
				break;
			}
			else
			{
				aux2 = aux->abajo;
				
				while(aux2)
				{	
					if(codtren == aux2->cod_tren)
					{
						flag = false;
						break;
					}
					else
					{
						if(aux2->siguiente == NULL)
						{
							break;
						}
						
						aux2 = aux2->siguiente;
					}
					
				}
				break;
			}			
		}
		else
		{	if(aux->siguiente == NULL)
			{
				flag = false;
				break;
			}
			aux = aux->siguiente;
		}
	}
		if(flag == true)
		{
			aux2->siguiente = new nodoTrenes(codtipotren, codtren, nombre);
		}		
}
*/

//*******************************************************************MÉTODOS MOSTRAR************************************************************************

void lista::mostrarPaises()
{
	nodoPaises *aux;
   if (primeroPaises == NULL)
       cout << "No hay elementos" << endl;  
   else
   {
   		aux = primeroPaises;

		while(aux->siguiente != NULL) 
		{
		    cout << aux->nombre_pais << "-> ";
		    aux = aux->siguiente;
		}
		cout << aux->nombre_pais << endl;

   }
}


void lista::mostrarCiudades()
{
	pnodoPaises aux = primeroPaises;
	
	while(aux)
	{	cout << aux->nombre_pais<< "->" << endl;
		cout << "   Ciudades:";
	
		while(true)
		{ 
			pnodoCiudades aux2 = aux->abajo;
			
			while(aux2)
			{
				cout << "  " << aux2->nombre_ciudad; 
				
				aux2 = aux2->siguiente;
				
				if(aux2 == NULL)
				{
					cout << endl;
					break;
				}
				cout << "->";
			}
			break;
		}
		aux = aux->siguiente;
	}
	
	
}

void lista::mostrarConexiones()
{
	pnodoPaises aux = primeroPaises;
	
	while(aux)
	{	cout << aux->nombre_pais<< "->" << endl;
		cout << "   Ciudad:";
	
		while(true)
		{ 
			pnodoCiudades aux2 = aux->abajo;
			
			while(aux2)
			{
				cout << "  " << aux2->nombre_ciudad << endl;
				cout<<"       Conexiones:";
				
				 pnodoConexiones aux3 = aux2->abajo;
				 
				 while(aux3)
				 {
				 	cout<<aux3->cod_conexion;
				 	
				 	aux3 = aux3->siguiente;
				 }
				
				aux2 = aux2->siguiente;
				
				if(aux2 == NULL)
				{
					cout << endl;
					break;
				}
				cout << "->";
			}
			break;
		}
		aux = aux->siguiente;
	}
}

void lista::mostrarTipoTrenes()
{ 
	nodoTipotrenes *aux;
   if (primeroTipotrenes == NULL)
       cout << "No hay elementos" << endl;  
   else
   {
   		aux = primeroTipotrenes;

		while(aux->siguiente != NULL) 
		{
		    cout << aux->nombre_tipo_tren << "-> ";
		    aux = aux->siguiente;
		}
		cout << aux->nombre_tipo_tren << endl;

   }
	
}

void lista::mostrarTrenes()
{
	
	
	
}



lista leerArch(int numero,lista todo);

int main(){
	lista todo;
	for(int numero = 1; numero < 9; numero++){
		todo = leerArch(numero,todo);
	}
	
	cout << "Bienvenido!" << endl; 
	
	
	pnodoPaises aux = todo.primeroPaises;
	while(true)
	{
		cout << "Si desea ingresar como usuario digite 1, si desea ingresar como administrador digite 2. " << endl;
		
		int opcion;
		cin>>opcion;
		cout<< endl;
		
		if(opcion == 1)
		{	
		while(true)
			{
				cout << "1.	Consultar Paises\n" <<
						"2.	Consultar Ciudades\n"<<
						"3.	Consultar Conexiones\n"<<
						"4.      Consultar Tipo tren\n"<<
						"5.	Consultar Trenes\n"<<
						"6.	Consultar Precios\n"<<
						"7.	Consultar numasientos disponibles de un tren\n"<<
	  					"8.	Consultar Rutas\n" << 
						"9.      Cerrar Sesion" << endl;
		
				int opcion;
				cin>>opcion;
				cout << endl;
				if(opcion == 1)
				{
					todo.mostrarPaises();
				}
				else if(opcion == 2)
				{
					todo.mostrarCiudades();
				}
				else if(opcion == 3)
				{
					todo.mostrarConexiones();
				}
				else if(opcion == 4)
				{   
					todo.mostrarTipoTrenes();
				}
				else if(opcion == 5)
				{   
				//	todo.mostrarTrenes();
				}
				else if(opcion == 6)
				{
					//todo.mostrarPrecios();
				}
				else if(opcion == 7)
				{
					//todo.mostrarnumasientos disponibles de un tren();
				}
				else if(opcion == 8)
				{
					//todo.mostrarRutas();
				}
				else if(opcion == 9)
				{
					//todo.mostrarCerrar Sesión();
				}
				else
				{
					cout<< "Codigo no valido" << endl;
				}
			}	
		}
		else if(opcion == 2)
		{	
			//admin
		}
		else
		{
			cout<< "Codigo no valido";
		}
		
	}

	return 0;
}


lista leerArch(int numero,lista todo){
	ifstream txt;
	string linea;

	if(numero == 1){
		txt.open("Paises.txt", ios::in);	
	}
	else if (numero == 2)
	{
		txt.open("Ciudades.txt", ios::in);
	}
	else if(numero == 3)
	{
		txt.open("Conexiones.txt", ios::in);	
	}
	else if(numero == 4)
	{
		txt.open("TipoTren.txt", ios::in);
	}
	else if(numero == 5)
	{
		txt.open("Tren.txt", ios::in);	
	}
	else if(numero == 6)
	{
		txt.open("Rutas.txt", ios::in);
	}	
	else if(numero == 7)
	{
		txt.open("Usuarios.txt", ios::in);	
	}
	else if(numero == 8)
	{
		txt.open("Administradores.txt", ios::in);	
	}
	/*
	if(txt.fail()){
		cout<< "No se pudo abrir el archivo"<< endl;
		exit(1);
	}
	*/
	if(numero == 1)
	{ 
		string CodPaises,Nombre; //DECLARACION
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodPaises = partir;		        
		    	}else if(numerovariable == 1){
		    		Nombre = partir;	
				}				
				numerovariable++;	
		    }

			todo.InsertarFinalPaises(CodPaises, Nombre);
  
		}return todo;
	}
	
	if(numero == 2)
	{
		string CodPaises, CodCiudad, Nombre; //DECLARACION
		
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodPaises = partir;		        
		    	}else if(numerovariable == 1){
		    		CodCiudad = partir;	
		    	}else if(numerovariable == 2){
		    		Nombre = partir;	
				}				
				numerovariable++;
		    }
			todo.InsertarFinalCiudades(CodPaises, CodCiudad, Nombre);		    
		}return todo;
	}
	
	if(numero == 3)
	{
		string CodPais, CodCiudad, CodConexion, CodPais2, CodCiudad2, Tiempo; //DECLARACION
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodPais = partir;		        
		    	}else if(numerovariable == 1){
		    		CodCiudad = partir;	
		    	}else if(numerovariable == 2){
		    		CodConexion = partir;	
				}else if(numerovariable == 3){
		    		CodPais2 = partir;	
				}else if(numerovariable == 4){
		    		CodCiudad2 = partir;	
				}else if(numerovariable == 5){
		    		Tiempo = partir;	
				}																
				numerovariable++;
		    }
			todo.InsertarFinalConexiones(CodPais, CodCiudad, CodConexion, CodPais2, CodCiudad2, Tiempo);		    
		}return todo;
	}
	
	if(numero == 4)
	{
		string CodTipoTren,Nombre; //DECLARACION
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodTipoTren = partir;		        
		    	}else if(numerovariable == 1){
		    		Nombre = partir;	
				}				
				numerovariable++;

		    }
			todo.InsertarFinalTipoTrenes(CodTipoTren,Nombre);		    
		}return todo;
	}
	if(numero == 5)
	{
		string CodTipoTren, CodTren, Nombre; //DECLARACION
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodTipoTren = partir;		        
		    	}else if(numerovariable == 1){
		    		CodTren = partir;	
				}else if(numerovariable == 2){
		    		Nombre = partir;	
				}						
				numerovariable++;
		    }
			//todo.InsertarFinalTrenes(CodTipoTren,Codtren, Nombre);		    
		}return todo;
	}
	if(numero == 6)
	{
		string CodTipoTren, CodTren, CodRuta, CodPais, CodCiudad, CodPais2, CodCiudad2, Precio; //DECLARACION
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodTipoTren = partir;		        
		    	}else if(numerovariable == 1){
		    		CodTren = partir;	
				}else if(numerovariable == 2){
		    		CodRuta = partir;	
				}else if(numerovariable == 3){
		    		CodPais = partir;	
				}else if(numerovariable == 4){
		    		CodCiudad = partir;	
				}else if(numerovariable == 5){
		    		CodPais2 = partir;	
				}else if(numerovariable == 6){
		    		CodCiudad2 = partir;	
				}else if(numerovariable == 7){
		    		Precio = partir;	
				}
										
				numerovariable++;
		    }
			//todo.InsertarFinalRutas(CodTipoTren, CodTren, CodRuta, CodPais, CodCiudad, CodPais2, CodCiudad2, Precio);		    
		}return todo;
	}
	if(numero == 7)
	{
		string CodPais, CodCiudad, Pasaporte, Nombre, Estado_Migratorio; //DECLARACION
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodPais = partir;		        
		    	}else if(numerovariable == 1){
		    		CodCiudad = partir;	
		    	}else if(numerovariable == 2){
		    		Pasaporte = partir;	
				}else if(numerovariable == 3){
		    		Nombre = partir;	
				}else if(numerovariable == 4){
		    		Estado_Migratorio = partir;	
				}																
				numerovariable++;
		    }
			//todo.InsertarFinalUsuarios(CodPais, CodCiudad, Pasaporte, Nombre, Estado_Migratorio);		    
		}return todo;
	}
	if(numero == 8)
	{
		string CodAdmin, Nombre; //DECLARACION
		while(std::getline(txt,linea))
		{
			int numerovariable = 0;
		   	std::stringstream stream(linea);
		   	std::string partir;		    		
		   	while(std::getline(stream,partir,';'))
		   	{
		    	if(numerovariable == 0){
		    		CodAdmin = partir;		        
		    	}else if(numerovariable == 1){
		    		Nombre = partir;	
		    	}													
				numerovariable++;
		    }
			//todo.InsertarFinalAdministradores(CodAdmin, Nombre);		    
		}return todo;
	}
}


