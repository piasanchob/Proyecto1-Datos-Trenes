// Métodos de creación de listas
#include "clase_trenes.h"
#include "Listadoblecircular.h"
//#include "clase_insercion.cpp"
class lista{
	
	public:
		
	lista() { primero = NULL; }
		
	lista lista_paises(string nombre);
	void lista_ciudades(string nombre);
	void lista_conexiones(string nombre);
	lista lista_tipo_trenes(string nombre);
	lista lista_trenes(string nombre);
	lista lista_rutas(string nombre);
	
	
	
	/*
	void insertar_doble_circular_pais(pnodo nodo);
	void insertar_nodo_ciudad(pnodo nodo);
	void insertar_nodo_conexion(pnodo nodo);
	*/
	pnodo_destinos primero;
	
	friend class listaDC;

};

lista lista::lista_paises(string nombre)
{
	
	lista lista_paises;
	FILE *archivo;
	
	string c;
	
	archivo = fopen(nombre.c_str(), "r");
	
	string codigo_pais;
	
	string nombre_pais;
	
	
	while(true)
	{
		
		c = fgetc(archivo);
		
		if (c == ";")
		{
			
			
		 	while(true)
		 	{
		 		if (c == "\n")
				 {
		 			break;
				 }
		 		
		 		c = fgetc(archivo);
		 		nombre_pais = nombre_pais + c;
		 		
			}
			pnodo_destinos nuevo = new nodo_destinos(codigo_pais, nombre_pais);
			pnodo_destinos aux = lista_paises.primero;
			
			int cont = 0;
			
			if(lista_paises.largoLista() == 0)
			{
				lista_paises.InsertarFinal(codigo_pais, nombre_pais);
				continue;
			}
			
			else
			{
			
			while(cont != lista_paises.largoLista())
			{
				if(nuevo->codigo_pais == aux->codigo_pais)
				{
					break;
				}
				
				else
				{
					cont++;
					if(cont == lista_paises.largoLista())
					{
						lista_paises.InsertarFinal(codigo_pais, nombre_pais);
						break;
					}
					
				}
				
								
			}
			
			
			
			if (feof(archivo))
			{
            	break;
			}
			
			}
		}
			
			
		codigo_pais = codigo_pais + c;	
		continue;	
	} 
	
	fclose(archivo);
	return lista_paises;
}

