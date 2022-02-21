#include<iostream>
using namespace std;

#define MAX 50

typedef struct edge
{
   int u, v , w;
}edge;
 
int main()
{
   int adj[MAX][MAX], n, f, l;
   edge MST[MAX];
   int create_matrix(int [MAX][MAX], int *);
   void display_adjacency(int adj[MAX][MAX], int n);
   //int kruskal(int adj[MAX][MAX], int n, edge MST[MAX], int (*l));
   //void display(edge MST[MAX], int l);
   
   adj[MAX][MAX] = {0};
   cout << "Enter the no of rows and columns : ";
   cin >> n;
   cout << endl;
   create_matrix(adj, &n);

   display_adjacency(adj, n);
   //kruskal(adj, n, MST, &l);
   //display(MST, l);
   return 0; 
}
 
int create_matrix(int adj[MAX][MAX], int *n) 
{
  int i, j, origin, destin, weight;
  i = 0;
  while(i < (*n))
  { 
    j = 0;
    while(j < (*n))
    {
      origin = i+1;
      destin = j+1;
      cout << "Enter weight for " << origin << " and " << destin << " : ";
      cin >> weight;
      cout << endl; 
      adj[origin-1][destin-1] = weight;
      j = (j + 1); 
    }
    i = (i + 1);
  }
  return 0; 
}

void display_adjacency(int adj[MAX][MAX], int n)
{
   int i, j;
   printf( "\n\nThe Adjacency Matrix is :- \n" );
   i = 0;
   while(i < n)
   {
      j = 0;
      while(j < n)
      {
         printf(" %d\t", adj[i][j]);
         j = (j + 1);
      }
      printf("\n\n");
      i = (i +1);
   }
   return ;
}

/*int kruskal(int adj[MAX][MAX], int n, edge MST[MAX], int (*l))
{
   edge elist[MAX];
   int i, j, belongs[MAX], u1, u2, V, k;
   int Sort(edge elist[MAX], int k);
   int find(int belongs[MAX], int V);
   int union1(int belongs[MAX], int u1, int u2, int n);
   k = 0;
   i = 1;
   while(i < n)
   {
      j = 0;
      while(j < i)
      {
         if(adj[i][j] != 0)
         {
            elist[k].u = i;
            elist[k].v = j;
            elist[k].w = adj[i][j];
            k = (k + 1);
         }
         j = (j + 1);
      }
      i = (i + 1);
   }
   Sort(elist, k);
   i = 0;
   while(i < n)
   {
      belongs[i] = i;
      i = (i + 1);
   }
   (*l) = 0;
   i = 0;
   while(i < k)
   {
      u1 = find(belongs, elist[i].u);
      u2 = find(belongs, elist[i].v);
      if(u1 != u2)
      {
         MST[(*l)] = elist[i];
         (*l) = ((*l) + 1);
         union1(belongs, u1, u2, n);
      }
      i = (i + 1);
   }
   return 0;
}

int Sort(edge elist[MAX], int k)
{
   int i, j;
   edge t;
   i = 1;
   while(i < k)
   {
     j = 0;
     while(j < (k-1))
     {
       if((elist[j].w) > (elist[j+1].w))
       {
          t = elist[j];
          elist[j] = elist[j+1];
          elist[j+1] = t;
       }
       j = (j + 1);
    }
    i = (i + 1);
  }
  return 0;
}

int find(int belongs[MAX], int V) 
{
   return(belongs[V]);
}

int union1(int belongs[MAX], int u1, int u2, int n)
{
  int i;
  i = 0;
  while(i < n)
  {
     if(belongs[i] == u2)
     {
        belongs[i] = u1;
     }
     i = (i + 1);
  }
  return 0;
}

void display(edge MST[MAX], int l)
{
   int i, cost=0;
   i = 0;
   while(i < l)
   {
     printf("\n%d\t%d\t%d", (MST[i].u), (MST[i].v), (MST[i].w));
     cost = (cost + (MST[i].w)); 
     i = i+1;
   }
   printf("\n\nCost of the spanning tree = %d", cost);
   return ;
}*/







