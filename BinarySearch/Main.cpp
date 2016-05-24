#include "bSearch.h"
#include "Tree.h"
#include <Windows.h>
#include <vector>
#include <stdlib.h>

void quickSort(vector<long int> *v, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = v->at((left + right) / 2);

	/* partition */
	while (i <= j) {
		while (v->at(i) < pivot)
			i++;
		while (v->at(j) > pivot)
			j--;
		if (i <= j) {
			tmp = v->at(i);
			v->at(i) = v->at(j);
			v->at(j) = tmp;
			i++;
			j--;
		}
	};

	/* recursion */
	if (left < j)
		quickSort(v, left, j);
	if (i < right)
		quickSort(v, i, right);
}

void main()
{
	int size, aux;
	int element;
	clock_t k = NULL, m = NULL, result = NULL;
	clock_t k1 = NULL, m1 = NULL, result1 = NULL;
	float r, r1;
	Tree *A = new Tree();
	Node *auxTree = new Node();
	bSearch b;
	vector<long int> v, v2;

	cout << "Informe o numero de elementos: ";
	cin >> size;

	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		//cout << element << " ";
		element = (rand()*rand());

		k += clock();
		A->insert(element);
		m += clock();

		k1 += clock();
		v.push_back(element);
		m1 += clock();
	}

	element = 0;

	for (int i = 0; i < size; i++)
	{
		element = (rand()*rand());

		v2.push_back(element);
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

	auxTree = A->balance(A->Root());

	m = clock();

	result = m - k;
	r = ((float)result) / CLOCKS_PER_SEC;

	Sleep(0.100);

	cout << "Tempo de balanceamento da arvore: " << r << endl << endl;

	cout << "Ordenando vetor..." << endl;

	k1 = clock();

	quickSort(&v, 0, size - 1);

	m1 = clock();

	result1 = m1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;

	cout << "Tempo de ordenacao do vetor: " << r1 << endl << endl;

	Sleep(0.100);

	cout << "A partir das chaves, do vetor2 aleatorio:" << endl;
	cout << "Procurando chaves na arvore e no vetor1..." << endl << endl;

	k = NULL;
	m = NULL;
	result = NULL;

	k1 = NULL;
	m1 = NULL;
	result1 = NULL;

	k = clock();

	b.bSearch_Tree(auxTree, size, v2);

	m = clock();
	result = m - k;
	r = ((float)result) / CLOCKS_PER_SEC;

	cout << "Tempo de execucao da busca na arvore: " << r << endl << endl;

	k1 = clock();

	b.bSearch_vector(v, size, v2);

	m1 = clock();

	result1 = m1 - k1;
	r1 = ((float)result1) / CLOCKS_PER_SEC;

	cout << "Tempo de execucao da busca no vetor: " << r1 << endl << endl;

	free(A);
}