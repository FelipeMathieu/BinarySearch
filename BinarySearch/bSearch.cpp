#include "bSearch.h"

void bSearch::bSearch_Tree(Node *t, int e)
{
	//clock_t i = NULL, j = NULL, w = NULL;
	//float y;
	bool aux = false;

	while (t != NULL)
	{
		//i += clock();
		if (e == t->element)
		{
			aux = true;
			//j += clock();
			break;
		}
		else if (e < t->element)
		{
			t = t->left;
		}
		else if(e > t->element)
		{
			t = t->right;
		}
		//j += clock();
	}

	/*w = j - i;
	y = ((float)w )/ CLOCKS_PER_SEC;*/

	if(aux)
	{
		cout << "Elemento " << e << " pertence a arvore!" << endl;
	}
	else
	{
		cout << "Elemento " << e << " nao pertence a arvore!" << endl;
	}
}

void bSearch::bSearch_vector(vector<int> *v, int e, int size)
{
	int meio, primeiro, ultimo;

	ultimo = size;
	meio = size / 2;
	primeiro = 0;

	while (primeiro <= ultimo)
	{
		if (v->at(meio) < e)
		{
			primeiro = meio + 1;
		}
		else if (v->at(meio) == e)
		{
			cout << "Elemento " << e << " existe no vetor!" << endl;
			break;
		}
		else
		{
			ultimo = meio - 1;
		}

		meio = (primeiro + ultimo) / 2;
	}

	if (primeiro > ultimo)
	{
		cout << "Elemento " << e << " nao existe no vetor!" << endl;
	}
}