void lista::lista_ciudades(string nombre)
{
	lista lista_ciudades;
	FILE *archivo;
	
	string c;
	
	archivo = fopen(nombre.c_str(), "r");
	
	string codigo_pais;
	
	string codigo_ciudad;
	
	string nombre_ciudad;
	
	while(true)
	{	
		
		c = fgetc(archivo);
		
		if (c == ";")
		{
			while(true)
			{
				
				c = fgetc(archivo);
				
				if(c == ";")
				{
					while(true)
		 			{
		 				if (c == "\n")
				 		{
		 					break;
				 		}
				 		
				 		c = fgetc(archivo);
		 				nombre_ciudad = nombre_ciudad + c;
				 		
				 	}
		 			
		 			break;
				}
				
				codigo_ciudad = codigo_ciudad + c;
				
			}
			
			pnodo_destinos nuevo = new nodo_destinos(codigo_pais, codigo_ciudad, nombre_ciudad);
			pnodo_destinos aux = lista_paises.primero;
			
			while(aux->siguiente != lista_paises.primero)
			{
				if(nuevo->codigo_pais == aux->codigo_pais)
				{
					pnodo_destinos primero_ciudad = aux->ciudad;
					pnodo_destinos aux2 = primero_ciudad;
					
					if(aux->ciudad == NULL)
					{
						aux->ciudad = nuevo;
						nuevo->pais = aux;
						
						nuevo->anterior=nuevo;
     					nuevo->siguiente=nuevo;
     					
     					break;
					}					
					
					else if(aux->ciudad->siguiente == aux->ciudad)
					{
						nuevo->anterior = aux2->anterior;
    					nuevo->siguiente= aux2->anterior->siguiente;
    				    aux2->anterior->siguiente=nuevo;
     					aux2->anterior=nuevo;	
     					
     					break;
					}
					
					else
					{
						while(aux2->siguiente != primero_ciudad)
						{
							if(nuevo->codigo_ciudad == aux2->codigo_ciudad)
							{
								break;
							}
							else
							{
								aux2 = aux2->siguiente;
								if(aux2->siguiente == primero_ciudad)
								{
									nuevo->anterior = aux2->anterior;
    								nuevo->siguiente= aux2->anterior->siguiente;
    				    			aux2->anterior->siguiente=nuevo;
     								aux2->anterior=nuevo;	
     								
									break;
								}
								
							}
							
						}
						break;
					}
				}
				aux=aux->siguiente;
				if (aux->siguiente == lista_paises.primero)
				{
					if(nuevo->codigo_pais == aux->codigo_pais)
					{
					pnodo_destinos primero_ciudad = aux->ciudad;
					pnodo_destinos aux2 = primero_ciudad;
					
					if(aux->ciudad == NULL)
					{
						aux->ciudad = nuevo;
						nuevo->pais = aux;
						
						nuevo->anterior=nuevo;
     					nuevo->siguiente=nuevo;
     					
     					break;
					}					
					
					else if(aux->ciudad->siguiente == aux->ciudad)
					{
						nuevo->anterior = aux2->anterior;
    					nuevo->siguiente= aux2->anterior->siguiente;
    				    aux2->anterior->siguiente=nuevo;
     					aux2->anterior=nuevo;	
     					
     					break;
					}
					
					else
					{
						while(aux2->siguiente != primero_ciudad)
						{
							if(nuevo->codigo_ciudad == aux2->codigo_ciudad)
							{
								break;
							}
							else
							{
								aux2 = aux2->siguiente;
								if(aux2->siguiente == primero_ciudad)
								{
									nuevo->anterior = aux2->anterior;
    								nuevo->siguiente= aux2->anterior->siguiente;
    				    			aux2->anterior->siguiente=nuevo;
     								aux2->anterior=nuevo;	
     								
									break;
								}
								
							}
							
						}
						break;
					}
					}
				}
				else
				{
					break;
				}
			}
			
		}
		else
		{
		
		codigo_pais = codigo_pais + c;
		
		    if (feof(archivo))
			{
            	break;
			}
		}
	}
	
	fclose(archivo);

}
	
	
	
