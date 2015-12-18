 =============================================================================
# File: CSimpleList.mak (Fall 2015)
# =============================================================================

CC = g++
CFLAGS = -Wall -g -c
LINK = g++
LFLAGS = -g
SEMESTER = Fall2015
VERSION = 01

a.out                   :       main.o CSimpleList.o
                                        $(LINK) $(LFLAGS) main.o CSimpleList.o

main.o                  :       main.cpp CSimpleList.h
                                        $(CC) $(CFLAGS) main.cpp

CSimpleList.o   :       CSimpleList.cpp CSimpleList.h
                                        $(CC) $(CFLAGS) CSimpleList.cpp

clean                   :
                                        rm -f *.o a.out


save                    :
                                        tar cvzf CSimpleListStaticArraySolution$(SEMESTER)_v$(VERSION).tar.gz           \
                                                                                                                                                CSimpleList.cpp       $
                                                                                                                                                CSimpleList.h         $
                                                                                                                                                main.cpp              $
                                                                                                                                                makefile              $
                                                                                                                                                *.txt
