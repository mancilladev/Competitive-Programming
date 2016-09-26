#include <iostream>

/*#define bajo 1
#define tope 20*/

void debug(int k);

int main(int argc, char const *argv[])
{
	int unidades[9] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
	// one two three four five six seven eight nine
	int tines[9] =    {6, 6, 8, 8, 7, 7, 9, 8, 8};
	// eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
	int decenas[9] =  {3, 6, 6, 5, 5, 5, 7, 6, 6};
	// ten twenty thirty forty fifty sixty seventy eighty ninety
	// int muldiez[10] =  [7, 8, 7];
	// million,thousand, hundred
	int cien = 10;
	// hundred and
	unsigned int conteo = 0;
	//numero de letras
	unsigned int trabajo;
	//numero que podemos modificar
	int bajo, tope;

	std::cin >> bajo >> tope;

	for (int numeroactual = bajo; numeroactual < tope; ++numeroactual)
	{
		if ((trabajo = numeroactual/100) > 0) // si tiene alguna centena
		{
			conteo += unidades[trabajo-1] + cien;
			if (numeroactual - (trabajo * 100) == 0 ) // si tiene algo aparte del multiplo de la centena "and"
			{
				conteo -= 3;
			}
		}

		if ((trabajo = (numeroactual % 100)/10) > 1) // si tiene algun digito mayor a 1 en las decenas
		{
			conteo += decenas[trabajo-1];
		}
		else if (trabajo && numeroactual % 10)//si tiene 10 mas otro digito
		{
			conteo += tines[(numeroactual % 10) - 1];
			continue;//tenemos que volver a empezar por que ya llegamos a las unidades
		}
		else if(trabajo)//si solo es el 10
		{
			conteo += decenas[0];
			continue;// si ya sabemos que es 10, ya sabemos que no hay unidades; por lo tanto reiniciamos el ciclo
		}

		if (trabajo = numeroactual % 10)// si tiene alguna unidad
		{
			conteo += unidades[trabajo-1];
		}

	}
	conteo += 11;//one thousand
	std::cout << conteo << std::endl;
	return 0;
}


void debug(int k)
{
	std::cout << k << std::endl;
}
