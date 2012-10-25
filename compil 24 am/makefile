all : definitions.o fmenu.o fprise.o ftour.o HumainVsHumain.o main.o projet

definitions.o : definitions.c
	gcc -c -Wall definitions.c

fmenu.o : fmenu.c
	gcc -c -Wall fmenu.c

fprise.o : fprise.c
	gcc -c -Wall fprise.c

ftour.o : ftour.c
	gcc -c -Wall ftour.c

HumainVsHumain.o : HumainVsHumain.c
	gcc -c -Wall HumainVsHumain.c

main.o : main.c
	gcc -c -Wall main.c

projet : definitions.o fmenu.o fprise.o ftour.o HumainVsHumain.o main.o
	gcc -o projet definitions.o fmenu.o fprise.o ftour.o HumainVsHumain.o main.o

clean :
	rm *.o



