#include <iostream>
#include <fstream>
#include <algorithm>
#include "timer.h"

using namespace std;

const int NUM=2000000;//Max 1000000, 10000 without shuffling
ofstream outfile;
int height;

typedef struct EmployeeInfo {
	int salary;
	int age;
	int emplNumber;
	int sin;
}EmployeeInfo;

typedef struct treeNode
{
	EmployeeInfo empl;
	int depth;
	struct treeNode *left;
	struct treeNode *right;

}treeNode;

treeNode* FindMin(treeNode *node)
{
	if (node == NULL)
	{
		/* There is no element in the tree */
		return NULL;
	}
	if (node->left) /* Go to the left sub tree to find the min element */
		return FindMin(node->left);
	else
		return node;
}
treeNode* FindMax(treeNode *node)
{
	if (node == NULL)
	{
		/* There is no element in the tree */
		return NULL;
	}
	if (node->right) /* Go to the right sub tree to find the max element */
		return FindMax(node->right);
	else
		return node;
}

treeNode * Insert(treeNode *node, EmployeeInfo empl, int depth)
{
	if (node == NULL)
	{
		treeNode *temp;
		temp = (treeNode *)malloc(sizeof(treeNode));
		temp->empl.salary = empl.salary;
		temp->empl.age = empl.age;
		temp->empl.emplNumber = empl.emplNumber;
		temp->empl.sin = empl.sin;
		temp->depth = depth;
		temp->left = temp->right = NULL;
		if (depth > height) height = depth;
		return temp;
	}

	if (empl.sin > (node->empl.sin))
	{
		node->right = Insert(node->right, empl, ++depth);
	}
	else if (empl.sin < (node->empl.sin))
	{
		node->left = Insert(node->left, empl, ++depth);
	}
	/* Else there is nothing to do as the employee information is already in the tree. */
	return node;

}

treeNode * Find(treeNode *node, int sin)
{
	if (node == NULL)
	{
		/* Element is not found */
		return NULL;
	}
	if (sin > node->empl.sin)
	{
		/* Search in the right sub tree. */
		return Find(node->right, sin);
	}
	else if (sin < node->empl.sin)
	{
		/* Search in the left sub tree. */
		return Find(node->left, sin);
	}
	else
	{
		/* Element Found */
		return node;
	}
}

void PrintInorder(treeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	PrintInorder(node->left);
//	cout << " depth:" << node->depth << " sin:" << node->empl.sin << " employee number:" << node->empl.emplNumber << " salary:" << node->empl.salary << " age:" << node->empl.age << endl;
	outfile << " depth:" << node->depth << " sin:" << node->empl.sin << " employee number:" << node->empl.emplNumber << " salary:" << node->empl.salary << " age:" << node->empl.age << endl;
	PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
	if (node == NULL)
	{
		return;
	}
//	cout << " depth:" << node->depth << " sin:" << node->empl.sin << " employee number:" << node->empl.emplNumber << " salary:" << node->empl.salary << " age:" << node->empl.age << endl;
	outfile << " depth:" << node->depth << " sin:" << node->empl.sin << " employee number:" << node->empl.emplNumber << " salary:" << node->empl.salary << " age:" << node->empl.age << endl;
	PrintPreorder(node->left);
	PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
	if (node == NULL)
	{
		return;
	}
	PrintPostorder(node->left);
	PrintPostorder(node->right);
//	cout << " depth:" << node->depth << " sin:" << node->empl.sin << " employee number:" << node->empl.emplNumber << " salary:" << node->empl.salary << " age:" << node->empl.age << endl;
	outfile << " depth:" << node->depth << " sin:" << node->empl.sin << " employee number:" << node->empl.emplNumber << " salary:" << node->empl.salary << " age:" << node->empl.age << endl;
}

int main()
{
	treeNode *root = NULL;
	int sinArray[NUM];
	for (int i = 0; i < NUM; ++i) sinArray[i] = 100000000 + i;
	random_shuffle(&sinArray[0], &sinArray[NUM]);
//	random_shuffle(begin(sinArray), end(sinArray));
//	for (int i = 0; i < NUM; ++i) cout << "i:" << i << " sin:" << sinArray[i] << endl;
	for (int i = 0; i < NUM; ++i) {
		EmployeeInfo empl;
		empl.age = 25 + (i * 2) % 45;
		empl.salary = 50000 + (i * 10) % 100000;
		empl.emplNumber = i;
		empl.sin = sinArray[i];
		root = Insert(root, empl, 0);
	}
	outfile.open("inorder.txt");
	cout << "INORDER (NUM=" << NUM << ", height=" << height << "): root node has sin:" << root->empl.sin << endl << endl;
	outfile << "INORDER (NUM=" << NUM << ", height=" << height << "): root node has sin:" << root->empl.sin << endl << endl;
	PrintInorder(root);
	outfile.close();
	treeNode * temp;
	temp = FindMin(root);
	cout << "Minimum element is " << temp->empl.sin << endl;
	temp = FindMax(root);
	cout << "Maximum element is " <<  temp->empl.sin << endl;
	int sin;
	Timer stopwatch;
	do {
		cout << "Enter a SIN to search (-1 to quit):";
		cin >> sin;
		stopwatch.start();
		temp = Find(root, sin);
		stopwatch.stop();
		if (temp == NULL) {
			cout << "SIN " << sin << " not found" << endl;
		}
		else {
			cout << "time:" << stopwatch.currtime() << " depth:" << temp->depth << " sin:" << temp->empl.sin << " employee number:" << temp->empl.emplNumber << " salary:" << temp->empl.salary << " age:" << temp->empl.age << endl;
			outfile << "time:" << stopwatch.currtime() << " depth:" << temp->depth << " sin:" << temp->empl.sin << " employee number:" << temp->empl.emplNumber << " salary:" << temp->empl.salary << " age:" << temp->empl.age << endl;
		}
	} while (sin > 0);
	cout << endl << "DONE" << endl << endl;
}
