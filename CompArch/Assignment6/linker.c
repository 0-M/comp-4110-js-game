#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nament {
    char name[26];
    int addr;
    struct nament *next;
} SYMTABENTRY;

void add_symbol(char * symbol, int line_number);
void print_first_pass(FILE*);
void generate_code();
void append_table();
int get_sym_val(char*);

SYMTABENTRY *symtab = NULL;

/* FILE p1 will be used to open each obj file : open, use it, close it
   FILE p2 will be used to temporarily aggregate obj files */
FILE *p1, *p2;
char cstr_12[13];

int main(int argc, char ** argv) {
    int i, start, pc_offset = 0, pc = 0;
    int object_file = 0, dump_tab = 0; // Flags for the -o -s flags
    int line_number, new_pc;
    char instruction[18];
    char symbol[26];

    // handles flags
    if(argc > 1 && (strcmp(argv[1], "-s") == 0))
        dump_tab = 1;
    else if(argc > 1 && (strcmp(argv[1], "-o") == 0))
        object_file = 1;

    if(dump_tab == 1 | object_file == 1)
        start = 2;
    else
        start = 1;

    p1 = fopen("/tmp/passone", "w+");
    unlink("/tmp/passone");

    for(i = start; i < argc; i++) {
        // Open p2 so we can start
        if((p2 = fopen(argv[i], "r")) == NULL) {
            printf("ERROR: Cannot open file %s\n", argv[i]);
            exit(1);
        }

        // Handles the code
        while(fscanf(p2, "%d %s", &pc, instruction) != EOF) {
            // Break once we hit line 4096
            if(pc == 4096)
                break;
            new_pc = pc + pc_offset;
            symbol[0] = '\0';
            // Finds uncooked instructions, handles the 3rd field in that instruction
            if(instruction[0] == 'U') {
                fscanf(p2, "%s", symbol);
            };
            fprintf(p1, "\t%d  %s  %s\n", new_pc, instruction, symbol);
        }

        // Handles the symbol table
        while(fscanf(p2, "%s %d", symbol, &line_number) != EOF) {
            add_symbol(symbol, line_number + pc_offset);
        }

        // pc_offset must be updated so we can update the rest of the symbol tables properly.
        pc_offset = new_pc + 1;
        fclose(p2);
    }

    if(object_file) {
        print_first_pass(p1);
        append_table();
        fclose(p1);
        return 0;
    }
    generate_code();

    fclose(p1);

    return 0;
}

// Add a symbol to our global linked-list of symbols
//
void add_symbol(char * symbol, int line_number){
    SYMTABENTRY *temp;
    if(symtab == NULL){
    	symtab = malloc(sizeof(SYMTABENTRY));
    	strncpy(symtab->name, symbol, 26);
    	symtab->addr = line_number;
        symtab->next = NULL;
    }else{
        temp = malloc(sizeof(SYMTABENTRY));
    	strncpy(temp->name, symbol, 26);
    	temp->addr = line_number;
        temp->next = symtab;
	symtab = temp;
    }
}


// prints temporary file built during the first pass of reading object files
//... this is an aggregation of all object file memory locations being
// printed to standard output.
//
void print_first_pass(FILE* fp) {
    char c;
    rewind(fp);
    if(fp) {
        while((c = getc(fp)) != EOF) {
            putchar(c);
        }
    }
}




// Read p2, extract the 16 bit instructions line-by-line, push it to an .exe
void generate_code() {
    char linbuf[10];
    char instruction[18];
    int pc, mask, sym_val, i, j, old_pc, diff;
    char symbol[26];
    old_pc = 0;
    rewind(p1);

    while(fscanf(p1, "%d %s", &pc, instruction) != EOF) {
        if((diff = pc - old_pc) > 1) {
            for(j = 1; j < diff; j++) {
                printf("1111111111111111\n");
            }
        }
        old_pc = pc;
        if(instruction[0] == 'U') {
            fscanf(p1, "%s", symbol);
            if((sym_val = get_sym_val(symbol)) == -1) {
                fprintf(stderr, "no symbol for %s\n", symbol);
                exit(27);
            }
            for(i = 0; i < 12; i++) {
                cstr_12[i] = '0';
            }
            cstr_12[12] = '\0';

            mask = 2048;
            for(i = 0; i < 12; i++) {
                if(sym_val & mask)
                    cstr_12[i] = '1';
                mask >>= 1;
            }
            for(i = 0; i < 12; i++) {
                instruction[i + 5] = cstr_12[i];
            }
            printf("%s\n", &instruction[1]);
        } else {
            printf("%s\n", instruction);
        }
    }
}

// prints a line of  4096  x  to separate first-pass output from the printed
// symbol table, then prints the combined and relocated symbol table  to
// standard output (when called after print_first_pass() it produces a single
// combined object file output, but NOT an executable output)
//
void append_table() {
    printf(" 4096 x \n");
    SYMTABENTRY *temp;
    temp = symtab;
    while(temp->next != NULL) {
        printf("   %s\t\t%d\n", temp->name, temp->addr);
        temp = temp->next;
    }
    printf("   %s\t\t%d\n", temp->name, temp->addr);
}

// get symbol value of passed in argument
int get_sym_val(char name[]) {
    SYMTABENTRY *temp;
    temp = symtab;
    while(temp != NULL) {
        if(strcmp(temp->name, name) == 0)
            return temp->addr;
        temp = temp->next;
    }
    return -1;
}
