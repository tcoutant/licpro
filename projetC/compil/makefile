all : definitions.o fmenu.o fprise.o ftour.o HumainVsCPUMaxPions.o HumainVsCPUMinOptions.o HumainVsCPURandom.o HumainVsCPUMaxValeurCase.o modeDeJeu.o main.o projet

definitions.o : definitions.c
	gcc -c -Wall definitions.c

fmenu.o : fmenu.c
	gcc -c -Wall fmenu.c

fprise.o : fprise.c
	gcc -c -Wall fprise.c

ftour.o : ftour.c
	gcc -c -Wall ftour.c

HumainVsCPUMaxPions.o : HumainVsCPUMaxPions.c
	gcc -c -Wall HumainVsCPUMaxPions.c

HumainVsCPUMinOptions.o : HumainVsCPUMinOptions.c
	gcc -c -Wall HumainVsCPUMinOptions.c

HumainVsCPURandom.o : HumainVsCPURandom.c
	gcc -c -Wall HumainVsCPURandom.c

HumainVsCPUMaxValeurCase.o : HumainVsCPUMaxValeurCase.c
	gcc -c -Wall HumainVsCPUMaxValeurCase.c

modeDeJeu.o : modeDeJeu.c
	gcc -c -Wall modeDeJeu.c

main.o : main.c
	gcc -c -Wall main.c

projet : definitions.o fmenu.o fprise.o ftour.o modeDeJeu.o main.o
	gcc -o projet definitions.o fmenu.o fprise.o ftour.o HumainVsCPUMaxPions.o HumainVsCPUMinOptions.o HumainVsCPURandom.o HumainVsCPUMaxValeurCase.o modeDeJeu.o main.o

clean :
	rm *.o *~