void lista::lista_conexiones(string nombre)
{

	lista lista_ciudades;
	FILE *archivo;
	
	string c;
	
	archivo = fopen(nombre.c_str(), "r");
	
	string codigo_pais_origen;
	
	string codigo_ciudad_origen;
	
	string codigo_conexion;
	
	string codigo_pais_destino;
	
	string codigo_ciudad_destino;
	
	string tiempo;
	
	while(true)
	{

		c = fgetc(archivo);
		
		if (c == ";")
		{
			while(true)
			{
				c = fgetc(archivo);
				
				if(c == ";")
				{
					while(true)
					{
						c = fgetc(archivo);
						
						if(c == ";")
						{
							while(true)
							{
								c = fgetc(archivo);
								
								if(c == ";")
								{
									while(true)
									{
										c = fgetc(archivo);
										
										if(c == ";")
										{
											while(true)
											{
												c = fgetc(archivo);
												
												if(c == "\n")
												{
													break;
												}
												
												tiempo = tiempo + c;
												
											}
											break;
										}	
										codigo_ciudad_destino = codigo_ciudad_destino + c;
									}
									break;
								}
								
								codigo_pais_destino = codigo_pais_destino + c;
							}	
							break;
						}
						
						codigo_conexion = codigo_conexion + c;
					}
					break;
				}
				
				codigo_ciudad_origen = codigo_ciudad_origen + c;
			}
		
			pnodo_destinos nuevo = new nodo_destinos(codigo_pais_origen, codigo_ciudad_origen, codigo_conexion, codigo_pais_destino, codigo_ciudad_destino, tiempo);

		
			pnodo_destinos aux = lista_paises.primero;
			
			while(aux->siguiente != lista_paises.primero)
			{
				if(nuevo->codigo_pais == aux->codigo_pais)
				{
					pnodo_destinos aux2 = aux->ciudad;
					
					while(aux2->siguiente != aux->ciudad)
					{
						if(nuevo->codigo_ciudad_origen == aux2->codigo_ciudad)
						{
							pnodo_destinos aux3 = aux2->conexion;
							
							if(aux3->conexion == NULL)
							{
								aux2->conexion = nuevo;
								nuevo->ciudad = aux2;
								break;
								
							}
							
							else
							{
								while(aux3->siguiente != NULL)
								{
									if(nuevo->codigo_conexion == aux3->codigo_conexion)
									{
										break;
									}
									
									aux3 = aux3->siguiente;
								}
								
								if(aux3->siguiente == NULL)
									{
										if(nuevo->codigo_conexion == aux3->codigo_conexion)
										{
											break;
										}
										
										else
										{
											aux3->siguiente = nuevo;
											aux3->siguiente->anterior = aux3;
											break;	
											
										}
										
									}	
							}
					
						}
						aux2 = aux2->siguiente;
						if(aux2->siguiente == aux->ciudad)
						{
							if(nuevo->codigo_ciudad_origen == aux2->codigo_ciudad)
						{
							pnodo_destinos aux3 = aux2->conexion;
							
							if(aux3->conexion == NULL)
							{
								aux2->conexion = nuevo;
								nuevo->ciudad = aux2;
								
							}
							
							else
							{
								while(aux3->siguiente != NULL)
								{
									if(nuevo->codigo_conexion == aux3->codigo_conexion)
									{
										break;
									}
									
									aux3 = aux3->siguiente;
								}
								
								if(aux3->siguiente == NULL)
									{
										if(nuevo->codigo_conexion == aux3->codigo_conexion)
										{
											break;
										}
										
										else
										{
											aux3->siguiente = nuevo;
											aux3->siguiente->anterior = aux3;
											break;	
											
										}
										
									}	
							}
					
						}
						}
						
					}
				
				}
				aux = aux->siguiente;
			}
				
				if(aux->siguiente == lista_paises.primero)
				{
					if(nuevo->codigo_pais == aux->codigo_pais)
				{
					pnodo_destinos aux2 = aux->ciudad;
					
					while(aux2->siguiente != aux->ciudad)
					{
						if(nuevo->codigo_ciudad_origen == aux2->codigo_ciudad)
						{
							pnodo_destinos aux3 = aux2->conexion;
							
							if(aux3->conexion == NULL)
							{
								aux2->conexion = nuevo;
								nuevo->ciudad = aux2;
								break;
								
							}
							
							else
							{
								while(aux3->siguiente != NULL)
								{
									if(nuevo->codigo_conexion == aux3->codigo_conexion)
									{
										break;
									}
									
									aux3 = aux3->siguiente;
								}
								
								if(aux3->siguiente == NULL)
									{
										if(nuevo->codigo_conexion == aux3->codigo_conexion)
										{
											break;
										}
										
										else
										{
											aux3->siguiente = nuevo;
											aux3->siguiente->anterior = aux3;
											break;	
											
										}
									}	
							}
						}
						aux2 = aux2->siguiente;						
					}
				}	
				}			
		}		
		else
		{
			codigo_pais_origen = codigo_pais_origen + c;
	
				if (feof(archivo))
				{
            		break;
				}
		}	
		fclose(archivo);
	
	}
}
lista lista::lista_tipo_trenes(string nombre)
{
	
	
}




















	/*
						int cont = 0;
			
						if(lista_ciudades.largoLista() == 0)
						{
						lista_ciudades.InsertarFinalciudad(codigo_pais, codigo_ciudad, nombre_ciudad);
							break;
						}
			
						else
						{
			
						while(cont != lista_ciudades.largoLista())
						{
							if(nuevo->codigo_ciudad == aux->codigo_ciudad)
							{
								break;
							}
				
							else
							{
								cont++;
								if(cont == lista_ciudades.largoLista())
								{
									lista_ciudades.InsertarFinalciudad(codigo_pais, codigo_ciudad, nombre_ciudad);
									break;
								}
							
							}				
						}
						}
				}
				else
				{
					aux = aux->siguiente;
					
				}
				
			}
			
			if (feof(archivo))
			{
            	break;
			}
			
		}
		else
		{
		
			codigo_pais = codigo_pais + c;
			continue;
			
		}
	}
			fclose(archivo);
			return lista_ciudades;
	
}



*/


























