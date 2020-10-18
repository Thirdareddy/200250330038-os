
cc=gcc

builddemo: builddemo.o add.o
  $(cc)-o builddemo builddemo.o add.o

builddemo.o: builddemo.c
  $(cc)-c -o builddemo.o builddemo.c

add.o: add.c
  $(cc)-c -o add.o add.c
   
