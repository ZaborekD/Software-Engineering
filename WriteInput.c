#include <stdio.h>

int main(){

int nodes = 6,x,y;
int tt;
int n;

/*
int graph[9][9] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
*/


int graph[6][6] ={{0,1,3,1000,1000,3},{1,0,5,1,1000,1000},{3,5,0,1000,1,1000},{1000,1,1000,0,4,1000},{1000,1000,1,4,0,5},{3,1000,1000,1000,5,0}};


FILE *Ptr;

Ptr = fopen("input.dat","w+");
//fwrite(&nodes,sizeof(int),1,Ptr);
for(x=0;x<nodes;x++){

for(y=0;y<nodes;y++){

	n = graph[x][y];
		//fwrite(&n,sizeof(int),1,Ptr);
	fprintf(Ptr,"%d ",n);

	}
fprintf(Ptr,"\n ",n);

}

//fread(&tt,sizeof(int),1,Ptr);

//fscanf(Ptr,"%d",&tt);
//rintf("%d",tt);

//printf("%c",c);


fclose(Ptr);
}
