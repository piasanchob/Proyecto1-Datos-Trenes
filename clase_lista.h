// Métodos de creación de listas
#include "clase_trenes.h"
#include "Listadoblecircular.h"

class lista{
	
	public:
		
	lista() { primero = NULL; }
		
	lista lista_paises(string nombre);
	void lista_ciudades(string nombre);
	void lista_conexiones(string nombre);
	lista lista_tipo_trenes(string nombre);
	lista lista_trenes(string nombre);
	lista lista_rutas(string nombre);
	
	void InsertarFinal(string codpais, string nombrepais);
	void InsertarFinalciudad(string codpais, string codciudad, string nombreciudad);
	
	int largoLista();
	
	pnodo_destinos primero;
	pnodo_trenes primero_;
	
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
	lista lista_tipo_trenes;
	
	FILE *archivo;
		
	string c;
	
	archivo = fopen(nombre.c_str(), "r");
	
	string codigo_tipo_tren;
	
	string nombre_tipo_tren;
	
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
				nombre_tipo_tren = nombre_tipo_tren + c;
			}
			
			break;
		}
		
		codigo_tipo_tren = codigo_tipo_tren + c;
	}
	
	pnodo_trenes nuevo = new nodo_trenes(codigo_tipo_tren, nombre_tipo_tren);
	pnodo_trenes aux = lista_trenes.primero_;
	while(true)
	{
		
	if(lista_trenes.primero_ == NULL)
	{
		lista_tipo_trenes.InsertarFinalD(codigo_tipo_tren, nombre_tipo_tren); 
		break;	
	}
	
	else 
	{	while(aux->siguiente != NULL)
		{
			if(nuevo->codigo_tipo_tren == aux->codigo_tipo_tren)
			{
				break;
			}
			aux = aux->siguiente;	
		}
		
		if(aux->siguiente == NULL && nuevo->codigo_tipo_tren != aux->codigo_tipo_tren)
		{
			lista_tipo_trenes.InsertarFinalD(codigo_tipo_tren, nombre_tipo_tren); 	
			break;
		}
		break;
	
	}
	}
	
	fclose(archivo);
	return lista_tipo_trenes;
}

