# 1 "master/IDA_CES.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "master/IDA_CES.c" 2
# 1 "master/IDA_CES.h" 1





# 1 "master/operation_CES.h" 1
# 26 "master/operation_CES.h"
typedef struct CE_2 {
    char cp[8];
    char co[8];
    char ep[12];
    char eo[12];
    char sp[6];
} CE;




extern CE state_CE;
extern const CE deff_CE;
extern const CE r_CE;
extern const CE u_CE;
extern const CE d_CE;
extern const CE l_CE;
extern const CE f_CE;
extern const CE b_CE;
extern const CE m_CE;
extern const CE s_CE;
extern const CE e_CE;
extern const CE y_CE;
extern const CE x_CE;
extern const CE z_CE;


extern char LED_Light[6][9];



void over_write_CE_from_A_to_B(const CE , CE *);
void over_write_CE(const CE);
extern unsigned int total_number_of_moves;



typedef struct enm {
    const CE(*DATA);
    char *name;
    char CE_count;

} CE_LISTER;

extern const CE_LISTER CE_LIST[(2 + 12 * 3)];


extern const char LED_C[8][3];


extern const char LED_E[12][2];


char str_cmp_const(const char p1[], char *p2);

void set_C(void);
void set_E(void);
void set_S(void);
void set_CES(void);

char command_turn_CE(const char *s);

typedef struct TURN_NUM2 {
    const char MEN_SURFASE[4];
    const char POINT_NUM[12];
} TURN_NUM;

extern char TURN_COUNT;
void command_turn_ARRAY(const char *s);
void ARRAY_SIDE_TURN(const char surface);
void ARRAY_LINE_TURN(const char MOVE_LOW, const TURN_NUM MEN_NUM_1);

void turn_CE(const CE_LISTER *);
# 6 "master/IDA_CES.h" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 1 3



# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 2 3






# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\features.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 2 3
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 22 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long int wchar_t;
# 127 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned size_t;
# 176 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __int24 int24_t;
# 212 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef __uint24 uint24_t;
# 21 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 2 3


int atoi (const char *);
long atol (const char *);
long long atoll (const char *);
double atof (const char *);

float strtof (const char *restrict, char **restrict);
double strtod (const char *restrict, char **restrict);
long double strtold (const char *restrict, char **restrict);





long strtol (const char *restrict, char **restrict, int);
unsigned long strtoul (const char *restrict, char **restrict, int);
long long strtoll (const char *restrict, char **restrict, int);
unsigned long long strtoull (const char *restrict, char **restrict, int);

int rand (void);
void srand (unsigned);
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
          void abort (void);
int atexit (void (*) (void));
          void exit (int);
          void _Exit (int);
# 65 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
void *bsearch (const void *, const void *, size_t, size_t, int (*)(const void *, const void *));





__attribute__((nonreentrant)) void qsort (void *, size_t, size_t, int (*)(const void *, const void *));

int abs (int);
long labs (long);
long long llabs (long long);

typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;
typedef struct { long long quot, rem; } lldiv_t;

div_t div (int, int);
ldiv_t ldiv (long, long);
lldiv_t lldiv (long long, long long);


typedef struct { unsigned int quot, rem; } udiv_t;
typedef struct { unsigned long quot, rem; } uldiv_t;
udiv_t udiv (unsigned int, unsigned int);
uldiv_t uldiv (unsigned long, unsigned long);
# 104 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdlib.h" 3
size_t __ctype_get_mb_cur_max(void);
# 7 "master/IDA_CES.h" 2

# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 1 3
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 3
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 10 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef void * va_list[1];




typedef void * __isoc_va_list[1];
# 145 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long ssize_t;
# 254 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long off_t;
# 407 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\bits/alltypes.h" 3
typedef struct _IO_FILE FILE;
# 24 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 2 3
# 52 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\c99\\stdio.h" 3
typedef union _G_fpos64_t {
 char __opaque[16];
 double __align;
} fpos_t;

extern FILE *const stdin;
extern FILE *const stdout;
extern FILE *const stderr;





FILE *fopen(const char *restrict, const char *restrict);
FILE *freopen(const char *restrict, const char *restrict, FILE *restrict);
int fclose(FILE *);

