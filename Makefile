CC 	= gcc
CFLAGS 	= -O3 

SRCS_LIB = gen_list.c \
	gen_stack.c 

SRCS =	mainlst.c \
	mainpile.c

OBJS_LIB = $(SRCS_LIB:.c=.o)
OBJS = $(SRCS:.c=.o)

LIB = libgen_list.a

all:  release

release: mainlst mainpile $(LIB)

$(LIB): $(OBJS_LIB)
	ar -r $(LIB) $(OBJS_LIB)

debug: 
	$(MAKE) $(MAKEFILE) DEBUG="-g -D DEBUG"

mainlst: mainlst.o $(LIB)
	gcc $(CFLAGS) $(DEBUG) -o mainlst mainlst.o -L. -lgen_list

mainpile: mainpile.o $(LIB)
		gcc $(CFLAGS) $(DEBUG) -o mainpile mainpile.o -L. -lgen_list

$(OBJS_LIB): $(SRCS_LIB)

$(OBJS): $(SRCS)

.c.o:
	gcc $(CFLAGS) $(DEBUG) -c $<

clean:
	rm -f *.o
	rm $(LIB)
	rm mainlst
	rm mainpile
