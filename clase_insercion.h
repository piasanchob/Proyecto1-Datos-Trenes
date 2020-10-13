class insertar{
	public:
	void insertar_doble_circular_pais();
	
	friend class lista;
};

void insertar::insertar_doble_circular_pais()
{
			if (lista_paises == NULL)
			{
				primero = new nodo_destinos(codigo_pais, nombre_pais);
				primero->anterior = primero;
				primero->siguiente = primero;
			}
			else
			{
				
				while(true)
				{
				
				pnodo nuevo = new nodo_destinos(codigo_pais, nombre_pais);
				pnodo aux = lista_paises.primero;
				
				
				
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
				
				
				}
				while(aux->siguiente != lista_paises.primero)
				{
					if(nuevo->codigo_pais == aux->siguiente->codigo_pais)
					{
					break;
					}
					else
					{
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
					
				}
     		}
     		
			
}
		

