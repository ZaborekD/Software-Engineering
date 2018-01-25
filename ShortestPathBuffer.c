#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdafx.h>

#define V 6


int smallestDistance(int dist[], bool shortestPoints[]);
void algorithm( int);
void moveLineIntoMemory(int *buffer,int);

//shortest path using single point using restricted memory
//Dijkstra

int main(){
	
	

	algorithm(0);

	

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



void algorithm( int start)
{
	int distance[V]; //final solution
	bool shortestPoints[V]; //shortest points selected yet?

	int buffer[V];
	

	for (int i = 0; i < V; i++)//setting everything to brand new
        	distance[i] = INT_MAX, shortestPoints[i] = false;

	distance[start] = 0;//setting starting node distance to 0

	for (int count = 0; count < V-1; count++)
     	{
       
       		int u = smallestDistance(distance, shortestPoints);
  		moveLineIntoMemory(buffer,u);

      
       		shortestPoints[u] = true;
  
     
       		for (int t = 0; t < V; t++)
         			if (!shortestPoints[t] && buffer[t] && distance[u] != INT_MAX && distance[u]+buffer[t] < distance[t])
            				distance[t] = distance[u] + buffer[t];
     	}
  
	printf("Shortest Path\n");
      	printf("Node  Distance\n");
   	for (int i = 0; i < V; i++)
      		printf("%d \t %d\n", i, distance[i]);

}


void moveLineIntoMemory(int *buffer,int u){
	FILE *Ptr;
	Ptr = fopen("input.dat","r");
int n;
	for(int x=0;x<=u;x++){

		for(int y=0;y<V;y++){

	
			fscanf(Ptr,"%d ",&n);
			if(x<=u)
			buffer[y] = n;
		}
	

}

fclose(Ptr);
return ;
}


