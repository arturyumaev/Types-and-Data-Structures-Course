all: build run


build:
	gcc -o main.exe main.c

run:
	./main.exe

push:
	git add -A
	git commit -m "Update"
	git push -u origin master
