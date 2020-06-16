#include <iostream>
#include <string.h>

using namespace std;

//Estructura Pila
struct pila
{
	int top;
	unsigned capacity;
	int* lista;
};

// Operaciones Pila
struct pila* createpila( unsigned capacity )
{
	struct pila* pila = (struct pila*) malloc(sizeof(struct pila));

	if (!pila) return NULL;

	pila->top = -1;
	pila->capacity = capacity;
	pila->lista = (int*) malloc(pila->capacity * sizeof(int));

	if (!pila->lista) return NULL;

	return pila;
}

int isEmpty(struct pila* pila)
{
	return pila->top == -1 ;
}

char peek(struct pila* pila)
{
	return pila->lista[pila->top];
}

char pop(struct pila* pila)
{
	if (!isEmpty(pila))
		return pila->lista[pila->top--] ;
	return '$';
}

void push(struct pila* pila, char op)
{
	pila->lista[++pila->top] = op;
}


// Evaluador de Postfijo
int evaluatePostfix(char* exp)
{
	//Crea una pila con dimensiones de la entrada
	struct pila* pila = createpila(strlen(exp));
	int i;

	//Verifica exito al crear Pila
	if (!pila) return -1;

	//Toma caracter por caracter, para ponerlos en la pila si son operandos y aplica operacion si lo es
	for (i = 0; exp[i]; ++i)
	{
		// Si es numero apila
		if (isdigit(exp[i]))
			push(pila, exp[i] - '0');

		// si es operador lo opera
		else
		{
			int val1 = pop(pila);
			int val2 = pop(pila);
			switch (exp[i])
			{
			case '+': push(pila, val2 + val1); break;
			case '-': push(pila, val2 - val1); break;
			case '*': push(pila, val2 * val1); break;
			case '/': push(pila, val2/val1); break;
			}
		}
	}
	return pop(pila);
}

// Main
int main()
{
    //minimo dos operadores y un operador (3)
	char exp[3];
	cout<<"Ingresa tu expresion PostFijo: ";
	cin>>exp;
	cout<<endl;
	cout<<"Resultado Postfijo: "<< evaluatePostfix(exp);
	return 0;
}
