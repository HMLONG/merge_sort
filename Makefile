mergesort : merge_sort.o
	gcc -o merge_sort merge_sort.o
mergesort.o : merge_sort.c
	gcc -c merge_sort.c
clean :
	rm merge_sort merge_sort.o