int remove(const char *);
int rename(const char *, const char *);

int feof(FILE *);
int ferror(FILE *);
int fflush(FILE *);
void clearerr(FILE *);

int fseek(FILE *, long, int);
long ftell(FILE *);
void rewind(FILE *);

int fgetpos(FILE *restrict, fpos_t *restrict);
int fsetpos(FILE *, const fpos_t *);

size_t fread(void *restrict, size_t, size_t, FILE *restrict);
size_t fwrite(const void *restrict, size_t, size_t, FILE *restrict);

int fgetc(FILE *);
int getc(FILE *);
int getchar(void);
int ungetc(int, FILE *);

int fputc(int, FILE *);
int putc(int, FILE *);
int putchar(int);

char *fgets(char *restrict, int, FILE *restrict);

char *gets(char *);


int fputs(const char *restrict, FILE *restrict);
int puts(const char *);


#pragma printf_check(printf) const
#pragma printf_check(vprintf) const
#pragma printf_check(sprintf) const
#pragma printf_check(snprintf) const
#pragma printf_check(vsprintf) const
#pragma printf_check(vsnprintf) const


int printf(const char *restrict, ...);
int fprintf(FILE *restrict, const char *restrict, ...);
int sprintf(char *restrict, const char *restrict, ...);
int snprintf(char *restrict, size_t, const char *restrict, ...);

int vprintf(const char *restrict, __isoc_va_list);
int vfprintf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsprintf(char *restrict, const char *restrict, __isoc_va_list);
int vsnprintf(char *restrict, size_t, const char *restrict, __isoc_va_list);

int scanf(const char *restrict, ...);
int fscanf(FILE *restrict, const char *restrict, ...);
int sscanf(const char *restrict, const char *restrict, ...);
int vscanf(const char *restrict, __isoc_va_list);
int vfscanf(FILE *restrict, const char *restrict, __isoc_va_list);
int vsscanf(const char *restrict, const char *restrict, __isoc_va_list);

void perror(const char *);

int setvbuf(FILE *restrict, char *restrict, int, size_t);
void setbuf(FILE *restrict, char *restrict);

char *tmpnam(char *);
FILE *tmpfile(void);




FILE *fmemopen(void *restrict, size_t, const char *restrict);
FILE *open_memstream(char **, size_t *);
FILE *fdopen(int, const char *);
FILE *popen(const char *, const char *);
int pclose(FILE *);
int fileno(FILE *);
int fseeko(FILE *, off_t, int);
off_t ftello(FILE *);
int dprintf(int, const char *restrict, ...);
int vdprintf(int, const char *restrict, __isoc_va_list);
void flockfile(FILE *);
int ftrylockfile(FILE *);
void funlockfile(FILE *);
int getc_unlocked(FILE *);
int getchar_unlocked(void);
int putc_unlocked(int, FILE *);
int putchar_unlocked(int);
ssize_t getdelim(char **restrict, size_t *restrict, int, FILE *restrict);
ssize_t getline(char **restrict, size_t *restrict, FILE *restrict);
int renameat(int, const char *, int, const char *);
char *ctermid(char *);







char *tempnam(const char *, const char *);
# 8 "master/IDA_CES.h" 2




char depth_add(void);

extern const CE m_CE_IDA;
extern const CE s_CE_IDA;
extern const CE e_CE_IDA;

extern const CE_LISTER CE_IDA_LIST[18 + 1];

extern char shortest_command[2];
extern char shortest_depth;
void initialization_shortest_command(void);

char Create_Shoretest_command_Most_deep(void);
char Create_shortest_command_depp_N1(char check_depth);
char branch_off(void);
# 1 "master/IDA_CES.c" 2


char shortest_command[2];
char shortest_depth;

void initialization_shortest_command(void)
{
 char i;
 shortest_depth = 0;
 for (i = 0; i < 2; i++)
  shortest_command[i] = '\0';
}





char Create_Shoretest_command_Most_deep(void)
{
 char check_depth;
 char search_flag;
 check_depth = shortest_depth;
 depth_add();

 search_flag = 1;
 while (search_flag == 1)
 {
  search_flag = Create_shortest_command_depp_N1(check_depth);

  check_depth--;
 }
 while (branch_off() == 1)
  ;
 return search_flag;
}

