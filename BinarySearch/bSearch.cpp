#include "bSearch.h"

void bSearch::bSearch_Tree(Node *t, int size, vector<long int> v1)
{
	int count = 0;
	Node *t1 = t;

	for (int i = 0; i < size; i++)
	{
		while (t != NULL)
		{
			if (v1.at(i) == t->element)
			{
				count += 1;
				break;
			}
			else if (v1.at(i) < t->element)
			{
				t = t->left;
			}
			else if (v1.at(i) > t->element)
			{
				t = t->right;
			}
		}
		t = t1;
	}

	free(t1);

	cout << "Existem " << count << " chaves do vetor1 na arvore." << endl;
}

void bSearch::bSearch_vector(vector<long int> v, int size, vector<long int> v1)
{
	int meio, primeiro, ultimo, count = 0;

	ultimo = size-1;
	meio = size / 2;
	primeiro = 0;

	for (int i = 0; i < size; i++)
	{
		while (primeiro <= ultimo)
		{
			if (v.at(meio) < v1.at(i))
			{
				primeiro = meio + 1;
			}
			else if (v.at(meio) == v1.at(i))
			{
				count += 1;
				break;
			}
			else
			{
				ultimo = meio - 1;
			}

			meio = (primeiro + ultimo) / 2;
		}

		ultimo = size-1;
		meio = size / 2;
		primeiro = 0;
	}

	cout << "Existem " << count << " chaves do vetor2 no vetor1." << endl;
}