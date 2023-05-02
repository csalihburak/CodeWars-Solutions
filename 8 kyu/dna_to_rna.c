/*Deoxyribonucleic acid, DNA is the primary information storage molecule in biological systems. It is composed of four nucleic acid bases Guanine ('G'), Cytosine ('C'), Adenine ('A'), and Thymine ('T').

Ribonucleic acid, RNA, is the primary messenger molecule in cells. RNA differs slightly from DNA its chemical structure and contains no Thymine. In RNA Thymine is replaced by another nucleic acid Uracil ('U').

Create a function which translates a given DNA string into RNA.*/

#include <stdlib.h>
#include <string.h>

char *dna_to_rna(const char *dna)
{
    int i = 0;
    int j = 0;
    char *rna = malloc(sizeof(char) * (strlen(dna) + 1));
    while (dna[i])
    {
        if (dna[i] == 'A')
            rna[j] = 'A';
        else if (dna[i] == 'G')
            rna[j] = 'G';
        else if (dna[i] == 'C')
            rna[j] = 'C';
        else if (dna[i] == 'T')
            rna[j] = 'U';
        else if (dna[i] == 'U')
            rna[j] = 'T';
        i++;
        j++;
    }
    rna[j] = '\0';
    return rna;
}