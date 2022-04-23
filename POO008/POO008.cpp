

#include <iostream>
#include <cassert>
#include <cstddef>

class IntArray
{
private:
	int* m_array{};
	int m_tamanho{};

public:
	IntArray(int tamanho) // constructor
	{
		assert(tamanho > 0);

		m_array = new int[static_cast<std::size_t>(tamanho)]{};
		m_tamanho = tamanho;
	}

	~IntArray() // destructor
	{
		// Dinámicamente delete el array que asignamos antes
		delete[] m_array;
	}

	void setValor(int indice, int valor) { m_array[indice] = valor; }
	int getValor(int indice) { return m_array[indice]; }
	int getTamanho() { return m_tamanho; }
};

int main()
{
	IntArray ar (10); // asigna 10 integers
	for (int contador{ 0 }; contador < ar.getTamanho(); ++contador)
		ar.setValor(contador, contador + 1);

	std::cout << "El valor del elemento 3 es: " << ar.getValor(3) << '\n';

	return 0;
} // ar se destruye aquí, así que la función destructor ~IntArray() es llamada aquí







