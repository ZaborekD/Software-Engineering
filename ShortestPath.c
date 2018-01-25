#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6


int smallestDistance(int dist[], bool shortestPoints[]);
void algorithm(int graph[V][V], int);


//shortest path using single point
//Dijkstra

int main(){


	int graph[V][V];
	int n;
	FILE *Ptr;


	Ptr = fopen("input.dat","r");

	for(int x=0;x<V;x++){

		for(int y=0;y<V;y++){

	
			fscanf(Ptr,"%d ",&n);

			graph[x][y] = n;
		}
	

	}




	algorithm(graph,0);

	fclose(Ptr);


	return 0;
}

int smallestDistance(int distance[], bool shortestPoints[])
{
   
   	int min = INT_MAX, min_index;
  
  	 for (int v = 0; v < V; v++)
    		 if (shortestPoints[v] == false && distance[v] <= min)
        		 min = distance[v], min_index = v;
  
   	return min_index;
}



void algorithm(int graph[V][V], int start)
{
	int distance[V]; //final solution
	bool shortestPoints[V]; //shortest points selected yet?

	for (int i = 0; i < V; i++)//setting everything to brand new
        	distance[i] = INT_MAX, shortestPoints[i] = false;

	distance[start] = 0;//setting starting node distance to 0

	for (int count = 0; count < V-1; count++)
     	{
       
       		int u = smallestDistance(distance, shortestPoints);
  
      
       		shortestPoints[u] = true;
  
     
       		for (int t = 0; t < V; t++)
         			if (!shortestPoints[t] && graph[u][t] && distance[u] != INT_MAX && distance[u]+graph[u][t] < distance[t])
            				distance[t] = distance[u] + graph[u][t];
     	}
  
	printf("Shortest Path\n");
      	printf("Node  Distance\n");
   	for (int i = 0; i < V; i++)
      		printf("%d \t %d\n", i, distance[i]);

}
