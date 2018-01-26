#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define V 8

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d tt %d\n", i, dist[i]);
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int src, int partition)
{
  
      int buffer[V/partition][V];     //initializing buffer and other numbers
      int currPartition = -1, partitionNumber = 0;
      
      
     int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
     
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized

     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V-1; count++)
     {

       int u = minDistance(dist, sptSet);


       //which file to grab
       partitionNumber = (int)floor(u/(V/partition));
       
       //if partition needed has not been loaded, load it
       if(partitionNumber != currPartition){
            readFile(partition,partitionNumber, buffer);
            currPartition = partitionNumber;
       }
       
       // Mark the picked vertex as processed
       sptSet[u] = true;


       for (int v = 0; v < V; v++)

       //getting placement in buffer
       int U = 0
       if(u!= 0) U = u % partition;
       
         if (!sptSet[v] && buffer[U][v] && dist[u] != INT_MAX
                                       && dist[u]+buffer[U][v] < dist[v])
            dist[v] = dist[u] + buffer[U][v];
     }

     printSolution(dist, V);
}

  void readFile(int partition, int partitionNumber, int *buffer){

    std::string data;

//reading from file into data
   std::ifstream binFile(partitionNumber + ".dat", std::ios::in | std::ios::binary);
   if(binFile.is_open())
   {
      size_t len = 0;
      binFile.read((char*)&len, sizeof(len));
      data.resize(len);
      binFile.read((char*)&data[0], len);
   }
   
   
   //putting data into buffer & convert to int
   for(int y = 0;y<(V/partition);y++){
   
   for(int x = 0; x<V;x++){
     
     //must get each binary chunk from char array
     //?====================================================================?
     string temp =  
       
       buffer[y][x] = std::stoi(temp,nullptr,2);
       
     }
     
   }


  }


int main(int argc, char *argv[]){
	int S = stoi(argv[1]);
	int partition = atoi(argv[2]);

	ifstream inputFile;

	inputFile.open("C:\\Users\\Me\\Desktop\\Software Engineering\\input.txt");

	if(!inputFile) cout << "error" << endl;

	int graph[V][V] = { INT_MAX };

	int source, destination, weight;
	while(inputFile >> source >> destination >> weight){
		cout << source << " " << destination << " " << weight << endl;
		graph[source][destination] = weight;
	}

	int col_written = 0;
	for(int i = 0; i < partition; i++){
		ofstream file;
		file.open(to_string(i) + ".dat", ofstream::binary);

		if(file.is_open()){

      for(int j = col_written; j < V / partition; j++, col_written++){

        for(int k = 0; k < V; k++){

          string towrite = to_string(graph[j][k]);
          size_t len = towrite.size();
          file.write((char*)&len, sizeof(len));
          file.write((char*)&towrite[0], len);

        }

      }

      col_written ++;
      file.close();

		}


	}
    dijkstra(0, partition);

    return 0;
}
