/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** objdump
*/

#ifndef MY_OBJDUP_H_
# define MY_OBJDUP_H_

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <elf.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct objdump_s {
	int fd;
	void *buf;
	char *machine_name;
	struct stat s;
	struct mach_header_64 *elf;
	struct section_64 *symtab;
	struct section_64 *shd;
	struct section_64 sect_sym;
	struct section_64 *str_tab;
	int nb_file;
	int nb_func;
	int shnum;
	char *file_name;
} objdump_t;

typedef struct pc_s {
	int macro;
	char *str;
} pc_t;

void get_machine_name(void);
void get_str_tab(void);
char *getflag(void);
void print_dec(unsigned int y, char *str, unsigned int max);
void print_end(unsigned int y, int i, char *str);
void print_hex(int i);
void print_data(char *sh_strtab_p);
int is_ok(char *str, int i);
int find(int size, char *str, const char **str2);
int verif_flag(struct mach_header_64 *elf);

objdump_t objdump;

#endif /* !MY_OBJDUP_H_ */
