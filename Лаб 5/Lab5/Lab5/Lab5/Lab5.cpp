#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "BFS.h"
#include "DFS.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int m[7][7]  ={  
		          {0, 1, 1, 1, 0, 0, 0},
			      {0, 0, 0, 0, 0, 0, 0},
				  {0, 0, 0, 1, 0, 1, 0},
				  {0, 0, 0, 0, 0, 0, 0},
				  {0, 1, 0, 1, 0, 0, 0},
		          {0, 0, 0, 1, 0, 0, 1},
				  {0, 0, 0, 0, 1, 0, 0},
	               };
 setlocale(LC_ALL, "rus");
 graph::AMatrix g1(7,(int*) m);
 std::cout<<std::endl;
 std::cout<<std::endl<< "-- матрица смежности "<< std::endl;
 for (int i = 0; i < g1.nV; i++)
   {
     std::cout<<std::endl;
	for (int j = 0; j < g1.nV; j++)
		std::cout<< g1.get(i,j) << " ";     
   };
 std::cout<<std::endl;
 
 graph::AList g2(g1);
 std::cout<<std::endl;
 std::cout<<std::endl<< "-- списки смежных вершин "<< std::endl;
 for (int i = 0; i < g1.nV; i++)
   {
	std::cout<<std::endl<< i << ": ";
	for (int j = 0; j < g2.size(i); j++)
		std::cout<<g2.get(i,j)<< " ";
   }
 std::cout<<std::endl;


 cout << endl << "-- поиск в ширину " << endl;
 cout << endl << "0 1 2 3 5 6 4 " << endl;

 cout << endl << "-- поиск в глубину " << endl;
 cout << endl << " 0 2 5 6 4 1 3" << endl;

 cout << endl << "Топологическая сортировка " << endl;
 cout << endl << " 0 2 5 6 4 1 3" << endl;

 BFS b1(g2,0);
 std::cout<<std::endl;
 std::cout<<std::endl<< "-- поиск в ширину "<< std::endl;
 int k1;
 while ((k1 = b1.get())!= BFS::NIL)
	 std::cout<< k1 << " ";
 std::cout<<std::endl;

 DFS b2(g2);
 std::cout<<std::endl;
 std::cout<<std::endl<< "-- поиск в глубину "<< std::endl;
 for (int i = 0; i < g2.nV; i++) 
	 std::cout<< b2.get(i) << " ";
 std::cout<<std::endl;

 std::cout << std::endl << "Топологическая сортировка" << std::endl;
	for (std::vector <int>::iterator i (b2.topological_sort.begin ()); i != b2.topological_sort.end (); ++i)
		std::cout << *i << ' ';
	std::cout << std::endl; 
 

 system("pause");
 return 0;
}



