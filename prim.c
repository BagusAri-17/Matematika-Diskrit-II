#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int vertex, min, a, b;
    int temp = 0, counter = 1, minbobot = 0;
    system("cls");
    printf("================================\n");
    printf("Program Sederhana Algoritma Prim\n");
    printf("================================\n\n");
    // Menentukan Jumlah Simpul (Vertex)
    printf("Masukkan Jumlah Objek Wisata : ");
    scanf("%d", &vertex);
    int jarak[vertex][vertex], ae[vertex][vertex], vt[vertex];
    // ae = Active Edge, vt = vertex terkunjungi

    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            ae[i][j] = 999;
            vt[i] = 0;
        }
    }

    // Menentukan Nilai Bobot Pada Sisi (Edge)
    printf("Masukan Jarak Setiap Objek Wisata : \n");
    for(int i = 0; i < vertex; i++){
        for(int j = 0; j < vertex; j++){
            if(i == j){
                jarak[i][j] = 999;
            } else if(j > i){
                printf("Edge [%d][%d] = ", i+1, j+1);
                scanf("%d", &jarak[i][j]);
                if(jarak[i][j] == 0){
                    jarak[i][j] = 999;
                }
                jarak[j][i] = jarak[i][j];
            } else continue;
        }
    }
    
    // Sisi Yang Terpilih Untuk Dijadikan MST
    printf("\nJalur yang terpilih :\n");
    while (counter < vertex)
    {
        min = 999;

        for(int i = 0; i < vertex; i++){
            if(ae[temp][i] < 1000){
                ae[temp][i] = jarak[temp][i];
            }
        }

        
        for(int i = 0; i < vertex; i++){
            for(int j = 0; j < vertex; j++){
                if(ae[i][j] < min){
                    min = ae[i][j];
                    a = i;
                    b = j;
                }
            }
        }


        if(vt[a] == 0 || vt[b] == 0){
            printf("%d. edge[%d][%d] = %d\n", counter++, a+1, b+1, min);
            minbobot += min;
            temp = b;
        }

        vt[a] = vt[b] = 1;
        ae[a][b] = ae[b][a] = 1000;
    }
    // Bobot Minimum
    printf("\nJarak Minimum = %d Km\n", minbobot);
    
}