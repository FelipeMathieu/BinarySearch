#include "bSearch.h"

void bSearch::bSearch_Tree(Node *t, int e)
{
	int count = 0;
	Node *t1 = t;

	for (int i = 0; i <= e; i++)
	{
		while (t != NULL)
		{
			if (i == t->element)
			{
				count += 1;
				break;
			}
			else if (i < t->element)
			{
				t = t->left;
			}
			else if (i > t->element)
			{
				t = t->right;
			}
		}
		t = t1;
	}

	cout << "De 0 ate " << e << " procurados na arvore. " << count << " elementos pertencem a arvore." << endl;
}

void bSearch::bSearch_vector(vector<int> *v, int e, int size)
{
	int meio, primeiro, ultimo, count = 0;

	ultimo = size;
	meio = size / 2;
	primeiro = 0;

	for (int i = 0; i <= e; i++)
	{
		while (primeiro <= ultimo)
		{
			if (v->at(meio) < i)
			{
				primeiro = meio + 1;
			}
			else if (v->at(meio) == i)
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

		ultimo = size;
		meio = size / 2;
		primeiro = 0;
	}

	cout << "De 0 ate " << e << " procurados no vetor. " << count << " elementos pertencem ao vetor." << endl;
}