/*
void lista::insertar_doble_circular_pais(pnodo nodo)
{
			if (ListaVacia())
			{
				primero = nodo;
				primero->anterior = primero;
				primero->siguiente = primero;
			}
			else
			{
				
				while(true)
				{
				
				pnodo nuevo = nodo;
				cout << lista_paises.primero;
				//pnodo aux = lista_paises.primero;
				
				
				
					if(nuevo->codigo_pais == aux->codigo_pais)
					{
						break;
					}
				
					else if(aux->siguiente == lista_paises.primero)
					{
						nuevo->anterior = primero->anterior;
     					nuevo->siguiente=primero->anterior->siguiente;
     					primero->anterior->siguiente=nuevo;
     					primero->anterior=nuevo;
     					break;
					}
				
					else
					{
					
						while(aux->siguiente != lista_paises.primero)
						{
							if(nuevo->codigo_pais == aux->siguiente->codigo_pais)
							{
							break;
							}
							else
							{
								aux->anterior = aux;
								aux = aux->siguiente;
								if(aux->siguiente == lista_paises.primero)
								{
									nuevo->anterior = primero->anterior;
     								nuevo->siguiente=primero->anterior->siguiente;
     								primero->anterior->siguiente=nuevo;
     								primero->anterior=nuevo;
									break;	
								
								}
							}
				
						}
						
						break;
					}	
				}
     		}	
}

lista lista::lista_ciudades(string nombre)
{
	lista lista_ciudades;
	FILE *archivo;
	
	string c;
	
	archivo = fopen(nombre.c_str(), "r");
	
	string codigo_pais;
	
	string codigo_ciudad;
	
	string nombre_ciudad;
	
	while(true)
	{	
		
		c = fgetc(archivo);
		
		if (c == ";")
		{
			while(true)
			{
				
				c = fgetc(archivo);
				
				if(c == ";")
				{
					while(true)
		 			{
		 				if (c == "\n")
				 		{
		 					break;
				 		}
				 		
				 		c = fgetc(archivo);
		 				nombre_ciudad = nombre_ciudad + c;
				 		
				 	}
		 			
		 			break;
				}
				
				codigo_ciudad = codigo_ciudad + c;
				
			}
			
			pnodo nuevo = new nodo_destino(codigo_pais, codigo_ciudad, nombre_ciudad);
			insertar_nodo_ciudad(nuevo);
			//lista de ciudades
			//hacerlistaciudades();
			
		
			

			
			if (feof(archivo))
			{
            	break;
			}
			
		}
			codigo_pais = codigo_pais + c;
			continue;	
	}
			fclose(archivo);
			return lista_ciudades;
	
}

void lista::insertar_nodo_ciudad(pnodo nodo)
{

	pnodo primero_pais = lista_paises.primero;
	pnodo aux = primero_pais;
	
	
	while(aux->siguiente != primero_pais)
	{
		if(nodo->codigo_pais == aux->codigo_pais)
		{
			if (aux->ciudad == NULL)
			{
				pnodo primero_ciudad = nodo;
				
				aux->ciudad = primero_ciudad;
				primero_ciudad->pais = aux;
				
				primero_ciudad->siguiente = primero_ciudad;
				primero_ciudad->anterior = primero_ciudad;
				break;
			}
			else if(primero_ciudad->siguiente == primero_ciudad)
			{
				if(nodo->codigo_ciudad == primero_ciudad->codigo_ciudad)
				{
					break;
				}
				else
				{
						nodo->anterior = primero_ciudad->anterior;
     					nodo->siguiente=primero_ciudad->anterior->siguiente;
     					primero_ciudad->anterior->siguiente=nodo;
     					primero_ciudad->anterior=nodo;	
     					break;
				}
				
			}
			else
			{
				pnodo aux2 = primero_ciudad;
				
				while(aux2->siguiente != primero_ciudad)
				{
					if(nodo->codigo_ciudad == aux2->codigo_ciudad)
					{
					break;
					}
					
					else
					{
						aux2->anterior = aux;
						aux2 = aux2->siguiente;	
					}
				}
				
				if(nodo->codigo_ciudad == aux2->codigo_ciudad)
				{
				break;
				}
				
				else
				{
					nodo->anterior = aux2->anterior;
     				nodo->siguiente=aux2->anterior->siguiente;
     				aux2->anterior->siguiente=nodo;
     				aux2->anterior=nodo;	
     				break;
				}	
				
			}
		}
		else
		{	aux->anterior = aux;
			aux = aux->siguiente;
			
			if(aux->siguiente == primero_pais)	
			{
				if(nodo->codigo_pais == aux->codigo_pais)
		{
			if (aux->ciudad == NULL)
			{
				pnodo primero_ciudad = nodo;
				
				aux->ciudad = primero_ciudad;
				primero_ciudad->pais = aux;
				
				primero_ciudad->siguiente = primero_ciudad;
				primero_ciudad->anterior = primero_ciudad;
				break;
			}
			else if(primero_ciudad->siguiente == primero_ciudad)
			{
				if(nodo->codigo_ciudad == primero_ciudad->codigo_ciudad)
				{
					break;
				}
				else
				{
						nodo->anterior = primero_ciudad->anterior;
     					nodo->siguiente=primero_ciudad->anterior->siguiente;
     					primero_ciudad->anterior->siguiente=nodo;
     					primero_ciudad->anterior=nodo;
						 break;	
				}
				
			}
			else
			{
				pnodo aux2 = primero_ciudad;
				
				while(aux2->siguiente != primero_ciudad)
				{
					if(nodo->codigo_ciudad == aux2->codigo_ciudad)
					{
					break;
					}
					
					else
					{
						aux2->anterior = aux;
						aux2 = aux2->siguiente;	
					}
				}
				
				if(nodo->codigo_ciudad == aux2->codigo_ciudad)
				{
				break;
				}
				
				else
				{
					nodo->anterior = aux2->anterior;
     				nodo->siguiente=aux2->anterior->siguiente;
     				aux2->anterior->siguiente=nodo;
     				aux2->anterior=nodo;
					 break;	
				}	
				
			}
		}
			}
		}
	}
}
	
		
	

lista lista::lista_conexiones(string nombre)
{
	lista lista_conexiones;
	FILE *archivo;
	
	string c;
	
	archivo = fopen(nombre.c_str(), "r");
	
	string codigo_pais_origen;
	
	string codigo_ciudad_origen;
	
	string codigo_conexion;
	
	string codigo_pais_destino;
	
	string codigo_ciudad_destino;
	
	string tiempo;
	
	
	while(true)
	{

		c = fgetc(archivo);
		
		if (c == ";")
		{
			while(true)
			{
				c = fgetc(archivo);
				
				if(c == ";")
				{
					while(true)
					{
						c = fgetc(archivo);
						
						if(c == ";")
						{
							while(true)
							{
								c = fgetc(archivo);
								
								if(c == ";")
								{
									while(true)
									{
										c = fgetc(archivo);
										
										if(c == ";")
										{
											while(true)
											{
												c = fgetc(archivo);
												
												if(c == "\n")
												{
													break;
												}
												
												tiempo = tiempo + c;
												
											}
											break;
										}	
										codigo_ciudad_destino = codigo_ciudad_destino + c;
									}
									break;
								}
								
								codigo_pais_destino = codigo_pais_destino + c;
							}	
							break;
						}
						
						codigo_conexion = codigo_conexion + c;
					}
					break;
				}
				
				codigo_ciudad_origen = codigo_ciudad_origen + c;
			}
		
			pnodo nuevo = new nodo_destino(codigo_pais_origen, codigo_ciudad_origen, codigo_conexion, codigo_pais_destino, codigo_ciudad_destino, tiempo);
			lista_ciudades.insertar_doble_circular_ciudad(nuevo);
			
			if (feof(archivo))
			{
            	break;
			}
		
		}
	
	codigo_pais_origen = codigo_pais_origen + c;
	
	continue;
	}
	fclose(archivo);
	return lista_conexiones;
	
}

void lista::insertar_nodo_conexiones()
{
	
	
	
	
}
*/

