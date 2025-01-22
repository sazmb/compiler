#include <stdio.h>
#include "header_files/def.h"
#include "header_files/symbolTable.h"
#include "header_files/genCode.h"
#include "header_files/parser.h"
#include <stdlib.h>
#include <string.h>

void print_usage(const char *program_name) {
    printf("Usage: %s [options] <input_file>\n", program_name);
    printf("Options:\n");
    printf("  -verbose        Enable verbose mode\n");
    printf("  -o <file>       Specify output file\n");
    exit(EXIT_FAILURE);
}


char* estrai_sottostringa(const char* stringa, int inizio, int lunghezza) {
    int lunghezza_stringa = strlen(stringa);

    // Verifica che l'indice e la lunghezza siano validi
    if (inizio < 0 || inizio >= lunghezza_stringa || lunghezza < 0 || inizio + lunghezza > lunghezza_stringa) {
        printf("Errore: indice o lunghezza non validi.\n");
        return NULL;
    }

    // Alloca spazio per la sottostringa (+1 per il terminatore)
    char* sottostringa = malloc((lunghezza + 1) * sizeof(char));
    if (sottostringa == NULL) {
        perror("Errore nell'allocazione della memoria");
        return NULL;
    }

    // Copia i caratteri dalla stringa originale alla sottostringa
    strncpy(sottostringa, stringa + inizio, lunghezza);

    // Aggiunge il terminatore alla fine della sottostringa
    sottostringa[lunghezza] = '\0';

    return sottostringa;
}




int main(int argc, char *argv[]) {
    int verbose = 0; // Flag per modalità dettagliata
    char *input_file = NULL;
    char *output_file = NULL;
    FILE *infile = NULL;
    FILE *outfile = NULL;
    FILE *outfile2 = NULL;
    Pnode tree;

    // Parsing delle opzioni
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-verbose") == 0) {
            verbose = 1; // Abilita modalità dettagliata
        }
        else if (strcmp(argv[i], "-o") == 0) {
            if (i + 1 < argc) {
                output_file = argv[++i]; // Specifica il file di output
            } else {
                fprintf(stderr, "Error: Missing output file after -o option.\n");
                print_usage(argv[0]);
            }
        } else if (argv[i][0] == '-') {
            if (strcmp(argv[i], "-") == 0) {
                input_file = "-"; // Indica che si deve leggere da stdin
            } else {
                fprintf(stderr, "Unknown option: %s\n", argv[i]);
                print_usage(argv[0]);
            }
        } else {
            input_file = argv[i]; // File di input
        }
    }

    // Se non è stato specificato un file di input, leggi da stdin
    if (input_file == NULL) {
        fprintf(stderr, "Error: No input file specified.\n");
        print_usage(argv[0]);
    }

    // Apertura del file di input
    if (strcmp(input_file, "-") == 0) {
        infile = stdin; // Leggi da stdin se l'input è "-"

    }
    else
        {
         infile = fopen(input_file, "r");
        if (infile == NULL) {
            perror("Error opening input file");
            exit(EXIT_FAILURE);
        }

    }

    // Apertura del file di output (se specificato) o utilizzo di stdout
    outfile = output_file ? fopen(output_file, "w") : stdout;
    if (output_file && outfile == NULL) {
        perror("Error opening output file");
        if (infile != stdin) fclose(infile);
        exit(EXIT_FAILURE);
    }
    //creazione del file verbose output 2
    if (verbose && output_file!=NULL) {
        char* output_file2 =string_concat(estrai_sottostringa(output_file,0,strlen(output_file)-4), "_ver.txt");
        outfile2=fopen(output_file2, "w");
        if (output_file2 && outfile2 == NULL) {
            perror("Error opening output file");
            if (infile != stdin) fclose(infile);
            exit(EXIT_FAILURE);
        }
    }
    tree= generate_abstree(infile);
    if (verbose) treeprint(tree, 0);
    Ptable table=generate_symboltable(tree);
    if (verbose) printTable(table);
    Code code=startGenCode(tree);
    if(verbose && output_file)
        printCode_v(&code, outfile,outfile2) ;
    else if (verbose)
        printCode_v(&code, outfile,outfile) ;
    else
        printCode(&code, outfile);


    // Chiudi i file se non sono stdin o stdout
    if (infile != stdin) {
        fclose(infile);
    }
    if (output_file) {
        fclose(outfile);
    }

    // Messaggio di fine se verbose è abilitato
    if (verbose) {
        printf("Processing completed.\n");
    }

    return 0;
}