char branch_off(void)
{
 char return_num = 0;
 char a, b, c = 1, d = 0;

 char check_depth = 0;
 if (shortest_depth == 0)
  return 0;
 check_depth = 0;
 while (check_depth < shortest_depth)
 {
  if (check_depth >= 1)
  {
   c = (18 + shortest_command[check_depth] - shortest_command[check_depth - 1]) % 3;
   d = CE_IDA_LIST[shortest_command[check_depth - 1]].name[0];
  }

  a = CE_IDA_LIST[shortest_command[check_depth]].name[0];
  b = CE_IDA_LIST[shortest_command[check_depth + 1]].name[0];
  if ((a == b) || (c == 0 && d == b))


  {
   return_num = 1;
# 75 "master/IDA_CES.c"
   if (shortest_command[check_depth + 1] == 18)
   {


    signed char i;
    for (i = check_depth; i >= 0; i--)
    {
     if (shortest_command[i] != 18)
     {
      break;
     }
    }

    if (i == -1)
    {
     shortest_depth++;
     shortest_command[0] = 1;
    }
    else
    {
     shortest_command[i]++;
    }
    for (check_depth = i + 1; check_depth <= shortest_depth; check_depth++)
     shortest_command[check_depth] = 1;
   }
   else
   {
    shortest_command[check_depth + 1]++;

    for (check_depth = check_depth + 2; check_depth <= shortest_depth; check_depth++)
     shortest_command[check_depth] = 1;
   }

   break;
  }
  check_depth++;
 }
 return return_num;
}

char depth_add(void)
{
 if (shortest_command[shortest_depth] >= 18)
 {
  char NEXT_FLAG = 1;
  char check_depth;
  for (check_depth = 0; check_depth < shortest_depth; check_depth++)
  {
   if (shortest_command[check_depth] != 18)
   {
    NEXT_FLAG = 0;
   }
  }
  if (NEXT_FLAG)
  {
   shortest_depth++;
   shortest_command[shortest_depth] = 1;
   return 1;
  }
  return 0;
 }
 return 0;
}






char Create_shortest_command_depp_N1(char check_depth)
{
 char return_num;
 return_num = 0;
 if (shortest_command[check_depth] == 18)
 {
  shortest_command[check_depth] = 1;

  return_num = 1;
 }
 else
 {
  shortest_command[check_depth]++;
 }
 return return_num;
}

const CE_LISTER CE_IDA_LIST[18 + 1] = {
 {&deff_CE, "deff", 0},


 {&u_CE, "U", 1},
 {&l_CE, "L", 1},
 {&f_CE, "F", 1},
 {&d_CE, "D", 1},
 {&r_CE, "R", 1},
 {&b_CE, "B", 1},





 {&u_CE, "U'", 3},
 {&l_CE, "L'", 3},
 {&f_CE, "F'", 3},
 {&d_CE, "D'", 3},
 {&r_CE, "R'", 3},
 {&b_CE, "B'", 3},





 {&u_CE, "U2", 2},
 {&l_CE, "L2", 2},
 {&f_CE, "F2", 2},
 {&d_CE, "D2", 2},
 {&r_CE, "R2", 2},
 {&b_CE, "B2", 2},





};

const CE m_CE_IDA = {
 {0, 1, 2, 3, 4, 5, 6, 7},
 {0, 0, 0, 0, 0, 0, 0, 0},
 {0, 1, 2, 3, 8, 5, 4, 7, 10, 9, 6, 11},
 {0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0},
 {3, 0, 2, 5, 4, 1}};

const CE s_CE_IDA = {
 {0, 1, 2, 3, 4, 5, 6, 7},
 {0, 0, 0, 0, 0, 0, 0, 0},
 {0, 1, 2, 3, 4, 7, 6, 11, 8, 5, 10, 9},
 {0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
 {4, 1, 0, 3, 5, 2}};

const CE e_CE_IDA = {
 {0, 1, 2, 3, 4, 5, 6, 7},
 {0, 0, 0, 0, 0, 0, 0, 0},
 {1, 2, 3, 0, 4, 5, 6, 7, 8, 9, 10, 11},
 {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
 {0, 4, 1, 2, 3, 5}};
