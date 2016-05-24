#include "bSearch.h"
#include "Tree.h"
#include <cstdlib>
#include <Windows.h>
#include <vector>

void main()
{
	int size, aux;
	int element;
	clock_t k = NULL, m = NULL, result = NULL;
	clock_t k1 = NULL, m1 = NULL, result1 = NULL;
	float r, r1;
	Tree *A = new Tree();
	bSearch b;
	vector<int> *v = new vector<int>;

	cout << "Informe o numero de elementos: ";
	cin >> size;

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		element = rand() % RAND_MAX;

		k += clock();
		A->insert(element);
		m += clock();

		k1 += clock();
		v->push_back(element);
		m1 += clock();
	}

	result = m - k;
	r = ((float)result)/CLOCKS_PER_SEC;

	element = 0;

	Sleep(0.1000);
	cout << endl;
	cout << "Tempo de insercao na arvore: " << r << endl;

	result1 = m1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;

	element = 0;

	Sleep(0.1000);
	cout << endl;
	cout << "Tempo de insercao no vetor: " << r1 << endl << endl;

	k1 = NULL;
	m1 = NULL;
	result1 = NULL;

	cout << "Balanceando Arvore..." << endl;
	
	k = clock();

	A->balance(A->Root());

	m = clock();

	result = m - k;
	r = ((float)result) / CLOCKS_PER_SEC;

	Sleep(0.100);

	cout << "Tempo de balanceamento da arvore: " << r << endl << endl;

	cout << "Ordenando vetor..." << endl;

	k1 = clock();

	for (int i = 0; i < size; i++) 
	{
		for (int j = size - 1; j > i; j--) 
		{
			if (v->at(j) < v->at(j - 1))
			{
				aux = v->at(j);
				v->at(j) = v->at(j - 1);
				v->at(j - 1) = aux;
			}	
		}
	}

	m1 = clock();

	result1 = m1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;

	cout << "Tempo de ordenacao do vetor: " << r1 << endl << endl;

	cout << endl;

	Sleep(0.100);

	cout << "Qual elemento deseja procurar: ";
	cin >> element;
	cout << endl;

	k = NULL;
	m = NULL;
	result = NULL;

	k1 = NULL;
	m1 = NULL;
	result1 = NULL;

	k = clock();

	b.bSearch_Tree(A->Root(), element);

	m = clock();
	result = m - k;
	r = ((float)result) / CLOCKS_PER_SEC;

	cout << "Tempo de execucao da busca na arvore: " << r << endl << endl;

	k1 = clock();

	b.bSearch_vector(v, element, size);

	m1 = clock();

	result1 = m1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;

	cout << "Tempo de execucao da busca no vetor: " << r1 << endl << endl;
}