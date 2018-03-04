/*
** EPITECH PROJECT, 2018
** my_nm
** File description:
** my_nm
*/

#ifndef MY_NM_H_
# define MY_NM_H_

# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
//# include <elf.h>
#include <mach-o/loader.h>
#include <mach-o/nlist.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct nmtab_s {
	int value;
	char *name;
	char type;
} nmtab_t;

typedef struct nm_s {
	int fd;
	void *buf;
	nmtab_t *nmtab;
	struct stat s;
	struct mach_header_64 *elf;
	struct symtab_command *symtab;
	struct section_64 *shd;
	struct section_64 sect_sym;
	struct section_64 *str_tab;
	int nb_file;
	int nb_func;
	int shnum;
	int osn;
	char *file_name;
}	nm_t;

void get_str_tab(void);
struct section_64 get_section(int macro);
void fill_nmtab(void);
void aff_nmtab(void);
void sort_nmtab(void);
char print_type(struct symtab_command sym, struct section_64 *shdr);

nm_t nm;

#endif /* !MY_NM_H_ */
