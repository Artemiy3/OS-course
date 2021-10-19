#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int clock = 0; // last clock
    int current_clock; // clock of the current reference
    int page_id; // id of referenced page
    int hits = 0; // count of hits happened
    int misses = 0; // count of misses happened
    int virtual_memory[n][2]; // table of n rows with id of each page and its counter of references
    for(int i = 0; i < n; i++){ // initially all ids are -1 and counters are 0
        virtual_memory[i][0] = -1;
        virtual_memory[i][1] = 0;
    }
    int r_bits[n];
    for(int i = 0; i < n; i++){
        r_bits[i] = 0;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &current_clock, &page_id);
        if(current_clock > clock){ // if clock has been changed, then we should update counters in virtual memory using R bits
            clock = current_clock;
            for(int j = 0; j < n; j++){
                virtual_memory[j][1] = (virtual_memory[j][1] >> 1) | (r_bits[j] << 7);
                r_bits[j] = 0;
            }
        }
        bool hit = 0;
        for(int j = 0; j < n; j++){ // trying to find id in virtual memory
            if(virtual_memory[j][0] == page_id){
                r_bits[j] = 1;
                hit = 1; // if found, then hit happened
                break;
            }
        }
        if(hit){
            hits++;
            printf("1\n");
        }else{ // if hit didn't happen, the it's miss
            misses++;
            printf("0\n");
            int min_counter = 256;
            int id_of_min;
            int index_of_min;
            for(int j = 0; j < n; j++){ // finding the page with the oldest reference or the empty row
                if(virtual_memory[j][1] < min_counter){
                    min_counter = virtual_memory[j][1];
                    id_of_min = virtual_memory[j][0];
                    index_of_min = j;
                }else if(virtual_memory[j][1] == min_counter && virtual_memory[j][0] < id_of_min){
                    id_of_min = virtual_memory[j][0];
                    index_of_min = j;
                }
            }
            virtual_memory[index_of_min][0] = page_id;
            virtual_memory[index_of_min][1] = 0;
            r_bits[index_of_min] = 1;
        }
    }
    double ratio = (double) hits / (double) misses;
    printf("%f", ratio);
    return 0;
}
